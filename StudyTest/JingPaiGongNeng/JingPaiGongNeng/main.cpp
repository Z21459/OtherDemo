//
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <cstring>
//#include <cmath>
//#include <conio.h>
//#include <malloc.h>
//#include <cmath>
//#include <ctime>
//#include <windows.h>
//#include <process.h>
//#include <vector>
//#define Max_User 2000
////_CRT_SECURE_NO_WARNINGS ���fopen()�ȱ�������  ������ӵ�Ԥ��������������
//
//using namespace std;
//char T[20];//�û���
//HANDLE hTimer;//�޹ر���
//int Rott;//ʣ��ʱ��;
//char Buyer[20];
//char Seller[20];
//char Tpassword[21];//����
//
//
//typedef struct RANK
//{
//	char Name[20];
//	int score;
//} RANK;//���а�
//
//
//typedef struct Bag_Goods
//{
//	int G_ID;  //���
//	char G_Name[20];//����
//	int New_old;//�¾�
//	char Desc[120];//����
//	int Price;//����
//	int years;   //���
//	char size[40]; //��С
//	int weight;//����
//	int State;// 1 ���� 0 ���
//	int flag;// 1 �����õ���
//} Bag_Goods;
//
//
//typedef struct T_G
//{
//	int G_ID;  //���
//	char G_Name[20];//����
//	int New_old;//�¾�
//	char Desc[120];//����
//	int Price;//����
//	int years;   //���
//	char size[40]; //��С
//	int weight;//����
//	int State;//�Ƿ�����
//	int flag;// 1 �����õ���
//	struct T_G *next;
//} T_G;//����������� ɾ��������Ʒ
//
//
//typedef struct USER
//{
//	char Name[20];     //����
//	char Sex[10];           //�Ա�
//	char Pho_num[20];       //�ֻ��绰
//	char Mail[20];  //����
//	char Spec[30];  //����ǩ��
//	int score;   //��������
//	char Acc_num[20];     //�û���
//	char Password[20]; //����
//	int Sum;  //���ټ���Ʒ
//	char Address[40];//��ַ
//	Bag_Goods MyGoods[20];//��Ʒ���
//} USER;
//
//
//typedef struct TIME
//{
//	int Year;
//	int Month;
//	int Day;
//	int Hour;
//	int Min;
//	int Sec;
//} TIME;//������Ʒ��ʼʱ��
//
//
//typedef struct Bid_Money
//{
//	char Next_Haver_Name[20];//��һ�������˵� ����
//	int Money;
//
//
//	int Ye;
//	int Mo;
//	int Da;
//	int Ho;
//	int Mi;
//	int Se;
//} Bid_Money;//�����˵���Ϣ
//
//
//
//
//typedef struct BIDDER//������Ʒ����Ϣ
//{
//	int NUM;
//	char Haver[20];//��ǰӵ����
//	int G_ID;//��Ʒ��ԭ�������
//	char Address[40];//��ַ
//	char B_Name[20];//��Ʒ����
//	int B_years;//��Ʒ���
//	int B_New_old;//��Ʒ�¾�
//	char B_Desc[20];//��Ʒ����
//	int B_Price;///���ļ۸�
//	int B_H_Price;///һ�ڼ�
//	int Final_Price;///���ռ�
//	int B_weight;//����
//	char B_size[40];//����
//	int M_M;//��ä
//	int Z_F;//����
//	TIME B_Time;//����ʱ��
//	char Ber[20];//����
//	int flag1;///    1 ���� 2 ����  3��֧�� 4���ڻָ���ɱ������ 5 ���ھ���
//	int flag2;///    1 ��֧�� 2 ������
//	int sum;//������
//	Bid_Money Mark[30];//�۸�
//	//ENDTIME e_time;
//} BIDDER;
//
//
//
//
//
//
//BIDDER Bidder[1000];//������Ʒ
//USER User[500];//�û���Ϣ
//RANK Rank[500];//���а�
//
//
//int mintues;//�Ʒ�
//int seconds;//����
//int Re_min;//�޹ر���
//int Re_sec;//�޹ر���
//int F_H;//��һ��Ǯ����
//int S_H;//�޹ر���
//int Bi, Bn;//������������Ʒ
//int UI, UN;//��¼�˵��±�
//int Start = 0, End = 0;//�޹ر���
//
//
/////����
//void delay(double second);//�ӳ�
//void In_System();//loading...
//void str_to_ch(string A, char a[]);//��string��Ϊchar a[]�洢
//void Menu();//��ӭ����
//void Jugel();//�ж�
//void Register();//ע��
//void Login();//��¼
//void Cancel();//ע��
//void Login_Warning();//�����������
//void Login_welcome();//��½��ɽ���
//void Watch_Bag(); //�鿴����
//void Add_Goods(int i, int n);//������Ʒ
//void Del_Goods(int i, int n);//ɾ����Ʒ
//void GoodTraverse(int i, int n);//�鿴�޸���Ʒ��Ϣ
//
//
/////��¼�޸�
//void Revise_User_Info();//�޸��û���Ϣ
//void Revise_User_Info_Pho_Num(int i, int j);//�޸��ֻ�����
//void Revise_User_Info_Spec(int i, int j);//�޸ĸ���ǩ��
//void Revise_User_Info_Password(int i, int j);//�޸�����
//void Revise_User_Info_Mail(int i, int j);//�޸�����
//void Revise_User_Info_Address(int i, int j);//�޸ĵ�ַ
//
//
/////��¼��ѯ
//void Revise_G_ID(int i, int n);//����Ʒ��Ų�ѯ
//void Revise_G_Name(int i, int n);//����Ʒ���ֲ�ѯ
//void Revise_G_New_Old(int i, int n);//����Ʒ�¾ɲ�ѯ
//void Revise_G_State(int i, int n);//����Ʒ������ѯ
//void Revise_G_size(int i, int n);//��Ʒ����
//void Revise_All_G(int i, int n);//�鿴������Ʒ
//void Revise_Part_G(int Ui, int mid);//�鿴��һ��Ʒ
//void I_just_check(int i, int n);//����ѯ������Ʒ
//void Change_Good(int i, int n);//�ı���Ʒ��Ϣ
//void Flag_Good(int i, int n);//�����õ�����Ʒ
//
//
/////���Ŷ���
//void Quick_Sort(USER User[], int Ui, int left, int right, int choice);//����
//void Bin_Search(USER User[], int Ui, int left, int right, int choice, int e);//���ֲ���
//void Rank_Quick_Sort(RANK Rank[], int left, int right);//���а�
//void B_S(BIDDER Bidder[], int Ui, int left, int right, int e);//���ֲ���
//void Del_Auction();//ɾ������
//
//
/////�û�
//int Read_U_All_File();//��ȡUSERȫ���ļ�
//int Read_U_Part_File(int n);//��ȡUERR�ؼ��ļ�
//void WriteinFile(int i);//д���ļ�
/////������Ʒ
//int ReadALL_BFile();//��ȡ������Ʒ�ļ�
//void Write_B_inFile(int i);//д���ļ�
//int Read_B_PartFile(int B_n);//��ȡ�ؼ��ļ�
//void CLear_File();
/////���а�
//void Rank_Read(int Un);//��ȡ�û�������
//
//
//void Pre_Bid(int Ui, int Un);//����Ʒ����ƽ̨������
//void Password_Undisplay(char Pw[]);//������ʾ
//
//
/////ֱ�Ӳ鿴��Ϣ
//void Revise_Online();//�鿴��Ϣ ������չ
//void Revise_Online_Good();//����¼�鿴��Ʒ
//void Revise_Online_User();//����¼�鿴�û�
//void Revise_Online_Rank();//����¼�鿴���а�
//
//
//void Help();///���� ������չ
//void Mannel();///�û��ֲ�
//void Receive_rewards();///��ȡ����
//
//
//void About_Author();///�������� ������չ
//
//
//void Join_Pm();//���뾺��
//
//
//void Auction_All_Revise(int B_i, int B_n);//�鿴������Ϣ
//void Auction_Size_Revise(int B_i, int B_n);//�鿴��һ������Ϣ
//
//
//int Online_Money(int P, int flag1, int flag2);//���ϼ�Ǯ
//void Payment(int p);//֧��
//void Racket(int p);//����
//void Overdue();//����û��Ҫ�Ķ���
//void Back_Bag();//�ص�������
//
//
//void Decide_Time(int B_n);//����ʱ��������
//
//
//void Count_Backwards_time();//ʱ�䵹��
//void Waiting_Time();//�ȴ�ʱ��
//int Time_minus(int p);//ʱ���
//
//
//
//
//int main()//������
//{
//
//
//	system("mode con cols=237 lines=100");
//	memset(T, '\0', sizeof(char));
//	int choice1, choice2, choice3;
//
//
//	/*int B_n=ReadALL_BFile();
//	printf("%d\n",B_n);
//	for(int i=0; i<B_n; i++)
//	{
//		printf("  %s  \n",Bidder[i].B_Name);
//		printf("  %d  \n",Bidder[i].flag1);
//	}
//	Overdue();
//	Back_Bag();
//	for(int i=0; i<B_n; i++)
//	{
//		printf("  %s  \n",Bidder[i].B_Name);
//		printf("  %d  \n",Bidder[i].flag1);
//		//printf("  %s  \n",Bidder[i].Mark[1].Next_Haver_Name);
//	}*/
//	//Overdue();
//	//Back_Bag();
//	//In_System();
//	while (1)
//	{
//		Overdue();
//		Back_Bag();
//		system("cls");
//		Menu();
//		printf("\nPs����ע���û�Ӧ�����Ķ� ���� �� ��ʹ����֪\n");
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		scanf("%d", &choice1);
//		choice2 = 0;
//		system("cls");
//		switch (choice1)
//		{
//
//
//		case 1://��¼
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t*********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                 0��������½                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                 3��������һ��                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                 5���˳�����                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                       *\n");
//				printf("\t\t\t\t\t\t\t\t*********************************************************\n");
//				scanf("%d", &choice2);
//				if (choice2 == 3)break;
//				if (choice2 == 5)exit(0);
//				if (!choice2)
//				{
//					if (T[0] == '\0')
//					{
//						Login();
//						system("pause");
//					}
//					cout << endl;
//					while (1)
//					{
//						if (T[0] == '\0')
//						{
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t*                   ���ؼ�����¼��                       *\n");
//							printf("\t\t\t\t\t\t\t\t*                   3��������һ��                        *\n");
//							printf("\t\t\t\t\t\t\t\t*                   5���˳�����                          *\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t�����룺");
//							scanf("%d", &choice2);
//						}
//						system("cls");
//						if (choice2 == 3)break;
//						if (choice2 == 5)exit(0);
//						while (1)
//						{
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t*                    9��֧������������Ʒ                 *\n");
//							printf("\t\t\t\t\t\t\t\t*                    8��ע�� ���µ�¼                    *\n");
//							printf("\t\t\t\t\t\t\t\t*                    7���鿴�����޸��û���Ϣ             *\n");
//							printf("\t\t\t\t\t\t\t\t*                    6���鿴������Ʒ                     *\n");
//							printf("\t\t\t\t\t\t\t\t*                    4���μ�����                         *\n");
//							printf("\t\t\t\t\t\t\t\t*                    3��������һ��                       *\n");
//							printf("\t\t\t\t\t\t\t\t*                    5���˳�����                         *\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t�����룺");
//							scanf("%d", &choice2);
//							if (choice2 == 3)break;
//							if (choice2 == 8)
//							{
//								Cancel();//ע��
//								break;
//							}
//							switch (choice2)
//							{
//
//
//							case 1:
//							case 2:
//							case 4://�μӾ���
//								//printf("%s\n",T);
//								Join_Pm();
//								cout << endl;
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t�����룺");
//								scanf("%d", &choice3);
//								system("cls");
//								if (choice3 == 3)break;
//								switch (choice3)
//								{
//								case 1:
//								case 2:
//								case 4:
//									break;
//								case 5:
//									exit(0);
//								}
//							case 5:
//								exit(0);
//							case 6:
//								//printf("%s\n",T);
//								Overdue();
//								Watch_Bag();
//								cout << endl;
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t�����룺");
//								scanf("%d", &choice3);
//								system("cls");
//								if (choice3 == 3)break;
//								switch (choice3)
//								{
//								case 1:
//								case 2:
//								case 4:
//									break;
//								case 5:
//									exit(0);
//								}
//							case 7:
//								Revise_User_Info();
//								system("CLS");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t�����룺");
//								scanf("%d", &choice3);
//								system("cls");
//								if (choice3 == 3)break;
//								switch (choice3)
//								{
//								case 1:
//								case 2:
//								case 4:
//									break;
//								case 5:
//									exit(0);
//								}
//							case 9:
//								Jugel();
//								system("CLS");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//								printf("\t\t\t\t\t\t\t\t�����룺");
//								scanf("%d", &choice3);
//								system("cls");
//								if (choice3 == 3)break;
//								switch (choice3)
//								{
//								case 1:
//								case 2:
//								case 4:
//									break;
//								case 5:
//									exit(0);
//								}
//							}
//						}
//					}
//
//
//				}
//				break;
//		case 2://ע��
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0������ע��                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3��������һ��                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Register();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t�����룺");
//					scanf("%d", &choice2);
//				}
//				system("cls");
//				if (choice2 == 3)break;
//				switch (choice2)
//				{
//
//
//				case 1:
//				case 2:
//				case 4:
//					break;
//				case 5:
//					exit(0);
//
//
//				}
//			}
//			break;
//		case 4://ֱ�Ӳ�ѯ���ɲ���¼��
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0��������ѯ                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3��������һ��                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//				printf("\t\t\t\t\t\t\t\t������: ");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Revise_Online();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//					printf("\t\t\t\t\t\t\t\t�����룺");
//					scanf("%d", &choice2);
//				}
//				if (choice2 == 3)break;
//				if (choice3 == 5)exit(0);
//			}
//			system("cls");
//			break;
//		case 6:
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0������Ѱ�����                     *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3��������һ��                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                    5���˳�                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Help();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t�����룺");
//					scanf("%d", &choice2);
//				}
//				if (choice2 == 3)break;
//				if (choice2 == 5)exit(0);
//			}
//			system("cls");
//			break;
//		case 7://��������
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0������                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3��������һ��                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                    5���˳�                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					About_Author();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3��������һ��                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5���˳�����                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//					printf("\t\t\t\t\t\t\t\t�����룺");
//					scanf("%d", &choice2);
//				}
//				if (choice2 == 3)break;
//				if (choice2 == 5)exit(0);
//			}
//			system("cls");
//			break;
//		case 5:
//			exit(0);
//		default:
//			break;
//			}
//		}
//		//return 0;
//// Jugel();
//	}
//}
//
//
//void Join_Pm()///�μӾ���
//{
//	int choice, choice2, B_i, B_n;
//
//
//	Overdue();//����û��Ҫ�Ķ���
//	Back_Bag();
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//	//printf("  %d %d\n",B_i,B_n);
//	if (B_i == B_n || B_i == -1)
//	{
//		printf("\t\t\t\t\t\t\t\t***********************Ŀǰû����Ʒ����*********************\n");
//		system("Pause");
//		return;
//	}
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t*********ע�� �����뾺�Ŀ���ѡ����һ�� ���� �˳�********\n");
//		//system("pause");
//		//printf("��������ϵͳ��...\n");
//		while (1)
//		{
//			Overdue();//����û��Ҫ�Ķ���
//			Back_Bag();
//			B_n = ReadALL_BFile();
//			B_i = Read_B_PartFile(B_n);
//			if (B_i == B_n || B_i == -1)
//			{
//				printf("\t\t\t\t\t\t\t\t***********************Ŀǰû����Ʒ����*********************\n");
//				system("Pause");
//				return;
//			}
//			printf("\t\t\t\t\t\t\t\t*******************Ŀǰ�� %d ����Ʒ����*******************\n", B_n - B_i);
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                     1���鿴������Ʒ                    *\n");
//			printf("\t\t\t\t\t\t\t\t*                     2�����뾺��                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                     3�������ˣ���                      *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice);
//			if (choice == 3)break;
//			switch (choice)
//			{
//			case 1:
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                   1����� �鿴 ��Ʒ                    *\n");
//				printf("\t\t\t\t\t\t\t\t*                   2������ �鿴 ��Ʒ                    *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				scanf("%d", &choice2);
//				system("cls");
//				if (choice2 == 1)Auction_All_Revise(B_i, B_n);
//				if (choice2 == 2)Auction_Size_Revise(B_i, B_n);
//				break;
//			case 2:
//				Overdue();//����û��Ҫ�Ķ���
//				Back_Bag();
//				B_n = ReadALL_BFile();
//				B_i = Read_B_PartFile(B_n);
//				Bi = B_i;
//				Bn = B_n;
//				Waiting_Time();
//				system("pause");
//				system("cls");
//				break;
//			default:
//				break;
//			}
//		}
//	}
//}
//
//
//void Auction_All_Revise(int B_i, int B_n)///�鿴��Ʒ ���
//{
//	int i = Bidder[B_i].NUM + B_i, j = Bidder[B_n - 1].NUM + B_i, mid, flag = 0, e;
//	//printf("%d %d %d %d\n",i,j,Bidder[B_i].NUM,B_i);
//	//printf("     %d %d\n",B_i,B_n);
//	printf("\t\t\t\t\t\t\t\t���� ���� ��Ʒ ��ţ�");
//	scanf("%d", &e);
//	e = e + B_i - 1;
//	//printf("%d %d %d\n",i,j,e);
//	while (j >= i)
//	{
//		mid = (i + j) / 2;
//		if (e == Bidder[mid].NUM + B_i)
//		{
//			flag = 1;
//			if (Bidder[mid].B_New_old)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���֣� %s\n", Bidder[mid].B_Name);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %s\n", Bidder[mid].B_Desc);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ͣ� %s\n", Bidder[mid].B_size);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ļۣ� %d\n", Bidder[mid].B_Price);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %d\n", Bidder[mid].B_weight);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (Bidder[mid].B_H_Price)printf("\t\t\t\t\t\t\t\t������Ʒ֧����߼�����߼ۣ�%d\n", Bidder[mid].B_H_Price);
//			else printf("\t\t\t\t\t\t\t\t������Ʒ��֧��һ�ڼ�\n");
//			if (Bidder[mid].M_M == 1)printf("\t\t\t\t\t\t\t\t��Ʒ������ʽΪ ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������ʽΪ ä��\n");
//			if (Bidder[mid].Z_F == 1)printf("\t\t\t\t\t\t\t\t��������Ϊ �۸��ߵã�\n");
//			else printf("\t\t\t\t\t\t\t\t��������Ϊ �۵��ߵã�\n");
//			printf("\t\t\t\t\t\t\t\t������Ʒ��ʼ����ʱ�� ��%04d %02d %02d %02d %02d %02d\n", Bidder[mid].B_Time.Year, Bidder[mid].B_Time.Month, Bidder[mid].B_Time.Day, Bidder[mid].B_Time.Hour, Bidder[mid].B_Time.Min, Bidder[mid].B_Time.Sec);
//			cout << endl;
//			break;
//		}
//		if (e > Bidder[mid].NUM + B_i)i = mid + 1;
//		else if (e <= Bidder[mid].NUM + B_i)j = mid - 1;
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\tû�������Ϣ\n");
//	system("pause");
//	system("cls");
//}
//
//
//void Auction_Size_Revise(int B_i, int B_n)///�鿴��һ��Ʒ
//{
//	int i, flag = 0;
//	char T_c[40];
//	printf("\t\t\t\t\t\t\t\t����������鿴����Ʒ���ͣ�");
//	scanf("%s", T_c);
//	//BGP_Choose(i);
//
//
//	for (i = B_i; i < B_n; i++)
//	{
//		flag = 1;
//		if (!strcmp(T_c, Bidder[i].B_size))
//		{
//			if (Bidder[i].B_H_Price == 1)printf("\t\t\t\t\t\t\t\t������Ʒ֧����߼�����߼ۣ�%d\n", Bidder[i].B_H_Price);
//			else printf("\t\t\t\t\t\t\t\t������Ʒ��֧��һ�ڼ�\n");
//			if (Bidder[i].M_M == 1)printf("\t\t\t\t\t\t\t\t��Ʒ������ʽΪ ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������ʽΪ ä��\n");
//			if (Bidder[i].Z_F == 1)printf("\t\t\t\t\t\t\t\t��������Ϊ �۸��ߵã�\n");
//			else printf("\t\t\t\t\t\t\t\t��������Ϊ �۵��ߵã�\n");
//			if (Bidder[i].B_New_old)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			cout << endl;
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���֣� %s\n", Bidder[i].B_Name);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %s\n", Bidder[i].B_Desc);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ͣ� %s\n", Bidder[i].B_size);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ļۣ� %d\n", Bidder[i].B_Price);
//			printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %d\n", Bidder[i].B_weight);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t������Ʒ��ʼ����ʱ�� ��%04d %02d %02d %02d %02d %02d\n", Bidder[i].B_Time.Year, Bidder[i].B_Time.Month, Bidder[i].B_Time.Day, Bidder[i].B_Time.Hour, Bidder[i].B_Time.Min, Bidder[i].B_Time.Sec);
//			cout << endl;
//			cout << endl;
//			cout << endl;
//
//
//		}
//	}
//	if (!flag) printf("\t\t\t\t\t\t\t\tû���ҵ������Ʒ\n");
//	system("pause");
//	system("cls");
//
//
//}
/////��Ҫ�޸� ����ʱ��
//void Pre_Bid(int Ui, int Un)///����Ʒ����ƽ̨������
//{
//	int T_ID, flag = 0, Q = 1, j;
//	Overdue();
//	int B_n = ReadALL_BFile();
//	while (Q)
//	{
//		flag = 0;
//		printf("\t\t\t\t\t\t\t\t������ϣ��������ƽ̨��������Ʒ ��ţ�");
//		scanf("%d", &T_ID);
//		for (j = 0; j < User[Ui].Sum; j++)
//		{
//			if (T_ID == User[Ui].MyGoods[j].G_ID&&User[Ui].MyGoods[j].State != 1)
//				//if(T_ID==User[Ui].MyGoods[j].G_ID)
//			{
//				printf("\t\t\t\t\t\t\t\t�ҵ���Ʒ��\n");
//				printf("\t\t\t\t\t\t\t\t��������Ʒ�������Ϣ:\n");
//				User[Ui].MyGoods[j].State = 1;
//				flag = 1;
//				break;
//			}
//		}
//		if (!flag)
//		{
//			printf("\t\t\t\t\t\t\t\t��Ʒ��Ų����ڣ�\n");
//			printf("\t\t\t\t\t\t\t\t�����Ѿ���ƽ̨��������\n");
//		}
//		else
//		{
//			Bidder[B_n].G_ID = User[Ui].MyGoods[j].G_ID;
//			strcpy(Bidder[B_n].Address, User[Ui].Address);
//			strcpy(Bidder[B_n].Haver, User[Ui].Acc_num);
//			strcpy(Bidder[B_n].B_Desc, User[Ui].MyGoods[j].Desc);
//			strcpy(Bidder[B_n].B_Name, User[Ui].MyGoods[j].G_Name);
//			Bidder[B_n].B_New_old = User[Ui].MyGoods[j].New_old;
//			strcpy(Bidder[B_n].B_size, User[Ui].MyGoods[j].size);
//			Bidder[B_n].B_years = User[Ui].MyGoods[j].years;
//			Bidder[B_n].B_weight = User[Ui].MyGoods[j].weight;
//			Bidder[B_n].B_Price = User[Ui].MyGoods[j].Price;
//
//
//			Bidder[B_n].flag1 = 1;//����
//			Bidder[B_n].flag2 = 0;//��û֧�� ����
//			Bidder[B_n].sum = 0;//
//
//
//			Bidder[B_n].B_H_Price = 0;
//
//
//			printf("\t\t\t\t\t\t\t\t���� ��1�� ����  ��2�� ä��: ");
//			scanf("%d", &Bidder[B_n].M_M);
//
//
//			Bidder[B_n].Z_F = 1;
//
//
//
//
//			Decide_Time(B_n);
//
//
//			system("cls");
//			B_n++;
//		}
//		cout << endl;
//		printf("\t\t\t\t\t\t\t\t1����������ϣ��������ƽ̨��������Ʒ\n");
//		printf("\t\t\t\t\t\t\t\t0���˳�����\n");
//		scanf("%d", &Q);
//	}
//	printf(" %d \n", B_n);
//
//
//	Write_B_inFile(B_n);
//	WriteinFile(Un);
//	//for(int q=0; q<Bn; q++)printf("%s %s\n",Bidder[q].B_Name,Bidder[q].Haver);
//}
/////��Ҫ�޸�
//void Payment(int p)///֧��
//{
//	//��ά��;
//	printf("\n\n\t\t\t\t\t\t\t\t***********  ***** *** * * * **  ***********\n"
//		"\t\t\t\t\t\t\t\t**   *   ** ***   * *   * ** *   **   *   **\n"
//		"\t\t\t\t\t\t\t\t**  ***  ** * ***  **  ***** *** **  ***  **\n"
//		"\t\t\t\t\t\t\t\t**   *   **  ****  *****  ***    **   *   **\n"
//		"\t\t\t\t\t\t\t\t***********   ** **   ****  *    ***********\n"
//		"\t\t\t\t\t\t\t\t * ** ** * *** *****      **** * * * ***** *\n"
//		"\t\t\t\t\t\t\t\t * * ** ** *  *** * ***      ** *** * **  *\n"
//		"\t\t\t\t\t\t\t\t  * ** **   ***  * **   ***  *  ** ** * * *\n"
//		"\t\t\t\t\t\t\t\t**  *** * ***   **   *   ** ** * * ** *    *\n"
//		"\t\t\t\t\t\t\t\t ***   * * * ***       * * ** **    ** * ** \n"
//		"\t\t\t\t\t\t\t\t*   *  * * *** ** *  ***   ** * * *  * ** *\n"
//		"\t\t\t\t\t\t\t\t* **   ** *   ** * *** ** **   *** * * ** ***\n"
//		"\t\t\t\t\t\t\t\t ** **   * ** **    * **** *  **  * * *  * *\n"
//		"\t\t\t\t\t\t\t\t* **  * * ** * * * * ** * * *  *  ** * * * *\n"
//		"\t\t\t\t\t\t\t\t* *      * ****        **** * ** * * ** * **\n "
//		"\t\t\t\t\t\t\t\t* * * * * ***  **   *  *** * ** ** * ** * * \n"
//		"\t\t\t\t\t\t\t\t  * * * ** * ** *  ** * * * * * * ***********\n"
//		"\t\t\t\t\t\t\t\t* ** * ** * * ** **  * ** * * *   **   *   **\n"
//		"\t\t\t\t\t\t\t\t  *    *  ** * * ** *** * * * * * **  ***  **\n"
//		"\t\t\t\t\t\t\t\t* * * ** * * ****  * * * ** * *   **   *   **\n"
//		"\t\t\t\t\t\t\t\t*** * ** * * **  * * * * * * * *  ***********\n");
//	printf("\n\t\t\t\t\t\t\t\t֧����/΢�� ɨһɨ���֧��");
//	Sleep(2000);
//	int Un, Index_B, Index_S, flag1 = 0, flag2 = 0, i, j;
//	Un = UN;
//	for (i = 0; i < Un; i++)
//	{
//		if (!strcmp(User[i].Acc_num, Buyer) && !flag1)
//		{
//			Index_B = i;
//			flag1 = 1;
//		}
//		if (!strcmp(User[i].Acc_num, Seller) && !flag2)
//		{
//			Index_S = i;
//			flag2 = 1;
//		}
//		if (flag1&&flag2)break;
//	}
//	User[Index_B].score += 1;
//	User[Index_S].score += 1;
//	if (User[Index_B].Sum < 20)
//	{
//		//printf(" %d %s \n",User[Index_B].Sum,User[Index_B].Acc_num);
//		///�޸����
//		strcpy(User[Index_B].MyGoods[User[Index_B].Sum].Desc, Bidder[p].B_Desc);
//		strcpy(User[Index_B].MyGoods[User[Index_B].Sum].G_Name, Bidder[p].B_Name);
//		User[Index_B].MyGoods[User[Index_B].Sum].New_old = Bidder[p].B_New_old;
//		strcpy(User[Index_B].MyGoods[User[Index_B].Sum].size, Bidder[p].B_size);
//		User[Index_B].MyGoods[User[Index_B].Sum].Price = Bidder[p].Final_Price;
//		User[Index_B].MyGoods[User[Index_B].Sum].State = 0;
//		User[Index_B].MyGoods[User[Index_B].Sum].flag = 1;
//		User[Index_B].MyGoods[User[Index_B].Sum].weight = Bidder[p].B_weight;
//		User[Index_B].MyGoods[User[Index_B].Sum].years = Bidder[p].B_years;
//
//
//		if (!strcmp(T, Buyer))
//		{
//			printf("\n\t\t\t\t\t\t\t\t�� ����Ʒ �����ţ�");
//			while (1)
//			{
//				int flag3 = 0;
//				scanf("%d", &User[Index_B].MyGoods[User[Index_B].Sum].G_ID);
//				for (int k = 0; k < User[Index_B].Sum; k++)
//				{
//					if (User[Index_B].MyGoods[User[Index_B].Sum].G_ID == User[Index_B].MyGoods[k].G_ID)
//					{
//						flag3 = 1;
//						break;
//					}
//				}
//				if (flag3)printf("\n\t\t\t\t\t\t\t\t����Ѿ����� ���������룺");
//				else break;
//			}
//		}
//		User[Index_B].Sum++;
//	}
//	else printf("\n\t\t\t\t\t\t\t\t���� ���� ֱ������ �û� ��ַ\n");
//	///�޸�����
//	for (j = 0; j <= User[Index_S].Sum; j++)if (User[Index_S].MyGoods[j].G_ID == Bidder[p].G_ID)break;
//	for (; j <= User[Index_S].Sum; j++)User[Index_S].MyGoods[j] = User[Index_S].MyGoods[j + 1];
//	User[Index_S].Sum--;
//
//
//	WriteinFile(Un);
//
//
//	//printf(" %d %s \n",User[Index_B].Sum,User[Index_B].Acc_num);
//
//
//	printf("\n\t\t\t\t\t\t\t\t֧���ɹ���\n");
//	printf("\n\t\t\t\t\t\t\t\t��Ʒ�������� : %s \n", User[Index_B].Address);
//	//printf("\t\t\t\t\t\t\t\t�˳������ �Ϳ��ʹ�\n");
//	system("pause");
//
//
//}
//
//
//void Racket(int p)///����
//{
//	int Un, i, Index_B, Index_S, flag1 = 0, flag2 = 0, j;
//	Un = UN;
//	for (i = 0; i < Un; i++)
//	{
//		if (!strcmp(User[i].Acc_num, Buyer) && !flag1)
//		{
//			Index_B = i;
//			flag1 = 1;
//		}
//		if (!strcmp(User[i].Acc_num, Seller) && !flag2)
//		{
//			Index_S = i;
//			flag2 = 1;
//		}
//		if (flag1&&flag2)break;
//	}
//	///�޸����
//	User[Index_B].score -= 5;
//	printf("\t\t\t\t\t\t\t\t��������ȼ���5��\n");
//	///�޸�����
//	for (j = 0; j <= User[Index_S].Sum; j++)if (User[Index_S].MyGoods[j].G_ID == Bidder[p].G_ID)break;
//	User[Index_S].MyGoods[j].State = 0;//δ�ĳ�
//	WriteinFile(Un);
//
//
//	printf("\n\t\t\t\t\t\t\t\t��Ʒ������\n");
//	system("pause");
//
//
//}
//
//
//void Count_Backwards_time()
//{
//	int Money, choice;
//	if (Bidder[Bi].flag1 == 6)
//	{
//		printf("\t\t\t\t\t\t\t\tһ�ڼ��Ѿ�����, �޷��μӸ���Ʒ����\n");
//		system("pause");
//		return;
//	}
//	if (Time_minus(Bi) <= 60)
//	{
//		SYSTEMTIME sys;
//		GetLocalTime(&sys);
//		printf("\t\t\t\t\t\t\t\t������ʣ��ʱ��: %d  second\n", Rott);
//		printf("\t\t\t\t\t\t\t\tע�⣡��\n");
//		cout << endl;
//		if (Bidder[Bi].B_New_old)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//		else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                  ������Ʒ���֣� %s\n", Bidder[Bi].B_Name);
//		// printf("\t\t\t\t\t\t\t\t*                  ������Ʒ�¾ɣ� %d\n",Bidder[Bi].B_New_old);
//		printf("\t\t\t\t\t\t\t\t*                  ������Ʒ������ %s\n", Bidder[Bi].B_Desc);
//		printf("\t\t\t\t\t\t\t\t*                  ������Ʒ���ͣ� %s\n", Bidder[Bi].B_size);
//		printf("\t\t\t\t\t\t\t\t*                  ������Ʒ������ %d\n", Bidder[Bi].B_weight);
//		printf("\t\t\t\t\t\t\t\t*                  ������Ʒ��ۣ� %d\n", Bidder[Bi].B_Price);
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		if (Bidder[Bi].B_H_Price)printf("һ�ڼ�Ϊ ��%d \n", Bidder[Bi].B_H_Price);
//		cout << endl;
//
//
//		printf("\t\t\t\t\t\t\t\t1������  0���˳�����\n");
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		scanf("%d", &choice);
//		Online_Money(Bidder[Bi].B_H_Price, Bidder[Bi].M_M, Bidder[Bi].Z_F);
//		if (choice)
//		{
//			printf("\t\t\t\t\t\t\t\t�������㾺�ĵļ۸�: ");
//			while (1)
//			{
//				scanf("%d", &Money);
//				if (Money > Bidder[Bi].B_Price&&Money >= 1 && Money <= 99999)break;
//				else printf("\t\t\t\t\t\t\t\t���������� �۸� :");
//			}
//
//
//			Bidder[Bi].sum++;
//			Bidder[Bi].flag1 = 5;
//			strcpy(Bidder[Bi].Mark[Bidder[Bi].sum].Next_Haver_Name, T);
//			Bidder[Bi].Mark[Bidder[Bi].sum].Money = Money;
//
//
//			Bidder[Bi].Mark[Bidder[Bi].sum].Ye = sys.wYear;
//			Bidder[Bi].Mark[Bidder[Bi].sum].Mo = sys.wMonth;
//			Bidder[Bi].Mark[Bidder[Bi].sum].Da = sys.wDay;
//			Bidder[Bi].Mark[Bidder[Bi].sum].Ho = sys.wHour;
//			Bidder[Bi].Mark[Bidder[Bi].sum].Mi = sys.wMinute;
//			Bidder[Bi].Mark[Bidder[Bi].sum].Se = sys.wSecond;
//
//
//
//
//			Online_Money(Bidder[Bi].B_H_Price, 2, Bidder[Bi].Z_F);
//			Bidder[Bi].Final_Price = Bidder[Bi].Mark[F_H].Money;///���ռ�
//			strcpy(Bidder[Bi].Ber, Bidder[Bi].Mark[F_H].Next_Haver_Name);
//
//
//			//printf("%d\n",Bidder[Bi].sum);
//			//printf("%s\n",Bidder[Bi].Mark[Bidder[Bi].sum].Next_Haver_Name);
//			//printf("%d\n",Bidder[Bi].Mark[Bidder[Bi].sum].Money);
//			Write_B_inFile(Bn);
//			printf("\t\t\t\t\t\t\t\tOK\n");
//			return;
//		}
//		else if (!choice)return;
//	}
//}
//
//
//void Waiting_Time()///�ȴ�ʱ��
//{
//	//printf("ע�� ���������������˳�\n");
//	if (Time_minus(Bi) < 60 && Time_minus(Bi) > 0)
//	{
//		Count_Backwards_time();
//		return;
//	}
//	else
//	{
//		while (Time_minus(Bi) < 0)
//		{
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                  �ȴ�������ʼ                          *\n");
//			printf("\t\t\t\t\t\t\t\t*                  ���� %d ��                            *\n", abs(Time_minus(Bi)));
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			system("pause");
//			system("cls");
//		}
//		printf("\t\t\t\t\t\t\t\t      ������ʼ\n");
//		printf("\t\t\t\t\t\t\t\t���� %d �� \n", Rott);
//		Count_Backwards_time();
//		return;
//	}
//
//
//}
//
//
/////��Ҫ�޸�
//void Overdue()///����û��Ҫ�Ķ���
//{
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	int i, B_n, j, k, count = 0;
//	B_n = ReadALL_BFile();
//	if (Bidder[0].B_Name[0] == '\0')return;
//	for (j = 0; j < B_n; j++)
//	{
//		if (Time_minus(j) < 60)break;
//	}
//	for (i = 0; i < j; i++)
//	{
//		//if(Time_minus(i)<60)break;
//		Bidder[i].flag1 = 2;
//		if (Bidder[i].sum >= 1 && Bidder[i].flag1 != 6)Bidder[i].flag1 = 3;
//	}
//
//
//	for (k = j; k < B_n; k++)
//	{
//		Bidder[k].NUM = count++;
//		//printf("  Ok  %d %s \n",Bidder[k].NUM,Bidder[k].B_Name);
//	}
//	//printf("OK\n");
//	Write_B_inFile(B_n);
//}
//
//
//void Back_Bag()///�ص�����
//{
//	int Un, B_n, B_i;
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//	Un = Read_U_All_File();
//	//printf("%d  \n",B_i);
//	for (int i = 0; i < B_i; i++)
//	{
//		if (Bidder[i].flag1 == 2)
//		{
//			for (int j = 0; j < Un; j++)
//			{
//				if (!strcmp(Bidder[i].Haver, User[j].Acc_num))
//				{
//					for (int k = 0; k < User[j].Sum; k++)
//					{
//						if (Bidder[i].G_ID == User[j].MyGoods[k].G_ID)
//						{
//							User[j].MyGoods[k].State = 0;
//							Bidder[i].flag1 = 4;
//						}
//					}
//				}
//			}
//		}
//	}
//	WriteinFile(Un);
//	Write_B_inFile(B_n);
//}
//
//
/////��Ҫ�޸�
//int Online_Money(int P, int flag1, int flag2)///���ϼ�Ǯ
//{
//	int Highest = 0, Lowest = 100000, i;
//	i = Bidder[Bi].sum;
//	//printf("%d\n",i);
//	if (!i)
//	{
//		printf("\t\t\t\t\t\t\t\tĿǰû�м۸���Ϣ\n");
//		return 0;
//	}
//	if (P)
//	{
//		if (flag1 == 1)//����
//		{
//			if (flag2 == 1)//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money >= P)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//						return 1;
//						break;
//					}
//					else if (Bidder[Bi].Mark[k].Money > Highest)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("\t\t\t\t\t\t\t\tĿǰ��߼۸���: %d \n", Highest);
//			}
//			else//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money <= P)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//						return 1;
//						break;
//					}
//					if (Bidder[Bi].Mark[k].Money < Lowest)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("Ŀǰ��ͼ۸���: %d \n", Lowest);
//			}
//		}
//		else//ä��
//		{
//			if (flag2 == 1)//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money >= P)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//						return 1;
//						break;
//					}
//					if (Bidder[Bi].Mark[k].Money > Highest)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//			}
//			else//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money <= P)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//						return 1;
//						break;
//					}
//					if (Bidder[Bi].Mark[k].Money < Lowest)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//			}
//		}
//	}
//	else//����߼�
//	{
//		if (flag1 == 1)//����
//		{
//			if (flag2 == 1)//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money > Highest)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("\t\t\t\t\t\t\t\tĿǰ��߼۸���: %d \n", Highest);
//			}
//			else//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money < Lowest)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("Ŀǰ��ͼ۸���: %d \n", Lowest);
//			}
//		}
//		else
//		{
//			if (flag2 == 1)//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money > Highest)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//			}
//			else//����
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money < Lowest)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//
//int Time_minus(int p)///ʱ���
//{
//	long long t1;
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	int MONTH[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int YEAR, day, day2, i;
//	if ((Bidder[p].B_Time.Year % 4 == 0 && Bidder[p].B_Time.Year % 100 != 0) || Bidder[p].B_Time.Year % 400 == 0)YEAR = 366;
//	else YEAR = 365;
//
//
//	day = 0, day2 = 0;
//	for (i = 0; i < sys.wMonth; i++)day += MONTH[i];
//	if (sys.wMonth > 2)day++;
//	day += sys.wDay;
//
//
//	for (i = 0; i < Bidder[p].B_Time.Month; i++)day2 += MONTH[i];
//	if (Bidder[p].B_Time.Month > 2)day2++;
//	day2 += Bidder[p].B_Time.Day;
//
//
//	t1 = (sys.wYear - Bidder[p].B_Time.Year)*YEAR * 24 * 60 + (day - day2) * 24 * 60 * 60 + (sys.wHour - Bidder[p].B_Time.Hour) * 60 * 60 + (sys.wMinute - Bidder[p].B_Time.Min) * 60 + (sys.wSecond - Bidder[p].B_Time.Sec);
//
//
//	if (t1 == 0)Rott = 60;
//	else if (t1 > 0 && t1 < 60)Rott = 60 - t1;
//	return t1;
//}
//
//
/////�޸�
//void Decide_Time(int B_n)///����ʱ��
//{
//	int MONTH[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	if (!B_n)
//	{
//		Bidder[B_n].B_Time.Year = sys.wYear;
//		Bidder[B_n].B_Time.Month = sys.wMonth;
//		Bidder[B_n].B_Time.Day = sys.wDay;
//		Bidder[B_n].B_Time.Hour = sys.wHour;
//		Bidder[B_n].B_Time.Min = sys.wMinute;
//		Bidder[B_n].B_Time.Sec = sys.wSecond;
//	}
//	else
//	{
//		if (Time_minus(B_n - 1) > 60)
//		{
//			Bidder[B_n].B_Time.Year = sys.wYear;
//			Bidder[B_n].B_Time.Month = sys.wMonth;
//			Bidder[B_n].B_Time.Day = sys.wDay;
//			Bidder[B_n].B_Time.Hour = sys.wHour;
//			Bidder[B_n].B_Time.Min = sys.wMinute;
//			Bidder[B_n].B_Time.Sec = sys.wSecond;
//		}
//		else
//		{
//			Bidder[B_n].B_Time.Year = Bidder[B_n - 1].B_Time.Year;
//			Bidder[B_n].B_Time.Month = Bidder[B_n - 1].B_Time.Month;
//			Bidder[B_n].B_Time.Day = Bidder[B_n - 1].B_Time.Day;
//			Bidder[B_n].B_Time.Hour = Bidder[B_n - 1].B_Time.Hour;
//			Bidder[B_n].B_Time.Min = Bidder[B_n - 1].B_Time.Min + 1;
//			Bidder[B_n].B_Time.Sec = Bidder[B_n - 1].B_Time.Sec + 20;
//
//
//			if (Bidder[B_n].B_Time.Sec >= 60)
//			{
//				Bidder[B_n].B_Time.Sec -= 60;
//				Bidder[B_n].B_Time.Min++;
//			}
//
//
//			if (Bidder[B_n].B_Time.Min >= 60)
//			{
//				Bidder[B_n].B_Time.Min -= 60;
//				Bidder[B_n].B_Time.Hour++;
//			}
//			if (Bidder[B_n].B_Time.Hour >= 24)
//			{
//				Bidder[B_n].B_Time.Hour -= 24;
//				Bidder[B_n].B_Time.Day++;
//			}
//			if (((Bidder[B_n].B_Time.Year % 4 == 0 || Bidder[B_n].B_Time.Year % 100 != 0) && Bidder[B_n].B_Time.Year % 400 == 0) && Bidder[B_n].B_Time.Month == 2)
//			{
//				if (Bidder[B_n].B_Time.Day >= MONTH[Bidder[B_n].B_Time.Month] + 1)
//				{
//					Bidder[B_n].B_Time.Day = 1;
//					Bidder[B_n].B_Time.Month++;
//				}
//			}
//			else if (Bidder[B_n].B_Time.Day >= MONTH[Bidder[B_n].B_Time.Month])
//			{
//				Bidder[B_n].B_Time.Day = 1;
//				Bidder[B_n].B_Time.Month++;
//			}
//			if (Bidder[B_n].B_Time.Month >= 12)
//			{
//				Bidder[B_n].B_Time.Month = 1;
//				Bidder[B_n].B_Time.Year++;
//			}
//		}
//	}
//	//for(int k=0; k<=B_n; k++)
//	//{
//	//printf("%04d %02d %02d %02d %02d %02d \n",Bidder[k].B_Time.Year,Bidder[k].B_Time.Month,Bidder[k].B_Time.Day,Bidder[k].B_Time.Hour,Bidder[k].B_Time.Min,Bidder[k].B_Time.Sec);
//	//}
//	system("pause");
//
//
//}
//
//
//void Watch_Bag()///����������ʲô��Ʒ
//{
//	int i, n, choice3;
//	//n=Read_U_All_File();
//	//i=Read_U_Part_File(n);
//	n = UN;
//	i = UI;
//	while (1)
//	{
//		//n=Read_U_All_File();
//		//i=Read_U_Part_File(n);
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                  6������Ʒ��������ƽ̨������           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  7��������Ʒ                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  8��ɾ����Ʒ                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  9���鿴���޸���Ʒ��Ϣ                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                  10��ɾ��������Ʒ����                  *\n");
//		printf("\t\t\t\t\t\t\t\t*                  3��������һ��                         *\n");
//		printf("\t\t\t\t\t\t\t\t*                  5���˳�����                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		scanf("%d", &choice3);
//		system("CLS");
//		if (choice3 == 3)break;
//		switch (choice3)
//		{
//		case 6:
//			Pre_Bid(i, n);
//			break;
//		case 7:
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                0���������м�������Ʒ����               *\n");
//			printf("\t\t\t\t\t\t\t\t*                3��������һ����                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice3);
//			if (choice3 == 3)break;
//			while (1)
//			{
//				Add_Goods(i, n);
//				system("CLS");
//				//printf("\t\t\t\t\t\t\t\t�ף����Ѿ����������Ʒ���� \n");
//				system("pause");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                  3��������һ��                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                  5���˳�����                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice3);
//				system("CLS");
//				if (choice3 == 3)break;
//				switch (choice3)
//				{
//				case 5:
//					exit(0);
//				}
//			}
//			break;
//		case 8:
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                  0����������ɾ����Ʒ����               *\n");
//			printf("\t\t\t\t\t\t\t\t*                  3��������һ��                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice3);
//			system("CLS");
//			if (choice3 == 3)break;
//			while (1)
//			{
//				Del_Goods(i, n);
//				//printf("\t\t\t\t\t\t\t\t�ף����Ѿ����ɾ����Ʒ���� \n");
//				system("pause");
//				system("CLS");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                  3��������һ��                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                  5���˳�����                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice3);
//				if (choice3 == 3)break;
//				switch (choice3)
//				{
//				case 5:
//					exit(0);
//				}
//			}
//		case 9:
//			GoodTraverse(i, n);
//			break;
//		case 10:
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                  0����������ɾ��������Ʒ����           *\n");
//			printf("\t\t\t\t\t\t\t\t*                  3��������һ��                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice3);
//			system("CLS");
//			if (choice3 == 3)break;
//			Del_Auction();
//			break;
//		case 5:
//			exit(0);
//		default:
//			break;
//		}
//	}
//}
//
//
//void Del_Auction()
//{
//	int Ui, Un, B_i, B_n, i, j, ID;
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//
//
//	//Un=Read_U_All_File();
//	//Ui=Read_U_Part_File(Un);
//	Un = UN;
//	Ui = UI;
//	printf("\t\t\t\t\t\t\t\t�����������¼���Ʒ�� ��ţ�");
//	scanf("%d", &ID);
//	for (i = B_i; i < B_n; i++)
//	{
//		if (Bidder[i].G_ID == ID && !strcmp(Bidder[i].Haver, T))break;
//	}
//	if (Time_minus(i) < -120)
//	{
//		for (int k = 0; k < User[Ui].Sum; k++)
//		{
//			if (User[Ui].MyGoods[k].G_ID == ID)
//			{
//				User[Ui].MyGoods[k].State = 0;
//				printf(" %s \n", User[Ui].MyGoods[k].G_Name);
//				break;
//			}
//		}
//		for (j = i; j < B_n; j++)Bidder[j] = Bidder[j + 1];
//		User[Ui].score = User[Ui].score - 2;
//		//CLear_File();
//		B_n--;
//		WriteinFile(Un);
//		Write_B_inFile(B_n);
//		printf("\t\t\t\t\t\t\t\t�ף����Ѿ����ɾ��������Ʒ���� \n");
//
//
//	}
//	else printf("\t\t\t\t\t\t\t\t����Ʒ׼������ �޷�ɾ��\n");
//	system("pause");
//}
//
//
//void CLear_File()
//{
//	FILE *fp;
//	fp = fopen("Bidder.txt", "wb");
//	fclose(fp);
//}
//
//
//
//
//void I_just_check(int i, int n)///��㷭��������Ʒ
//{
//	int choice, Ui, Un, e;
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             1���� ���� ������Ʒ                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             2���� ��� ������Ʒ                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             3���� �۸� ������Ʒ                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             4���� ��� ������Ʒ                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             5������                                    *\n");
//	printf("\t\t\t\t\t\t\t\t*             6���˳�����                                *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//	printf("\t\t\t\t\t\t\t\t�����룺");
//	scanf("%d", &choice);
//	system("cls");
//	//Un=Read_U_All_File();
//	//Ui=Read_U_Part_File(Un);
//	Un = UN;
//	Ui = UI;
//	if (choice == 5)return;
//	else if (choice == 6)exit(0);
//	else
//	{
//		Quick_Sort(User, Ui, 0, User[Ui].Sum - 1, choice);//����
//		printf("\t\t\t\t\t\t\t\t����������ҵ������Ϣ��");
//		cin >> e;
//		Bin_Search(User, Ui, 0, User[Ui].Sum - 1, choice, e);//���ֲ���
//	}
//	WriteinFile(Un);
//	system("pause");
//	system("cls");
//
//
//}
//
//
//void Quick_Sort(USER User[], int Ui, int left, int right, int choice)///����
//{
//	int i = left, j = right, t;
//	Bag_Goods T;
//	if (choice == 1)//����
//	{
//		t = User[Ui].MyGoods[left].weight;
//		T = User[Ui].MyGoods[left];
//		if (left >= right)return;
//		while (j != i)
//		{
//			while (j > i&&User[Ui].MyGoods[j].weight >= User[Ui].MyGoods[i].weight)j--;
//			if (j > i)User[Ui].MyGoods[i] = User[Ui].MyGoods[j];
//			while (j > i&&t >= User[Ui].MyGoods[i].weight)i++;
//			if (j > i)User[Ui].MyGoods[j] = User[Ui].MyGoods[i];
//		}
//		User[Ui].MyGoods[i] = T;
//		Quick_Sort(User, Ui, left, i - 1, choice);
//		Quick_Sort(User, Ui, i + 1, right, choice);
//	}
//	else if (choice == 2)//���
//	{
//		t = User[Ui].MyGoods[left].years;
//		T = User[Ui].MyGoods[left];
//		if (left >= right)return;
//		while (j != i)
//		{
//			while (j > i&&User[Ui].MyGoods[j].years >= User[Ui].MyGoods[i].years)j--;
//			if (j > i)User[Ui].MyGoods[i] = User[Ui].MyGoods[j];
//			while (j > i&&t >= User[Ui].MyGoods[i].years)i++;
//			if (j > i)User[Ui].MyGoods[j] = User[Ui].MyGoods[i];
//		}
//		User[Ui].MyGoods[i] = T;
//		Quick_Sort(User, Ui, left, i - 1, choice);
//		Quick_Sort(User, Ui, i + 1, right, choice);
//	}
//	else if (choice == 3)//�۸�
//	{
//		t = User[Ui].MyGoods[left].Price;
//		T = User[Ui].MyGoods[left];
//		if (left >= right)return;
//		while (j != i)
//		{
//			while (j > i&&User[Ui].MyGoods[j].Price >= User[Ui].MyGoods[i].Price)j--;
//			if (j > i)User[Ui].MyGoods[i] = User[Ui].MyGoods[j];
//			while (j > i&&t >= User[Ui].MyGoods[i].Price)i++;
//			if (j > i)User[Ui].MyGoods[j] = User[Ui].MyGoods[i];
//		}
//		User[Ui].MyGoods[i] = T;
//		Quick_Sort(User, Ui, left, i - 1, choice);
//		Quick_Sort(User, Ui, i + 1, right, choice);
//	}
//	else if (choice == 4)//���
//	{
//		t = User[Ui].MyGoods[left].G_ID;
//		T = User[Ui].MyGoods[left];
//		if (left >= right)return;
//		while (j != i)
//		{
//			while (j > i&&User[Ui].MyGoods[j].G_ID >= User[Ui].MyGoods[i].G_ID)j--;
//			if (j > i)User[Ui].MyGoods[i] = User[Ui].MyGoods[j];
//			while (j > i&&t >= User[Ui].MyGoods[i].G_ID)i++;
//			if (j > i)User[Ui].MyGoods[j] = User[Ui].MyGoods[i];
//		}
//		User[Ui].MyGoods[i] = T;
//		Quick_Sort(User, Ui, left, i - 1, choice);
//		Quick_Sort(User, Ui, i + 1, right, choice);
//
//
//	}
//
//
//}
//
//
//void Bin_Search(USER User[], int Ui, int left, int right, int choice, int e)///���ֲ���
//{
//	int i = left, j = right, mid, flag = 0;
//	if (choice == 1)//����
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].weight)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t���ҳɹ�\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//
//
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].weight)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].weight)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid + 1);
//					}
//				}
//				break;
//			}
//			if (e > User[Ui].MyGoods[mid].weight)i = mid + 1;
//			else j = mid - 1;
//		}
//		if (!flag)
//		{
//			printf("\t\t\t\t\t\t\t\t����ʧ��\n");
//		}
//	}
//	else if (choice == 2)//���
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].years)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t���ҳɹ�\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].years)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].years)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid + 1);
//					}
//				}
//				break;
//			}
//			if (e > User[Ui].MyGoods[mid].years)i = mid + 1;
//			else j = mid - 1;
//		}
//		if (!flag)
//		{
//			printf("   %d\n", mid);
//			printf("\t\t\t\t\t\t\t\t����ʧ��\n");
//		}
//	}
//	else if (choice == 3)//�۸�
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].Price)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t���ҳɹ�\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].Price)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].Price)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid + 1);
//					}
//				}
//				break;
//			}
//			if (e > User[Ui].MyGoods[mid].Price)i = mid + 1;
//			else j = mid - 1;
//		}
//		if (!flag)
//		{
//			printf("\t\t\t\t\t\t\t\t����ʧ��\n");
//		}
//	}
//	else if (choice == 4)//���
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].G_ID)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t���ҳɹ�\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].G_ID)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].G_ID)
//					{
//						printf("\t\t\t\t\t\t\t\t������Ʒ������Ϣ��\n");
//						Revise_Part_G(Ui, mid + 1);
//					}
//				}
//				break;
//			}
//			if (e > User[Ui].MyGoods[mid].G_ID)i = mid + 1;
//			else j = mid - 1;
//		}
//		if (!flag)
//		{
//			printf("\t\t\t\t\t\t\t\t����ʧ��\n");
//
//
//		}
//	}
//}
//
//
//void Rank_Quick_Sort(RANK Rank[], int left, int right)///���а�
//{
//	int i = left, j = right, t = Rank[i].score;
//	RANK T = Rank[left];
//	if (left >= right)return;
//	while (i < j)
//	{
//		while (i < j&&Rank[i].score >= Rank[j].score)j--;
//		if (i < j)Rank[i] = Rank[j];
//		while (i < j&&t <= Rank[i].score)i++;
//		if (i < j)Rank[j] = Rank[i];
//	}
//	Rank[i] = T;
//	Rank_Quick_Sort(Rank, left, i - 1);
//	Rank_Quick_Sort(Rank, i + 1, right);
//}
//
//
//void Revise_Part_G(int Ui, int mid)///�鿴��һ��Ʒ
//{
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t��Ʒ ��ţ�%d \n", User[Ui].MyGoods[mid].G_ID);
//	printf("\t\t\t\t\t\t\t\t��Ʒ���֣�%s\n", User[Ui].MyGoods[mid].G_Name);
//	if (User[Ui].MyGoods[mid].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//	else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//
//
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*           ��Ʒ������%s\n", User[Ui].MyGoods[mid].Desc);
//	printf("\t\t\t\t\t\t\t\t*           ��Ʒ���ͣ�%s\n", User[Ui].MyGoods[mid].size);
//	printf("\t\t\t\t\t\t\t\t*           ��Ʒ���ۣ�%d\n", User[Ui].MyGoods[mid].Price);
//	printf("\t\t\t\t\t\t\t\t*           ��Ʒ������%d\n", User[Ui].MyGoods[mid].weight);
//	printf("\t\t\t\t\t\t\t\t*           ��Ʒ��ݣ�%d\n", User[Ui].MyGoods[mid].years);
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	if (User[Ui].MyGoods[mid].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//	else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//	cout << endl;
//}
//
//
//void Revise_G_ID(int i, int n)///����Ʒ��Ų�ѯ
//{
//	int T_ID;
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t�����������ѯ������� ��Ʒ���:\n");
//	scanf("%d", &T_ID);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (T_ID == User[i].MyGoods[k].G_ID)
//		{
//			printf("\t\t\t\t\t\t\t\t��Ʒ���֣�%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_Name(int i, int n)///����Ʒ���ֲ�ѯ
//{
//	char T_Name[20];
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t�����������ѯ������� ��Ʒ���ƣ�");
//	scanf("%s", T_Name);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (!strcmp(T_Name, User[i].MyGoods[k].G_Name))
//		{
//			printf("\t\t\t\t\t\t\t\t��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("������Ʒ�¾ɣ� ��\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_New_Old(int i, int n)///����Ʒ�¾ɲ�ѯ
//{
//	int choice;
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t1���� ����Ʒ ������\n");
//	printf("\t\t\t\t\t\t\t\t2���� ����Ʒ ������\n");
//	printf("\t\t\t\t\t\t\t\t�����룺");
//	scanf("%d", &choice);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (choice == User[i].MyGoods[k].New_old)
//		{
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ���ƣ�%s\n", User[i].MyGoods[k].G_Name);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*           ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_State(int i, int n)///����Ʒ������ѯ
//{
//	int choice;
//
//
//	printf("\t\t\t\t\t\t\t\t1����ӡ������Ʒ\n");
//	printf("\t\t\t\t\t\t\t\t0����ӡ��������Ʒ\n\t\t\t\t\t\t\t\t�����룺\n");
//	scanf("%d", &choice);
//	cout << endl;
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (User[i].MyGoods[k].State == choice)
//		{
//			printf("\t\t\t\t\t\t\t\t��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t��Ʒ���ƣ�%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*          ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_All_G(int i, int n)///�鿴������Ʒ
//{
//
//
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		cout << endl;
//		printf("\t\t\t\t\t\t\t\t��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//		printf("\t\t\t\t\t\t\t\t��Ʒ���ƣ�%s\n", User[i].MyGoods[k].G_Name);
//		if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//		else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//		printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//		printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//		printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//		printf("\t\t\t\t\t\t\t\t*         ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//		else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//		cout << endl;
//		cout << endl;
//	}
//}
//
//
//void Revise_G_size(int i, int n)///��Ʒ����
//{
//
//
//	char T_size[40];
//	printf("\t\t\t\t\t\t\t\t��������Ʒ�� ����: ");
//	scanf("%s", T_size);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (!strcmp(T_size, User[i].MyGoods[k].size))
//		{
//			cout << endl;
//			printf("\t\t\t\t\t\t\t\t��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t��Ʒ���ƣ�%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*             ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*             ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*             ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*             ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*             ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//			cout << endl;
//			cout << endl;
//		}
//	}
//}
//
//
//void GoodTraverse(int i, int n)///�鿴��Ʒ
//{
//	system("cls");
//	int choice, choice2;
//	printf("\t\t\t\t\t\t\t\tĿǰ��ӵ�� %d ��Ʒ\n", User[i].Sum);
//	if (!User[i].Sum)printf("\t\t\t\t\t\t\t\t����Ϊ�գ����Է��ؽ��������Ʒ����\n");
//	else
//	{
//		while (1)
//		{
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                0�������鿴�޸���Ʒ                     *\n");
//			printf("\t\t\t\t\t\t\t\t*                3������                                 *\n");
//			printf("\t\t\t\t\t\t\t\t*                5���˳�����                             *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice);
//			if (choice == 3)break;
//			switch (choice)
//			{
//			case 5:
//				exit(0);
//			case 0:
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*              1���� ��Ʒ��� ����ѯ                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              2���� ��Ʒ���� ����ѯ                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              3���� ��Ʒ�¾� ����ѯ                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              4���� ��Ʒ���� ���� ����ѯ                *\n");
//				printf("\t\t\t\t\t\t\t\t*              5������Ʒ ���� ����ѯ                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              6����ѯ ���� ��Ʒ                         *\n");
//				printf("\t\t\t\t\t\t\t\t*              7������ ���� ��Ʒ                         *\n");
//				printf("\t\t\t\t\t\t\t\t*              8���޸���Ʒ��Ϣ                           *\n");
//				printf("\t\t\t\t\t\t\t\t*              9����ѯ �����õ��� ��Ʒ                   *\n");
//				printf("\t\t\t\t\t\t\t\t*              10������                                  *\n");
//				printf("\t\t\t\t\t\t\t\t*              11���˳�����                              *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice2);
//				switch (choice2)
//				{
//				case 1:
//					Revise_G_ID(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 2:
//					Revise_G_Name(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 3:
//					Revise_G_New_Old(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 4:
//					Revise_G_State(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 6:
//					Revise_All_G(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 5:
//					Revise_G_size(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 7:
//					I_just_check(i, n);
//					system("PAUSE");
//					system("cls");
//					break;
//				case 8:
//					Change_Good(i, n);//�ı���Ʒ��Ϣ
//					system("PAUSE");
//					system("cls");
//					break;
//				case 9:
//					Flag_Good(i, n);//�����õ�����Ʒ
//					system("PAUSE");
//					system("cls");
//					break;
//				case 10:
//					break;
//				case 11:
//					exit(0);
//				default:
//					break;
//				}
//			}
//		}
//	}
//}
//
//
//void Flag_Good(int i, int n)
//{
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (User[i].MyGoods[k].flag)
//		{
//			cout << endl;
//			printf("\t\t\t\t\t\t\t\t��Ʒ��ţ�%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t��Ʒ���ƣ�%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			else printf("\t\t\t\t\t\t\t\t������Ʒ�¾ɣ� ��\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ͣ�%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ���ۣ�%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ������%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*         ��Ʒ��ݣ�%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t��Ʒ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������\n");
//			cout << endl;
//			cout << endl;
//		}
//
//
//	}
//}
//
//
//void Change_Good(int i, int n)
//{
//	int Ui = i, Un = n, e, j, flag = 0;
//	printf("\t\t\t\t\t\t\t\t����������ı���Ϣ�� ��Ʒ ��ţ�");
//	scanf("%d", &e);
//	for (j = 0; j < User[Ui].Sum; j++)
//	{
//		if (User[Ui].MyGoods[j].G_ID == e)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\tû�и���Ʒ\n");
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ�����֣�");
//		scanf("%s", User[Ui].MyGoods[j].G_Name);
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ��������");
//		scanf("%s", User[Ui].MyGoods[j].Desc);
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ�����");
//		scanf("%s", User[Ui].MyGoods[j].size);
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ�Ĺ��ۣ�");
//		scanf("%d", &User[Ui].MyGoods[j].Price);
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ����ݣ�");
//		scanf("%d", &User[Ui].MyGoods[j].years);
//		printf("\t\t\t\t\t\t\t\t��������������Ʒ����������λ �ˣ���");
//		scanf("%d", &User[Ui].MyGoods[j].weight);
//		User[Ui].MyGoods[j].State = 0;
//		printf("\t\t\t\t\t\t\t\t�޸ĳɹ�\n");
//	}
//	WriteinFile(Un);
//
//
//}
//
//
//void Del_Goods(int i, int n)///ɾ����Ʒ
//{
//	//USER User[100];
//	//printf(" 111  \n");
//	int j, flag;
//	int T_ID;
//	T_G *p, *p1, *head = NULL, *tail = NULL, *p2 = NULL;//T_G
//
//
//	for (j = User[i].Sum; j >= 0; j--)
//	{
//		p = (T_G*)malloc(sizeof(T_G));
//		p->G_ID = User[i].MyGoods[User[i].Sum - j].G_ID;
//		strcpy(p->G_Name, User[i].MyGoods[User[i].Sum - j].G_Name);
//		p->New_old = User[i].MyGoods[User[i].Sum - j].New_old;
//		strcpy(p->Desc, User[i].MyGoods[User[i].Sum - j].Desc);
//		p->Price = User[i].MyGoods[User[i].Sum - j].Price;
//		p->years = User[i].MyGoods[User[i].Sum - j].years;
//		strcpy(p->size, User[i].MyGoods[User[i].Sum - j].size);
//		p->weight = User[i].MyGoods[User[i].Sum - j].weight;
//		p->State = User[i].MyGoods[User[i].Sum - j].State;
//		p->next = NULL;
//		if (j == User[i].Sum)head = p;
//		else tail->next = p;
//		tail = p;
//	}
//	printf("\t\t\t\t\t\t\t\t��������ɾ����Ʒ�� ��ţ�");
//	scanf("%d", &T_ID);
//	p1 = head;
//	while (p1)
//	{
//		flag = 0;
//		if (p1->G_ID == T_ID)
//		{
//			if (p1->State == 1)
//			{
//				flag = 2;
//				break;
//			}
//			if (p1 == head)
//			{
//				head = head->next;
//				free(p1);
//				flag = 1;
//				break;
//			}
//			else
//			{
//				p2->next = p1->next;
//				flag = 1;
//				free(p1);
//				break;
//			}
//		}
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\t����ɾ������Ʒ������ \n\t\t\t\t\t\t\t\t���˳����� ����ȷ����Ʒ��Ϣ\n");
//	else if (flag == 2)printf("\t\t\t\t\t\t\t\t����ɾ������Ʒ������ \n\t\t\t\t\t\t\t\t������ɾ����Ʒ��Ϣ\n");
//
//
//	else
//	{
//		printf("\t\t\t\t\t\t\t\tɾ��  ��Ʒ �ɹ���\n");
//		User[i].Sum--;
//	}
//	p1 = head;
//	j = 0;
//	while (p1)
//	{
//		strcpy(User[i].MyGoods[j].Desc, p1->Desc);
//		strcpy(User[i].MyGoods[j].G_Name, p1->G_Name);
//		User[i].MyGoods[j].New_old = p1->New_old;
//		strcpy(User[i].MyGoods[j].size, p1->size);
//		User[i].MyGoods[j].G_ID = p1->G_ID;
//		User[i].MyGoods[j].weight = p1->weight;
//		User[i].MyGoods[j].Price = p1->Price;
//		User[i].MyGoods[j].State = p1->State;
//		User[i].MyGoods[j].years = p1->years;
//		j++;
//		p1 = p1->next;
//	}
//	WriteinFile(n);
//}
//
//
//void Add_Goods(int i, int n)///������Ʒ
//{
//	T_G *p, *head = NULL, *tail = NULL, *p1, *p2 = NULL;
//	int j;
//	n = Read_U_All_File();
//	i = Read_U_Part_File(n);
//	//printf("  %d  \n",User[i].Sum);
//	if (User[i].Sum == 20)
//	{
//		printf("\t\t\t\t\t\t\t\t��������!\n");
//		printf("\t\t\t\t\t\t\t\t���Ƚ�������������Ʒ�ӱ����¼�\n");
//		system("pause");
//		return;
//	}
//	for (j = 0; j < User[i].Sum; j++)
//	{
//		p = (T_G*)malloc(sizeof(T_G));
//		p->G_ID = User[i].MyGoods[j].G_ID;
//		//printf(" %d \n",p->G_ID);
//		strcpy(p->G_Name, User[i].MyGoods[j].G_Name);
//		p->New_old = User[i].MyGoods[j].New_old;
//		strcpy(p->Desc, User[i].MyGoods[j].Desc);
//		p->Price = User[i].MyGoods[j].Price;
//		//printf(" %lf \n",p->Price);
//		p->years = User[i].MyGoods[j].years;
//		strcpy(p->size, User[i].MyGoods[j].size);
//		p->weight = User[i].MyGoods[j].weight;
//		p->State = User[i].MyGoods[j].State;
//		p->next = NULL;
//		if (!j)head = p;
//		else tail->next = p;
//		tail = p;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t�������Ӽ�����Ʒ��");
//	int m;
//	scanf("%d", &m);
//
//
//	for (j = 0; j < m; j++)
//	{
//		p = (T_G*)malloc(sizeof(T_G));
//		p->next = NULL;
//		if (!User[i].Sum && !j)head = p;
//		else tail->next = p;
//		tail = p;
//		printf("\t\t\t\t\t\t\t\t��%d����Ʒ���:  ", j + 1);
//		while (1)
//		{
//			p1 = head;
//			scanf("%d", &p->G_ID);
//			while (p1 != p)
//			{
//				if (p->G_ID == p1->G_ID&&p1 != p)
//				{
//					printf("\t\t\t\t\t\t\t\t  %d  ", p->G_ID);
//					printf("\t\t\t\t\t\t\t\t��Ʒ����Ѿ����ڣ�\n");
//					printf("\t\t\t\t\t\t\t\t������������Ʒ���:");
//					break;
//				}
//				p1 = p1->next;
//				if (p1 == p)break;
//			}
//			if (p1 == p)break;
//		}
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ����:");
//		scanf("%s", p->G_Name);
//
//
//		printf("\t\t\t\t\t\t\t\t(���� 1�� New or 2�� Old)\n\t\t\t\t\t\t\t\t��Ʒ�¾� :");
//		scanf("%d", &p->New_old);
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ����:");
//		scanf("%s", p->Desc);
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ����:");
//		scanf("%s", p->size);
//
//
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ���:");
//		scanf("%d", &p->years);
//		//printf("  %d ", p->years);
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ����:");
//		while (1)
//		{
//			scanf("%d", &p->Price);
//			if (p->Price > 0 && p->Price < 99999)break;
//			printf("\t\t\t\t\t\t\t\t����۸�����\n");
//			printf("\t\t\t\t\t\t\t\t��������۸�");
//		}
//
//
//		//printf("  %lf ", p->Price);
//
//
//		printf("\t\t\t\t\t\t\t\t��Ʒ��������λ �ˣ�:");
//		scanf("%d", &p->weight);
//		//printf("  %lf ", p->weight);
//
//
//		p->State = 0; //״̬
//		p->flag = 0;
//		cout << endl;
//	}
//	User[i].Sum += m;
//	p1 = head;
//	/*while(p1)
//	{
//		printf("%s \n",p1->G_Name);
//		p1=p1->next;
//	}*/
//	j = User[i].Sum;
//	while (p1)
//	{
//		strcpy(User[i].MyGoods[-j + User[i].Sum].Desc, p1->Desc);
//		strcpy(User[i].MyGoods[-j + User[i].Sum].G_Name, p1->G_Name);
//		User[i].MyGoods[-j + User[i].Sum].New_old = p1->New_old;
//		strcpy(User[i].MyGoods[-j + User[i].Sum].size, p1->size);
//		User[i].MyGoods[-j + User[i].Sum].G_ID = p1->G_ID;
//		User[i].MyGoods[-j + User[i].Sum].weight = p1->weight;
//		User[i].MyGoods[-j + User[i].Sum].Price = p1->Price;
//		User[i].MyGoods[-j + User[i].Sum].State = p1->State;
//		User[i].MyGoods[-j + User[i].Sum].years = p1->years;
//		j--;
//		p2 = p1;
//		p1 = p1->next;
//		free(p2);
//	}
//	WriteinFile(n);
//	printf("\t\t\t\t\t\t\t\t��Ʒ������ɣ�\n");
//	system("Pause");
//}
//
//
//void Revise_User_Info()///�޸��û���Ϣ
//{
//	//USER User[100];
//	//FILE *fp;
//	int i, j, choice3;
//	//j=Read_U_All_File();
//	//i=Read_U_Part_File(j);
//	j = UN;
//	i = UI;
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*                ��Ŀǰ���е���Ϣ��\n");
//	printf("\t\t\t\t\t\t\t\t*                ���֣�%s\n", User[i].Name);
//	printf("\t\t\t\t\t\t\t\t*                �Ա�%s\n", User[i].Sex);
//	printf("\t\t\t\t\t\t\t\t*                �ֻ����룺%s\n", User[i].Pho_num);
//	printf("\t\t\t\t\t\t\t\t*                ���䣺%s\n", User[i].Mail);
//	printf("\t\t\t\t\t\t\t\t*                ����ǩ����%s\n", User[i].Spec);
//	printf("\t\t\t\t\t\t\t\t*                ���룺%s\n", User[i].Password);
//	printf("\t\t\t\t\t\t\t\t*                Ŀǰ������Ʒ������%d\n", User[i].Sum);
//	printf("\t\t\t\t\t\t\t\t*                �����֣�%d \n", User[i].score);
//	printf("\t\t\t\t\t\t\t\t*                ��ַ��%s\n", User[i].Address);
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t������������еĲ���\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*               1���޸��ֻ�����                          *\n");
//	printf("\t\t\t\t\t\t\t\t*               2���޸�����                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               3���޸�����                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               4������ǩ��                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               5���ջ���ַ                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               6��������һ��                            *\n");
//	printf("\t\t\t\t\t\t\t\t*               0���˳�����                              *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t�����룺");
//	scanf("%d", &choice3);
//	if (choice3 == 6)return;
//	switch (choice3)
//	{
//	case 1:
//		system("CLS");
//		Revise_User_Info_Pho_Num(i, j);
//		break;
//	case 2:
//		system("CLS");
//		Revise_User_Info_Mail(i, j);
//		break;
//	case 3:
//		system("CLS");
//		Revise_User_Info_Password(i, j);
//		break;
//	case 4:
//		system("CLS");
//		Revise_User_Info_Spec(i, j);
//		break;
//	case 5:
//		system("CLS");
//		Revise_User_Info_Address(i, j);
//		break;
//	case 0:
//		exit(0);
//	default:
//		break;
//	}
//}
//
//
//void Revise_User_Info_Address(int i, int j)///�޸ĵ�ַ
//{
//	printf("\t\t\t\t\t\t\t\t������������ĵ�ַ: ");
//	scanf("%s", User[i].Address);
//	WriteinFile(j);
//}
//
//
//void Revise_User_Info_Spec(int i, int j)///�޸ĸ���ǩ��
//{
//	printf("\t\t\t\t\t\t\t\t������������ĸ���ǩ��: ");
//	scanf("%s", User[i].Spec);
//	WriteinFile(j);
//}
//
//
//void Revise_User_Info_Password(int i, int j)///�޸�����
//{
//	char T_Password[20];
//	int count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t����������ǰ�����룺");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Password);
//		if (!strcmp(T_Password, User[i].Password))
//		{
//			flag = 0;
//			printf("\t\t\t\t\t\t\t\t���������������:");
//			scanf("%s", T_Password);
//			strcpy(User[i].Password, T_Password);
//			break;
//		}
//		else
//		{
//			printf("\t\t\t\t\t\t\t\t����������� �㻹��%d�λ�����������\n", count);
//			printf("\t\t\t\t\t\t\t\t��������������:");
//		}
//	}
//	if (!flag)
//	{
//		WriteinFile(j);
//		printf("\t\t\t\t\t\t\t\t�޸�����ɹ���\n");
//	}
//	else printf("\t\t\t\t\t\t\t\t�޸�����ʧ��\n");
//	system("PAUSE");
//}
//
//
//void Revise_User_Info_Mail(int i, int j)///�޸�����
//{
//	char T_Mail[20];
//	int k, count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t����������ǰ�����䣺");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Mail);
//		if (!strcmp(T_Mail, User[i].Mail))
//		{
//			printf("\t\t\t\t\t\t\t\t���������µ����䣺");
//			while (1)
//			{
//				scanf("%s", T_Mail);
//				for (k = 0; k <= j; k++)
//				{
//					if (!strcmp(T_Mail, User[k].Mail) && k != i)break;
//				}
//				if (k > j)
//				{
//					printf("\t\t\t\t\t\t\t\t�޸�����ɹ���\n");
//					flag = 0;
//					break;
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\t�����Ѿ���ע�ᣡ\n");
//					printf("\t\t\t\t\t\t\t\t�������������µ����䣺");
//				}
//			}
//		}
//		if (!flag)break;
//		if (flag)printf("\t\t\t\t\t\t\t\t�㻹��%d�λ�����������ǰ������\n", count);
//	}
//	if (flag && !count)printf("\t\t\t\t\t\t\t\t�޸�����ʧ��\n");
//	if (!flag)//�п���bug
//	{
//		strcpy(User[i].Mail, T_Mail);
//		WriteinFile(j);
//		//printf("\t\t\t\t\t\t\t\t�޸�����ɹ�!\n");
//	}
//	system("Pause");
//}
//
//
//void Revise_User_Info_Pho_Num(int i, int j)///�޸��ֻ�����
//{
//	char T_Pho_Num[20];
//	int k, count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t����������ǰ���ֻ����룺");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Pho_Num);
//		if (!strcmp(T_Pho_Num, User[i].Pho_num))
//		{
//			printf("\t\t\t\t\t\t\t\t���������µ��ֻ����룺");
//			while (1)
//			{
//				scanf("%s", T_Pho_Num);
//				for (k = 0; k <= j; k++)
//				{
//					if (!strcmp(T_Pho_Num, User[k].Pho_num) && k != i)break;
//				}
//				if (k > j)
//				{
//					printf("\t\t\t\t\t\t\t\t�޸��ֻ�����ɹ���\n");
//					flag = 0;
//					break;
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\t�ֻ������Ѿ����ڣ�\n");
//					printf("\t\t\t\t\t\t\t\t�������������µ��ֻ����룺");
//				}
//			}
//		}
//		if (!flag)break;
//		if (flag)printf("\t\t\t\t\t\t\t\t�㻹��%d�λ�����������ǰ���ֻ�����\n", count);
//	}
//	if (flag && !count)printf("\t\t\t\t\t\t\t\t�޸��ֻ�����ʧ��\n");
//	if (!flag)//�п���bug
//	{
//		strcpy(User[i].Pho_num, T_Pho_Num);
//		WriteinFile(j);
//		//printf("\t\t\t\t\t\t\t\t�޸��ֻ�����ɹ�!\n");
//	}
//	system("PAUSE");
//}
//
//
//void Register()///ע���˻�
//{
//	//USER User[100];
//	FILE *fp;
//	int i = 0, j, k = 1;
//	if ((fp = fopen("User.txt", "rb")) == NULL)i = 0;
//	else
//	{
//		while (fread(&User[i], sizeof(USER), 1, fp) > 0)i++;
//	}
//	fclose(fp);
//	//printf("   %d     \n",i);
//	if (i >= 100)
//	{
//		printf("\t\t\t\t\t\t\t\t����������\n");
//		printf("\t\t\t\t\t\t\t\t�ȴ�ϵͳ����\n");
//		system("pause");
//		return;
//	}
//	printf("\t\t\t\t\t\t\t\t���������������");
//	scanf("%s", User[i].Name);
//	printf("\t\t\t\t\t\t\t\t����������Ա�");
//	scanf("%s", User[i].Sex);
//
//
//	printf("\t\t\t\t\t\t\t\t����������ֻ����룺");
//	while (k)
//	{
//		scanf("%s", User[i].Pho_num);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Pho_num, User[i].Pho_num))
//			{
//				printf("\t\t\t\t\t\t\t\t�ֻ������Ѿ���ע�ᣡ\n");
//				printf("\t\t\t\t\t\t\t\t�����������ֻ����룺");
//				break;
//			}
//		}
//		if (strlen(User[i].Pho_num) != 11)
//		{
//			k = 1;
//			printf("\t\t\t\t\t\t\t\t�Ƿ��ֻ�����\n\t\t\t\t\t\t\t\t�����������ֻ�����:");
//		}
//		else if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t������������䣺");
//	k = 1;
//	while (k)
//	{
//		scanf("%s", User[i].Mail);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Mail, User[i].Mail))
//			{
//				printf("\t\t\t\t\t\t\t\t�����Ѿ���ע�ᣡ\n");
//				printf("\t\t\t\t\t\t\t\t�������������䣺");
//				break;
//			}
//		}
//		if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t��������ĵ�ַ��");
//	scanf("%s", User[i].Address);
//
//
//
//
//	printf("\t\t\t\t\t\t\t\t��������ĸ���ǩ����");
//	scanf("%s", User[i].Spec);
//
//
//	printf("\t\t\t\t\t\t\t\t����������˺ţ�");
//	k = 1;
//	while (k)
//	{
//		scanf("%s", User[i].Acc_num);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Acc_num, User[i].Acc_num))
//			{
//				printf("\t\t\t\t\t\t\t\t�˺��Ѿ���ע�ᣡ\n");
//				printf("\t\t\t\t\t\t\t\t�����������˺ţ�");
//				break;
//			}
//		}
//		if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t������������룺");
//	//scanf("%s",User[i].Password);
//	Password_Undisplay(User[i].Password);
//
//
//	User[i].Sum = 0;
//	User[i].score = 5;//��������
//	printf("\t\t\t\t\t\t\t\t\n������Ʒ����Ϊ 0\n");
//	printf("\t\t\t\t\t\t\t\t��ʼ�û������Ȼ���Ϊ 5 ��\n");
//	//User[i].MyGoods[1].G_ID=1;
//
//
//	printf("\t\t\t\t\t\t\t\t\nע��ɹ�\n");
//
//
//	if ((fp = fopen("User.txt", "wb")) == NULL)
//	{
//		printf("\t\t\t\t\t\t\t\t�ļ�������\n");
//		exit(0);
//	}
//	for (int j = 0; j <= i; j++)
//	{
//		fwrite(&User[j], sizeof(USER), 1, fp);
//		//printf("%d\n",j);
//	}
//
//
//	fclose(fp);
//
//
//	i = 0;
//	fp = fopen("User.txt", "rb");
//
//
//	while (fread(&User[i], sizeof(USER), 1, fp) > 0)i++;
//
//
//	//printf("%s \n",User[i-1].Name);
//	fclose(fp);
//	printf("Fine\n");
//	//system("CLS");
//
//
//}
//
//
//void Login()///��¼�˻�
//{
//	FILE *fp;
//	//USER User[100];
//	fp = fopen("User.txt", "rb");
//	int i = 0, flag1 = 0, count = 4;
//	printf("\t\t\t\t\t\t\t\t��������� �˺š�������ֻ����룺");
//	int Un = Read_U_All_File();
//	while (count--)
//	{
//		flag1 = 0;
//		scanf("%s", T);
//		for (i = 0; i < Un; i++)
//		{
//			//printf("%s\n",User[i].Name);
//			if (!strcmp(T, User[i].Acc_num))
//			{
//				flag1 = 1;
//				break;
//			}
//			else if (!strcmp(T, User[i].Pho_num))
//			{
//				flag1 = 1;
//				break;
//			}
//			else if (!strcmp(T, User[i].Mail))
//			{
//				flag1 = 1;
//				break;
//			}
//		}
//		if (flag1)break;
//		else printf("\t\t\t\t\t\t\t\t�˺Ų����� �㻹��%d���������˺�\n \t\t\t\t\t\t\t\t������������� �˺š�������ֻ����룺", count);
//	}
//	fclose(fp);
//	if (count == -1)
//	{
//		printf("\n\t\t\t\t\t\t\t\tǿ���˳�������...\n");
//		system("\t\t\t\t\t\t\t\tpause");
//		exit(0);
//	}
//	count = 4;
//	if (flag1)
//	{
//		while (count--)
//		{
//			printf("\t\t\t\t\t\t\t\t������������룺");
//			//scanf("%s",Tpassword);
//			Password_Undisplay(Tpassword);
//			//printf("%s  %s\n",Tpassword,User[i].Password);
//			//system("pause");
//			if (!strcmp(Tpassword, User[i].Password))
//			{
//				system("CLS");
//				Login_welcome();
//				printf("\t\t\t\t\t\t\t\t��ӭ��½ %s\n", User[i].Acc_num);
//				//for(int j=0;j<strlen(User[i].Acc_num);j++)T[j]=User[i].Acc_num[j];
//				strcpy(T, User[i].Acc_num);
//				UN = Un;
//				UI = i;
//				//printf("��ӭ��½ %s\n",T);
//				break;
//			}
//			else
//			{
//				system("CLS");
//				Login_Warning();
//				memset(Tpassword, '\0', sizeof(char));
//				printf("\t\t\t\t\t\t\t\t�������,��������������\n");
//				printf("\t\t\t\t\t\t\t\t�㻹�� %d ���������\n", count);
//			}
//		}
//		//cout<<count<<endl;
//		if (count == -1)exit(0);
//	}
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t�ֻ��绰 �� �û��� �� ���䲻���ڻ����������\n");
//		memset(T, '\0', sizeof(char));
//		//system("pause");
//		system("cls");
//	}
//
//
//}
//
//
//void Cancel()///ע��
//{
//	memset(T, '\0', sizeof(char));
//	memset(Tpassword, '\0', sizeof(char));
//	printf("\t\t\t\t\t\t\t\t���Ѿ��˳����˺���\n");
//	system("pause");
//	system("CLS");
//}
//
//
//void Revise_Online()///ֱ�Ӳ�ѯ
//{
//
//
//	int choice;
//	while (1)
//	{
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                1����ѯ ������Ʒ                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                2����ѯ �û���Ϣ                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                3���鿴 ���а�                          *\n");
//		printf("\t\t\t\t\t\t\t\t*                4������                                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                5���˳�                                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		cin >> choice;
//		if (choice == 4)return;
//		if (choice == 5)exit(0);
//		switch (choice)
//		{
//		case 1:
//			Revise_Online_Good();
//			break;
//		case 2:
//			Revise_Online_User();
//			break;
//		case 3:
//			Revise_Online_Rank();
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//
//void Revise_Online_Good()///ֱ�Ӳ鿴������Ʒ
//{
//	int i, flag = 0;
//	int B_i, B_n;
//	char Bid_Name[20];
//	printf("\t\t\t\t\t\t\t\t������ ���� ��ѯ ��Ʒ�����ƣ�");
//	scanf("%s", Bid_Name);
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//	for (i = B_i; i < B_n; i++)
//	{
//		if (!strcmp(Bid_Name, Bidder[i].B_Name))
//		{
//			flag = 1;
//			printf("\t\t\t\t\t\t\t\t��Ʒ�� �۸����Ϊ��%d \n", Bidder[i].B_Price);
//			if (Bidder[i].B_H_Price == 1)
//			{
//				printf("\t\t\t\t\t\t\t\t��Ʒ֧��һ�ڼ�\n");
//				printf("\t\t\t\t\t\t\t\t��Ʒһ�ڼ� ��%d \n", Bidder[i].B_H_Price);
//			}
//			else  printf("\t\t\t\t\t\t\t\t��Ʒ��֧��һ�ڼ�\n");
//			if (Bidder[i].Z_F == 1)printf("\t\t\t\t\t\t\t\t��Ʒ������ʽ Ϊ ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ������ʽ Ϊ ����\n");
//			if (Bidder[i].M_M == 1)printf("\t\t\t\t\t\t\t\t��Ʒ�۸���Ϣʵʱ����\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ�۸���Ϣ��󹫲�\n");
//
//
//			printf("\t\t\t\t\t\t\t\t��Ʒ���� %d g", Bidder[i].B_weight);
//			printf("\t\t\t\t\t\t\t\t��Ʒ��� %d ", Bidder[i].B_years);
//			if (Bidder[i].B_New_old == 1)printf("\t\t\t\t\t\t\t\t��Ʒ�¾�״������\n");
//			else printf("\t\t\t\t\t\t\t\t��Ʒ�¾�״������\n");
//			printf("\t\t\t\t\t\t\t\t��Ʒ���� :%s \n", Bidder[i].B_Desc);
//
//
//			printf("\t\t\t\t\t\t\t\t��Ʒ���� %04d %02d %02d %02d %02d %02d ��ʼ����\n", Bidder[i].B_Time.Year, Bidder[i].B_Time.Month, Bidder[i].B_Time.Day, Bidder[i].B_Time.Hour, Bidder[i].B_Time.Min, Bidder[i].B_Time.Sec);
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\tû���ҵ������Ʒ\n");
//	else printf("\t\t\t\t\t\t\t\t���ϵ�½ ����������\n");
//	system("pause");
//	system("cls");
//
//
//}
//
//
//void Revise_Online_User()///ֱ�Ӳ鿴�û���Ϣ
//{
//	int Un, flag = 0;
//	char User_Name[20];
//	Un = Read_U_All_File();
//	printf("\t\t\t\t\t\t\t\t������������� �û� ���˺�: ");
//	scanf("%s", User_Name);
//	for (int i = 0; i < Un; i++)
//	{
//		if (!strcmp(User_Name, User[i].Acc_num))
//		{
//			flag = 1;
//			printf("\t\t\t\t\t\t\t\t���û������ȣ�%d\n", User[i].score);
//			printf("\t\t\t\t\t\t\t\t���û�����ǩ��:%s\n", User[i].Spec);
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\tû�и��û���Ϣ\n");
//	system("pause");
//}
//
//
//void Menu()///��ͷĿ¼
//{
//	HANDLE consolehwnd;
//	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
//	for (int j = 7, i = 0; i < 118; i++)
//	{
//		SetConsoleTextAttribute(consolehwnd, j++);
//		if (j == 15)j = 7;
//		cout << " -- ";
//		if (i == 58)cout << endl;
//	}
//	SetConsoleTextAttribute(consolehwnd, 15);
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                       ////////////                                                                                                                                                                                   |||");
//	printf(" |||                                   ///////////////                                                                                                                                                                                    |||");
//	printf(" |||                               //////////////////                                                                                                                                                                                     |||");
//	printf(" |||                            ////////////////////                                                                                                                                                                                      |||");
//	printf(" |||                           ////////////////////                                                                                                                                           SSS                                         |||");
//	printf(" |||                                      ////////                                                                              PPP                 pppppp                               SSSSSSSSSSSSS                                    |||");
//	printf(" |||                                     ////////                     YYYYYYYYYYYYYYYYYYYYYYYYYYYYY                             PPP                pppppp                                SSSSSSSSSSSSS                                    |||");
//	printf(" |||                                    ////////                      YYYYYYYYYYYYYYYYYYYYYYYYYYYYY                             PPP               ppppp                                       SSS                                         |||");
//	printf(" |||                                   ////////                                                                            PPPPPPPPPPPP     PPPPPPPPPPPPPPPPP                SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS                        |||");
//	printf(" |||                                  ////////                                                                             PPPPPPPPPPPP     PPPPPPPPPPPPPPPPP                SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSss                        |||");
//	printf(" |||                                 ////////                                                                                   PPP         PP             PP                                                 SSs                         |||");
//	printf(" |||                                ////////                                                                                    PPP         PP             PP                           SSS   SSS    sss     SSs                          |||");
//	printf(" |||                               ////////                   YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY                    PPP         PP             PP                            SS   SSS   sss     SS                            |||");
//	printf(" |||                              ////////                    YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY                    PPP         PP             PP                      SSS        SSS  sss                                    |||");
//	printf(" |||                             ////////                                YYYY            yyyyy                                  PPP         PP             PP                        SS       SSS ss                                      |||");
//	printf(" |||                            ////////                                 YYYY             yyyy                                  PPPPPPPP    PPPPPPPPPPPPPPPPP                sssSSSSSSSSSSSSSSSSSSSSSSSSSSSsss                            |||");
//	printf(" |||                           ////////                                  YYYY             yyyy                              PPPPPPPPPP      PPPPPPPPPPPPPPPPP                sssSSSSSSSSSSSSSSSSSSSSSSSSSSSsss                            |||");
//	printf(" |||                          ////////                                  YYYY              yyyy                           PPPPPPPPPP         PP             PP                                 SS                                          |||");
//	printf(" |||                         ////////                                  YYYY               yyyy                                  PPP         PP             PP                               ss  Ss                                        |||");
//	printf(" |||                        ////////                                  YYYY                 yyyy                                 PPP         PP             PP                              ss    SS                                       |||");
//	printf(" |||                       ////////                                 YYYY                    yyyy                                PPP         PP             PP                            ss       SS                                      |||");
//	printf(" |||                      ////////                                YYYY                        yyyy  yyyy                        PPP         PP             PP                          ssS         SS                                     |||");
//	printf(" |||                     ////////                               YYYY                            yyyyyyy                         PPP         PP             PP                        ssss           SSS                                   |||");
//	printf(" |||                    ////////                             YYYY                                 yyy                      pp  PPPP         PPPPPPPPPPPPPPPPP                     sssss              SSS                                  |||");
//	printf(" |||                   ////////                                                                                             ppppPPP         PPPPPPPPPPPPPPPPPP                 sssss                  SSSS                                |||");
//	printf(" |||                                                                                                                         pppp                                           sssss                      sSSSss                             |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 1 ��  �û���¼                                                                                                                   |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 2 ��  �û�ע��                                                                                                                   |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 4 ��  ��ѯ                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 5 ��  �˳�                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 6 ��  ����                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  �� 7 ��  ��������                                                                                                                   |||");
//	printf(" |||                                                                                                                                                                                                                                      ||| ");
//	for (int j = 7, i = 0; i < 118; i++)
//	{
//		SetConsoleTextAttribute(consolehwnd, j++);
//		if (j == 15)j = 7;
//		cout << " -- ";
//		if (i == 58)cout << endl;
//	}
//	SetConsoleTextAttribute(consolehwnd, 15);
//}
//
//
//void Help()///����
//{
//	int choice;
//	while (1)
//	{
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                 1��ʹ����֪                            *\n");
//		printf("\t\t\t\t\t\t\t\t*                 2����ȡ��Ʒ                            *\n");
//		printf("\t\t\t\t\t\t\t\t*                 3������                               *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		scanf("%d", &choice);
//		if (choice == 3)break;
//		if (choice == 1)Mannel();//�û��ֲ�
//		if (choice == 2)Receive_rewards();//��ȡ����
//		system("cls");
//	}
//}
//
//
//void Mannel()///�û��ֲ�
//{
//	printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      ��ƽ̨���ڸ����û����������Լ�����Ʒ                     *\n");
//	printf("\t\t\t\t\t\t\t\t*      �����û�ӵ���Լ��ı���                                   *\n");
//	printf("\t\t\t\t\t\t\t\t*      ����������Ϊ20����Ʒ ���Լǵý�������������Ʒ���Ŷ      *\n");
//	printf("\t\t\t\t\t\t\t\t*      �����û�ͨ�����Ļ�� ������ �� ����                      *\n");
//	printf("\t\t\t\t\t\t\t\t*      �෴ �û� ��� ���� ɾ��������Ʒ ������ �� �½�          *\n");
//	printf("\t\t\t\t\t\t\t\t*      ɾ���Լ�������Ʒ �������κ�Ӱ��                          *\n");
//	printf("\t\t\t\t\t\t\t\t*      �����Ȳ������Կ��� ���/���ҵ� ���ų̶�                  *\n");
//	printf("\t\t\t\t\t\t\t\t*      �����Ȼ����Ի�ȡ һ���� ��Ʒ                             *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      ÿ����Ʒ����ʱ���Զ�������Ǯ  �۸��ߵ�                 *\n");
//	printf("\t\t\t\t\t\t\t\t*      ÿ����Ʒ����ʱ  ����һ����Ϣ����Զ��˳�������Ϣ         *\n");
//	printf("\t\t\t\t\t\t\t\t*      ÿ����Ʒ����ʱ  ���� ���� ���� ����                      *\n");
//	printf("\t\t\t\t\t\t\t\t*      ÿ����Ʒ������ʱ��Ϊ 60 ��                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      ������Ʒģʽ Ϊ Frist in Frist out                       *\n");
//	printf("\t\t\t\t\t\t\t\t*      ǰ�澺����Ʒ�Ŀ�ʼʱ�� �� ������Ʒ ��>= 60s              *\n");
//	printf("\t\t\t\t\t\t\t\t*      ��һ����Ʒ��û��ʼ����ʱ ��Ҫ�ȴ�                        *\n");
//	printf("\t\t\t\t\t\t\t\t*      ÿ��������Ʒ���Խ���ɾ�� ����ʱ������                    *\n");
//	printf("\t\t\t\t\t\t\t\t*      ɾ����������Լ��������޸���Ʒ��Ϣ                       *\n");
//	printf("\t\t\t\t\t\t\t\t*      ����۸� ��ΧΪ 1 �� 99999                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      �����ͨ��ע���˺Ž��н�һ�����˽�                       *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      �û� �˺� ���� �Ա�  ����ǩ�� �����Դ�� 16 �ַ�       *\n");
//	printf("\t\t\t\t\t\t\t\t*      �û� �ֻ� һ���� 11 λ ����                              *\n");
//	printf("\t\t\t\t\t\t\t\t*      �û� ���� ��Ʒ��Ϣ �޸�ʱ ����                           *\n");
//	printf("\t\t\t\t\t\t\t\t*      ��������ʱ Ӧ�ð������ָ��                              *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      �������bug �ǿ϶����ر�����Ա������   ��~               *\n");
//	printf("\t\t\t\t\t\t\t\t*              �϶��� ����͵͵����ȥ��                          *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//
//
//	char Test[50];
//	printf("\t\t\t\t\t\t\t\t������ �� �����Ķ���� ��\n");
//	printf("\t\t\t\t\t\t\t\t������ ��");
//	scanf("%s", Test);
//
//
//	system("Pause");
//}
//
//
//void Receive_rewards()///��ȡ����
//{
//	if (T[0] == '\0')
//	{
//		printf("\t\t\t\t\t\t\t\t���Ƚ��е�¼����\n");
//		system("Pause");
//		system("cls");
//	}
//	else
//	{
//		int Ui, choice;
//		//Un=Read_U_All_File();
//		//Ui=Read_U_Part_File(Un);
//		Ui = UI;
//		printf("\t\t\t\t\t\t\t\t0��������\n");
//		printf("\t\t\t\t\t\t\t\t�����Ȼ���     ��Ʒ\n");
//		printf("\t\t\t\t\t\t\t\t1��5           ��Ʊ\n");
//		printf("\t\t\t\t\t\t\t\t2��500         С���ֻ�3\n");
//		printf("\t\t\t\t\t\t\t\t3��1500        GTX1080Ti\n");
//		printf("\t\t\t\t\t\t\t\t4��2500        ����˹���籭�ܾ�����Ʊ\n");
//		printf("\t\t\t\t\t\t\t\t�����룺");
//		scanf("%d", &choice);
//		if (!choice)return;
//		if (choice == 1 && User[Ui].score >= 5)printf("\t\t\t\t\t\t\t\t�������� %s \n", User[Ui].Address);
//		else if (choice == 2 && User[Ui].score >= 500)printf("\t\t\t\t\t\t\t\t�������� %s \n", User[Ui].Address);
//		else if (choice == 3 && User[Ui].score >= 1500)printf("\t\t\t\t\t\t\t\t�������� %s \n", User[Ui].Address);
//		else if (choice == 4 && User[Ui].score >= 2500)printf("\t\t\t\t\t\t\t\t�������� %s \n", User[Ui].Address);
//		else printf("\t\t\t\t\t\t\t\t�����Ȳ���\n");
//		system("Pause");
//		system("cls");
//	}
//}
//
//
//void About_Author()///�������� ������չ
//{
//	int choice, choice2;
//	char Admin[20];
//	printf("\t\t\t\t\t\t\t\t1�������ߵ�¼\n");
//	printf("\t\t\t\t\t\t\t\t2����������\n");
//	printf("\t\t\t\t\t\t\t\t�����룺");
//	scanf("%d", &choice);
//	if (choice == 1)
//	{
//		printf("\t\t\t\t\t\t\t\t������ ������֤�� :");
//		scanf("%s", Admin);
//		if (strlen(Admin) < 6 && (Admin[0] == 'A' || Admin[0] == 'a') && (Admin[1] == 'D' || Admin[1] == 'd') && (Admin[2] == 'M' || Admin[2] == 'm') && (Admin[3] == 'I' || Admin[3] == 'i') && (Admin[4] == 'N' || Admin[4] == 'n'))
//		{
//			printf("\t\t\t\t\t\t\t\t1���鿴 ���� �������� ����ƽ̨�ϵ� ��Ʒ��Ϣ\n");
//			printf("\t\t\t\t\t\t\t\t2���޸��û���Ϣ\n");
//			printf("\t\t\t\t\t\t\t\t�����룺");
//			scanf("%d", &choice2);
//			if (choice2 == 1)
//			{
//				int B_n = ReadALL_BFile();
//				int B_i = Read_B_PartFile(B_n);
//				for (int i = 0; i < B_n; i++)
//				{
//					cout << endl;
//					if (i < B_i)
//					{
//						printf("�Ѿ�������ɵ���Ʒ��\n");
//						printf("��Ʒ���ƣ�%s\n", Bidder[i].B_Name);
//						printf("��Ʒ��ۣ�%d\n", Bidder[i].B_Price);
//						//printf("��Ʒ��߼ۣ�%d\n",Bidder[i].B_H_Price);
//						printf("��Ʒ��ݣ�%d\n", Bidder[i].B_years);
//						printf("��Ʒ������%d\n", Bidder[i].B_weight);
//						printf("��Ʒ������%s\n", Bidder[i].B_Desc);
//
//
//						printf("��Ʒԭ���ˣ�%s\n", Bidder[i].Haver);
//						if (Bidder[i].Ber[0] != '\0')printf("��Ʒ������%s\n", Bidder[i].Ber);
//						if (Bidder[i].flag1 == 4)printf("��Ʒ �ָ� ԭ������\n");
//						else if (Bidder[i].flag1 == 3 && Bidder[i].flag2 == 1)printf("��Ʒ������\n");
//						else if (Bidder[i].flag1 == 3 && Bidder[i].flag2 == 2)printf("��Ʒ����\n");
//						else if (Bidder[i].flag1 == 6)printf("��Ʒ�Լ۸�>=��߼۱�����\n");
//						cout << endl;
//						if (Bidder[i].sum >= 1)
//						{
//							printf("������        ���ļ�         ����ʱ�� \n");
//							for (int j = 1; j <= Bidder[i].sum; j++)printf("%s        %d         %04d %02d %02d %02d %02d %02d\n", Bidder[i].Mark[j].Next_Haver_Name, Bidder[i].Mark[j].Money, Bidder[i].Mark[j].Ye, Bidder[i].Mark[j].Mo, Bidder[i].Mark[j].Da, Bidder[i].Mark[j].Ho, Bidder[i].Mark[j].Mi, Bidder[i].Mark[j].Se);
//						}
//					}
//					else
//					{
//						printf("�Ѿ���ʼ �� δ��ʼ ������Ʒ��\n");
//						printf("��Ʒ���ƣ�%s\n", Bidder[i].B_Name);
//						printf("��Ʒ��ۣ�%d\n", Bidder[i].B_Price);
//						//printf("��Ʒ��߼ۣ�%d\n",Bidder[i].B_H_Price);
//						printf("��Ʒ��ݣ�%d\n", Bidder[i].B_years);
//						printf("��Ʒ������%d\n", Bidder[i].B_weight);
//						printf("��Ʒ������%s\n", Bidder[i].B_Desc);
//
//
//						printf("��Ʒԭ���ˣ�%s\n", Bidder[i].Haver);
//					}
//
//
//					cout << endl;
//					cout << endl;
//				}
//				system("pause");
//			}
//			else
//			{
//				int Ui, Un, flag = 0;
//				char NNN[20];
//				Un = Read_U_All_File();
//				printf("\t\t\t\t\t\t\t\t�����������޸� �û� ��Ϣ�� �˺�:");
//				scanf("%s", NNN);
//				for (int i = 0; i < Un; i++)
//				{
//					if (!strcmp(NNN, User[i].Acc_num))
//					{
//						flag = 1;
//						Ui = i;
//						break;
//					}
//				}
//				if (flag)
//				{
//					printf("\t\t\t\t\t\t\t\t�����������޸� �û� �� �����룺");
//					scanf("%s", User[Ui].Password);
//					WriteinFile(Un);
//					printf("\t\t\t\t\t\t\t\t�޸ĳɹ�\n");
//					system("pause");
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\tû������û�\n");
//					system("pause");
//				}
//			}
//		}
//		else
//		{
//			printf("\t\t\t\t\t\t\t\t�������\n");
//			system("pause");
//		}
//	}
//	else if (choice == 2)
//	{
//		char T[20];
//		printf("\t\t\t\t\t\t\t\t�ش����⣬�����ʵ�\n");
//		printf("\t\t\t\t\t\t\t\t������ �������֣�");
//		scanf("%s", T);
//		if (strlen(T) < 4 && (T[0] == 'L' || T[0] == 'l') && (T[1] == 'T' || T[1] == 't') && (T[2] == 'S' || T[2] == 's'))
//		{
//
//
//			HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
//			SetConsoleTextAttribute(t, 12);
//			printf("\t\t\t\t\t\t\t\t                                     000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                                   0000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                                 00000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                                0000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 14);
//			printf("\t\t\t\t\t\t\t\t                              0000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                             000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                           000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                          00000000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 10);
//			printf("\t\t\t\t\t\t\t\t                         0000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                        000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                       00000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                      0000000000000000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 11);
//			printf("\t\t\t\t\t\t\t\t                     00000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                     000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                     000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                    000000000000000000000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 9);
//			printf("\t\t\t\t\t\t\t\t                    000000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                   00000000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                   00000000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                   00000000000000000000000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 13);
//			printf("\t\t\t\t\t\t\t\t                   000000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                     0000000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                      00000000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                       000000000000000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 7);
//			printf("\t\t\t\t\t\t\t\t                        000000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                           000000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                            0000000000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                             000000000000000000000000000000\n");
//			SetConsoleTextAttribute(t, 15);
//			printf("\t\t\t\t\t\t\t\t                              0000000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                                000000000000000000000000\n");
//			printf("\t\t\t\t\t\t\t\t                                 0000000000000000000000\n");
//
//
//
//
//			cout << endl;
//			cout << endl;
//			printf("\n\t\t\t\t\t\t\t\t����  ͷ����� һ�����ʵ����ǲʵ�\n\n\n");
//			printf("\t\t\t\t\t\t\t\t���Ѵ�����ʱ���뾫��Ѱ�Ҳʵ����� ����Ϸ �Ĺ��̣���just for fun�� \n\n\n");
//
//
//
//
//			printf("SCAU_17 0212 Luo.T4 \n");
//			system("pause");
//		}
//		else printf("������� ��\n");
//	}
//}
//
//
//void delay(double second)///��¼�ӳ�
//{
//	clock_t delay = second * CLOCKS_PER_SEC;
//	clock_t start = clock();
//	while (clock() - start < delay)
//		;
//}
//
//
//void In_System()///Loading...
//{
//	string load = "Loading";
//	string wait = ".";
//	int count_1 = 0, i;
//	while (count_1 < 15)
//	{
//		if (!(count_1 % 5))system("CLS");
//		if (!(count_1 % 5))
//		{
//			for (i = 0; i < 27; i++)cout << endl;
//			for (i = 0; i < 52; i++)cout << "  ";
//			printf("%s", load);
//			//cout << load;
//		}
//		delay(0.3);
//		if (count_1)printf("%s", wait); //cout << wait;
//		count_1++;
//	}
//	system("CLS");
//}
//
//
//void Password_Undisplay(char Pw[])///������ʾ
//{
//	char c;
//	//char Pw[128] = {'\0'};
//	char incr[2] = { 0,'\0' };
//	int i = 0;
//	while ('\r' != (c = _getch()))
//	{
//
//
//		if (c == '\b')
//		{
//			i--;
//			printf("\b");
//			printf(" ");
//			printf("\b");
//			continue;
//		}
//		else
//		{
//			printf("*");
//		}
//		incr[0] = c;
//		strcat(Pw, incr);
//		i++;
//	}
//	Pw[i] = '\0';
//	//printf("\n%s", pw);
//}
//
//
//void Login_Warning()///�������
//{
//	HANDLE T = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(T, 12);
//
//
//	printf("\t\t\t\t\t\t      W               W         A             RRRRRRRRR       N         N        IIIIIIIIIII           N         N         GGGGGGGGGGG  \n"
//		"\t\t\t\t\t\t      W       W       W        A A            R        R      N N       N             II               N N       N         G         G  \n"
//		"\t\t\t\t\t\t      W     W W     W        A   A           R        R      N  N      N             II               N  N      N         G         G   \n"
//		"\t\t\t\t\t\t      W     W W     W       A     A          R        R      N   N     N             II               N   N     N         G         G   \n"
//		"\t\t\t\t\t\t      W   W   W   W       A       A         RRRRRRRRR       N    N    N             II               N    N    N         G              \n"
//		"\t\t\t\t\t\t      W   W   W   W      AAAAAAAAAAA        RR              N     N   N             II               N     N   N         G      GGGG    \n"
//		"\t\t\t\t\t\t      W W     W W      A           A       R RR            N      N  N             II               N      N  N         G         G     \n"
//		"\t\t\t\t\t\t      WWW     WWW     A             A      R   RR          N       N N             II               N       N N         G         G     \n"
//		"\t\t\t\t\t\t      W       W     A               A     R     RR        N         N        IIIIIIIIIIII          N         N         GGGGGGGGGGG      \n"
//		"\t\t\t\t\t\t                                                   AA                                                                                   \n"
//		"\t\t\t\t\t\t                                                 AA  AA                                                                                 \n"
//		"\t\t\t\t\t\t                                               AA      AA                                                                               \n"
//		"\t\t\t\t\t\t                                             AA    AA    AA                                                                             \n"
//		"\t\t\t\t\t\t                                          AA       AA      AA                                                                           \n"
//		"\t\t\t\t\t\t                                        AA         AA        AA                                                                         \n"
//		"\t\t\t\t\t\t                                      AA           AA          AA                                                                       \n"
//		"\t\t\t\t\t\t                                    AA                           AA                                                                     \n"
//		"\t\t\t\t\t\t                                 AA                AA              AA                                                                   \n"
//		"\t\t\t\t\t\t                               AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                                                                 \n");
//
//
//	SetConsoleTextAttribute(T, 15);
//
//
//}
//
//
//void Login_welcome()///��ӭ��¼
//{
//
//
//	printf("\t\t\t\t\t\t                                                                                                                                                     \n"
//		"\t\t\t\t\t\t     W               W      EEEEEEEEEEEE         L                 CCCCCCCCCCCC        OOOOOOOOOOOOO         M                 M      EEEEEEEEEEEE   \n"
//		"\t\t\t\t\t\t     W       W       W      E                    L                 C                   O           O         M M             M M      E              \n"
//		"\t\t\t\t\t\t     W     W W     W       E                    L                 C                   O           O         M  M           M  M      E               \n"
//		"\t\t\t\t\t\t     W     W W     W       E                    L                 C                   O           O         M   M         M   M      E               \n"
//		"\t\t\t\t\t\t     W   W   W   W        EEEEEEEEEEE          L                 C                   O           O         M    M       M    M      EEEEEEEEEEE      \n"
//		"\t\t\t\t\t\t     W   W   W   W        E                    L                 C                   O           O         M     M     M     M      E                \n"
//		"\t\t\t\t\t\t     W W     W W         E                    L                 C                   O           O         M      M   M      M      E                 \n"
//		"\t\t\t\t\t\t     WWW     WWW         E                    L                 C                   O           O         M       M M       M      E                 \n"
//		"\t\t\t\t\t\t     W       W          EEEEEEEEEEEE         LLLLLLLLLLLL      CCCCCCCCCCCC        OOOOOOOOOOOOO         M        M        M      EEEEEEEEEEEE       \n");
//}
//
//
/////�û���Ϣ
//int Read_U_All_File()///��ȡȫ���ļ�
//{
//	FILE *fp;
//	int j = 0;
//	fp = fopen("User.txt", "rb");
//	while (fread(&User[j], sizeof(USER), 1, fp) > 0)j++;
//	fclose(fp);
//	return j;
//}
//
//
//int Read_U_Part_File(int n)///��ȡ�ؼ��ļ�
//{
//	int i = 0;
//	for (i = 0; i <= n; i++)
//	{
//		if (!strcmp(T, User[i].Acc_num))
//			break;
//	}
//	return i;
//}
//
//
//void WriteinFile(int i)///д���ļ�
//{
//	FILE *fp;
//	fp = fopen("User.txt", "wb");
//	for (int k = 0; k < i; k++)fwrite(&User[k], sizeof(USER), 1, fp);
//	fclose(fp);
//}
//
//
/////������Ʒ
//int ReadALL_BFile()///��ȡ������Ʒ�ļ�
//{
//	FILE *fp;
//	int j = 0;
//	fp = fopen("Bidder.txt", "rb");
//	while (fread(&Bidder[j], sizeof(BIDDER), 1, fp) > 0)j++;
//	fclose(fp);
//	return j;
//}
//
//
//void Write_B_inFile(int i)///д���ļ�
//{
//	FILE *fp;
//	fp = fopen("Bidder.txt", "wb");
//	for (int k = 0; k < i; k++)fwrite(&Bidder[k], sizeof(BIDDER), 1, fp);
//	fclose(fp);
//}
//
//
//int Read_B_PartFile(int B_n)///��ȡ��һ��flag1==1
//{
//	int i;
//	for (i = 0; i < B_n; i++)
//	{
//		if (Bidder[i].flag1 == 1 || Bidder[i].flag1 == 5)return i;
//	}
//	if (B_n >= 1 && Bidder[B_n - 1].B_Name[0] != '\0')return B_n;
//	else return -1;
//}
//
//
//void Rank_Read(int Un)///��ȡ�û�������
//{
//	for (int j = 0; j < Un; j++)
//	{
//		strcpy(Rank[j].Name, User[j].Acc_num);
//		Rank[j].score = User[j].score;
//	}
//}
//
//
//void Revise_Online_Rank()///�鿴���а�
//{
//	int Un = Read_U_All_File(), n, j, k;
//	Rank_Read(Un);
//	Rank_Quick_Sort(Rank, 0, Un - 1);//���а�
//	if (Un >= 20)n = 20;
//	else n = Un;
//	printf("������ ������ ��ߵ� ǰ %d λ �û�\n", n);
//	printf("�û���                ������\n");
//	for (int i = 0; i < n; i++)
//	{
//		j = strlen(Rank[i].Name);
//		for (k = 0; k < j - 2; k++)printf("*");
//		for (; k < j; k++)printf("%c", Rank[i].Name[k]);
//		for (; k < 25; k++)printf(" ");
//		printf("%d\n", Rank[i].score);
//	}
//	system("pause");
//	system("cls");
//}
//
//
//void Jugel()///�ж��Ƿ� ֧�� ����
//{
//	Bn = ReadALL_BFile();
//	Bi = Read_B_PartFile(Bn);
//	int i, choice, flag = 0;
//	Overdue();//����û��Ҫ�Ķ���
//	Back_Bag();//�ص�������
//	for (i = 0; i < Bi; i++)
//	{
//		if (Bidder[i].flag1 == 3)
//		{
//			//Online_Money(Bidder[i].B_H_Price,2,Bidder[i].Z_F);
//			if (!strcmp(T, Bidder[i].Ber) && Bidder[i].flag2 != 1 && Bidder[i].flag2 != 2)
//			{
//				strcpy(Buyer, T);
//				strcpy(Seller, Bidder[i].Haver);
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*       ������Ʒ���֣� %s\n", Bidder[i].B_Name);
//				printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %s\n", Bidder[i].B_Desc);
//				printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ͣ� %s\n", Bidder[i].B_size);
//				printf("\t\t\t\t\t\t\t\t*       ������Ʒ���ļۣ� %d\n", Bidder[i].B_Price);
//				printf("\t\t\t\t\t\t\t\t*       ������Ʒ������ %d\n", Bidder[i].B_weight);
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//				printf("\t\t\t\t\t\t\t\t*                              1 ��֧��                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                              2 ������                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//				printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//				printf("\t\t\t\t\t\t\t\t�����룺");
//				scanf("%d", &choice);
//				if (choice == 1)
//				{
//					flag = 1;
//					Bidder[i].flag2 = 1;
//					Payment(i);
//				}
//				else
//				{
//					flag = 1;
//					Bidder[i].flag2 = 2;
//					Racket(i);
//				}
//			}
//		}
//		system("cls");
//	}
//	if (!flag)
//	{
//		printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//		printf("\t\t\t\t\t\t\t\t*                        So Sad��                               *\n");
//		printf("\t\t\t\t\t\t\t\t*                       ��û�о��ĵ���Ʒ                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//		printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//	}
//	Write_B_inFile(Bn);
//	system("pause");
//	system("cls");
//}
//

#include <iostream>
#include <vector>
#include<ctime>
#include <map>
#include <queue>
using namespace std;
class A
{
public:
	A() {}
	~A(){}
public:
	int id;
	int c;
};
typedef map<int, A*>AMap;

class B
{
public:
	B() {}
	~B() {}
	void insertgood(int id,A* nA)
	{
		a_map.insert(AMap::value_type(id, nA));
	}
	void deletegood(int id,bool &flag)
	{
		map<int, A*>::iterator it = a_map.find(id);
		if (it != a_map.end())
		{
			a_map.erase(it);//ɾ��ָ��
			cout << "ɾ��" << id << "��ֵ\n";
			flag = true;
		}
		else
		{
			cout << "û��ֵ����ɾ��\n";
			flag = false;
		}
		
	}
	bool jingpai(int &f)//��������� ���ĳɹ�
	{
		map<int, A*>::iterator it = a_map.begin();
		if (a_map.size() == 0)
		{
			return false;
		}
		for (; it != a_map.end(); it++)
		{
			temp.push_back(it->second->c);//����
			//0 1 2 3 4  temp
			//1 2 3 4 5  key

			//1 0 3 2 4  value
			//cout << it->second->c;
		}
		//�����ʼֵ��С  ��֤��10��
		while (temp.size() < 10)
		{
			temp.push_back(0);
		}
		int index = 0;
		int min = temp[0];
		for (int i = 1; i < temp.size(); i++)//1. 01324   
		{
			if (min > temp[i] && min!=0)
			{
				min = temp[i];
				index = i;
			}
		}
		f = index;
		temp.clear();
		return true;
	}
	void printmap()
	{
		map<int, A*>::iterator it = a_map.begin();
		for (; it != a_map.end(); it++)
		{
			cout << it->second->id << " " << it->second->c << endl;
		}
		cout << endl;
	}
	vector<int>temp;
	AMap a_map;
};

//����  �Ƚ��ȳ�
int main()
{
	B b;
	//�����ĸ�
	for (int i = 0; i < 10; i++)
	{
		A* a1 = new A;
		a1->id = i;
		a1->c = rand() % 10;//���������
		b.insertgood(a1->id, a1);
	}
	std::cout << "��ʼ��map\n";
	b.printmap();

	//����ʱ�� ��������
	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	int t1 = 21 * 60 * 60 + 30 * 60 + 0;
	while (1)
	{
		struct tm t;
		time_t now;
		time(&now);
		localtime_s(&t, &now);
		int t2 = t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec;
		bool falg = false;
		bool flag1 = true;
		int count = 1;
		if(t1 == t2)//��ʼ����
		{
			while (1)//����1����
			{
				struct tm t;
				time_t now;
				time(&now);
				localtime_s(&t, &now);
				long int t3 = t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec;
				int f = 0;//��ʾ���ĳɹ��ڼ���
				falg = b.jingpai(f);
				if (falg)//�������
				{
					b.deletegood(f, flag1);//�ɹ�ɾ��
					if (flag1)
					{
						cout << "���ĳɹ�" << count++ <<"�κ�mapΪ\n";
						b.printmap();
					}
					else
					{
						break;
					}
					if ((t3 - t1) == 60)
					{
						break;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}