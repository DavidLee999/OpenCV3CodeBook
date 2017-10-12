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

void colorReduce2(cv::Mat image, int div = 64)
{
    int nl = image.rows;
    int nc = image.cols * image.channels();

    if (image.isContinuous())
    {
        nc *= nl;
        nl = 1;
    }

    int n = static_cast<int>(log(static_cast<double>(div))/ log(2.0) + 0.5);
    uchar mask = 0xFF << n;
    uchar div2 = div >> 1;

    for (int j = 0; j < nl; ++j)
    {
        uchar* data = image.ptr<uchar>(j);
        for (int i = 0; i < nc; ++i)
        {
            *data &= mask;
            *data++ += div2;
        }
    }
}

void colorReduce3(cv::Mat image, int div = 64)
{
    int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
    uchar mask = 0xFF << n;
    uchar div2 = div >> 1;

    cv::Mat_<cv::Vec3b>::iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::iterator itend = image.end<cv::Vec3b>();

    for (; it != itend; ++it)
    {
        (*it)[0] &= mask;
        (*it)[0] += div2;
        (*it)[1] &= mask;
        (*it)[1] += div2;
        (*it)[2] &= mask;
        (*it)[2] += div2;
    }
}

int main()
{
    cv::Mat image = cv::imread("boldt.jpg");

    colorReduce3(image);

    cv::namedWindow("Image");
    cv::imshow("Image", image);
    cv::waitKey();

    return 0;
}
