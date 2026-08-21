#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <cmath>

class Parser{
    private:
         const std::string& src;
        size_t pos;
    
    public:
         Parser(const std::string& text) : src(text),pos(0){

         }
         double parseNumber(){
            size_t start = pos;

            while (pos<src.size()&&std::isdigit(static_cast<unsigned char>(src[pos])) || src[pos] == '.')
            {
                pos++;
            }
            return std::stod(src.substr(start,pos-start));
            
         };

}

int main() {
    std::cout << "C++ Console Calculator\n";

    std::string expression;

    std::cout << "Enter Expression: ";
    std::getline(std::cin, expression);

    std::cout << "You entered: " << expression << '\n';


    return 0;
}