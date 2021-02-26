#include <iostream>
#include <cmath>

class Shape{
public:
    virtual double Area() = 0;
    static void PrintShape(Shape &shape){
        std::cout << "Shape: " << shape.Area() << std::endl;
    }
};

class Circle : public Shape{
public:
    Circle(double radius){
        this->radius = radius;
    }

    double Area()override{
        return M_1_PI * std::pow(radius, 2.0);
    }

private:
    double radius;    
    
};

class Square : public Shape{
public:
    Square(double side){
        this->side = side;
    }

    double Area()override final{
        return side * side;
    }

private:
    double side;
    
};

class Rectangle : public Shape{
public:
    Rectangle(double width, double height){
        this->width = width;
        this->height = height;
    }

    double Area()override final{
        return this->width * this->height;
    }

private:
    double height;
    double width;
    
};



int main(int argc, char const *argv[])
{
    Circle circle(10.0);
    Square square(10.0);
    Rectangle rectangle(10.0, 10.0);

    Shape::PrintShape(circle);
    Shape::PrintShape(square);
    Shape::PrintShape(rectangle);

    return 0;
}
