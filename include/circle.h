#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

class Circle : public Curve {
private:
    double radius_;

public:
    explicit Circle(double radius);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;

    double getRadius() const;
};

#endif // CIRCLE_H