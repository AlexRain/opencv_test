// opencv_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	// 读入一张图片（游戏原画）    
	Mat image = imread("6AD346FD-207D-4129-9CFE-B13E75707AFD.jpg");
	Mat outImage;
	// 创建一个名为 "游戏原画"窗口    
	namedWindow("游戏原画");

	////转灰度图
	//Mat grayimg;
	//cvtColor(img, grayimg, CV_BGR2GRAY);

	////转HSV
	//Mat HSVImage;
	//cvtColor(img, HSVImage, COLOR_BGR2HSV);    //将图像转换为HSV图

	////转lab
	//Mat labimg;
	//cvtColor(img, labimg, COLOR_BGR2Lab);

	//// 在窗口中显示游戏原画    
	//imshow("游戏原画", img);
	//imshow("灰度图", grayimg);
	//imshow("HSV", HSVImage);
	//imshow("Lab", labimg);

	// 创建与原图像等尺寸的图像  
	int div = 1;
	outImage.create(image.size(), image.type());
	int nr = image.rows;
	// 将3通道转换为1通道  
	int nl = image.cols*image.channels();
	for (int k = 0; k < nr; k++)
	{
		// 每一行图像的指针  
		const uchar* inData = image.ptr<uchar>(k);
		uchar* outData = outImage.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			outData[i] = inData[i] / div*div + div / 2;  //这里也可以用*outData下面的例子就是可以参考
		}
	}

	imshow("通道转换", outImage);

	// 等待6000 ms后窗口自动关闭    
	waitKey(0);

	//VideoCapture cap;
	//if (!cap.open("Clip_480_5sec_6mbps_h264.mp4"))  // check if we succeeded
	//{
	//	cout << "Open default camera failed";
	//	system("pause");
	//	return -1;
	//}
	//	
	//Mat edges;
	//namedWindow("edges", 1);
	//for (;;)
	//{
	//	Mat frame;
	//	cap >> frame; // get a new frame from camera
	//	cvtColor(frame, edges, CV_BGR2GRAY);
	//	GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
	//	Canny(edges, edges, 0, 30, 3);
	//	imshow("edges", edges);
	//	if (waitKey(30) >= 0) 
	//		break;
	//}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

