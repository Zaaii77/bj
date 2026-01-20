#ifndef BLACKJACK_HPP
# define BLACKJACK_HPP

# include <map>
# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <algorithm>
# include "Dealer.hpp"

# define STARTING_MONEY 500
# define DECK_NUMBER 6

class   BlackJack
{
    public:
		BlackJack();
		~BlackJack() {};
		BlackJack(const BlackJack& other) = delete;
		BlackJack&	operator=(const BlackJack& other) = delete;
		void		dealCardToPlayer(Player& player);
		Player&		getPlayer(void);
    private:
		Dealer				dealer;
		Player				player;
};

#endif