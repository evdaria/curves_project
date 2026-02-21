#ifndef GEOMETRY_H
#define GEOMETRY_H

/// Точка в трехмерном пространстве
struct Point3D {
    double x;
    double y;
    double z;

    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

/// Вектор в трехмерном пространстве
struct Vector3D {
    double dx;
    double dy;
    double dz;

    Vector3D(double dx = 0, double dy = 0, double dz = 0) : dx(dx), dy(dy), dz(dz) {}
};

#endif // GEOMETRY_H