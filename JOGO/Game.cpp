#include "Game.h"

void Game::drawTransparency(Mat frame, Mat transp, int x, int y) {
    Mat mask;
    vector<Mat> layers;
    
    split(transp, layers); // seperate channels
    Mat rgb[3] = { layers[0],layers[1],layers[2] };
    mask = layers[3]; // png's alpha channel used as mask
    merge(rgb, 3, transp);  // put together the RGB channels, now transp insn't transparent 
    Mat roi1 = frame(Rect(x, y, transp.cols, transp.rows));
    Mat roi2 = roi1.clone();
    transp.copyTo(roi2.rowRange(0, transp.rows).colRange(0, transp.cols), mask);
    double alpha = 0.9;
    addWeighted(roi2, alpha, roi1, 1.0 - alpha, 0.0, roi1);
}

void Game::PreencheCores(vector<string> &cores)
{
    cores.push_back("amarelo");
    cores.push_back("azul");
    cores.push_back("verde");
    cores.push_back("vermelho");
}

int Game::Generate(int total){
    srand(time(NULL));
    return rand()% total;
}

vector<string> Game::newGame()
{
    int RandomPath = Generate(4);
    int RandomImg = Generate(3);
    cout << "\n=================================SELEÇÃO DE COR=================================" << endl;
    cout << "MAIN FILE FROM PATH: " << RandomPath << endl;
    cout << "WITH INDEX OF: " << RandomImg << endl;
    cout << "================================================================================\n" << endl;

    // PASTA 0 - VERDE
    // PASTA 1 - VERMELHO
    // PASTA 2 - ROSA
    // PASTA 3 - AZUL

    int imgs[] = {0,1,2};
    vector<int> ibagens (imgs, imgs + sizeof(imgs) /sizeof(int));

    ibagens.erase(ibagens.begin()+RandomImg);

    vector<string> paths(5);

    paths[0] = "cor" + to_string(RandomPath) + "/" + to_string(RandomImg) + ".png";
    
    int OddImage;
    vector<int> j = {0, 1, 2, 3};
    for(int i = 1; i < 5; i++){
        // srand(time(NULL));
        // random_shuffle(ibagens.begin(),ibagens.end());
        int n = rand()%j.size();
        if(j[n] == RandomPath){
            OddImage = ibagens.at(rand()%2);
        }else
            OddImage = rand()%3;
        
        paths[i] = "cor" + to_string(j[n]) + "/" + to_string(OddImage) + ".png";
        j.erase(j.begin() + n);
        cout << "PATH SENDO LIDO: " << paths[i] << endl;
    }

        // LÊ A IMAGEM SELECIONADA
        if(!imread(paths[0], IMREAD_UNCHANGED).data){
            cout << "[ERRO] Imagem nao encontrada" << endl;
            cout << "Tentado no path: " << paths[0] << endl;
    }

    return paths;
}

vector<string> Game::Start(){
    while(1){
        Mat image;
        
        image = imread("start.jpg", WINDOW_AUTOSIZE);
        
        putText(image, //target image
        "MAX SCORE: " + to_string(player.getRecorde()), //text
        cv::Point(200, 360),
        cv::FONT_HERSHEY_DUPLEX,
        1.0,
        CV_RGB(255, 255, 255), //font color
        2);

        imshow("Start", image);

        if(waitKey(5) == 's' || waitKey(5) == 'S' ){
            destroyAllWindows();
            player.setPosicaoJogoAnterior(true);
            return newGame();
        }

        if (waitKey(5) == 27)
        {
            player.SalvaRecorde();
            cout << "****RECORDE SALVO: " << player.getRecorde() << endl;
            EscException esc;
            throw esc;
        }    
    }
}