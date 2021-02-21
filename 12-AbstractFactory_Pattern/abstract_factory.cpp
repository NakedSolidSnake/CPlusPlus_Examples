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
        cout << "Draw Shape::Circle" << endl; 
    }
};

class Square : public Shape
{
    void draw() override
    {
        cout << "Draw Shape::Square" << endl;
    }
};

class Triangle : public Shape
{    
    void draw() override
    {
        cout << "Draw Shape::Triangle" << endl;
    }
};

class Color
{
public:
    virtual void fill() = 0;
};


class Blue : public Color
{
    void fill() override
    {
        cout << "Blue color" << endl;
    }
};

class Red : public Color
{
    void fill() override
    {
        cout << "Red color" << endl;
    }
};

class Green : public Color 
{
    void fill() override
    {
        cout << "Green color" << endl;
    }
};

class AbstractFactory
{
public:
    virtual Color *getColor(string color) = 0;
    virtual Shape *getShape(string shape) = 0;
};

class ShapeFactory : public AbstractFactory
{

    Color *getColor(string color) override
    {
        return nullptr;
    }

public:
    Shape *getShape(string shape) override
    {
        if(shape.empty())
        {
            return nullptr;
        }

        if(!shape.compare("CIRCLE")){
            return new Circle();
        } else if(!shape.compare("TRIANGLE")){
            return new Triangle();
        } else if(!shape.compare("SQUARE")){
            return new Square();
        }

        return nullptr;
    }
};

class ColorFactory : public AbstractFactory
{
    Color *getColor(string color) override
    {
        if(color.empty()){
            return nullptr;
        }

        if(!color.compare("RED")){
            return new Red();
        } else if(!color.compare("GREEN")){
            return new Green();
        } else if (!color.compare("BLUE")){
            return new Blue();
        }

        return nullptr;
    }

    Shape *getShape(string shape) override
    {
        return nullptr;
    }
};

class FactoryProducer
{
    public:
    static AbstractFactory *getFactory(string choice){
        if(!choice.compare("SHAPE")){
            return new ShapeFactory();
        } else if (!choice.compare("COLOR")){
            return new ColorFactory();
        }

        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    AbstractFactory *shapeFactory = FactoryProducer::getFactory("SHAPE");

    Shape *shape1 = shapeFactory->getShape("CIRCLE");    
    shape1->draw();

    Shape *shape2 = shapeFactory->getShape("TRIANGLE");
    shape2->draw();

    Shape *shape3 = shapeFactory->getShape("SQUARE");    
    shape3->draw();

    AbstractFactory *colorFactory =  FactoryProducer::getFactory("COLOR");

    Color *color1 = colorFactory->getColor("RED");
    color1->fill();

    Color *color2 = colorFactory->getColor("GREEN");
    color2->fill();

    Color *color3 = colorFactory->getColor("BLUE");
    color3->fill();

    return 0;
}
