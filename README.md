# LearningColors
Project aimed at teaching the colors to toddlers through a game.

The goal is to match the object at the center of the screen with another one with the same color. After a succesful match, the respective color is announced by sound. The player needs to hold something yellow (or of another color, if the parameters are adjusted) to identify their hand and therefore which object is being selected. Also, it is necessary to place the hand in the central object to initialize each round.

<br/>
<p align="center">
  <img src="https://user-images.githubusercontent.com/34425678/213879073-becb0574-9e5a-4b64-b6ad-7b516dce941f.jpg" width=500 />
  <br/>
  <img src="https://user-images.githubusercontent.com/34425678/213878873-a18d9020-7f94-4400-82d1-4f9943fd1fe9.png" width=500 />
</p>

## To compile <br/>
Inside folder JOGO: <br/>
$ g++ *.cpp *.h -o tst \`pkg-config --cflags --libs opencv4\` <br/>
$./tst

## Contributors <br/>
Felipe Honorato (https://github.com/Felipehonorato1); <br/>
Lara di Cavalcanti Pontes; <br/>
Maria Eduarda Dantas Hardman (https://github.com/dudahardman).
