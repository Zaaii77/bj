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
    std::cout << "You will start with " << STARTING_MONEY << "$. Try to earn more\nGame strarting.." << std::endl;
    sleep(5);
}

void    BlackJack::betPhase(void)
{
    std::string bet;
    std::cout << "\033[2J\033[H";
    std::cout << "You money is : " << player.getMoney() << std::endl;
    std::cout << "How many you want to bet ?" << std::endl;
    while (player.getBet() == 0)
    {
        std::getline(std::cin, bet);
        if (std::cin.eof())
            throw (std::runtime_error("User leave the table"));
        if (player.setBet(atoi(bet.c_str())))
            break ;
    }
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
	dealer.pickSecondCard();
}

void	BlackJack::playerChoice(void)
{
	std::string	userChoice;
	char		choice;
	int			sum = player.getHandSum();

	while (sum < 21)
	{
		userChoice.clear();
		choice = 0;
		while (userChoice.length() != 1 && choice != 's' && choice != 'd')
		{
			std::cout << "Your hand: " << sum << ". Dealer card: " << dealer.getCardValue(0) << std::endl;
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
			sum = player.getHandSum();
			std::cout << "your hand is now " << sum << std::endl;
			if (sum > 21)
				return ;
		}
		else if (choice == 's')
			return ;
		else
			std::cout << "'d' to draw or 's' to stop" << std::endl;
	}   
    if (player.getHandSum() > 21)
    {
        std::cout << "wasted you get " << player.getHandSum() << std::endl;
        gameStatus = LOOSE;
        return ;
    }
    else if (player.getHandSum() == 21)
    {
        if (player.handSize() == 2)
            std::cout << "BLACKJACK BODY !" << std::endl;
        else
            std::cout << "What a chance, you get 21" << std::endl;
    }
}

void    BlackJack::dealerPhase(void)
{
    while (dealer.getHandSum() < 17)
    {
        dealer.pickCard();
        std::cout << "Dealer pick a " << dealer.getCardValue(dealer.getDeckSize() - 1) << ". dealer's hand: " << dealer.getHandSum() << std::endl;
    }
    if (dealer.getHandSum() > 21)
    {
        std::cout << "You won. Dealer get " << dealer.getHandSum() << std::endl;
        gameStatus = WIN;
        
    }
    if (dealer.getHandSum() < 22 && dealer.getHandSum() > player.getHandSum())
    {
        std::cout << "Dealer won. You get " << player.getHandSum() << " and the dealer have " << dealer.getHandSum() << std::endl;
        return ;
    }
    else if (dealer.getHandSum() < 22 && dealer.getHandSum() == player.getHandSum())
    {
        std::cout << "You and the dealer have the same hand sum, draw." << std::endl;
        gameStatus = DRAW;
        return ;
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
                return ;
            }
            else if (dealer.getHandSum() > player.getHandSum())
            {
                std::cout << "You loose noob" << std::endl;
                gameStatus = LOOSE;
                return ;
            }
        }
    }
}

void    BlackJack::moneyPhase(void)
{
    switch (gameStatus)
    {
        case WIN:
            if (player.handSize() == 2 && player.getHandSum() == 21)
                player.addMoney(roundf(player.getBet() * 2));
            else
                player.addMoney(roundf(player.getBet()) * 1.5);
            break ;
        case DRAW:
            player.addMoney(player.getBet());
        case LOOSE:
            break ;
        case NONE:
            std::cout << "There is a mistake in the code bro" << std::endl;
            break ;
    }
    player.setBet(0);
    gameStatus = NONE;
}

void    BlackJack::startGame(void)
{
    while (player.getMoney() > 0)
    {
        moneyPhase();
        betPhase();
        dealingPhase();
        std::cout << "Dealer have " << dealer.getCardValue(0) << std::endl;
		this->playerChoice();
        dealer.showSecondCard();
        dealerPhase();
    }
}
