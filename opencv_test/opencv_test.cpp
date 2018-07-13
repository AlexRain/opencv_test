// opencv_test.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ����һ��ͼƬ����Ϸԭ����    
	Mat image = imread("6AD346FD-207D-4129-9CFE-B13E75707AFD.jpg");
	Mat outImage;
	// ����һ����Ϊ "��Ϸԭ��"����    
	namedWindow("��Ϸԭ��");

	////ת�Ҷ�ͼ
	//Mat grayimg;
	//cvtColor(img, grayimg, CV_BGR2GRAY);

	////תHSV
	//Mat HSVImage;
	//cvtColor(img, HSVImage, COLOR_BGR2HSV);    //��ͼ��ת��ΪHSVͼ

	////תlab
	//Mat labimg;
	//cvtColor(img, labimg, COLOR_BGR2Lab);

	//// �ڴ�������ʾ��Ϸԭ��    
	//imshow("��Ϸԭ��", img);
	//imshow("�Ҷ�ͼ", grayimg);
	//imshow("HSV", HSVImage);
	//imshow("Lab", labimg);

	// ������ԭͼ��ȳߴ��ͼ��  
	int div = 1;
	outImage.create(image.size(), image.type());
	int nr = image.rows;
	// ��3ͨ��ת��Ϊ1ͨ��  
	int nl = image.cols*image.channels();
	for (int k = 0; k < nr; k++)
	{
		// ÿһ��ͼ���ָ��  
		const uchar* inData = image.ptr<uchar>(k);
		uchar* outData = outImage.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			outData[i] = inData[i] / div*div + div / 2;  //����Ҳ������*outData��������Ӿ��ǿ��Բο�
		}
	}

	imshow("ͨ��ת��", outImage);

	// �ȴ�6000 ms�󴰿��Զ��ر�    
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

