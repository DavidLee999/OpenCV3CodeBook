#include "colorDetector.h"

#include <vector>

cv::Mat ColorDetector::process(const cv::Mat& image)
{
	result.create(image.size(), CV_8U);

	if (useLab)
		cv::cvtColor(image, converted, CV_BGR2Lab);

	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();

	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	if (useLab)
	{
		it = converted.begin<cv::Vec3b>();
		itend = converted.end<cv::Vec3b>();
	}

	for (; it != itend; ++it, ++itout)
	{
		if (getDistanceToTargetColor(*it) < maxDist)
			*itout = 255; // set to white
		else
			*itout = 0; // set to black
	}

	return result;
}