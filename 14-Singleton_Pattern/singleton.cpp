#include <iostream>

using namespace std;

class SingleObject
{

private: 
    static SingleObject *instance;
    SingleObject(){

    }  

public:
    static SingleObject *getInstance(){
        if(!instance)
            instance =  new SingleObject();            
        return instance;
    }

    void showMessage(){
        cout << "Hello World." << endl;
    }  
};

SingleObject *SingleObject::instance = 0;

int main(int argc, char const *argv[])
{
    SingleObject *s = SingleObject::getInstance();
    s->showMessage();

    cout << "Value: " << s << endl;

    SingleObject *s2 = SingleObject::getInstance();
    s2->showMessage();

    cout << "Value: " << s2 << endl;
    return 0;
}
