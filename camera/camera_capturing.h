//
// Created by Ilia Ozhmegov on 9/16/20.
//

#ifndef DITHERING_CAPTURING_H
#define DITHERING_CAPTURING_H

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

class Camera{
private:
    static Camera   *instance;
    cv::VideoCapture cap;
    cv::Mat          frame;

    Camera(){
        try {
            cap.open(0);
        }catch (int e){
            using namespace std;
            cout << "Did not manage to open camera: " << e << '\n';
        }
    }

public:
    ~Camera(){
        frame.deallocate();
        cap.release();
    }


    static Camera * openCamera(){
        if (!instance) {
            instance = new Camera;
        }
        return instance;
    }

    cv::Mat *next(){
        cap >> frame;
        return &frame;
    }

    cv::Mat *getFrame(){
        if (frame.empty()) next();
        return &frame;
    }

};

#endif //DITHERING_CAPTURING_H
