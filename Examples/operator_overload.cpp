#include <iostream>
#include <sstream>

class Box{

public:

    Box(){

    }

    Box(std::string name, int width, int height)
    {
        this->name = name;
        this->width = width;
        this->height = height;
    }

    /* Increment internal parameters */
    Box& operator ++(){
        this->height++;
        this->width++;
        return *this;
    }

    /* Format like to_string */
    operator const char *(){
        std::ostringstream boxStream;
        boxStream << "Box : " << this->height << ", " << this->width << ", " << this->name;
        this->out = boxStream.str();
        return this->out.c_str();
    }

    /* Sum objects contents */
    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.width = boxSum.width + box2.width;
        boxSum.height = boxSum.height + box2.height;
    }

    /* Link an index to an attribute*/
    auto operator [](int x){
        switch (x)
        {
        case 0:
            return (int)name.length();
            break;
        
        case 1:
            return width;
            break;

        case 2:
            return height;
            break;
        
        default:
            break;
        }
    }

    /* Compare 2 objects */
    bool operator == (const Box& box2){
        return (this->name.compare(box2.name) == 0 && this->width == box2.width && this->height == box2.height);
    }

    /* Verify if current object is lesser than another object */
    bool operator < (const Box& box){
        return this->width < box.width && this->height < box.height;
    }

    /* Verify if current object is greater than another object */
    bool operator > (const Box& box){
        return this->width > box.width && this->height > box.height;
    }

    /* Copy all data to a current object */
    void operator = (const Box& box){
        this->height = box.height;
        this->width = box.width;
        this->name = box.name;
    }

    void toString(void)
    {
        std::cout << "name: " << this->name << ", width: " << this->width << ", height: " << this->height << std::endl;
    }

private:
    int width;
    int height;
    std::string name;
    std::string out;
};

int main(int argc, char const *argv[])
{
    Box box("Box", 10, 10);
    Box box2("Box2", 12, 12);
    ++box;
    box.toString();

    if(box > box2){
        std::cout << box << std::endl;
    }else {
        std::cout << box2 << std::endl;
    }

    return 0;
}
