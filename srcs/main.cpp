#include "../incs/BlackJack.hpp"

int main(void)
{
    try
    {
        srand(time(0));
        BlackJack   bj;

        bj.startGame();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}
