
#include "../headerspace/WatershedAlg.h"
using namespace cv;

Mat WatershedAlg::antiInverseImage(Mat image) {
        #pragma omp parallel for schedule(dynamic,2) collapse(2)
        for(int i = 0; i < image.rows; i++) {
           //#pragma omp parallel for
            for(int j = 0; j < image.cols; j++) {
                if( (int) image.at<uchar>(i,j) == ZERO ) {
                    image.at<uchar>(i,j) = ZERO;
                } else {
                    image.at<uchar>(i,j) = ONE;
                }
            }
        }

        return image;
    }
