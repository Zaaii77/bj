#ifndef BLACKJACK_HPP
# define BLACKJACK_HPP

# include <map>
# include <string>
# include <iostream>
# include "Dealer.hpp"

# define STARTING_MONEY 500
# define DECK_NUMBER 6

class   BlackJack
{
    public:
		BlackJack() {};
		~BlackJack() {};
		BlackJack(const BlackJack& other) = delete;
		BlackJack&	operator=(const BlackJack& other) = delete;
    private:
		Dealer				dealer;
		std::vector<Player>	players;
		
};

#endif