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

void	Player::addCard(Card card)
{
	hand.push_back(card);
	std::cout << "hand size: " << hand.size() << std::endl;
	std::cout << hand.front().getType() << std::endl;
}