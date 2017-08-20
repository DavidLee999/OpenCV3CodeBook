#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

void onMouse(int event, int x, int y, int flags, void* param)
{
    cv::Mat* im = reinterpret_cast<cv::Mat*>(param);

    switch (event)
    {
        case cv::EVENT_LBUTTONDOWN:
            std::cout << "at (" << x << ", " << y << ") value is: "
                << static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
            break;
        default:
            break;
    }
}

int main()
{
    cv::Mat image;
    std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;

    image = cv::imread("puppy.bmp", cv::IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cerr << "Error reading image ...\n";
        return 0;
    }

    std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;
    std::cout << "This image has " << image.channels() << " channel(s)" << std::endl;

    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

    cv::setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));

    cv::Mat result;
    cv::flip(image, result, 1);
    
    cv::namedWindow("Output Image");
    cv::imshow("Output Image", result);

	while (cv::waitKey(0) == 'q')
		cv::destroyAllWindows();

    cv::imwrite("output.bmp", result);

    cv::namedWindow("Drawing on an Image");

    cv::circle(image, cv::Point{ 155, 110 }, 65, 0, 3);
    cv::putText(image, "This is a dog", cv::Point{ 40, 200 }, cv::FONT_HERSHEY_PLAIN, 2.0, 255, 2);

    cv::imshow("Drawing on an Image", image);

    cv::waitKey(0);

    return 0;
}


