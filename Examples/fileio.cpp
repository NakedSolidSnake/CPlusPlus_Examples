#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ofstream out;
    std::ifstream in;

    std::string txt = "Cristiano Silva de Souza";
    std::string read_file;

    out.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    if(out.is_open()){
        out << txt ;
        out.close();
    }

    in.open("test.txt", std::ios_base::in);
    if(in.is_open()){
        while(in.good()){
            getline(in, read_file);
            
            read_file += "\n";
        }
        in.close();
    }

    std::cout << read_file;
    
    return 0;
}
