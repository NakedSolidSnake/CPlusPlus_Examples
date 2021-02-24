#include <iostream>

class Person
{
    public:
    Person();
    Person(std::string name, std::string address, unsigned char age);

    std::string getName() const;
    void setName(std::string name);

    std::string getAddress() const;
    void setAddress(std::string address);

    unsigned char getAge() const; 
    void setAge(unsigned char age);

    void to_string() const;
    

    private:
        std::string name;
        std::string address;
        unsigned char age;
};

Person::Person() : 
name(""),
address(""),
age(0)
{

}

Person::Person(std::string name, std::string address, unsigned char age) : 
name(name),
address(address),
age(age)
{

}

std::string Person::getName() const
{
    return this->name;
}

void Person::setName(std::string name)
{
    this->name = name;
}

std::string Person::getAddress() const
{
    return this->address;
}

void Person::setAddress(std::string address)
{
    this->address = address;
}

unsigned char Person::getAge() const
{
    return this->age;
}

void Person::setAge(unsigned char age)
{
    this->age = age;
}

void Person::to_string() const
{
    std::cout << this->name << " " << this->address << " " << (int)this->age << std::endl;
}

int main(int argc, char const *argv[])
{
    Person person;
    person.setName("Cristiano Silva de Souza");
    person.setAddress("Rua Dos Bobos numero 0");
    person.setAge(42);
    person.to_string();    

    Person person2("Sara de Oliveira", "Rua dos Bobos numero 0", 32);
    person2.to_string();
    person2.setName("Sara de Oliveira Souza");
    person2.to_string();

    Person person3;
    person3.to_string();
    return 0;
}
