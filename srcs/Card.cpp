#include "../incs/Card.hpp"

Card::Card(int val)
{
    if (val < AS || val > KING)
        throw (std::runtime_error("Error with card construction"));
    type = static_cast<Type>(val);
}

Card::Card(const Card& other)
{
    *this = other;
}

Card&   Card::operator=(const Card& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

Card&   Card::operator=(const Card&& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

const Type& Card::getType(void) const
{
    return (this->type);
}

int Card::getValue(void)
{
    switch (type)
    {
        case AS:
            return (1);
        case TWO:
            return (2);
        case THREE:
            return (3);
        case FOUR:
            return (4);
        case FIVE:
            return (5);
        case SIX:
            return (6);
        case SEVEN:
            return (7);
        case EIGHT:
            return (8);
        case NINE:
            return (9);
        case TEN:
        case JACK:
        case QUEEN:
        case KING:
            return (10);
    }
    return (0);
}