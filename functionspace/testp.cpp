#include<iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include<queue>
#include <vector>
#include<random>
#include <cv.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <queue>
#include<string>
#include <cstdlib>
#include<omp.h>
using namespace std;
int main(){


cv::Mat srcImg=cv::imread("/opt/Bilder/inmigre.bmp");
cv::imshow("picture",srcImg);
cv::waitKey(0);
return 0;

string filename34="/opt/test34.txt";
ofstream fout34(filename34);

     for(int i = 0; i < srcImg.rows; i++) {
          for(int j = 0; j < srcImg.cols; j++) {

          fout34<<((int)srcImg.at<uchar>(i,j))<<",";
             

        }
         fout34<<endl;
     }
       fout34.close();




return 0;

}