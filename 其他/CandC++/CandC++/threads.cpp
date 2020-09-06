#include <iostream>
#include <thread>//ֱ�Ӵ���һ���߳�
#include <chrono>//�߳��ݶ�
#include <windows.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std::chrono;

using namespace std;

void foo(const char* name)//�̴߳���
{
	cout << "hello" << name << endl;
}
//���Ա������Ϊ�߳����
class Greet
{
public:
	void SayHello(const char* name) {
		std::cout << "Hello" << name << "from" << this->owner << endl;
	}
private:
	const char* owner = "Greet";

};
//join�ȴ��߳�ִ�����--��ʹ���̺߳����Ѿ�ִ����ɺ󣬵���join��Ȼ����Ч��

//�߳���ͣ  �߳�ͣ��һ��sleep_for �� sleep_until
void pausable() {
	//sleep500ms
	std::this_thread::sleep_for(milliseconds(500));
	//sleep��ָ��ʱ���
	std::this_thread::sleep_until(system_clock::now() + milliseconds(500));
}

//�߳�ֹͣ--�߳�ִ���꣬��Ȼֹͣ ����������֮ǰjoin�£�ȷ���̳߳ɹ�����


///////////////////���̱߳��///////////////////
//windows�ṩHANDLE CreateThread(
//NULL,��ʼ��ջ��С��ִ�к���(�ص�����)��ִ�к���������NULL�������̴߳�����־�������������ڻ���߳�ID)
//����ɹ����õ��߳̾����ʧ�ܷ���NULL
//windows�رն����� BOOL WINAPI CloseHandle(HANDLE hObject);

//���̱߳��ʵ��      --���߳�ͬ�� ���û�����(Mutex)�������߳�ͬ��
//��Ҫ�������¼�����������ͬ��
//HANDLE WINAPI CreateMutex(NULL,������ǰ�߳��Ƿ�ӵ��Mutex����Ȩ��Mutex����)
//DWORD WINAPI WaitForSingleObject(������������ʱ���)
//BOOL WINAPI ReleaseMute(HANDLE hMutex) �ͷ���ӵ�еĻ���������

HANDLE hMutex = NULL;//������

DWORD WINAPI Fun(LPVOID lpParamter) {//�ص������̺߳���
	for (int i = 0; i < 10; i++) {
		//����һ����������
		WaitForSingleObject(hMutex,INFINITE);

		cout << "a thread" << endl;
		Sleep(200);
		//�ͷŻ�������
		ReleaseMutex(hMutex);
	}
	return 0L;
}


int GetSum(vector<int>::iterator first, vector<int>::iterator last) {
	return accumulate(first, last, 0);//C++��׼�㷨
}

//�߳�Ҫ���������д������̺߳�����
void GetSumT(vector<int>::iterator first, vector<int>::iterator last, int &result)
{
	result = accumulate(first, last, 0); //����C++��׼���㷨
}


int maint(int argc,char *argv[]) {
	//�����߳�
//	thread thread(foo,"C++11s");

//	Greet greet;
//	std::thread thread(&Greet::SayHello, &greet, "C++11");
//	std::thread thread(pausable);
//  thread.join();//�ȴ��߳�ִ����

/*
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);//�����߳�
	hMutex = CreateMutex(NULL,FALSE,"screen");
	//�ر��߳� ���
	CloseHandle(hThread);
	//���߳�ִ��·��
	for (int i = 0; i < 10; i++) {
		//�����û�����
		WaitForSingleObject(hMutex, INFINITE);

		cout << "main thread" << endl;
		Sleep(500);
		//�ͷŻ�����
		ReleaseMutex(hMutex);
	}
*/
	//���߳�ʵ��
/*	vector<int> largArrays;
	for (int i = 0; i < 100000; i++) {
		if (i % 2 == 0)
			largArrays.push_back(i);
		else
			largArrays.push_back(i);
	}
	int res = GetSum(largArrays.begin(),largArrays.end());
	*/
	int result1, result2, result3, result4, result5;
	vector<int> largeArrays;
	for (int i = 0; i < 100000000; i++)
	{
		if (i % 2 == 0)
			largeArrays.push_back(i);
		else
			largeArrays.push_back(-1 * i);
	}
	//thread first(�̺߳�����������1������2��......)��ÿ���߳���һ���̺߳������߳�Ҫ���������д���̺߳����С�
	thread first(GetSumT, largeArrays.begin(),
		largeArrays.begin() + 20000000, std::ref(result1)); //���߳�1
	thread second(GetSumT, largeArrays.begin() + 20000000,
		largeArrays.begin() + 40000000, std::ref(result2)); //���߳�2
	thread thrid(GetSumT, largeArrays.begin() + 40000000,
		largeArrays.begin() + 60000000, std::ref(result3)); //���߳�3
	thread fouth(GetSumT, largeArrays.begin() + 60000000,
		largeArrays.begin() + 80000000, std::ref(result4)); //���߳�4
	thread fifth(GetSumT, largeArrays.begin() + 80000000,
		largeArrays.end(), std::ref(result5)); //���߳�5

	first.join(); //���߳�Ҫ�ȴ����߳�ִ����� join()��һ����������
	second.join();
	thrid.join();
	fouth.join();
	fifth.join();
	//first.detach()��ʱ��������Ҫ����һ�����й۲���̣߳�ĬĬ��ѯ�����ĳ��״̬�����ֵĳ�Ϊ�ػ��̡߳������̻߳������߳�����֮���Զ����١�
	int resultSum = result1 + result2 + result3 + result4 + result5; //���ܸ������̵߳Ľ��
	//C++��һ����׼�̺߳���ֻ�ܷ���void�������Ҫ���߳��з���ֵ�������ô������õķ���
	
	system("pause");
	return 0;
}