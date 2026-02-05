#ifndef SHOE_HPP
# define SHOE_HPP

# include "Card.hpp"
# include <vector>

class   Shoe
{
    public:
        Shoe();
        ~Shoe() {};
        Shoe(const Shoe& other) = delete;
        Shoe&   operator=(const Shoe& other) = delete;
        Shoe(Shoe&& other) = default;
        int	        size(void);
        Card        giveCard(void);
        void        resetShoe(void);
    private:
        std::vector<Card>    cards;
};

#endif