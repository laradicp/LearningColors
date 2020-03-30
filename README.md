# LearningColors
Projeto para as disciplinas de Linguagem de Programação I e Laboratório de Linguagem de Programação I.

Voltado ao aprendizado das cores por bebês, nosso projeto é um jogo que consiste em combinar objetos com cores iguais. Para jogá-lo, é necessário segurar algo de cor amarela (ou de outra cor, caso haja mudança nos parâmetros relacionados à detecção), a fim de possibilitar o rastreamento da mão.

PARA COMPILAR:
TEM DE ESTAR NA PASTA PELO TERMINAL, PARA ENTÃO MANDAR:
$ g++ -ggdb main.cpp -o tst pkg-config --cflags --libs opencv4
$./tst

Divisão do projeto: 
Felipe: geração do jogo e das imagens selecionadas aleatoriamente;
Lara: reconhecimento dos objetos e posicionamento das imagens geradas;
Maria Eduarda: menu do jogo, sistema de pontos e high score em arquivo.
