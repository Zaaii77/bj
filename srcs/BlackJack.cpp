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

BlackJack::BlackJack() : stopFlag(false)
{
    std::string name;

    std::cout << "Welcome to your personal blackjack game!" << std::endl;
    while (!nameIsValid(name))
    {
        std::cout << "What's your name?" << std::endl;
        std::getline(std::cin, name);
        if (std::cin.eof())
            throw (std::runtime_error("Program closed by user"));
    }
    name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
    this->player = Player(name, STARTING_MONEY);
    std::cout << "Nice to meet you, " << name << "!" << std::endl;
    std::cout << "You will start with $" << STARTING_MONEY << ". Try to earn more!\nGame starting..." << std::endl;
    sleep(2);
}

void    BlackJack::betPhase(void)
{
    float       playerM;
    std::string bet;
    std::cout << "\033[2J\033[H" << std::endl;
    moneyPhase();
    playerM = player.getMoney();
    std::cout << "Your money is: $" << playerM << std::endl;
    if (playerM == 0)
    {
        stopFlag = true;
        return ;
    }
    std::cout << "How much do you want to bet?" << std::endl;
    while (player.getBet() == 0)
    {
        std::getline(std::cin, bet);
        if (std::cin.eof())
            throw (std::runtime_error("User leave the table"));
        if (atoi(bet.c_str()) > 0 && player.setBet(atoi(bet.c_str())))
            break ;
        else
            std::cout << "Please enter a valid number > 0" << std::endl;
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
    std::cout << "Dealing cards...\n" << std::endl;
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
			std::cout << "Select an option:" << std::endl;
			std::cout << "'d' to draw or 's' to stand" << std::endl;
			std::getline(std::cin, userChoice);
			if (std::cin.eof())
				throw (std::runtime_error("User stop the program"));
			choice = userChoice.empty() ? 0 : userChoice.front();
		}
		if (choice == 'd')
		{
			dealCardToPlayer(player);
			std::cout << "You picked a " << player.getCardValue(player.handSize() - 1) << std::endl;
			sum = player.getHandSum();
			std::cout << "Your hand is now " << sum << std::endl;
			if (sum > 21)
            {
                roundMsg = "Busted! You got " + std::to_string(sum);
                gameStatus = LOOSE;
				return ;
            }
		}
		else if (choice == 's')
			return ;
		else
			std::cout << "'d' to draw or 's' to stand" << std::endl;
	}   
    if (player.getHandSum() > 21)
    {
        roundMsg = "Busted! You got " + std::to_string(player.getHandSum());
        gameStatus = LOOSE;
        return ;
    }
    else if (player.getHandSum() == 21)
    {
        if (player.handSize() == 2)
            roundMsg = "BLACKJACK!";
        else
            roundMsg = "Lucky! You got 21!";
    }
}

void    BlackJack::dealerPhase(void)
{
    int dHandSum = dealer.getHandSum();
    int pHandSum = player.getHandSum();
    while (dHandSum < 17)
    {
        dealer.pickCard();
        dHandSum = dealer.getHandSum();
        std::cout << "Dealer picks a " << dealer.getCardValue(dealer.getDeckSize() - 1);
        std::cout << ". Dealer's hand: " << dHandSum << std::endl;
    }
    if (dHandSum > 21)
    {
        roundMsg = "You won! Dealer got " + std::to_string(dHandSum);
        gameStatus = WIN;
        return ;
    }
    if (dHandSum < 22 && dHandSum > pHandSum)
    {
        roundMsg.clear();
        roundMsg = "Dealer won. You got " + std::to_string(pHandSum);
        roundMsg += " and the dealer has " + std::to_string(dHandSum);
        gameStatus = LOOSE;
        return ;
    }
    else if (dHandSum < 22 && dHandSum == pHandSum)
    {
        roundMsg = "You and the dealer have the same hand. Draw.";
        gameStatus = DRAW;
        return ;
    }
    else
    {
        while (dHandSum < 22 && dHandSum < pHandSum)
        {
            dealer.pickCard();
            dHandSum = dealer.getHandSum();
            if (dHandSum > 21)
            {
                roundMsg = "You won! Dealer got " + std::to_string(dHandSum);
                gameStatus = WIN;
                return ;
            }
            else if (dHandSum > pHandSum)
            {
                roundMsg = "The dealer has a better hand. Sorry!";
                gameStatus = LOOSE;
                return ;
            }
            else if (dHandSum == pHandSum)
            {
                roundMsg = "Dealer got the same hand as you. Draw.";
                gameStatus = DRAW;
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
            break ;
        case LOOSE:
            break ;
        case NONE:
            std::cout << "There is a mistake in the code bro" << std::endl;
            break ;
    }
    std::cout << roundMsg << std::endl;
    roundMsg.clear();
    player.setBet(0);
    gameStatus = NONE;
}

void    BlackJack::startGame(void)
{
    while (1)
    {
        betPhase();
        if (stopFlag == true)
            break ;
        dealingPhase();
        std::cout << "Dealer have " << dealer.getCardValue(0) << std::endl;
		this->playerChoice();
        if (gameStatus != LOOSE)
        {
            dealer.showSecondCard();
            dealerPhase();
        }
    }
    std::cout << "Sorry, you've spent all your money. See you later!" << std::endl;
}
