#include "../incs/Player.hpp"

Player&	Player::operator=(const Player& other)
{
	if (this != &other)
	{
		hand = other.hand;
		money = other.money;
		name = other.name;
	}
	return (*this);
}
