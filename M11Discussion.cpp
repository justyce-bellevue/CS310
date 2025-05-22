#include <iostream> 
#include <string>   


tempalte <typename T>
T combine(T val1, T val2) {
    return val1 + val2 
}

int main() {
    int num1 = 5;
    int num2 = 10;
    int sum = combine(num1, num2);
    std::cout << "Combined integers: " << sum << std::endl;

    std::string s1 = "Hello";
    std::string s2 = "World";
    std::string result = combine(s1, s2);
    std::cout << "Combined strings: " << result << std::endl;

    return 0;
}
