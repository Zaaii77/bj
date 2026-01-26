#ifndef DEALER_HPP
# define DEALER_HPP

# include "Shoe.hpp"
# include "Player.hpp"

class   Dealer
{
    public:
        Dealer() : handSum(0) {};
		~Dealer() {};
		Dealer(const Dealer& other) = delete;
		Dealer&	operator=(const Dealer& other) = delete;
        void    dealCard(Player& player);
        void    checkShoe(void);
        size_t  getDeckSize();
        void    pickCard(void);
        int     getHandSum(void);
        int     getCardValue(int index);
    private:
        Shoe                shoe;
        std::vector<Card>   hand;
        int                 handSum;
};

#endif