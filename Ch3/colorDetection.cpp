#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "colorDetector.h"

int main()
{
	ColorDetector cdetect;

	cv::Mat image = cv::imread("boldt.jpg");
	if (image.empty())
		return 0;

	cdetect.setTargetColor(230, 190, 130);

	cv::namedWindow("result");
	cv::Mat result = cdetect.process(image);
	cv::imshow("result", result);

	cv::waitKey();
	return 0;
}