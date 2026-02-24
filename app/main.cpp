#include <iostream>
#include <memory>
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

int main() {
    std::cout << "Hello, Curves project!" << std::endl;

    auto circle = std::make_unique<Circle>(5.0);
    auto ellipse = std::make_unique<Ellipse>(2.5, 5.0);
    return 0;
}