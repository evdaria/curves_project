#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class Ellipse : public Curve {
private:
    double radiusX_;
    double radiusY_;

public:
    explicit Ellipse(double radiusX, double radiusY);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;

    double getRadiusX() const;
    double getRadiusY() const;
};

#endif // ELLIPSE_H