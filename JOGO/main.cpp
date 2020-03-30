#include "Game.h"

// using namespace std;
// using namespace cv;

int main(int argc, const char** argv){
    Game game;

    ifstream arquivo;
    arquivo.open("recorde.txt");
    if(!arquivo.is_open()){
        cout << "Impossivel ler o arquivo" << endl;
    }
    int recorde;
    arquivo >> recorde;
    game.player.setRecorde(recorde);
    arquivo.close();

    Mat frame;
    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }

    namedWindow("Control", WINDOW_AUTOSIZE); //create a window called "Control"

    //LARA
    int iLowH = 22;
    int iHighH = 38;

    int iLowS = 65; 
    int iHighS = 165;

    int iLowV = 70;
    int iHighV = 255;

    //DUDA
    // int iLowH = 20;
    // int iHighH = 30;

    // int iLowS = 65; 
    // int iHighS = 165;
    // int iLowS = 100; 
    // int iHighS = 255;

    // int iLowV = 70;
    // int iLowV = 100;
    // int iHighV = 255;

    //Create trackbars in "Control" window
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);

    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    vector<string> paths(5);
    try
    {
        paths = game.Start();
    }
    catch (EscException esc)
    {
        esc.exibeMensagem();
        return 0;
    }
    
    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        flip(imgOriginal,imgOriginal,1);

        game.drawTransparency(imgOriginal, imread(paths[0], IMREAD_UNCHANGED), 270, 195);
        game.drawTransparency(imgOriginal, imread(paths[1], IMREAD_UNCHANGED), 20, 20);
        game.drawTransparency(imgOriginal, imread(paths[2], IMREAD_UNCHANGED), 520, 20);
        game.drawTransparency(imgOriginal, imread(paths[3], IMREAD_UNCHANGED), 20, 370);
        game.drawTransparency(imgOriginal, imread(paths[4], IMREAD_UNCHANGED), 520, 370);

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
        
        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
            
        //morphological opening (remove small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

        //morphological closing (fill small holes in the foreground)
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //Calculate the moments of the thresholded image
        Moments oMoments = moments(imgThresholded);

        // if the area <= 1000000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
        if (oMoments.m00 > 1000000)
        {
            game.player.setXY(oMoments.m10/oMoments.m00, oMoments.m01/oMoments.m00);
            if(game.player.detectColor(paths) == 1)
                paths = game.newGame();
            else if(game.player.detectColor(paths) == 2)
            {
                try
                {
                    paths = game.Start();
                }
                catch (EscException esc)
                {
                    esc.exibeMensagem();
                    return 0;
                }
            }
        }

        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        imshow("Original", imgOriginal); //show the original image

        if (waitKey(5) == 27)
        {
            game.player.SalvaRecorde();
            cout << "****RECORDE SALVO: " << game.player.getRecorde() << endl;
            cout << "Esc key pressed by user" << endl;
            break; 
        }
    }

    return 0;
}