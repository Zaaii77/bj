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