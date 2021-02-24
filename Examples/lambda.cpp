#include <iostream>

int main(int argc, char const *argv[])
{
    /* Just Create a lambda it's does nothing */
    [](){
        std::cout << "I'm a Lambda, I'll do nothing no one is calling me :(" << std::endl;
    };

    /* Create and executing */
    [](){
        std::cout << "I'm a Lambda which executes" << std::endl;
    }();

    /* Create a lambda and stores in a variable */
    auto lambda = [](){
        std::cout << "I'm a Lambda stored in a variable" << std::endl;
    };

    lambda();

    /* Create a lambda which gets a parameter */
    auto lambda_param = [](int x){
        std::cout << "My parameter is " << x << std::endl;
    };

    lambda_param(10);

    

    return 0;
}

