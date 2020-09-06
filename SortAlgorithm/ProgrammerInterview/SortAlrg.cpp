#include<iostream>
using namespace std;

//����  ѡ�� ���� �鲢  ϣ��

//����
void InsertSort(int a[], int n) {
	////Ĭ�ϵ�һ�����򣬴ӵڶ�����ʼ
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		//��һ�β������ѭ��
		for (; j >= 0; --j) {//���ǰ���Ѿ����� ��ֱ�ӱ�־
			if (a[j] <= a[i])// �Ȳ��ҵ���־  ֮�������λ����
				break;
		}
		if (j != i - 1) {
			int temp = a[i];
			for (int k = i; k > j + 1; --k)//k�����������λ ��i�����ȫ����λ
			{
				a[k] = a[k - 1];
			}
			a[j + 1] = temp;
		}
	}
	//int temp,i,j; //5,8,2,6,4 
	//for (i = 1; i < n; i++) {
	//	temp = a[i];//�ݴ���С
	//	for (j = i - 1; j >=0&&temp<a[j]; j--) {
	//		a[j+1] = a[j];//������Ų1λ
	//	}
	//	a[j + 1] = temp;
	//}
}

//ð��
void SortBoop(int a[], int n) {//�����Ƚ� ���н���
	int f = 0;//��־�Ƿ񽻻�
	for (int i = 0; i < n; i++) {
		//ÿ��֮ǰ��������
		f = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]){
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				f = 1;//��������ֵ1
			}
		}
		if (f != 1)//����û�н��� ��f=0
			return;
	}
}

//����
void SortQuick(int a[], int bgn,int end) {
	if (bgn >= end - 1) {
		return;
	}
	int left = bgn;
	int right = end - 1;
	int std = a[left];
	while (left < right) {
		while (left < right) {
			if(std > a[right]){//�����ұ�׼ֵС��
				a[left++] = a[right];
				break;
			}
			--right;
		}
		while (left < right) {
			if (std <= a[left]) {//ǰ���ұ�׼ֵ���
				a[right--] = a[left];
				break;
			}
			++left;
		}
	}
	//�ֱ�����߽��еݹ�
	a[left] = std;
	SortQuick(a, bgn, left);
	SortQuick(a, right + 1, end);
}

//ϣ��  ����̶����� ÿ�μ�ȥһ��  Ϊ��������ĸĽ�
void SortShell(int a[], int n) {
	//�̶����� ���н���  ֪����󲽳�����1 
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		//ÿ����в�������
		for (i = 0; i < n; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)//ǰ gap��һ����5���൱��ǰ6�ζ����������ѭ��   ��   �ڶ���
			{
				if (a[i] > a[j])
					break;
			}
			if (j != i - gap) {//
				int temp = a[i];
				for (int k = i; k > j; k -= gap)
					a[k] = a[k - gap];
				a[j + gap] = temp;
			}
		}
		//��ӡ��ǰ��gap������״̬
		cout << "\ngap=" << gap;
		cout << "\ncurrent list:";
		for (int h = 0; h < n; h++)
			cout << a[h] << "  ";
	}
}

//�鲢 ��·�鲢 ����������  Ȼ���ĸ����� �����ϲ�
//  ʱ�临�Ӷ�  n2  �ռ临�Ӷ� n
void Merger(int a[], int bgn, int mid, int end) {//2,8,5,4,6    a  0  2  5  /*a 0 5 10
	int i, j, k = 0;
	int * temp = new int[end - bgn + 1];//����ռ�  ����ռ��СΪ6
	for (i = bgn,j = mid+1; i <= mid && j< end;) {
			if (a[i] < a[j]) {
				temp[k++] = a[i++];//�ж������������� ���ǰ��С�ں��� ��С�Ĵ���������
				//�������������� ������һλ
			}
			else {
				temp[k++] = a[j++];//���ǰ�������棬����������ȥ��������һλ
			}
	}
	if (i <= mid)
		temp[k++] = a[i++];
	if (j < end)
		temp[k++] = a[j++];
	for (i = 0, k = 0; i < end; i++, k++) {
		a[i] = temp[k];
	}
	delete[]temp;
}

void SortGui(int a[], int low,int high) {//������ֳ�������  �ݹ�ֱ��������
	//��ͷ�ͽ�β Ԫ�ظ���
	int mid = (high-low) / 2;
	for (int i = low; i <= mid; i++) {
		for (int j = i + 1; j <= mid; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int j = mid + 1; j < high; j++) {
		for (int k = j + 1; k < high; k++) {
			if (a[j] > a[k]) {
				int temp = a[j];
				a[j] = a[k];
				a[k] = temp;
			}
		}
	}
	cout << endl << "SortGui";
	for (int i = 0; i < high; i++) {
		cout << a[i];
	}
	//SortGui(a, low, mid);
	//SortGui(a, mid + 1, high);
	Merger(a, low, mid, high);
}

//������ �����С��  ��û�г�
void HeadSort(int a[], int len) {//
	//���� ѡ����С������� ���ڶ��� ������Ϊ�� ������ �����ֵΪ�Ѷ�ֵ
	int max;
	for (int i = 0; i < len;i++) {
		if (a[i] > a[i + 1])
			max = a[i];//�ҵ����ѵĶ���
	}
	cout << "max" << max;
}
int main3(int argc, char *argv[]) {
	int a[10] = { 5,8,2,6,4,8,1,3,10,7};
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}
	HeadSort(a, 10);
	//InsertSort(a, 10);
	//SortBoop(a, 10);
	//SortQuick(a, 0, 10);
	//SortShell(a, 10);
	//SortGui(a, 0, 10);
	cout  << endl << "SortLat";
	for (int i = 0; i < 10; i++) {
		cout <<  a[i];
	}
	system("pause");
	return 0;
}