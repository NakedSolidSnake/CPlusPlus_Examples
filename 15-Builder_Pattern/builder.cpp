#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Packing;

class Item
{
public:
    virtual string name() = 0;
    virtual Packing *packing() = 0;
    virtual float price() = 0;
};

class Packing
{
public:
    virtual string pack() = 0;
};

class Wrapper : public Packing
{
    string pack() override
    {
        return "Wrapper";
    }
};

class Bottle : public Packing
{
     string pack() override
    {
        return "Bottle";
    }
};

class Burger : public Item
{
    Packing *packing() override
    {
        return new Wrapper();
    }

    virtual float price() = 0;
    virtual string name() = 0;
};

class ColdDrink : public Item 
{
    Packing *packing() override
    {
        return new Bottle();
    }

    virtual float price() = 0;
    virtual string name() = 0;
};

class VegBurger : public Burger
{
    float price() override
    {
        return 25.0f;
    }

    string name() override
    {
        return "Veg Burger";
    }
};

class ChickenBurger : public Burger
{
    float price() override
    {
        return 50.5f;
    }

    string name() override
    {
        return "Chicken Burger";
    }
};

class Coke : public ColdDrink
{
    float price() override
    {
        return 30.0f;
    }

    string name() override
    {
        return "Coke";
    }
};

class Pepsi : public ColdDrink
{
    float price() override
    {
        return 35.0f;
    }

    string name() override
    {
        return "Pepsi";
    }
};

class Meal
{
private:
    vector<Item *> items;

public:
    void addItem(Item *item)
    {
        items.push_back(item);
    }

    float getCost()
    {
        float cost = 0.0f;
        for(Item *item : items){
            cost += item->price();
        }

        return cost;
    }

    void showItems()
    {
        for(Item *item : items)
        {
            cout << "Item: " << item->name();
            cout << ", Packing : " << item->packing()->pack();
            cout << ", Price : " << item->price() << endl;
        }
    }
};

class MealBuilder
{
public:
    Meal *prepareVegMeal()
    {
        Meal *meal = new Meal();
        meal->addItem(new VegBurger());
        meal->addItem(new Coke());
        return meal;
    }

    Meal *prepareNonVegMeal()
    {
        Meal *meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};

int main(int argc, char const *argv[])
{
    MealBuilder *mealBuilder = new MealBuilder();
    Meal *vegMeal = mealBuilder->prepareVegMeal();
    cout << "Veg Meal" << endl;
    vegMeal->showItems();
    cout << "Total Cost: " << vegMeal->getCost() << endl;

    Meal *nonVegMeal = mealBuilder->prepareNonVegMeal();
    cout << "\n\nNon Veg Meal" << endl;
    nonVegMeal->showItems();
    cout << "Total Cost: " << nonVegMeal->getCost() << endl;

    return 0;
}
