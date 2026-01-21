#include "../incs/BlackJack.hpp"

bool    nameIsValid(const std::string& name)
{
    for (size_t i = 0; i < name.length(); i++)
    {
        if (std::isalpha(name[i]))
            return (true);
    }
    return (false);
}

BlackJack::BlackJack()
{
    std::string name;

    std::cout << "Welcome in your personnal blackjack game !" << std::endl;
    while (!nameIsValid(name))
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
    gameStatus = NONE;
    player.clearHand();
    std::cout << "Dealing phase...\n" << std::endl;
    dealCardToPlayer(player);
    dealer.pickCard();
    dealCardToPlayer(player);
}

void    BlackJack::startGame(void)
{
    while (player.getMoney() > 0)
    {
        dealingPhase();
        std::cout << "Dealer have " << dealer.getCardValue(0) << std::endl;
        if (player.getHandSum() > 21)
        {
            std::cout << "wasted you get " << player.getHandSum() << std::endl;
            break ;
        }
        while (player.getHandSum() <= 21)
        {
            std::string userChoice;
            char    choice = 0;
            while (userChoice.length() != 1 && choice != 's' && choice != 'd')
            {
                std::cout << "Your hand: " << player.getHandSum() << ". Dealer card: " << dealer.getCardValue(0) << std::endl;
                std::cout << "select an option:" << std::endl;
                std::cout << "'d' to draw or 's' to stop" << std::endl;
                std::getline(std::cin, userChoice);
                if (std::cin.eof())
                    throw (std::runtime_error("User stop the program"));
                choice = userChoice.empty() ? 0 : userChoice.front();
            }
            if (choice == 'd')
            {
                dealCardToPlayer(player);
                std::cout << "you picked a " << player.getCardValue(player.handSize() - 1) << std::endl;
                std::cout << "your hand is now " << player.getHandSum() << std::endl;
                if (player.getHandSum() > 21)
                    break ;
            }
            else
                break ;
        }
        if (player.getHandSum() > 21)
        {
            std::cout << "wasted you get " << player.getHandSum() << std::endl;
            break ;
        }
        else if (player.getHandSum() == 21)
        {
            if (player.handSize() == 2)
                std::cout << "BLACKJACK BODY !" << std::endl;
            else
                std::cout << "What a chance, you get 21" << std::endl;
        }
        while (dealer.getHandSum() < 17)
            dealer.pickCard();
        if (dealer.getHandSum() < 22 && dealer.getHandSum() > player.getHandSum())
        {
            std::cout << "Dealer won. You get " << player.getHandSum() << " and the dealer have " << dealer.getHandSum() << std::endl;
            break ;
        }
        else if (dealer.getHandSum() < 22 && dealer.getHandSum() == player.getHandSum())
        {
            std::cout << "You and the dealer have the same hand sum, draw." << std::endl;
            gameStatus = DRAW;
            break ;
        }
        else
        {
            while (dealer.getHandSum() < 22 && dealer.getHandSum() <= player.getHandSum())
            {
                dealer.pickCard();
                if (dealer.getHandSum() > 21)
                {
                    std::cout << "You won, dealer get " << dealer.getHandSum() << std::endl;
                    gameStatus = WIN;
                    break ;
                }
                else if (dealer.getHandSum() > player.getHandSum())
                {
                    std::cout << "You loose noob" << std::endl;
                    gameStatus = LOOSE;
                    break ;
                }
            }
        }
    }
}
