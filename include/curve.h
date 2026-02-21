#ifndef CURVE_H
#define CURVE_H

#include <geometry.h>

class Curve {
public:
    virtual ~Curve();

    virtual Point3D getPoint(double t) const = 0;
    virtual Vector3D getDerivative(double t) const = 0;

    Curve(const Curve&) = delete;
    Curve& operator=(const Curve&) = delete;

    Curve(Curve&&) = default;
    Curve& operator=(Curve&&) = default;

protected:
    Curve() = default;
};

#endif // CURVE_H