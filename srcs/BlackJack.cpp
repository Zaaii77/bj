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

void		BlackJack::dealCardToPlayer(Player& player)
{
    dealer.dealCard(player);
}

Player& BlackJack::getPlayer(void)
{
    return (player);
}

void    BlackJack::startGame(void)
{
    while (player.getMoney() > 0)
    {
        dealer.checkShoe();
        std::cout << "The dealer give you a card.." << std::endl;
        dealCardToPlayer(player);
        std::cout << "Your card is " << static_cast<Type>(player.getCardValue(0)) << std::endl;
        std::cout << "The dealer pick a card" << std::endl;
        dealer.pickCard();
        dealCardToPlayer(player);
    }
}