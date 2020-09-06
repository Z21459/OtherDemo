#include "allhead.h"


/*
OpenCv���Ĺ���ģ�� Mat���÷�
�������ݽṹ  ��̬���ݽṹ ��ͼ���� ������� OpenGl
���ص���� �������ͼ���������豸�еı�����ʽ  
���OpenCv��δ洢�ʹ���ͼ���Ƿǳ���Ҫ��
Mat��һ���� ����Ҫ�ֶ����ٿռ�  
����Ҫ����ʱ�Զ��ͷ�
��֮��Mat��һ���� ������������� ����ͷ��һ��ָ��洢��������ֵ�ľ����ָ��
����Ȥ����ROI ֻ��Ҫ���������߽���Ϣ����Ϣͷ
����һ��ͼ��ľ��� clone() copyto() 

�洢����ֵ��Ҫָ����ɫ�ռ�(�ƶ�һ��������ɫ)���������� RGB��͸����alpha

//�������ݽṹ
1. ��Point�� --���ƶ�ά�����
2. ��ɫ�ı�ʾ Scalar�� --�������ڴ�������ֵ
3. �ߴ�ı�ʾ Size�� --����ת��������� ��ʹ��Size(width,height)
4. ���α�ʾ Rect�� x,y,width,height ���Ͻǵ������;��ο�͸�
	���ú�����Size() area() contains(Point) inside(Rect) tl()���Ͻ����� br()���½�����
5. cvtColor()��ɫ�ռ�ת������ RGBתHSV��HSI Ҳ����ת���ɻҶȿռ�
	OpenCvĬ��ͼƬͨ���洢˳��BGR�����̺�  ������RGB

ֱ�� line()  ��Բ ellipse()  ���� rectangle() Բ circle �������fillPoly

*/

//������Բ��ͼƬ��
const string pathf = "2.jpg";
#define WINDOW_WIDTH 100
void onDrawEllipse(Mat &img, double angle)
{
	int thick = 2;
	int line = 8;
	ellipse(img,
		Point(WINDOW_WIDTH/2, WINDOW_WIDTH/2),
		Size(WINDOW_WIDTH/4, WINDOW_WIDTH/4),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thick,
		line);
	
	imshow("show", img);
	waitKey(0);
}
//����ʵ��Բ
void onDrawFilledCircle(Mat &img, Point center)
{
	int thickness = -1;//ʵ��Բ
	int lineType = 8;

	circle(img,
		center,
		WINDOW_WIDTH / 10,
		Scalar(0, 0, 255),
		thickness,
		lineType);
	imshow("show", img);
	waitKey(0);
}


int main4()
{
	//Mat r = Mat(10, 3, CV_8UC3);
	//randu(r, Scalar::all(0), Scalar::all(255));
	//Point2f p(6, 2);
	//std::cout << "�����=" << p << endl << endl;
	Mat img = imread(pathf);
	//onDrawEllipse(img, 0);
	onDrawFilledCircle(img, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	return 0;
}