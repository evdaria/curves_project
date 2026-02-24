#include "helix.h"
#include <stdexcept>
#include <cmath>

Helix::Helix(double radius, double step) : radius_(radius), step_(step) {
    if (radius <= 0.0 || step <= 0.0) {
        throw std::invalid_argument("Helix radius and step must be positive");
    }
}

Point3D Helix::getPoint(double t) const {
    return Point3D(radius_ * std::cos(t), radius_ * std::sin(t), step_ * t / (2 * M_PI));
}

Vector3D Helix::getDerivative(double t) const {
    return Vector3D(-radius_ * std::sin(t), radius_ * std::cos(t), step_ / (2 * M_PI));
}

double Helix::getRadius() const {
    return radius_;
}

double Helix::getStep() const {
    return step_;
}