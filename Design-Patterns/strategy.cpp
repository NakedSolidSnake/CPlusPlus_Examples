#include <iostream>

using namespace std;

class Strategy
{
public:
    virtual int doOperation(int a, int b) = 0;
};

class OperationAdd : public Strategy
{
    int doOperation(int a, int b) override
    {
        return a + b;
    }
};

class OperationSub : public Strategy
{
    int doOperation(int a, int b) override
    {
        return a - b;
    }
};

class OperationMul : public Strategy
{
    int doOperation(int a, int b) override
    {
        return a * b;
    }
};

class Context
{
    public: 
        Context (Strategy *s){
            this->strategy = s;
        }

        int executeStrategy(int a , int b){
            return strategy->doOperation(a, b);
        }

    private:
        Strategy *strategy;
};

int main(int argc, char const **argv)
{
    
    Context ctx(new OperationAdd());
    cout << "Sum 5 + 5 = " << ctx.executeStrategy(5, 5) << endl;

    return 0;
}


