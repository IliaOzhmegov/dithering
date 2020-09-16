#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "camera/camera_capturing.h"
#include "filters/dithering.h"


Camera *Camera::instance = 0;
using namespace cv;
int main(int argc, char** argv)
{

    Camera *s = s->openCamera();

    for(;;)
    {
        Mat * frame = s->next();
        if( frame->empty() ) break; // end of video stream
        dithering::simple(frame);
        imshow("this is you, smile! :)", *frame);
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }

    return 0;
}