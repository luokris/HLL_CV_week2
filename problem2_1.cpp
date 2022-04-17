#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;
using namespace std;

int        g_slider_position=0;
CvCapture *g_capture=NULL;

//滑块的回调函数
void onTrackbarSlide(int pos)
{
    cvSetCaptureProperty(g_capture,CAP_PROP_POS_FRAMES,pos);
}

//主函数
int main()
{
    namedWindow("Example2_3",0);
    g_capture=cvCreateFileCapture("testVideo.avi");
    int frames=(int)cvGetCaptureProperty(g_capture,CAP_PROP_FRAME_COUNT);
    if(frames!=0)
    {
        //创建滑块
        cvCreateTrackbar("Position","Example2_3",&g_slider_position,frames,onTrackbarSlide);
    }
    IplImage *frame;
    while(1)
    {
        frame=cvQueryFrame(g_capture);
        //获取当前帧的位置
        g_slider_position=(int)cvGetCaptureProperty(g_capture,CAP_PROP_POS_FRAMES);
        //实现滚动条随着视频播放自动移动
        cvSetTrackbarPos("Position","Example2_3",g_slider_position);
        if(!frame)
            break;
        cvShowImage("Example2_3",frame);

        if(waitKey(30)==27) //键盘ESC
            break;
        if (waitKey(30)==65||waitKey(30)==97) //键盘A
           cvSetCaptureProperty(CAP_PROP_POS_FRAMES, 0);  // 回到开始位置
                       continue;
        if(waitKey(30)==68||waitKey(30)==100) //键盘D
        {
            for(int i=0;i<4;i++)
                frame=cvQueryFrame(g_capture);

        }
        if(waitKey(30)==32) //空格键
            waitKey(0);
    }

    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Example2_3");
    return 0;
}
