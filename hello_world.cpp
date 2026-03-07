#include <iostream>
#include <string>

// Программа для демонстрации персонализированного "Hello World"
// Исправлено: удалено 'using namespace std' для большей ясности кода

int main()
{
    std::string name;  // Variable to store user's name
    
    // Prompt user for their name
    std::cout << "Enter your name: ";
    std::cin >> name;   // Read the input
    
    // Display personalized greeting
    std::cout << "Hello world from " << name << std::endl;
    
    return 0;  // Program executed successfully
}
