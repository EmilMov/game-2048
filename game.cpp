#include <iostream>
#include <iomanip>
#include <vector>
#include "game.h"
#include "moves.h"
int lose_win(const std::vector<std::vector<int>>& game){
    for(int i = 0 ; i < game.size(); i++){
        for(int j = 0 ; j < game[i].size() ; j++){
            if(game[i][j]==2048){
                return 2;
            }
        }
    }
    for(int i = 0 ; i < game.size(); i++){
        for(int j = 0 ; j < game[i].size() ; j++){
            if(game[i][j]==0){
                return 3;
            }
        }
    }
    for(int i = 0 ; i < game.size(); i++){
        for(int j = 0 ; j < game[i].size()-1 ; j++){
            if(game[i][j]==game[i][j+1]){
                return 1;
            }
        }
    }
    for(int i = 0 ; i < game.size()-1; i++){
        for(int j = 0 ; j < game[i].size() ; j++){
            if(game[i][j]==game[i+1][j]){
                return 1;
            }
        }
    }
    return 0;
}
void randoming(std::vector<std::vector<int>>& game){
    int x;
    int y;
    do{
        x = std::rand()%4;
        y = std::rand()%4;
    }while(game[x][y] != 0);
    
    game[x][y] = (std::rand() % 10==0)? 4:2;
}


void printing(const std::vector<std::vector<int>>& game) {
    std::system("clear");
    const int n = game.size();   // 4
    const int w = 5;             // cell width

    // Top border
    std::cout << '+';
    for (int j = 0; j < n; ++j) std::cout << std::string(w, '-') << '+';
    std::cout << '\n';

    for (int i = 0; i < n; ++i) {
        // --- 3 vertical lines per cell ---
        for (int line = 0; line < 3; ++line) {
            std::cout << '|';
            for (int j = 0; j < n; ++j) {
                std::string cell = "";
                if (line == 1) {  // Middle line only
                    cell = (game[i][j] == 0) ? "" : std::to_string(game[i][j]);
                }

                int len = cell.length();
                int left = (w - len) / 2;
                int right = w - len - left;

                std::cout << std::string(left, ' ') << cell << std::string(right, ' ');
                std::cout << '|';
            }
            std::cout << '\n';
        }

        // Horizontal separator (except after last row)
        if (i < n - 1) {
            std::cout << '+';
            for (int j = 0; j < n; ++j) std::cout << std::string(w, '-') << '+';
            std::cout << '\n';
        }
    }

    // Bottom border
    std::cout << '+';
    for (int j = 0; j < n; ++j) std::cout << std::string(w, '-') << '+';
    std::cout << '\n';

    std::cout << "w/a/s/d = move, q = quit\n\n";

// std::system("clear");
    // for(int i = 0 ; i < game.size();i++){
    //     for(int j = 0 ; j < game[i].size() ; j++){
    //         std::cout<<game[i][j]<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
}
void start(std::vector<std::vector<int>>& game){
    char movemant;
    randoming(game);
    randoming(game);
    while(movemant!='q'){
        if(lose_win(game)==2){
        std::cout<<"Congatulations you win the game🎉 \n will you continue game ?:(y/n)";
        char x;
        std::cin>>x;
        if(x=='n'){
            std::cout<<"Thank you for playing game";
            return;
        }
    }else if (lose_win(game)!=0){
        std::cout<<"Game over :";
        return;
    }
        
        printing(game);
        std::cin>>movemant;
        switch(movemant){
            case 'D':
            case 'd':
                move_right(game);
                randoming(game);
            break;
            case 'A':
            case 'a':
                move_left(game);
                randoming(game);
            break;
            case 'S':
            case 's':
            move_down(game);
            randoming(game);
            break;
            case 'W':
            case 'w':
            move_up(game);
            randoming(game);
            break;
            case 'Q':
            case 'q':
            return;
    }
}
}
