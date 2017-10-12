#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void sharpen(const cv::Mat &image, cv::Mat& result)
{
	result.create(image.size(), image.type());
	int nchannels = image.channels();

	for (int j = 1; j < image.rows - 1; ++j)
	{
		const uchar* previous = image.ptr<const uchar>(j - 1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j + 1);

		uchar* output = result.ptr<uchar>(j);

		for (int i = nchannels; i < (image.cols - 1) * nchannels; ++i)
			*output++ = cv::saturate_cast<uchar>(
				5 * current[i] - current[i - nchannels] - current[i + nchannels]
				- previous[i] - next[i]
				);
	}

	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	cv::Mat result;

	sharpen(image, result);

	cv::namedWindow("Image");
	cv::imshow("Image", result);
	cv::waitKey();

	return 0;
}