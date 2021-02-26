#include <iostream>
#include <functional>
#include <vector>

std::string msg1(){
    return "message 1";
}

std::string msg2(){
    return "message 2";
}

std::string msg3(){
    return "message 3";
}

std::string function_exec(std::function<std::string()> func){
    return func();
}

int main(int argc, char const *argv[])
{

    std::vector<std::function<std::string()>> functions;
    functions.push_back(msg1);
    functions.push_back(msg2);
    functions.push_back(msg3);

    for(auto f : functions){
        std::cout << function_exec(f) << std::endl;
    }

    return 0;
}
