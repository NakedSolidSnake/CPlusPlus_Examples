#include <iostream>

int main(int argc, char const *argv[])
{
    int num = 0;

    try
    {
        if(num == 0){
            throw "Number is zero";
        }
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {
        throw std::runtime_error("Error Occurred");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}
