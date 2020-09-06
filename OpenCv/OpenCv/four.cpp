#include "allhead.h"


/*
OpenCv核心功能模块 Mat的用法
基本数据结构  动态数据结构 绘图函数 数组操作 OpenGl
像素点矩阵 矩阵就是图像在数码设备中的表现形式  
理解OpenCv如何存储和处理图像是非常重要的
Mat是一个类 不需要手动开辟空间  
不需要不用时自动释放
总之，Mat是一个类 有两个数据组成 矩阵头和一个指向存储所有像素值的矩阵的指针
感兴趣区域ROI 只需要创建包含边界信息的信息头
复制一副图像的矩阵 clone() copyto() 

存储像素值需要指定颜色空间(制定一个给定颜色)和数据类型 RGB和透明度alpha

//常用数据结构
1. 点Point类 --绘制二维坐标点
2. 颜色的表示 Scalar类 --大量用于传递像素值
3. 尺寸的表示 Size类 --进行转到定义操作 常使用Size(width,height)
4. 矩形表示 Rect类 x,y,width,height 左上角点的坐标和矩形宽和高
	常用函数：Size() area() contains(Point) inside(Rect) tl()左上角坐标 br()右下角坐标
5. cvtColor()颜色空间转换函数 RGB转HSV，HSI 也可以转换成灰度空间
	OpenCv默认图片通道存储顺序BGR即蓝绿红  而不是RGB

直线 line()  椭圆 ellipse()  矩形 rectangle() 圆 circle 填充多边形fillPoly

*/

//绘制椭圆到图片上
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
//绘制实心圆
void onDrawFilledCircle(Mat &img, Point center)
{
	int thickness = -1;//实心圆
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
	//std::cout << "输出：=" << p << endl << endl;
	Mat img = imread(pathf);
	//onDrawEllipse(img, 0);
	onDrawFilledCircle(img, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	return 0;
}