# LearningColors
Project developed for teaching the colors to toddlers through a game.

The objective is to match the object in the middle of the screen with the other one with the same color. After a succesful match, the respective color is announced by sound. The player needs to hold something yellow (or of another color, if the parameters are adjusted) in order to OpenCV identify the hand and therefore which object is being selected among options.

## To compile <br/>
Inside folder JOGO: <br/>
$ g++ *.cpp *.h -o tst \`pkg-config --cflags --libs opencv4\` <br/>
$./tst

## Contributors <br/>
Felipe Honorato (https://github.com/Felipehonorato1); <br/>
Lara di Cavalcanti Pontes; <br/>
Maria Eduarda Dantas Hardman (https://github.com/dudahardman).
