//
// Created by Ilia Ozhmegov on 9/16/20.
//

#ifndef DITHERING_DITHERING_H
#define DITHERING_DITHERING_H

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

namespace dithering{
    void blackSquareInTheCorner(cv::Mat*);
    void simple (cv::Mat*);

};

#endif //DITHERING_DITHERING_H
