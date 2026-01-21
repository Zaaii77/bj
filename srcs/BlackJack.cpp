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

void    BlackJack::dealingPhase(void)
{
    dealer.checkShoe();
    std::cout << "The dealer give you a card.." << std::endl;
    dealCardToPlayer(player);
    std::cout << "Your card is " << static_cast<Type>(player.getCardValue(0)) << std::endl;
    std::cout << "The dealer pick a card" << std::endl;
    dealer.pickCard();
    dealCardToPlayer(player);
    std::cout << "Your card is " << static_cast<Type>(player.getCardValue(1)) << std::endl;
}

void    BlackJack::startGame(void)
{
    while (player.getMoney() > 0)
    {
        dealingPhase();
        int handValue = player.getHandSum();
        std::cout << "Dealer have " << dealer.getCardValue(0) << std::endl;
        if (handValue > 21)
            std::cout << "wasted you get " << handValue << std::endl;
        while (handValue < 21)
        {
            std::string userChoice;
            char    choice = 0;
            while (userChoice.length() != 1 && choice != 's' && choice != 'd')
            {
                choice = userChoice.empty() ? 0 : userChoice.front();
                std::cout << "select an option:\n'd' to draw or 's' to stop" << std::endl;
                std::getline(std::cin, userChoice);
                if (std::cin.eof())
                    throw (std::runtime_error("User stop the program"));
            }
            if (choice == 'd')
            {
                dealCardToPlayer(player);
                std::cout << "you picked a " << player.getCardValue(player.handSize() - 1) << std::endl;
                std::cout << "your hand is now " << player.getHandSum() << std::endl;
            }
            else
                break ;
        }
    }
}