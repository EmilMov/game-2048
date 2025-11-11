#include <iostream>
#include <vector>
#include "moves.h"

void move_right(std::vector<std::vector<int>>& game){
    for(int i = 0; i < game.size() ; i++){
        int point = game.size() - 1;
        for(int j = game[i].size()-1 ;j>=0;j--){
            if(game[i][j]!=0){
                if(point +1 < game.size() && game[i][j] == game[i][point+1]){
                        game[i][point + 1] = game[i][point + 1]+game[i][j];
                        game[i][j] = 0;
                    }else if(game[i][point] == 0){
                        game[i][point] = game[i][j];
                        game[i][j] = 0;
                        point --;
                    }else{
                        point--;
                    }
            }
        }
    }
}
void move_left(std::vector<std::vector<int>>& game){
    for(int i = 0 ; i<game.size() ; i++){
        int point =0;
        for(int j = 0 ; j<game[i].size() ; j++){
            if(game[i][j]!= 0 ){
                if(point > 0 && game[i][j] == game[i][point-1]){
                    game[i][point-1] = game[i][point-1] + game[i][j];
                    game[i][j] = 0;
                }else if(point < game[i].size() && game[i][point] == 0){
                    game[i][point] = game[i][j];
                    game[i][j] = 0;
                    ++point;
                }else{
                    ++point;
                }
            }
        }
    }
}
void move_up(std::vector<std::vector<int>>& game){
    for(int i = 0;i<game.size();i++){
        int point = 0;
        for(int j = 0 ; j<game[i].size();j++){
            if(game[j][i] != 0){
                    if(point>0 && game[point-1][i] == game[j][i]){
                        game[point - 1][i] = game[point - 1][i] + game[j][i];
                        game[j][i] = 0;
                        break;
                    }else if(game[point][i]==0){
                        game[point][i] = game[j][i];
                        game[j][i] = 0;
                        point++;
                    }else{
                        point++;
                    }
            }
        }
    }
}
void move_down(std::vector<std::vector<int>>& game){
    for(int i = 0 ; i < game.size();i++){
        int point = game.size()-1;
        for(int j = game.size()-1;j>=0;j--){
            if(game[j][i]!=0){
                if(point+1<game.size() && game[point+1][i] == game[j][i]){
                    game[point+1][i] = game[point+1][i]+game[j][i];
                    game[j][i] = 0;
                }else if(game[point][i]==0){
                    game[point][i]=game[j][i];
                    game[j][i]=0;
                    point--;
                }else{
                    point--;
                }
            }
        }
    }
}
