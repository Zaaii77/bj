#ifndef DEALER_HPP
# define DEALER_HPP

# include "Shoe.hpp"
# include "Player.hpp"

class   Dealer
{
    public:
        Dealer() {};
		~Dealer() {};
		Dealer(const Dealer& other) = delete;
		Dealer&	operator=(const Dealer& other) = delete;
    private:
        Shoe                shoe;
};

#endif