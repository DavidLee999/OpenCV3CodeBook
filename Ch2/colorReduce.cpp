#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void colorReduce(cv::Mat image, int div = 64)
{
	int nl = image.rows;
	int nc = image.cols * image.channels(); 

	for (int j = 0; j < nl; ++j)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; ++i)
			data[i] = data[i] / div * div + div / 2;
	}
}

void colorReduce(const cv::Mat& image, cv::Mat& result, int div = 64)
{
	int nl = image.rows;
	int nc = image.cols;
	int nchannels = image.channels();

	result.create(nl, nc, image.type());
	for (int j = 0; j < nl; ++j)
	{
		const uchar* data_in = image.ptr<uchar>(j);
		uchar* data_out = result.ptr<uchar>(j);

		for (int i = 0; i < nc * nchannels; ++i)
			data_out[i] = data_in[i] / div * div + div / 2;
	}
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	
	colorReduce(image);

	cv::namedWindow("Image");
	cv::imshow("Image", image);
	cv::waitKey();

	return 0;
}