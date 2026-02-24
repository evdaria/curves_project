#include <iostream>
#include <memory>
#include "circle.h"

int main() {
    std::cout << "Hello, Curves project!" << std::endl;

    auto circle = std::make_unique<Circle>(5.0);
    return 0;
}