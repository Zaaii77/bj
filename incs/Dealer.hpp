#ifndef DEALER_HPP
# define DEALER_HPP

# include "Shoe.hpp"
# include "Player.hpp"

class   Dealer
{
    public:
        Dealer() : handSum(0), hasAnAce(false) {};
		~Dealer() {};
		Dealer(const Dealer& other) = delete;
		Dealer&	operator=(const Dealer& other) = delete;
	
        void    	        dealCard(Player& player);
        void    	        checkShoe(void);
        size_t  	        getDeckSize();
        void    	        pickCard(void);
        int     	        getHandSum(void);
        int     	        getCardValue(size_t index);
		Card&	            getSecondCard(void);
		void		        pickSecondCard(void);
        void                showSecondCard(void);

    private:
        Shoe                shoe;
		Card				secondCard;
        std::vector<Card>   hand;
        int                 handSum;
        bool                hasAnAce;
};

#endif