#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "EscException.h"

class Game
{
    public:
        void drawTransparency(Mat frame, Mat transp, int x, int y);

        void PreencheCores(std::vector<string> &cores);

        int Generate(int total);

        std::vector<string> newGame();

        std::vector<string> Start();
    
        Player player;
};

#endif