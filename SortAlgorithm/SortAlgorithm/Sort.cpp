#include <iostream>
#include <vector>
using namespace std;

//��������������������ֵ�ͽ���
int getMaxValue(const vector<int> &arr) {
	int max = 0;
	for (auto val : arr) {
		if (val > max) {
			max = val;
		}
	}
	return max;
}

void Swap(int &pa, int &pb) {
	int temp = pa;
	pa = pb;
	pb = temp;
}

//ð���������αȽ�������Ԫ�أ���ǰһԪ�ش��ں�һԪ���򽻻�֮��ֱ�����һ��Ԫ�ؼ�Ϊ���
//Ȼ�����´���Ԫ�ؿ�ʼ�ظ�ͬ���Ĳ�����ֱ�������ڶ���Ԫ�ؼ�Ϊ�δ�Ԫ��   O(N2) �ȶ�
void bubbleSort(vector<int>&arr, int bgn, int end) {
	/*isLoop����ָʾ���α������Ƿ���Ԫ�ؽ�������û�У��������������У��˳�����*/
	bool isLoop = true;
	for (int i = end; true == isLoop && i > bgn; --i) {
		isLoop = false;
		for (int j = bgn + 1; j < i; ++j) {
			if (arr[j] < arr[j - 1]) {
				Swap(arr[j], arr[j - 1]);
				isLoop = true;
			}
		}
	}
}

//ѡ������ ���ȳ�ʼ����СԪ������ֵΪ��Ԫ�أ����α������������У�������С�ڸ���С����λ�ô���Ԫ����ˢ����С����Ϊ�ý�СԪ�ص�λ�ã�ֱ������βԪ�أ�����һ�α���
//������С������Ԫ������Ԫ�ؽ�����Ȼ�󣬳�ʼ����С����ֵΪ�ڶ�������������Ԫ��λ�ã�ͬ���Ĳ������ɵõ����еڶ���Ԫ�ؼ�Ϊ��СԪ�أ�O(N2) ���ȶ�
void selectSort(vector<int>&arr, int bgn, int end) {
	for (int i = 0; i < bgn; ++i) {
		int minIndex = 0;
		for (int j = i + 1; j < end; ++j) {
			if (arr[j] < arr[j + 1]){
				minIndex = j;
            }
		}
		if (minIndex != i) {
			Swap(arr[i], arr[minIndex]);
		}
	}
}

//�������� ��������ѡ������Ķ�λ˼�룩ѡһ��׼Ԫ�أ����ν�ʣ��Ԫ����С�ڸû�׼Ԫ�ص�ֵ��������࣬���ڵ��ڸû�׼Ԫ�ص�ֵ�������Ҳࣻ
//Ȼ��ȡ��׼Ԫ�ص�ǰ�벿�ֺͺ�벿�ֱַ����ͬ���Ĵ����Դ����ƣ�ֱ����������ʣ��һ��Ԫ��ʱ����������ɣ���ȶ�������˼�룬from up to down��O(NlogN) ���ȶ�
void quickSort(vector<int>&arr, int bgn, int end) {
	if (bgn >= end - 1) {
		return;
	}
	int lindex = bgn;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {
			if (arr[rindex] < std) {
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}
		while (lindex < rindex)
		{
			if (arr[lindex] >= std)
			{
				arr[rindex--] = arr[lindex];
				break;
			}
			++lindex;
		}
	}
	arr[lindex] = std;
	quickSort(arr, bgn, lindex);
	quickSort(arr, rindex + 1, end);
}
//��������  ����ǰ�沿�ֿ�Ϊ�������ν��������������Ԫ�ز��뵽ǰ������������У���ʼ״̬�������н���һ��Ԫ�أ�����Ԫ�ء�
//�ڽ���������Ԫ�ز����������еĹ����У���������������������У������˳����������Է������������б����ѽ�����״̬Ч�ʻ���ߡ�  O(N2) �ȶ�
void insertSort(vector<int>&arr, int bgn, int end) {
	for (int i = bgn + 1; i < end; i++) {
		/*
* ��Ϊ1,2�����ִ�����������j = beg - 1ʱ�����
* ����Ҫ��arr[i]���뵽��Ԫ��ǰ��λ�ã���ʹ��һ��for
* �����������֣�����ڷ����������ʱ�˳�
  */
    /*1*/
		int j = i - 1;
		for (; j > bgn; --j) {
			if (arr[j] <= arr[i])
				break;
		}
		/*2*/
		if (j != i - 1) {
			int temp = arr[i];
			for (int k = i; k > j + 1; --k) {
				arr[k] = arr[k - 1];
			}
			arr[j + 1] = temp;
		}
	 }
}
//ϣ������ - ��������ĸĽ��档Ϊ�˼������ݵ��ƶ��������ڳ�ʼ���нϴ�ʱȡ�ϴ�Ĳ�����ͨ��ȡ���г��ȵ�һ�룬��ʱֻ������Ԫ�رȽϣ�����һ�Σ�
//֮�󲽳����μ���ֱ������Ϊ1����Ϊ�����������ڴ�ʱ�����ѽӽ����򣬹ʲ���Ԫ��ʱ�����ƶ��Ĵ�������Խ��٣�Ч�ʵõ�����ߡ�O(N3/2) ���ȶ�
/*ϣ������*/
void shellSort(vector<int> &arr, int bgn, int end)
{
	for (int step = (end - bgn) / 2; step > 0; step /= 2)
	{
		for (int i = bgn; i < step; ++i)
		{
			/*
			* ���£�insertSort�ı���
			*/
			for (int j = i + step; j < end; j += step)
			{
				int k = j - step;
				for (; k >= i; k -= step)
					if (arr[k] <= arr[j])
						break;
				if (k != j - step)
				{
					int tmp = arr[j];
					for (int m = j; m > k + step; m -= step)
						arr[m] = arr[m - step];
					arr[k + step] = tmp;
				}
			}
		}
	}
}
//Ͱ���� - ʵ���������򣬵���Ԫ�ؼ�ֵ�ô�С�нϴ���ʱ������ڴ�ռ�Ľϴ��˷ѡ����ȣ��ҳ����������е����Ԫ��max�������ڴ��СΪmax + 1��Ͱ�����飩����ʼ��Ϊ0��
//Ȼ�󣬱����������У������ν�ÿ��Ԫ����Ϊ�±��ͰԪ��ֵ����1��
//��󣬱���ͰԪ�أ������ν�ֵ��0��Ԫ���±�ֵ�����������У�ͰԪ�� > 1������ֵ��С��ȵ�Ԫ�أ���ʱ���ν����������������У���������ɣ��������б�Ϊ�������С�O(x*N) �ȶ�

void bucketSort(vector<int> &arr)
{
	int max = getMaxValue(arr);
	int *pBuf = new int[max + 1];

	memset(pBuf, 0, (max + 1) * sizeof(int));
	for (auto const i : arr)
		++pBuf[i];

	for (int i = 0, j = 0; i <= max; ++i)
	{
		while (pBuf[i]--)
			arr[j++] = i;
	}
	delete[]pBuf;
}
//�������� - Ͱ����ĸĽ��棬Ͱ�Ĵ�С�̶�Ϊ10���������ڴ�ռ�Ŀ��������ȣ��ҳ����������е����Ԫ��max�������ΰ�max�ĵ�λ����λ������Ԫ������
//ͰԪ��10��Ԫ�صĴ�С��Ϊ����������Ԫ�ض�Ӧ��ֵΪ���Ԫ�صĸ�������ÿ�α������������У�Ͱ���䰴��Ӧ��ֵλ��С��Ϊ��10���㼶��
//Ͱ��Ԫ��ֵ�ú�Ϊ����������Ԫ�ظ�����O(x*N)  �ȶ�
//1. �������򣬰�������ֵ��λ��������
void countSort(vector<int> &arr, int exp)
{
	int bucket[10] = { 0 };
	int arrSize = arr.size();
	int *pTemp = new int[arrSize];
	memset(pTemp, 0, arrSize * sizeof(int));//������Ŀռ����

	//ͳ�Ƶ�λexp����ֵ����ֵ
	for (auto const val : arr)
		++bucket[(val / exp) % 10];

	//�����ֲ�
	for (int i = 1; i < 10; ++i)
		bucket[i] += bucket[i - 1];

	//��expλ��С������arrԪ�����pTemp
	for (int i = arrSize - 1; i >= 0; --i)
		pTemp[--bucket[(arr[i] / exp) % 10]] = arr[i];
	/*bugs*/
#if 0
	//bug1: bucket����εļ���ֵû����һ����Ӧ�Լ�1
	for (auto const val : arr)
		pTemp[bucket[(val / exp) % 10] - 1] = val;
	//bug2: arr����Ԫ��ÿ������ʱ���±�Ӧ�Ӵ�С�����������޷�ʵ������
	for (auto const val : arr)
		pTemp[--bucket[(val / exp) % 10]] = val;
#endif

	//pTemp -> arr
	for (int i = 0; i < arrSize; ++i)
		arr[i] = pTemp[i];
	delete[]pTemp;
}
//2. �ϲ�����λ����������
void radixSort(vector<int> &arr)
{
	int max = getMaxValue(arr);
	for (int exp = 1; max / exp != 0; exp *= 10)
		countSort(arr, exp);
}
//�鲢���� - �����˷��κ͵ݹ��˼�룬�ݹ� & ���� - ��������������ͬ���������������У�����ִ���������ֱ������ĩ�˵�����Ԫ�أ�
//���������ϲ���������õ��������н�������ֱ����������������ȶ�������˼�룬from down to up����O(NlogN) �ȶ�
/*�鲢����*/
//����������������
void mergeSortInOrder(vector<int> &arr, int bgn, int mid, int end)
{
	int *pBuf = new int[end - bgn];
	int *pTemp = pBuf;
	int lindex = bgn;
	int rindex = mid;

	while ((lindex < mid) && (rindex < end))
		*(pTemp++) = (arr[lindex] < arr[rindex]) ? arr[lindex++] : arr[rindex++];

	while (lindex < mid)
		*pTemp++ = arr[lindex++];
	while (rindex < end)
		*pTemp++ = arr[rindex++];

	//pTemp -> arr
	pTemp = pBuf;
	for (int i = bgn; i < end; i++)
		arr[i] = *pTemp++;

	delete[]pBuf;
}
//UpToDown To DownToUp
void mergeSort(vector<int> &arr, int bgn, int end)
{
	//����arr��or����һ��Ԫ�����˳�
	if (bgn >= end - 1)
		return;

	int mid = (bgn + end) / 2;
	mergeSort(arr, bgn, mid);
	mergeSort(arr, mid, end);
	mergeSortInOrder(arr, bgn, mid, end);
}
//������ - �������˼������ڶ�����е����ѵ���ʵ�֡����ȣ������������г���Ϊ������������������ѣ�
//Ȼ�����ν����Ԫ�أ������ڵ�Ԫ�أ�����������е����һ��Ԫ�ؽ���������������������ұߵ�Ҷ�ӽ��Ԫ�أ���
//ÿ�α�����ˢ�����һ��Ԫ�ص�λ�ã��Լ�1����ֱ��������Ԫ���ཻ����������� O(NlogN) ���ȶ�
/*������*/
//���ڵ�Ԫ���Զ������ƶ������ʵ�λ���Թ�������
void downToMaxHeap(vector<int> &arr, int bgn, int end)
{
	int child;
	int parent = bgn;

	/*�ٸ��ڵ������ƶ������ʵ�λ�� --����������ĺ��Ĵ����*/
	while ((child = parent * 2 + 1) < end)
	{
		if ((child < end - 1) && (arr[child] < arr[child + 1]))
			++child;    //�Һ��ӽڵ�
		if (arr[child] > arr[parent])
			Swap(arr[child], arr[parent]);
		else
			break;
		parent = child;
	}
}
//�����鹹��Ϊ����
void buildMaxHeap(vector<int> &arr, int bgn, int end)
{
	if (bgn >= end - 1)
		return;

	int parent = end / 2 - 1;
	while (parent >= 0)
	{
		downToMaxHeap(arr, parent, end);
		--parent;
	}
}
//������
void heapSort(vector<int> &arr, int bgn, int end)
{
	/*for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}*/
	//��������
	buildMaxHeap(arr, bgn, end);

	while (end > 1)
	{
		Swap(arr[0], arr[--end]);
		downToMaxHeap(arr, 0, end);
	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
}



int main() {
    //-https://www.cnblogs.com/Glory-D/p/7884525.html
	vector<int>a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(2);
	a.push_back(8);
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(2);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "\n";
	//cout << "***" <<sizeof(long) << sizeof(int) << sizeof(double) << sizeof(float) <<sizeof(long long) << sizeof(char*);
	insertSort(a, 0, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	system("pause");
	return 0;
}