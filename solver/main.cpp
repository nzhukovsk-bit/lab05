#include "formatter_ex.h"
#include "solver.h"
#include <iostream>
#include <string>

int main() {
    float a, b, c;
    
    std::cout << "Enter coefficients a, b, c: ";
    std::cin >> a >> b >> c;
    
    try {
        float x1, x2;
        solve(a, b, c, x1, x2);
        
        std::string message = "Roots: " + std::to_string(x1) + " and " + std::to_string(x2);
        formatter(std::cout, message);
    }
    catch (const std::logic_error& e) {
        formatter(std::cout, e.what());
    }
    
    return 0;
}
