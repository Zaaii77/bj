#include "../incs/BlackJack.hpp"

BlackJack::BlackJack()
{
    std::string name;

    std::cout << "Welcome in your personnal blackjack game !" << std::endl;
    while (name.empty())
    {
        std::cout << "What's your name ?" << std::endl;
        std::getline(std::cin, name);
        if (std::cin.eof())
            throw (std::runtime_error("Program closed by user"));
    }
    name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
    this->player = Player(name, STARTING_MONEY);
    std::cout << "Nice to meet you " << name << std::endl;
    std::cout << "You will start with " << STARTING_MONEY << "$. Try to earn more" << std::endl;
}