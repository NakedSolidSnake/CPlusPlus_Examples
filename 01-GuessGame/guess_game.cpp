#include <iostream>
#include <ctime>

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
    int guess;
    std::cout << "Type your guess number: ";
    std::cin >> guess;
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

// int getDifficulty()


int main(int argc, char const *argv[])
{
    printTitleStyle("Guess the Secret Number", '@');
    int tries = 3;
    const int max_tries = tries;
    double max_points = 1000.0;
    double points = max_points;

    srand(time(nullptr));

    int secret_number = produceSecretNumber(10);
    

    while(tries)
    {
        if(evaluateGuess(getValue(), secret_number)){
            break;
        }
        tries--;
        points -= (max_points / max_tries);
    }

    if(tries == 0)
    {
        std::cout << "You lose. Try again, maybe I'll have more luck next time" << std::endl;
        std::cout << "the secret number was: " << secret_number << std::endl;
    }

    std::cout << "Points: " << points << std::endl;
    
        
    return 0;
}
