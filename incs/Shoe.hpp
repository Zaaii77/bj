#ifndef SHOE_HPP
# define SHOE_HPP

# include "Card.hpp"

class   Shoe
{
    public:
        Shoe(int deckNumber) {};
        ~Shoe() {};
        Shoe(const Shoe& other) = delete;
        Shoe&   operator=(const Shoe& other) = delete;
    private:
        std::vector<Card>    cards;
};

#endif