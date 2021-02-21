#include <iostream>

using namespace std;

class Shape
{
    public:
    virtual void draw() = 0;
};

class Circle : public Shape 
{
    void draw() override
    {
        cout << "Draw Circle" << endl;
    }
};

class Square :  public Shape 
{
    void draw() override
    {
        cout << "Draw Square" << endl;
    }
};

class Rectangle : public Shape 
{
    void draw() override
    {
        cout << "Draw Rectangle" << endl;
    }
};

class ShapeFactory
{
    public:
    Shape *getShape(string shapeType)
    {
        if(shapeType.empty()){
            return nullptr;
        }

        if(!shapeType.compare("CIRCLE")){
            return new Circle();
        } else if (!shapeType.compare("RECTANGLE")){
            return new Rectangle();
        } else if(!shapeType.compare("SQUARE")){
            return new Square();
        } else {
            return nullptr;
        }


    }
};

int main(int argc, char const *argv[])
{
    ShapeFactory shapeFactory;
    Shape *circle = shapeFactory.getShape("CIRCLE");
    circle->draw();

    Shape *square = shapeFactory.getShape("SQUARE");

    Shape *rectangle = shapeFactory.getShape("RECTANGLE");
    return 0;
}
