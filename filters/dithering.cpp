//
// Created by Ilia Ozhmegov on 9/16/20.
//

#include "dithering.h"

void dithering::blackSquareInTheCorner(cv::Mat* frame){
    cv::rectangle(*frame,
                  cv::Point(0, 0),
                  cv::Point(100, 100),
                  cv::Scalar( 0, 0, 0 ),
                  -1);
}

void dithering::simple(cv::Mat *frame) {
    using namespace cv;

    int nrows = frame->rows;
    int ncols = frame->cols;

    cvtColor(*frame, *frame, COLOR_RGB2GRAY);

    int val = 0;
    for(int i=0; i < nrows; i++){
        for(int j=0; j < ncols; j++){
            val = frame->at<uchar>(i,j);

            if(val > 127){ val = 255;}
            else{val = 0;};

            frame->at<uchar>(i,j) = val;
        }
    }

}
