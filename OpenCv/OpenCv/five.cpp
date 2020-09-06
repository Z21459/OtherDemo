#include "allhead.h"
const string path5 = "2.jpg";

/*
����ͼ���е�����
���ø���Ȥ����ROI
����ͼ����
������ɫͨ��
���ж�ͨ��ͼ����
����ͼ��ԱȶȺ�����
ͼ����Ҷ�任


1.ͼ�����Ĵ�Сȡ�������õ���ɫģ�� ȡ����ͨ����  ��ͨ��-�������
LUT���� Look up table���� operationOnArrays:LUT()<lut>
��ʱ���� getTickCount()--CPU�¼���������ʱ  getTickFrequency()--CPU һ�����ߵ�������
�������
*/

void colorReduce(Mat &img, int div)
{
	imshow("ԭʼ", img);
	Mat detImg;
	detImg.create(img.rows, img.cols, img.type());
	double time0 = static_cast<double>(getTickCount());

	/* ���� ����*/
	detImg = img.clone();
	int row = detImg.rows;
	int col = detImg.cols*detImg.channels();//��������ͨ����

	for (int i = 0; i < row; i++)
	{
		uchar *data = detImg.ptr<uchar>(i);//�õ��������׵�ַ
		for (int j = 0; j < col; j++)
		{
			data[j] = data[j] / div * div + div / 2;//����ÿ������
		}
	}

	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	std::cout << time0 << endl;
	imshow("Ч��", detImg);
	waitKey(0);

}

//����Ȥ����ֵROI ���ӿɲ���three
/*
1.ʹ�ñ�ʾ��������Rect
2.ָ�����з�Χ Range
*/

//������ɫͨ���Ͷ�ͨ��ͼ
/*
split ��һ����ͨ������ɼ�����ͨ��
merge �������ͨ���ϲ���һ����ͨ��
*/

//ͼ��ԱȺ����ȵ���  --���ӵĸ��� 
/*
�������������������ֵ����������Ӧ���������ֵ������������
����  �Աȶ� ��ɫ �任
*/
int g_ConValue = 0;
int g_BrightValue = 0;
Mat img, desImgf;
static void onConBright(int, void *)
{
	namedWindow("Xiao", 1);//�������ֶ���Ҫһ��  ����û�취��ʾ����
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				desImgf.at<Vec3b>(i, j)[k] =
					saturate_cast<uchar>((g_ConValue*0.01)*(img.at<Vec3b>(i, j)[k]) + g_BrightValue);
			}
		}
	}
	imshow("Xiao", img);
	imshow("yuan", desImgf);
	while (char(waitKey(1)) != 'q'){};
}
static void onConstra(Mat &img)
{
	if (!img.data) return;
	desImgf = Mat::zeros(img.size(), img.type());

	g_ConValue = 80;
	g_BrightValue = 80;
	namedWindow("Xiao", 1);
	createTrackbar("Con", "Xiao",&g_ConValue, 300, onConBright);
	createTrackbar("Bright", "Xiao", &g_BrightValue, 200, onConBright);
	onConBright(g_ConValue,0);
	onConBright(g_BrightValue,0);
}

//����Ҷ�任 dft

int main5()
{
	img = imread(path5);
	//colorReduce(img, 32);
	onConstra(img);

	system("pause");
	return 0;
}