#ifndef BLACKJACK_HPP
# define BLACKJACK_HPP

# include <map>
# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <algorithm>
# include <unistd.h>
# include <math.h>
# include "Dealer.hpp"

# define STARTING_MONEY 500
# define DECK_NUMBER 6

enum	Status
{
	WIN,
	LOOSE,
	DRAW,
	NONE
};

class   BlackJack
{
    public:
		BlackJack();
		~BlackJack() {};
		BlackJack(const BlackJack& other) = delete;
		BlackJack&	operator=(const BlackJack& other) = delete;
		void		startGame();
    private:
		void				dealCardToPlayer(Player& player);
		Player&				getPlayer(void);
		void				dealingPhase(void);
		void				betPhase(void);
		void				playerChoice(void);
		void    			dealerPhase(void);
		void				moneyPhase(void);

		Dealer				dealer;
		Player				player;
		Status				gameStatus;
		std::string			roundMsg;
		bool				stopFlag = false;
};

#endif