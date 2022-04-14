#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//公式：Gray = 0.2989*R + 0.5870*G + 0.1140*B

void grayImageShow(cv::Mat &input, cv::Mat &output)
{
    for (int i = 0; i < input.rows; ++i)
    {
        for (int j = 0; j < input.cols; ++j)
        {
            output.at<uchar>(i, j) = cv::saturate_cast<uchar>(0.114*input.at<cv::Vec3b>(i, j)[0] + 0.587*input.at<cv::Vec3b>(i, j)[1] + 0.2989*input.at<cv::Vec3b>(i, j)[2]);
        }
    }
    cv::imshow("dst", output);
}

int main(void)
{
    cv::Mat src, gray, dst;

    gray=cv::imread("D:/week2/Lena.jpg", cv::IMREAD_GRAYSCALE); //由imread()得到的灰度图像
    src = cv::imread("D:/week2/Lena.jpgg");
    dst.create(src.rows, src.cols,CV_8UC1);

    cv::imshow("scr",src);
    cv::imshow("gray", gray);
    grayImageShow(src, dst);
    waitKey(0);

    return 0;
}
