#ifndef PLAYER_H
#define PLAYER_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;
using namespace cv;

class Player
{
    public:
        Player();

        void mp3Player(char file);

        void SalvaRecorde();

        int detectColor(std::vector<string> paths);

        void setXY(int x, int y);
        int getX();
        int getY();

        void setRecorde(int r);
        int getRecorde();

        void setPosicaoJogoAnterior(bool p);

    private:
        int posX, posY, pontos, recorde;
        bool posicaoJogoAnterior;
};

#endif