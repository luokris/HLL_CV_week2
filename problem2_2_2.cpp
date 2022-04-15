#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//定义高斯滤波函数
void myfilter(int filter_size, Mat& image_input, Mat& image_output);

void myfilter(int filter_size, Mat& image_input, Mat& image_output)
{
    image_output = image_input.clone();
    int k = (filter_size - 1) / 2;

    for (int i = k; i < (image_input.rows-k); i++)
    {
        for (int j = k; j < (image_input.cols - k); j++)
        {
            double sum = 0.0;
            double sum1 = 0.0;
            double sigma = sqrt(2);
            double g;
            for (int m = -k; m < k + 1; m++)
            {
                for (int n = -k; n < k + 1; n++)
                {
                    g = exp(-(m * m + n * n) / (2 * sigma * sigma));
                    sum = sum + g*image_input.at<uchar>(i + m, j + n);
                    sum1 = sum1 + g;
                }
            }
            image_output.at<uchar>(i, j) = (int)round(sum / sum1);

        }
    }
}

//主函数
int main()
{
    Mat image, image_output2;   //定义输入图像，输出图像
    image = imread("D:\\week2\\lena.jpg");  //读取图像；
    if (image.empty())
    {
        cout << "读取错误" << endl;
        return -1;
    }
    imshow("image", image);
    int a = 3;

    myfilter(a,image,image_output2);
    imshow("image_output2", image_output2);

    waitKey(0);  //暂停，保持图像显示，等待按键结束
    return 0;
}



