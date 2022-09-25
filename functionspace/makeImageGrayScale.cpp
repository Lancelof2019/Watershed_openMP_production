#include "../headerspace/WatershedAlg.h"
using namespace cv;

Mat WatershedAlg::makeImageGrayScale(Mat image) {
       /*Mat grayScale(image.rows, image.cols, CV_8UC1, Scalar(70));
        
    


        for(int i = 0; i < image.rows; i++) {

            for(int j = 0; j < image.cols; j++) {
                double gray = 0.21 * image.at<cv::Vec3b>(i,j)[0] +
                              0.72 * image.at<cv::Vec3b>(i,j)[1] +
                              0.07 * image.at<cv::Vec3b>(i,j)[2];



                              //Vec3b[0]->B  [1]->G [3]->R
                
                /*double gray = 0.114* image.at<cv::Vec3b>(i,j)[0] +
                              0.587 * image.at<cv::Vec3b>(i,j)[1] +
                              0.299 * image.at<cv::Vec3b>(i,j)[2];
                grayScale.at<uchar>(i,j) = (uchar) gray;
                
            }
        }
*/    
      Mat grayScale(image.rows, image.cols, CV_8UC1, Scalar::all(0));
   // Mat  grayScale(image.rows, image.cols, CV_8UC1)
    
    //GRAY=0.3*R+0.59*G+0.11*B

        #pragma omp parallel for collapse(2)
        for(int i = 0; i < image.rows; i++) {
            
            for(int j = 0; j < image.cols; j++) {
                double gray = 0.21 * image.at<cv::Vec3b>(i,j)[0] +
                              0.72 * image.at<cv::Vec3b>(i,j)[1] +
                              0.07 * image.at<cv::Vec3b>(i,j)[2];
                grayScale.at<uchar>(i,j) = (uchar) gray;
            }
        }
   
       
        cv::GaussianBlur(grayScale, grayScale, Size(3,5), 3,4);
        //string filename8="/opt/test8.txt";
       // ofstream fout8(filename8);

      //  for(int i = 0; i < image.rows; i++) {
     //       for(int j = 0; j < image.cols; j++) {

     //        fout8<<((int)grayScale.at<uchar>(i,j))<<",";
             

      //   }
    //      fout8<<endl;
   //  }
   //  fout8.close();

        image.release();
        return grayScale;
    }

