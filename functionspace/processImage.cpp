#include "../headerspace/WatershedAlg.h"
using namespace cv;
void WatershedAlg::processImage(Mat image,Mat duplImage)  {
        // Make image grayscale




       //lapseedFunc(image);



       image = makeImageGrayScale(image);

      // cv::imshow("make gray",image);
      // cv::waitKey(0);
       //Mat tempImage;

       
      // duplImage.copyTo(tempImage);

      // Mat threshTestImg;

     // duplImage.copyTo(threshTestImg);


        //cv::imshow("makeImageGrayScale",image);
       // cv::waitKey(0);

        // Erode foreground
       vector< vector<int> > erosionTargetThree{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, };
       image = erosion(image, erosionTargetThree);
        //cv::imshow("erosion",image);
       // cv::waitKey(0);
         // Apply threshold
        image = thresholdMeasure(image);
       // cv::imshow("threshold",image)
      //  cv::waitKey(0);
        //cv::imshow("thresholdMeasure",image);
       // cv::waitKey(0);
       
     
        // Inverse pixels
    
       // image = inverseImage(image);
        //cv::imshow("inverseImage",image);
       // cv::waitKey(0);

       image=antiInverseImage(image);
      //cv::imshow("antiInverseImage",image);
     // cv::waitKey(0);
       
    
        // Apply distance transform
        vector<Point> markers;
        image = distanceTransform(image,markers);
        //image=testDistanceTransform(image, markers);
        Mat distanceImage = image;
       // cv::imshow("distance transformation",distanceImage);
       // cv::waitKey(0);
        //cout << "Detected " << markers.size() << " markers \n";

        // Watershed
       if(markers.size() == 0) {
           #pragma omp parallel for collapse(2)
            for(int i = 0; i < image.rows; i++) {
                for(int j = 0; j < image.cols; j++) {
                    if((int) distanceImage.at<uchar>(i,j) != 0) {
                        markers.push_back(Point(i, j));
                        image.at<uchar>(i, j) = 25;
                       // cv::imshow("watershed result",image);
                      //  cv::waitKey(0);
                        //return watershed(image, markers);
                    }
                }
            }
        }


        image = watershed(image, markers,duplImage);
       // cv::imshow("watershed result",image);
        //cv::waitKey(0);

    }