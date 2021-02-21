#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string expression = "";
    std::vector<std::string> symbols;

    std::cout << "Enter your expression (ex. 6 + 5) : ";
    getline(std::cin, expression);

    std::stringstream ss(expression);
    std::string symbol;
    char space = ' ';

    while(getline(ss, symbol, space)){
        symbols.push_back(symbol);
    }

    int num1 = std::stoi(symbols[0]);
    int num2 = std::stoi(symbols[2]);
    std::string operation = symbols[1];

    if(operation == "+"){
        std::cout << num1 + num2 << std::endl;
    }
    
    return 0;
}
