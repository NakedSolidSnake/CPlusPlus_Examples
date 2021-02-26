#include <iostream>

class Shape
{
public:
    Shape(std::string shape_name)
    {
        this->shape_name = shape_name;
    }

private:
    std::string shape_name;
    friend class GetShapeName;
};

class GetShapeName
{
public:
    static std::string getShapeName(Shape &shape)
    {
        return shape.shape_name;
    }
};

int main(int argc, char const *argv[])
{
    Shape shape("Square");
    std::cout << "Shape type: " << GetShapeName::getShapeName(shape) << std::endl;
    return 0;
}

