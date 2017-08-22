#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	cv::namedWindow("Image");
	
	cv::Mat image = cv::imread("puppy.bmp");
	cv::Mat logo = cv::imread("smalllogo.png");

	cv::Mat imageROI{ image, cv::Rect{ image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows } };

	logo.copyTo(imageROI);

	cv::imshow("Image", image);
	cv::waitKey(0);

	image = cv::imread("puppy.bmp");
 
	imageROI = image(cv::Rect{ image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows });
	
	cv::Mat mask( logo);
	
	logo.copyTo(imageROI, mask);

	cv::imshow("Image", image);
	cv::waitKey(0);

	return 0;
	
}