#include <iostream>
#include <iomanip>
#include <vector>
#include "moves.h"
#include "game.h"

int main (){
    std::cout<<"Hi.Welcome tp my game .For starting game press 'Enter' and 'q' for quiting : ";
    std::cin.get();
    std::vector<std::vector<int>> game(4,std::vector<int> (4,0));
    start(game);
    return 0 ;
}