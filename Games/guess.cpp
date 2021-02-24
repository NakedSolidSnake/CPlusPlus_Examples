#include <iostream>
#include <limits>
#include <ctime>

class Game
{
    public:

        enum difficulties{ easy , medium, hard};

        Game(int max_tries) :        
        max_tries(max_tries),
        max_points(1000){

        }

        static Game getDifficulty(enum difficulties difficult){
            switch (difficult)
            {
            case Game::difficulties::easy:
                return Game(7);

            case Game::difficulties::medium:
                return Game(5);

            case Game::difficulties::hard:
                return Game(3);
            
            default:
                return Game(5);
            }
        }

        int getMaxTries() const
        {
            return this->max_tries;
        }

        int getMaxPoints() const
        {
            return this->max_points;
        }

    private:        
        const int max_tries;
        const int max_points;
};

void printTitleStyle(std::string message, const char decorate)
{
    int string_len = message.length();
    for(int i = 0; i < string_len + 4; i++)
        std::cout << decorate;

    std::cout << std::endl;
    std::cout << decorate << " " << message << " " << decorate << std::endl;

    for(int i = 0; i < string_len + 4; i++)
        std::cout << decorate;
    
    std::cout << std::endl;
}

int produceSecretNumber(int range)
{
    return (std::rand() % range + 1);
}

int getValue()
{
    int guess = 0;
    std::cout << "Type your guess number: ";

    while (!(std::cin >> guess))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.  Try again: ";
    }

    return guess;
}

bool evaluateGuess(int guess_number, int secret_number)
{
    bool ret = false;
    if(guess_number == secret_number)
    {
        std::cout << "You Win" << std::endl;
        ret = true;
    }
    else if(guess_number > secret_number)
    {
        std::cout << "Wrong. The secret number is less" << std::endl;
    }

    else 
    {
        std::cout << "Wrong. The secret number is higher" << std::endl;
    }

    return ret;
}

char selectDifficulty()
{
    char choose;
    bool keep = true;
    std::cout << "Select the level : " << std::endl;
    std::cout << "[q] - quit" << std::endl;
    std::cout << "[e] - easy" << std::endl;
    std::cout << "[m] - medium" << std::endl;
    std::cout << "[h] - hard" << std::endl;

    while(keep)
    {
        std::cin >> choose;
        if(choose == 'q' || choose == 'e' || choose == 'm' || choose == 'h')
        {
            keep = false;
        }
        else {
            std::cout << "This option doesn't exist. Please select a valid option" << std::endl;
        }
    }    

    return choose;
}

Game::difficulties convertSelection(char choose)
{
    Game::difficulties difficulty = Game::difficulties::medium;
    if(choose == 'q')
    {
        std::cout << "Quitting the game." << std::endl;
        exit(0);
    }
    else if(choose == 'e')
        difficulty = Game::difficulties::easy;

    else if(choose == 'm')
        difficulty = Game::difficulties::medium;

    else if(choose == 'h')
        difficulty = Game::difficulties::hard;

    return difficulty;
}

int main(int argc, char const *argv[])
{
    printTitleStyle("Guess the Secret Number", '@');

    int difficulty = selectDifficulty();
    Game game = Game::getDifficulty(convertSelection(difficulty));

    int tries = game.getMaxTries();   
    double points = game.getMaxPoints();

    srand(time(nullptr));

    int secret_number = produceSecretNumber(10);
    

    while(tries)
    {
        if(evaluateGuess(getValue(), secret_number)){
            break;
        }
        tries--;
        points -= (game.getMaxPoints() / game.getMaxTries());
    }

    if(tries == 0)
    {
        std::cout << "You lose. Try again, maybe I'll have more luck next time" << std::endl;
        std::cout << "the secret number was: " << secret_number << std::endl;
    }

    std::cout << "Points: " << points << std::endl;
    
        
    return 0;
}
