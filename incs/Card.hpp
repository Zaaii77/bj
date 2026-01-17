#ifndef CARD_HPP
# define CARD_HPP

# include <vector>

class   Card
{
    public:
        Card(int val) : value(val) {};
        ~Card() {};
        Card() = delete;
        Card(const Card& other) = delete;
        Card&   operator=(const Card& other) = delete;
    private:
        int value;
};

#endif