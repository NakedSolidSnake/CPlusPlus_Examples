#include <iostream>

using namespace std;

class Context;

class State{
public:
    virtual void doAction(Context &context) = 0;
};

class Context
{
    public:
    Context () {
        this->state = nullptr;
    }

    State *getState() const{
        return this->state;
    }

    void setState(State *state){
        this->state = state;
    }
        
    private:
    State *state;
};

class StartState : public State 
{
public:
    void doAction(Context &context) override{
        cout << "in Start state." << endl;
        context.setState(this);
    }

     string to_string(){
        return "Start state";
    }

};

class StopState : public State 
{
public:
    void doAction(Context &context) override{
        cout << "in Stop state." << endl;
        context.setState(this);
    }

    string to_string(){
        return "Stop state";
    }

};



int main(int argc, char const *argv[])
{
    Context context;

    StartState *start = new StartState();
    start->doAction(context);

    // context.getState()->to_string();

    StopState *stop = new StopState();
    stop->doAction(context);

    return 0;
}
