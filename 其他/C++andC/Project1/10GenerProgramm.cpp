#include <iostream>
#include <cstdio>

#define Max(a,b) (((a)>(b))?(a):(b))

using namespace std;
template<class T>
//c++��c�ĳ�����������󡣷��ͱ��-����ģ�壬��Ч���㷨�����ݽṹ���룬������ģ������϶�  

//����ģ�� ����ģ�壺ǰ����һ�ֳ���ĺ������壬����һ��ͬ��������������һ�ָ��߲�εĳ����ඨ�塣ǰ�ߵ�ʵ�������ɱ�������ڴ���������ʱ�Զ���ɣ�����ʵ���������ɳ���Ա�ڴ�������ʾָ��

//ģ����ȱ�㣺��ʡʱ�䣬�������á�����ʹ�û�ʹ�������ͣ�Ӱ���������Ч�ʡ� ��������޹صĴ������
 
//ģ���ػ�����ģ���ĳЩ���ͽ����ر���ʱ����Ϊ�ػ���

//����ģ�巺��
const T*find1(const T*arr, int n, T x) {
	const T* p = arr;
	for (int i = 0; i < n; i++) {
		if (*p == x) {
			return p;
		}
		++p;
	}
	return 0;
}


//����  �����˴����������
template<class T>
T max(T a, T b) {//���벻ͬ����  ѡ��ͬ�����
	return a > b ? a : b;//������ֵ
}



int main10() {

	cout << max(1, 2) << endl;
	cout << max(1.2, 1.4) << endl;

	system("pause");
	return 0;
}