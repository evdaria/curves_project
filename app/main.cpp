#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

const double MIN_RADIUS = 0.5;
const double MAX_RADIUS = 10;
const double MIN_STEP = 0.1;
const double MAX_STEP = 5;

int main() {
    std::vector<std::shared_ptr<Curve>> curves;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> type(0, 2);
    std::uniform_real_distribution<> radius(MIN_RADIUS, MAX_RADIUS);
    std::uniform_real_distribution<> step(MIN_STEP, MAX_STEP);

    try {
        std::cout << "Generate curves: " << std::endl;
        bool circle = false;
        bool ellipse = false;
        bool helix = false;
        while (!(circle && ellipse && helix)) {
            int curveType = type(gen);

            switch (curveType)
            {
            case 0: {
                circle = true;
                double circleRadius = radius(gen);
                curves.push_back(std::make_shared<Circle>(circleRadius));
                std::cout << "Circle: radius = " << circleRadius << std::endl;
                break;
            }
            case 1: {
                ellipse = true;
                double ellipseRadiusX = radius(gen);
                double ellipseRadiusY = radius(gen);
                curves.push_back(std::make_shared<Ellipse>(ellipseRadiusX, ellipseRadiusY));
                std::cout << "Ellipse: radiusX = " << ellipseRadiusX << ", radiusY = " << ellipseRadiusY << std::endl;
                break;
            }
            case 2: {
                helix = true;
                double helixRadius = radius(gen);
                double helixStep = step(gen);
                curves.push_back(std::make_shared<Helix>(helixRadius, helixStep));
                std::cout << "Helix: radius = " << helixRadius << ", step = " << helixStep << std::endl;
                break;
            }
            }
        }

        std::cout << "Total curves: " << curves.size() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    const double t = M_PI / 4.0;

    std::cout << "\nCurves point and derivative: " << std::endl;

    int index = 1;
    for (const auto& curve : curves) {
        Point3D p = curve->getPoint(t);
        Vector3D d = curve->getDerivative(t);

        std::cout << "Curve " << index++ << ":" << std::endl;
        std::cout << " point: (" << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;
        std::cout << " derivative: (" << d.dx << ", " << d.dy << ", " << d.dz << ")" << std::endl;
    }

    return 0;
}