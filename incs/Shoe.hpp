#ifndef SHOE_HPP
# define SHOE_HPP

# include "Card.hpp"

class   Shoe
{
    public:
        Shoe();
        ~Shoe() {};
        Shoe(const Shoe& other) = delete;
        Shoe&   operator=(const Shoe& other) = delete;
        Shoe(Shoe&& other) = default;
        Shoe&   operator=(Shoe&& other) = default;
        int	        size(void);
        Card        giveCard(void);
        void        resetShoe(void);
    private:
        std::vector<Card>    cards;
};

#endif