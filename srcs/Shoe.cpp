#include "../incs/BlackJack.hpp"

Shoe::Shoe()
{
	resetShoe();
}

void	Shoe::resetShoe(void)
{
	this->cards.clear();
	for (int j = 0; j < DECK_NUMBER; j++)
		for (int h = 0; h < 4; h++)
			for (int i = 0; i < 13; i++)
				this->cards.push_back(Card(i));
}

Card	Shoe::drawCard(void)
{
	int	randomDraw = rand() % this->cards.size();
	std::cout << randomDraw << std::endl;
	Card	drawed = std::move(this->cards[randomDraw]);
	this->cards.erase(this->cards.begin() + randomDraw);
	return (drawed);
}
