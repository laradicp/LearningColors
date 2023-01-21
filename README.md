# LearningColors
Project aimed at teaching the colors to toddlers through a game.

The goal is to match the object at the center of the screen with another one with the same color. After a succesful match, the respective color is announced by sound. The player needs to hold something yellow (or of another color, if the parameters are adjusted) to identify their hand and therefore which object is being selected. Also, it is necessary to place the hand in the central object to initialize each round.

![learning-colors-demo](https://user-images.githubusercontent.com/34425678/213878635-95aa7dbd-1010-42dc-b1fa-2da707f46c56.png)

## To compile <br/>
Inside folder JOGO: <br/>
$ g++ *.cpp *.h -o tst \`pkg-config --cflags --libs opencv4\` <br/>
$./tst

## Contributors <br/>
Felipe Honorato (https://github.com/Felipehonorato1); <br/>
Lara di Cavalcanti Pontes; <br/>
Maria Eduarda Dantas Hardman (https://github.com/dudahardman).
