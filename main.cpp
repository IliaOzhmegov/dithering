#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "camera/camera_capturing.h"


Camera *Camera::instance = 0;
using namespace cv;
int main(int argc, char** argv)
{

    Camera *s = s->openCamera();

    for(;;)
    {
        Mat * frame = s->getFrame();
        if( frame->empty() ) break; // end of video stream
        imshow("this is you, smile! :)", *frame);
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }

    //VideoCapture cap;
    //// open the default camera, use something different from 0 otherwise;
    //// Check VideoCapture documentation.
    //if(!cap.open(0))
    //    return 0;
    //for(;;)
    //{
    //    Mat frame;
    //    cap >> frame;
    //    if( frame.empty() ) break; // end of video stream
    //    imshow("this is you, smile! :)", frame);
    //    if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    //}
    //// the camera will be closed automatically upon exit
    //// cap.close();
    return 0;
}