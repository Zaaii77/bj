#ifndef DEALER_HPP
# define DEALER_HPP

# include "Shoe.hpp"
# include "Player.hpp"

class   Dealer
{
    public:
        
    private:
        Shoe                shoe;
        std::vector<Player> players;
};

#endif