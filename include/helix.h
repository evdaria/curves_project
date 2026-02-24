#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

class Helix : public Curve {
private:
    double radius_;
    double step_;

public:
    explicit Helix(double radius, double step);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;

    double getRadius() const;
    double getStep() const;
};


#endif // HELIX_H