#include "../headerspace/WatershedAlg.h"
using namespace cv;
#define ZERO 0
 void WatershedAlg::removeholesopt(Mat& src,int pnumThrshold, int handlingType, int neighbourType,int pixelThreshold)  {
   
   
 //  cv::imshow("distanceTransform before remove holes",src);
 //  cv::waitKey(0);
    int RemoveCount=0;       
    //string filename33="/opt/test33.txt";
   // ofstream fout33(filename33);
 //   string filename34="/opt/test34.txt";
 //   ofstream fout34(filename34);
   //  string filename35="/opt/test35.txt";
  //  ofstream fout35(filename35);
   // vector<Point> NeihborPos;
    //queue<int> qx, qy;
    //vector<Point>pixbuffer;
    Mat Pointlabel(src.rows,src.cols, CV_8UC1,Scalar::all(255) );  
    
 
 
       // cout<<"removing holes start. "<<endl;  
        #pragma omp parallel for collapse(2)
        for(int i = 0; i < src.rows; ++i)  {    
           // uchar* iData = src.ptr<uchar>(i);  
           // uchar* iLabel = Pointlabel.ptr<uchar>(i);  
           
            for(int j = 0; j < src.cols; ++j) {    
                 if(src.at<uchar>(i,j)>pixelThreshold){
                 Pointlabel.at<uchar>(i,j)=0;
                 
               
                 }
               // if (iData[j] > pixelThreshold)    
              //  {    
                   // iLabel[j] = 3;   
              //  }    
            }    
        }  

//**

 //  imshow("prepration for contours",Pointlabel);
//
  //  cv::waitKey(0);

   // Mat dulpPointlabel;
    //Pointlabel.copyTo(dulpPointlabel);
    vector<vector<Point>> contours;  
    vector<cv::Vec4i> hierarchy; 
    findContours(Pointlabel,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point()); 
    Mat imageContours=Mat::zeros(Pointlabel.size(),CV_8UC1);  
    Mat contouroutput=Mat::zeros(Pointlabel.size(),CV_8UC1);  
    Point p=Point(0,0);



   if (!contours.empty() && !hierarchy.empty()) 
	{
		vector<vector<Point> >::const_iterator itc = contours.begin();
   // cout<<"The number of size of contours"<<contours.size()<<endl;
	
		while (itc != contours.end()) 
		{
			
			cv::Rect countourposition = cv::boundingRect(Mat(*itc));
			
			double area = contourArea(*itc);
		
			if (area < pnumThrshold) 
			{
				#pragma omp parallel for collapse(2)
				for (int i = countourposition.y; i < countourposition.y + countourposition.height; i++) 
				{
					//uchar *output_data = dst.ptr<uchar>(i);
         
					for (int j = countourposition.x; j < countourposition.x + countourposition.width; j++) 
					{
						
						if ((int)Pointlabel.at<uchar>(i,j) == 255) 
						{
							Pointlabel.at<uchar>(i,j) = 2;
              src.at<uchar>(i,j)=pixelThreshold;

						}
					}
				}
			}
			itc++;
		}
	}

 }