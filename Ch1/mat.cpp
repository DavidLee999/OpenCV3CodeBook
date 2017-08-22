#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat function()
{
	cv::Mat ima{ 500, 500, CV_8U, 50 };
	return ima;
}

//int main()
//{
//	cv::Mat image1{ 240, 320, CV_8U, 100 };
//	cv::imshow("Image", image1);
//	cv::waitKey(0);
//
//	image1.create(200, 200, CV_8U);
//	image1 = 200;
//
//	cv::imshow("Image", image1);
//	cv::waitKey(0);
//
//	cv::Mat image2(240, 320, CV_8UC3, cv::Scalar{ 0, 0, 255 });
//	cv::imshow("Image", image2);
//	cv::waitKey(0);
//
//	image2 = cv::Scalar{ 0, 255, 0 };
//	cv::imshow("Image", image2);
//	cv::waitKey(0);
//
//	cv::Mat image3 = cv::imread("puppy.bmp");
//
//	cv::Mat image4{ image3 };
//	image1 = image3;
//
//	image3.copyTo(image2);
//	cv::Mat image5 = image3.clone();
//
//	cv::flip(image3, image3, 0);
//
//	cv::imshow("Image 3", image3);
//	cv::imshow("Image 1", image1);
//	cv::imshow("Image 2", image2);
//	cv::imshow("Image 4", image4);
//	cv::imshow("Image 5", image5);
//	cv::waitKey(0);
//
//	cv::Mat gray = function();
//	cv::imshow("Image", gray);
//	cv::waitKey(0);
//
//	image1 = cv::imread("puppy.bmp", CV_LOAD_IMAGE_GRAYSCALE);
//	image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
//
//	cv::imshow("Image", image2);
//	cv::waitKey(0);
//
//	return 0;
//}