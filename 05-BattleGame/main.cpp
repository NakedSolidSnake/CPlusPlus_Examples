#include <iostream>
#include <ctime>

class Warrior
{
    private:
        int attackMax;
        int blockMax;

    public:
        std::string name;
        int health;
        Warrior(std::string name, int health, int attackMax, int blockMax)
        {
            this->name = name;
            this->health = health;
            this->attackMax = attackMax;
            this->blockMax = blockMax;
        }

        int attack(){
            return std::rand() % this->attackMax;
        }

        int block(){
            return std::rand() % this->blockMax;
        }
};

class Battle{
    public:
        static void startFight(Warrior &w1, Warrior &w2){

            while(true)
            {
                if(Battle::getAttackResult(w1, w2).compare("Game Over") == 0){
                    std::cout << "Game Over\n";
                    break;
                }

                if(Battle::getAttackResult(w2, w1).compare("Game Over") == 0){
                    std::cout << "Game Over\n";
                    break;
                }
            }
        }

        static std::string getAttackResult(Warrior &w1, Warrior &w2){
            int w1Attack = w1.attack();
            int w2Block = w2.block();

            int damage = w1Attack - w2Block;

            damage = damage > 0 ? damage : 0;

            if(w2.health > 0 )
                w2.health -= damage;
            
            std::cout << w1.name << " attacks " << w2.name << " inflicted " << damage << std::endl;
            std::cout << w1.name << " health: " << w1.health << std::endl;
            std::cout << w2.name << " health: " << w2.health << std::endl;

            if(w2.health <= 0){
                std::cout << w1.name << " won" << std::endl;
                return "Game Over";
            }

            return "";

        }
 

};

int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    Battle::startFight(thor, hulk);

    return 0;
}
