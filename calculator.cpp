#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <cmath>

class Parser {
public:
    explicit Parser(const std::string& text) : src(text), pos(0) {}

    double parse() {
        double value = parseNumber();

        skipSpaces();

        if (pos != src.size()) {
            throw std::runtime_error(
                "Unexpected character at position " + std::to_string(pos)
            );
        }

        return value;
    }

private:
    const std::string& src;
    size_t pos;

    void skipSpaces() {
        while (pos < src.size() &&
               std::isspace(static_cast<unsigned char>(src[pos]))) {
            pos++;
        }
    }

    char peek() {
        skipSpaces();
        return pos < src.size() ? src[pos] : '\0';
    }

    char get() {
        skipSpaces();
        return pos < src.size() ? src[pos++] : '\0';
    }

    double parseNumber() {
        skipSpaces();

        size_t start = pos;

        while (pos < src.size() &&
               (std::isdigit(static_cast<unsigned char>(src[pos])) ||
                src[pos] == '.')) {
            pos++;
        }

        if (start == pos) {
            throw std::runtime_error(
                "Expected a number at position " + std::to_string(pos)
            );
        }

        return std::stod(src.substr(start, pos - start));
    }
};

int main() {
    std::cout << "C++ Console Calculator\n";

    std::string expression;

    std::cout << "Enter Expression: ";
    std::getline(std::cin, expression);

    try {
        Parser parser(expression);
        double result = parser.parse();

        std::cout << "Result: " << result << '\n';
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}