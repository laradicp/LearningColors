#include "Player.h"

Player::Player()
{
    posX = 0;
    posY = 0;
    pontos = 0;
    recorde = 0;
    posicaoJogoAnterior = true;
}

void Player::mp3Player(char file)
{    
    switch(file)
    {
        case '0':
            system("mpg321 /home/lara/Downloads/LearningColors-master/colors/0.mp3 &");
            //system("mpg321 /home/dudahardman/Área de Trabalho/LearningColors-master/colors/0.mp3 &");
        break;

        case '1':
            system("mpg321 /home/lara/Downloads/LearningColors-master/colors/1.mp3 &");
            //system("mpg321 /home/dudahardman/Área de Trabalho/LearningColors-master/colors/1.mp3 &");
        break;

        case '2':
            system("mpg321 /home/lara/Downloads/LearningColors-master/colors/2.mp3 &");
            //system("mpg321 /home/dudahardman/Área de Trabalho/LearningColors-master/colors/2.mp3 &");
        break;

        case '3':
            system("mpg321 /home/lara/Downloads/LearningColors-master/colors/3.mp3 &");
            //system("mpg321 /home/dudahardman/Área de Trabalho/LearningColors-master/colors/3.mp3 &");
    }
}

void Player::SalvaRecorde()
{
    ofstream arquivo;
    arquivo.open("recorde.txt");
    if(!arquivo.is_open()){
        cout << "Impossivel ler o arquivo" << endl;
    }
    arquivo << recorde;
    arquivo.close();
}

int Player::detectColor(vector<string> paths)
{
    //cout << posX << "," << posY << endl;
    if((posX > 20)&&(posX < 100)&&(posY > 80)&&(posY < 120)&&!(posicaoJogoAnterior))
    {
        if(paths[0][3] == paths[1][3])
        {
            mp3Player(paths[0][3]);
            pontos = pontos + 1;
            if(pontos > recorde)
                recorde = pontos;
            posicaoJogoAnterior = true;
            return 1;
        }
            else
        {
            if(pontos > recorde)
                recorde = pontos;
            pontos = 0;
            return 2;
        }
    }

    else if((posX > 510)&&(posX < 590)&&(posY > 80)&&(posY < 120)&&!(posicaoJogoAnterior))
    {
        if(paths[0][3] == paths[2][3])
        {
            mp3Player(paths[0][3]);
            pontos = pontos + 1;
            if(pontos > recorde)
                recorde = pontos;
            posicaoJogoAnterior = true;
            return 1;
        }
        else
        {
            if(pontos > recorde)
                recorde = pontos;
            pontos = 0;
            return 2;
        }
    }
    
    else if ((posX > 20)&&(posX < 100)&&(posY > 370)&&(posY < 410)&&!(posicaoJogoAnterior))
    {
        if(paths[0][3] == paths[3][3])
        {
            mp3Player(paths[0][3]);
            pontos = pontos + 1;
            if(pontos > recorde)
                recorde = pontos;
            posicaoJogoAnterior = true;
            return 1;
        }
        else
        {
            if(pontos > recorde)
                recorde = pontos;
            pontos = 0;
            return 2;
        }
    }

    else if ((posX > 510)&&(posX < 590)&&(posY > 370)&&(posY < 410)&&!(posicaoJogoAnterior))
    {
        if(paths[0][3] == paths[4][3])
        {
            mp3Player(paths[0][3]);
            pontos = pontos + 1;
            if(pontos > recorde)
                recorde = pontos;
            posicaoJogoAnterior = true;
            return 1;
        }
        else
        {
            if(pontos > recorde)
                recorde = pontos;
            pontos = 0;
            return 2;
        }
    }
    else if ((posX > 290)&&(posX < 370)&&(posY > 220)&&(posY < 260))
    {
        posicaoJogoAnterior = false;
        cout << "=====================================READY======================================" << endl;
    }

    return 0;
}

void Player::setXY(int x, int y)
{
    posX = x;
    posY = y;
}
int Player::getX()
{
    return posX;
}
int Player::getY()
{
    return posY;
}

void Player::setRecorde(int r)
{
    recorde = r;
}
int Player::getRecorde()
{
    return recorde;
}

void Player::setPosicaoJogoAnterior(bool p)
{
    posicaoJogoAnterior = p;
}