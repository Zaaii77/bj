#include "../incs/BlackJack.hpp"

Shoe::Shoe()
{
	resetShoe();
}

void	Shoe::resetShoe(void)
{
	std::cout << "reset shoe.." << std::endl;
	this->cards.clear();
	for (int j = 0; j < DECK_NUMBER; j++)
		for (int h = 0; h < 4; h++)
			for (int i = 0; i < 13; i++)
				this->cards.push_back(Card(i));
	sleep(3);
}

Card	Shoe::giveCard(void)
{
	int	randomDraw = rand() % this->cards.size();
	Card	drawed = std::move(this->cards[randomDraw]);
	this->cards.erase(this->cards.begin() + randomDraw);
	return (drawed);
}

int	Shoe::size(void)
{
	return (cards.size());
}
