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
////_CRT_SECURE_NO_WARNINGS 解决fopen()等报错问题  将其添加到预处理器定义里面
//
//using namespace std;
//char T[20];//用户名
//HANDLE hTimer;//无关变量
//int Rott;//剩余时间;
//char Buyer[20];
//char Seller[20];
//char Tpassword[21];//密码
//
//
//typedef struct RANK
//{
//	char Name[20];
//	int score;
//} RANK;//排行榜
//
//
//typedef struct Bag_Goods
//{
//	int G_ID;  //编号
//	char G_Name[20];//商名
//	int New_old;//新旧
//	char Desc[120];//描述
//	int Price;//估价
//	int years;   //年份
//	char size[40]; //大小
//	int weight;//重量
//	int State;// 1 拍卖 0 存放
//	int flag;// 1 拍卖得到的
//} Bag_Goods;
//
//
//typedef struct T_G
//{
//	int G_ID;  //编号
//	char G_Name[20];//商名
//	int New_old;//新旧
//	char Desc[120];//描述
//	int Price;//估价
//	int years;   //年份
//	char size[40]; //大小
//	int weight;//重量
//	int State;//是否拍卖
//	int flag;// 1 拍卖得到的
//	struct T_G *next;
//} T_G;//链表进行增加 删除背包物品
//
//
//typedef struct USER
//{
//	char Name[20];     //名字
//	char Sex[10];           //性别
//	char Pho_num[20];       //手机电话
//	char Mail[20];  //邮箱
//	char Spec[30];  //个性签名
//	int score;   //信誉评分
//	char Acc_num[20];     //用户名
//	char Password[20]; //密码
//	int Sum;  //多少件物品
//	char Address[40];//地址
//	Bag_Goods MyGoods[20];//物品编号
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
//} TIME;//拍卖物品开始时间
//
//
//typedef struct Bid_Money
//{
//	char Next_Haver_Name[20];//下一个竞拍人的 名字
//	int Money;
//
//
//	int Ye;
//	int Mo;
//	int Da;
//	int Ho;
//	int Mi;
//	int Se;
//} Bid_Money;//出价人的信息
//
//
//
//
//typedef struct BIDDER//拍卖物品的信息
//{
//	int NUM;
//	char Haver[20];//以前拥有者
//	int G_ID;//物品在原背包编号
//	char Address[40];//地址
//	char B_Name[20];//物品名字
//	int B_years;//物品年份
//	int B_New_old;//物品新旧
//	char B_Desc[20];//物品描述
//	int B_Price;///起拍价格
//	int B_H_Price;///一口价
//	int Final_Price;///最终价
//	int B_weight;//重量
//	char B_size[40];//类型
//	int M_M;//明盲
//	int Z_F;//正反
//	TIME B_Time;//拍卖时间
//	char Ber[20];//卖家
//	int flag1;///    1 拍卖 2 过期  3待支付 4过期恢复完成背包添加 5 正在竞拍
//	int flag2;///    1 已支付 2 已流拍
//	int sum;//出价人
//	Bid_Money Mark[30];//价格
//	//ENDTIME e_time;
//} BIDDER;
//
//
//
//
//
//
//BIDDER Bidder[1000];//竞拍物品
//USER User[500];//用户信息
//RANK Rank[500];//排行榜
//
//
//int mintues;//计分
//int seconds;//计秒
//int Re_min;//无关变量
//int Re_sec;//无关变量
//int F_H;//第一有钱的人
//int S_H;//无关变量
//int Bi, Bn;//正在拍卖的物品
//int UI, UN;//登录人的下标
//int Start = 0, End = 0;//无关变量
//
//
/////函数
//void delay(double second);//延迟
//void In_System();//loading...
//void str_to_ch(string A, char a[]);//将string变为char a[]存储
//void Menu();//欢迎界面
//void Jugel();//判断
//void Register();//注册
//void Login();//登录
//void Cancel();//注销
//void Login_Warning();//输入密码界面
//void Login_welcome();//登陆完成界面
//void Watch_Bag(); //查看背包
//void Add_Goods(int i, int n);//增加物品
//void Del_Goods(int i, int n);//删除物品
//void GoodTraverse(int i, int n);//查看修改物品信息
//
//
/////登录修改
//void Revise_User_Info();//修改用户信息
//void Revise_User_Info_Pho_Num(int i, int j);//修改手机号码
//void Revise_User_Info_Spec(int i, int j);//修改个性签名
//void Revise_User_Info_Password(int i, int j);//修改密码
//void Revise_User_Info_Mail(int i, int j);//修改邮箱
//void Revise_User_Info_Address(int i, int j);//修改地址
//
//
/////登录查询
//void Revise_G_ID(int i, int n);//按物品编号查询
//void Revise_G_Name(int i, int n);//按物品名字查询
//void Revise_G_New_Old(int i, int n);//按物品新旧查询
//void Revise_G_State(int i, int n);//按物品拍卖查询
//void Revise_G_size(int i, int n);//物品类型
//void Revise_All_G(int i, int n);//查看所有物品
//void Revise_Part_G(int Ui, int mid);//查看单一物品
//void I_just_check(int i, int n);//随便查询背包物品
//void Change_Good(int i, int n);//改变物品信息
//void Flag_Good(int i, int n);//拍卖得到的物品
//
//
/////快排二分
//void Quick_Sort(USER User[], int Ui, int left, int right, int choice);//快排
//void Bin_Search(USER User[], int Ui, int left, int right, int choice, int e);//二分查找
//void Rank_Quick_Sort(RANK Rank[], int left, int right);//排行榜
//void B_S(BIDDER Bidder[], int Ui, int left, int right, int e);//二分查找
//void Del_Auction();//删除竞拍
//
//
/////用户
//int Read_U_All_File();//读取USER全部文件
//int Read_U_Part_File(int n);//读取UERR关键文件
//void WriteinFile(int i);//写入文件
/////拍卖物品
//int ReadALL_BFile();//读取拍卖物品文件
//void Write_B_inFile(int i);//写入文件
//int Read_B_PartFile(int B_n);//读取关键文件
//void CLear_File();
/////排行榜
//void Rank_Read(int Un);//读取用户信誉度
//
//
//void Pre_Bid(int Ui, int Un);//将物品放在平台上拍卖
//void Password_Undisplay(char Pw[]);//密码显示
//
//
/////直接查看信息
//void Revise_Online();//查看信息 可以扩展
//void Revise_Online_Good();//不登录查看物品
//void Revise_Online_User();//不登录查看用户
//void Revise_Online_Rank();//不登录查看排行榜
//
//
//void Help();///帮助 可以扩展
//void Mannel();///用户手册
//void Receive_rewards();///领取奖励
//
//
//void About_Author();///关于作者 可以扩展
//
//
//void Join_Pm();//参与竞拍
//
//
//void Auction_All_Revise(int B_i, int B_n);//查看拍卖信息
//void Auction_Size_Revise(int B_i, int B_n);//查看单一拍卖信息
//
//
//int Online_Money(int P, int flag1, int flag2);//网上价钱
//void Payment(int p);//支付
//void Racket(int p);//流拍
//void Overdue();//过期没人要的东西
//void Back_Bag();//回到背包；
//
//
//void Decide_Time(int B_n);//决定时间拍卖；
//
//
//void Count_Backwards_time();//时间倒数
//void Waiting_Time();//等待时间
//int Time_minus(int p);//时间差
//
//
//
//
//int main()//主函数
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
//		printf("\nPs：新注册用户应该先阅读 帮助 中 的使用须知\n");
//		printf("\t\t\t\t\t\t\t\t请输入：");
//		scanf("%d", &choice1);
//		choice2 = 0;
//		system("cls");
//		switch (choice1)
//		{
//
//
//		case 1://登录
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t*********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                 0、继续登陆                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                 3、返回上一级                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                 5、退出程序                           *\n");
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
//							printf("\t\t\t\t\t\t\t\t*                   返回继续登录！                       *\n");
//							printf("\t\t\t\t\t\t\t\t*                   3、返回上一级                        *\n");
//							printf("\t\t\t\t\t\t\t\t*                   5、退出程序                          *\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t请输入：");
//							scanf("%d", &choice2);
//						}
//						system("cls");
//						if (choice2 == 3)break;
//						if (choice2 == 5)exit(0);
//						while (1)
//						{
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t*                    9、支付或者流拍物品                 *\n");
//							printf("\t\t\t\t\t\t\t\t*                    8、注销 重新登录                    *\n");
//							printf("\t\t\t\t\t\t\t\t*                    7、查看或者修改用户信息             *\n");
//							printf("\t\t\t\t\t\t\t\t*                    6、查看背包物品                     *\n");
//							printf("\t\t\t\t\t\t\t\t*                    4、参加拍卖                         *\n");
//							printf("\t\t\t\t\t\t\t\t*                    3、返回上一级                       *\n");
//							printf("\t\t\t\t\t\t\t\t*                    5、退出程序                         *\n");
//							printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//							printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//							printf("\t\t\t\t\t\t\t\t请输入：");
//							scanf("%d", &choice2);
//							if (choice2 == 3)break;
//							if (choice2 == 8)
//							{
//								Cancel();//注销
//								break;
//							}
//							switch (choice2)
//							{
//
//
//							case 1:
//							case 2:
//							case 4://参加竞拍
//								//printf("%s\n",T);
//								Join_Pm();
//								cout << endl;
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t请输入：");
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
//								printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t请输入：");
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
//								printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//								printf("\t\t\t\t\t\t\t\t请输入：");
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
//								printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//								printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//								printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//								printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//								printf("\t\t\t\t\t\t\t\t请输入：");
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
//		case 2://注册
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0、继续注册                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3、返回上一级                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Register();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t请输入：");
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
//		case 4://直接查询（可不登录）
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0、继续查询                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3、返回上一级                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//				printf("\t\t\t\t\t\t\t\t请输入: ");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Revise_Online();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//					printf("\t\t\t\t\t\t\t\t请输入：");
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
//				printf("\t\t\t\t\t\t\t\t*                    0、继续寻求帮助                     *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3、返回上一级                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                    5、退出                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					Help();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t请输入：");
//					scanf("%d", &choice2);
//				}
//				if (choice2 == 3)break;
//				if (choice2 == 5)exit(0);
//			}
//			system("cls");
//			break;
//		case 7://关于作者
//			while (1)
//			{
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                    0、继续                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                    3、返回上一级                       *\n");
//				printf("\t\t\t\t\t\t\t\t*                    5、退出                             *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
//				scanf("%d", &choice2);
//				if (!choice2)
//				{
//					About_Author();
//					cout << endl;
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t*                       3、返回上一级                    *\n");
//					printf("\t\t\t\t\t\t\t\t*                       5、退出程序                      *\n");
//					printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//					printf("\t\t\t\t\t\t\t\t**********************************************************\n");;
//					printf("\t\t\t\t\t\t\t\t请输入：");
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
//void Join_Pm()///参加竞拍
//{
//	int choice, choice2, B_i, B_n;
//
//
//	Overdue();//过期没人要的东西
//	Back_Bag();
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//	//printf("  %d %d\n",B_i,B_n);
//	if (B_i == B_n || B_i == -1)
//	{
//		printf("\t\t\t\t\t\t\t\t***********************目前没有物品拍卖*********************\n");
//		system("Pause");
//		return;
//	}
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t*********注意 ：进入竞拍可以选择竞拍一次 或者 退出********\n");
//		//system("pause");
//		//printf("进入拍卖系统中...\n");
//		while (1)
//		{
//			Overdue();//过期没人要的东西
//			Back_Bag();
//			B_n = ReadALL_BFile();
//			B_i = Read_B_PartFile(B_n);
//			if (B_i == B_n || B_i == -1)
//			{
//				printf("\t\t\t\t\t\t\t\t***********************目前没有物品拍卖*********************\n");
//				system("Pause");
//				return;
//			}
//			printf("\t\t\t\t\t\t\t\t*******************目前有 %d 件物品拍卖*******************\n", B_n - B_i);
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                     1、查看竞拍物品                    *\n");
//			printf("\t\t\t\t\t\t\t\t*                     2、参与竞拍                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                     3、打扰了！逃                      *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t请输入：");
//			scanf("%d", &choice);
//			if (choice == 3)break;
//			switch (choice)
//			{
//			case 1:
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                   1、编号 查看 物品                    *\n");
//				printf("\t\t\t\t\t\t\t\t*                   2、类型 查看 物品                    *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				scanf("%d", &choice2);
//				system("cls");
//				if (choice2 == 1)Auction_All_Revise(B_i, B_n);
//				if (choice2 == 2)Auction_Size_Revise(B_i, B_n);
//				break;
//			case 2:
//				Overdue();//过期没人要的东西
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
//void Auction_All_Revise(int B_i, int B_n)///查看物品 编号
//{
//	int i = Bidder[B_i].NUM + B_i, j = Bidder[B_n - 1].NUM + B_i, mid, flag = 0, e;
//	//printf("%d %d %d %d\n",i,j,Bidder[B_i].NUM,B_i);
//	//printf("     %d %d\n",B_i,B_n);
//	printf("\t\t\t\t\t\t\t\t输入 竞拍 物品 编号：");
//	scanf("%d", &e);
//	e = e + B_i - 1;
//	//printf("%d %d %d\n",i,j,e);
//	while (j >= i)
//	{
//		mid = (i + j) / 2;
//		if (e == Bidder[mid].NUM + B_i)
//		{
//			flag = 1;
//			if (Bidder[mid].B_New_old)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品名字： %s\n", Bidder[mid].B_Name);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品描述： %s\n", Bidder[mid].B_Desc);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品类型： %s\n", Bidder[mid].B_size);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品起拍价： %d\n", Bidder[mid].B_Price);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品重量： %d\n", Bidder[mid].B_weight);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (Bidder[mid].B_H_Price)printf("\t\t\t\t\t\t\t\t拍卖物品支持最高价且最高价：%d\n", Bidder[mid].B_H_Price);
//			else printf("\t\t\t\t\t\t\t\t拍卖物品不支持一口价\n");
//			if (Bidder[mid].M_M == 1)printf("\t\t\t\t\t\t\t\t物品拍卖方式为 明拍\n");
//			else printf("\t\t\t\t\t\t\t\t物品拍卖方式为 盲拍\n");
//			if (Bidder[mid].Z_F == 1)printf("\t\t\t\t\t\t\t\t拍卖规则为 价高者得！\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖规则为 价低者得！\n");
//			printf("\t\t\t\t\t\t\t\t拍卖物品开始拍卖时间 ：%04d %02d %02d %02d %02d %02d\n", Bidder[mid].B_Time.Year, Bidder[mid].B_Time.Month, Bidder[mid].B_Time.Day, Bidder[mid].B_Time.Hour, Bidder[mid].B_Time.Min, Bidder[mid].B_Time.Sec);
//			cout << endl;
//			break;
//		}
//		if (e > Bidder[mid].NUM + B_i)i = mid + 1;
//		else if (e <= Bidder[mid].NUM + B_i)j = mid - 1;
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\t没有相关信息\n");
//	system("pause");
//	system("cls");
//}
//
//
//void Auction_Size_Revise(int B_i, int B_n)///查看单一物品
//{
//	int i, flag = 0;
//	char T_c[40];
//	printf("\t\t\t\t\t\t\t\t请输入你想查看的物品类型：");
//	scanf("%s", T_c);
//	//BGP_Choose(i);
//
//
//	for (i = B_i; i < B_n; i++)
//	{
//		flag = 1;
//		if (!strcmp(T_c, Bidder[i].B_size))
//		{
//			if (Bidder[i].B_H_Price == 1)printf("\t\t\t\t\t\t\t\t拍卖物品支持最高价且最高价：%d\n", Bidder[i].B_H_Price);
//			else printf("\t\t\t\t\t\t\t\t拍卖物品不支持一口价\n");
//			if (Bidder[i].M_M == 1)printf("\t\t\t\t\t\t\t\t物品拍卖方式为 明拍\n");
//			else printf("\t\t\t\t\t\t\t\t物品拍卖方式为 盲拍\n");
//			if (Bidder[i].Z_F == 1)printf("\t\t\t\t\t\t\t\t拍卖规则为 价高者得！\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖规则为 价低者得！\n");
//			if (Bidder[i].B_New_old)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//			cout << endl;
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品名字： %s\n", Bidder[i].B_Name);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品描述： %s\n", Bidder[i].B_Desc);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品类型： %s\n", Bidder[i].B_size);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品起拍价： %d\n", Bidder[i].B_Price);
//			printf("\t\t\t\t\t\t\t\t*       拍卖物品重量： %d\n", Bidder[i].B_weight);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t拍卖物品开始拍卖时间 ：%04d %02d %02d %02d %02d %02d\n", Bidder[i].B_Time.Year, Bidder[i].B_Time.Month, Bidder[i].B_Time.Day, Bidder[i].B_Time.Hour, Bidder[i].B_Time.Min, Bidder[i].B_Time.Sec);
//			cout << endl;
//			cout << endl;
//			cout << endl;
//
//
//		}
//	}
//	if (!flag) printf("\t\t\t\t\t\t\t\t没有找到相关物品\n");
//	system("pause");
//	system("cls");
//
//
//}
/////需要修改 决定时间
//void Pre_Bid(int Ui, int Un)///将物品放在平台上拍卖
//{
//	int T_ID, flag = 0, Q = 1, j;
//	Overdue();
//	int B_n = ReadALL_BFile();
//	while (Q)
//	{
//		flag = 0;
//		printf("\t\t\t\t\t\t\t\t请输入希望放置在平台拍卖的物品 编号：");
//		scanf("%d", &T_ID);
//		for (j = 0; j < User[Ui].Sum; j++)
//		{
//			if (T_ID == User[Ui].MyGoods[j].G_ID&&User[Ui].MyGoods[j].State != 1)
//				//if(T_ID==User[Ui].MyGoods[j].G_ID)
//			{
//				printf("\t\t\t\t\t\t\t\t找到物品！\n");
//				printf("\t\t\t\t\t\t\t\t请输入物品的相关信息:\n");
//				User[Ui].MyGoods[j].State = 1;
//				flag = 1;
//				break;
//			}
//		}
//		if (!flag)
//		{
//			printf("\t\t\t\t\t\t\t\t物品编号不存在！\n");
//			printf("\t\t\t\t\t\t\t\t或者已经在平台上拍卖！\n");
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
//			Bidder[B_n].flag1 = 1;//竞拍
//			Bidder[B_n].flag2 = 0;//还没支付 流拍
//			Bidder[B_n].sum = 0;//
//
//
//			Bidder[B_n].B_H_Price = 0;
//
//
//			printf("\t\t\t\t\t\t\t\t输入 【1】 明拍  【2】 盲拍: ");
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
//		printf("\t\t\t\t\t\t\t\t1、继续输入希望放置在平台拍卖的物品\n");
//		printf("\t\t\t\t\t\t\t\t0、退出输入\n");
//		scanf("%d", &Q);
//	}
//	printf(" %d \n", B_n);
//
//
//	Write_B_inFile(B_n);
//	WriteinFile(Un);
//	//for(int q=0; q<Bn; q++)printf("%s %s\n",Bidder[q].B_Name,Bidder[q].Haver);
//}
/////需要修改
//void Payment(int p)///支付
//{
//	//二维码;
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
//	printf("\n\t\t\t\t\t\t\t\t支付宝/微信 扫一扫完成支付");
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
//		///修改买家
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
//			printf("\n\t\t\t\t\t\t\t\t请 新物品 输入编号：");
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
//				if (flag3)printf("\n\t\t\t\t\t\t\t\t编号已经存在 请重新输入：");
//				else break;
//			}
//		}
//		User[Index_B].Sum++;
//	}
//	else printf("\n\t\t\t\t\t\t\t\t背包 已满 直接送往 用户 地址\n");
//	///修改卖家
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
//	printf("\n\t\t\t\t\t\t\t\t支付成功！\n");
//	printf("\n\t\t\t\t\t\t\t\t物品即将送往 : %s \n", User[Index_B].Address);
//	//printf("\t\t\t\t\t\t\t\t退出程序后 就可送达\n");
//	system("pause");
//
//
//}
//
//
//void Racket(int p)///流拍
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
//	///修改买家
//	User[Index_B].score -= 5;
//	printf("\t\t\t\t\t\t\t\t你的信誉度减少5分\n");
//	///修改卖家
//	for (j = 0; j <= User[Index_S].Sum; j++)if (User[Index_S].MyGoods[j].G_ID == Bidder[p].G_ID)break;
//	User[Index_S].MyGoods[j].State = 0;//未拍出
//	WriteinFile(Un);
//
//
//	printf("\n\t\t\t\t\t\t\t\t物品已流拍\n");
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
//		printf("\t\t\t\t\t\t\t\t一口价已经出现, 无法参加该物品竞拍\n");
//		system("pause");
//		return;
//	}
//	if (Time_minus(Bi) <= 60)
//	{
//		SYSTEMTIME sys;
//		GetLocalTime(&sys);
//		printf("\t\t\t\t\t\t\t\t你拍卖剩余时间: %d  second\n", Rott);
//		printf("\t\t\t\t\t\t\t\t注意！：\n");
//		cout << endl;
//		if (Bidder[Bi].B_New_old)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//		else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                  拍卖物品名字： %s\n", Bidder[Bi].B_Name);
//		// printf("\t\t\t\t\t\t\t\t*                  拍卖物品新旧： %d\n",Bidder[Bi].B_New_old);
//		printf("\t\t\t\t\t\t\t\t*                  拍卖物品描述： %s\n", Bidder[Bi].B_Desc);
//		printf("\t\t\t\t\t\t\t\t*                  拍卖物品类型： %s\n", Bidder[Bi].B_size);
//		printf("\t\t\t\t\t\t\t\t*                  拍卖物品重量： %d\n", Bidder[Bi].B_weight);
//		printf("\t\t\t\t\t\t\t\t*                  拍卖物品起价： %d\n", Bidder[Bi].B_Price);
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		if (Bidder[Bi].B_H_Price)printf("一口价为 ：%d \n", Bidder[Bi].B_H_Price);
//		cout << endl;
//
//
//		printf("\t\t\t\t\t\t\t\t1、拍卖  0、退出拍卖\n");
//		printf("\t\t\t\t\t\t\t\t请输入：");
//		scanf("%d", &choice);
//		Online_Money(Bidder[Bi].B_H_Price, Bidder[Bi].M_M, Bidder[Bi].Z_F);
//		if (choice)
//		{
//			printf("\t\t\t\t\t\t\t\t请输入你竞拍的价格: ");
//			while (1)
//			{
//				scanf("%d", &Money);
//				if (Money > Bidder[Bi].B_Price&&Money >= 1 && Money <= 99999)break;
//				else printf("\t\t\t\t\t\t\t\t请重新输入 价格 :");
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
//			Bidder[Bi].Final_Price = Bidder[Bi].Mark[F_H].Money;///最终价
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
//void Waiting_Time()///等待时间
//{
//	//printf("注意 ；进入拍卖后不能退出\n");
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
//			printf("\t\t\t\t\t\t\t\t*                  等待拍卖开始                          *\n");
//			printf("\t\t\t\t\t\t\t\t*                  还有 %d 秒                            *\n", abs(Time_minus(Bi)));
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			system("pause");
//			system("cls");
//		}
//		printf("\t\t\t\t\t\t\t\t      拍卖开始\n");
//		printf("\t\t\t\t\t\t\t\t还有 %d 秒 \n", Rott);
//		Count_Backwards_time();
//		return;
//	}
//
//
//}
//
//
/////需要修改
//void Overdue()///过期没人要的东西
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
//void Back_Bag()///回到背包
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
/////需要修改
//int Online_Money(int P, int flag1, int flag2)///网上价钱
//{
//	int Highest = 0, Lowest = 100000, i;
//	i = Bidder[Bi].sum;
//	//printf("%d\n",i);
//	if (!i)
//	{
//		printf("\t\t\t\t\t\t\t\t目前没有价格信息\n");
//		return 0;
//	}
//	if (P)
//	{
//		if (flag1 == 1)//明拍
//		{
//			if (flag2 == 1)//正拍
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
//				printf("\t\t\t\t\t\t\t\t目前最高价格是: %d \n", Highest);
//			}
//			else//反拍
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
//				printf("目前最低价格是: %d \n", Lowest);
//			}
//		}
//		else//盲拍
//		{
//			if (flag2 == 1)//正拍
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
//			else//反拍
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
//	else//无最高价
//	{
//		if (flag1 == 1)//明拍
//		{
//			if (flag2 == 1)//正拍
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money > Highest)
//					{
//						F_H = k;
//						Highest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("\t\t\t\t\t\t\t\t目前最高价格是: %d \n", Highest);
//			}
//			else//反拍
//			{
//				for (int k = 0; k <= i; k++)
//				{
//					if (Bidder[Bi].Mark[k].Money < Lowest)
//					{
//						F_H = k;
//						Lowest = Bidder[Bi].Mark[k].Money;
//					}
//				}
//				printf("目前最低价格是: %d \n", Lowest);
//			}
//		}
//		else
//		{
//			if (flag2 == 1)//正拍
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
//			else//反拍
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
//int Time_minus(int p)///时间差
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
/////修改
//void Decide_Time(int B_n)///决定时间
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
//void Watch_Bag()///看看背包有什么物品
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
//		printf("\t\t\t\t\t\t\t\t*                  6、将物品放置拍卖平台上拍卖           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  7、增加物品                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  8、删除物品                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                  9、查看和修改物品信息                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                  10、删除竞拍物品操作                  *\n");
//		printf("\t\t\t\t\t\t\t\t*                  3、返回上一级                         *\n");
//		printf("\t\t\t\t\t\t\t\t*                  5、退出程序                           *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t请输入：");
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
//			printf("\t\t\t\t\t\t\t\t*                0、继续进行加入新物品操作               *\n");
//			printf("\t\t\t\t\t\t\t\t*                3、返回上一级；                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t请输入：");
//			scanf("%d", &choice3);
//			if (choice3 == 3)break;
//			while (1)
//			{
//				Add_Goods(i, n);
//				system("CLS");
//				//printf("\t\t\t\t\t\t\t\t亲，你已经完成增加物品操作 \n");
//				system("pause");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                  3、返回上一级                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                  5、退出程序                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
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
//			printf("\t\t\t\t\t\t\t\t*                  0、继续进行删除物品操作               *\n");
//			printf("\t\t\t\t\t\t\t\t*                  3、返回上一级                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t请输入：");
//			scanf("%d", &choice3);
//			system("CLS");
//			if (choice3 == 3)break;
//			while (1)
//			{
//				Del_Goods(i, n);
//				//printf("\t\t\t\t\t\t\t\t亲，你已经完成删除物品操作 \n");
//				system("pause");
//				system("CLS");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*                  3、返回上一级                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                  5、退出程序                           *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
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
//			printf("\t\t\t\t\t\t\t\t*                  0、继续进行删除竞拍物品操作           *\n");
//			printf("\t\t\t\t\t\t\t\t*                  3、返回上一级                         *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t请输入：");
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
//	printf("\t\t\t\t\t\t\t\t请输入你想下架物品的 编号：");
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
//		printf("\t\t\t\t\t\t\t\t亲，你已经完成删除竞拍物品操作 \n");
//
//
//	}
//	else printf("\t\t\t\t\t\t\t\t该物品准备拍卖 无法删除\n");
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
//void I_just_check(int i, int n)///随便翻翻背包物品
//{
//	int choice, Ui, Un, e;
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             1、按 重量 查找物品                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             2、按 年份 查找物品                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             3、按 价格 查找物品                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             4、按 编号 查找物品                        *\n");
//	printf("\t\t\t\t\t\t\t\t*             5、返回                                    *\n");
//	printf("\t\t\t\t\t\t\t\t*             6、退出程序                                *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//	printf("\t\t\t\t\t\t\t\t请输入：");
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
//		Quick_Sort(User, Ui, 0, User[Ui].Sum - 1, choice);//快排
//		printf("\t\t\t\t\t\t\t\t请输入你查找的相关信息：");
//		cin >> e;
//		Bin_Search(User, Ui, 0, User[Ui].Sum - 1, choice, e);//二分查找
//	}
//	WriteinFile(Un);
//	system("pause");
//	system("cls");
//
//
//}
//
//
//void Quick_Sort(USER User[], int Ui, int left, int right, int choice)///快排
//{
//	int i = left, j = right, t;
//	Bag_Goods T;
//	if (choice == 1)//重量
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
//	else if (choice == 2)//年份
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
//	else if (choice == 3)//价格
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
//	else if (choice == 4)//编号
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
//void Bin_Search(USER User[], int Ui, int left, int right, int choice, int e)///二分查找
//{
//	int i = left, j = right, mid, flag = 0;
//	if (choice == 1)//重量
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].weight)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t查找成功\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//
//
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].weight)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].weight)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
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
//			printf("\t\t\t\t\t\t\t\t查找失败\n");
//		}
//	}
//	else if (choice == 2)//年份
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].years)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t查找成功\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].years)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].years)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
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
//			printf("\t\t\t\t\t\t\t\t查找失败\n");
//		}
//	}
//	else if (choice == 3)//价格
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].Price)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t查找成功\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].Price)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].Price)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
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
//			printf("\t\t\t\t\t\t\t\t查找失败\n");
//		}
//	}
//	else if (choice == 4)//编号
//	{
//		while (j >= i)
//		{
//			mid = (i + j) / 2;
//			if (e == User[Ui].MyGoods[mid].G_ID)
//			{
//				flag = 1;
//				printf("\t\t\t\t\t\t\t\t查找成功\n");
//				//printf("   %d\n",mid);
//				Revise_Part_G(Ui, mid);
//				if (mid - 1 >= left)
//				{
//					if (e == User[Ui].MyGoods[mid - 1].G_ID)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
//						Revise_Part_G(Ui, mid - 1);
//					}
//				}
//
//
//				if (mid + 1 <= right)
//				{
//					if (e == User[Ui].MyGoods[mid + 1].G_ID)
//					{
//						printf("\t\t\t\t\t\t\t\t相似物品部分信息：\n");
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
//			printf("\t\t\t\t\t\t\t\t查找失败\n");
//
//
//		}
//	}
//}
//
//
//void Rank_Quick_Sort(RANK Rank[], int left, int right)///排行榜
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
//void Revise_Part_G(int Ui, int mid)///查看单一物品
//{
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t物品 编号：%d \n", User[Ui].MyGoods[mid].G_ID);
//	printf("\t\t\t\t\t\t\t\t物品名字：%s\n", User[Ui].MyGoods[mid].G_Name);
//	if (User[Ui].MyGoods[mid].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//	else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//
//
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*           物品描述：%s\n", User[Ui].MyGoods[mid].Desc);
//	printf("\t\t\t\t\t\t\t\t*           物品类型：%s\n", User[Ui].MyGoods[mid].size);
//	printf("\t\t\t\t\t\t\t\t*           物品估价：%d\n", User[Ui].MyGoods[mid].Price);
//	printf("\t\t\t\t\t\t\t\t*           物品重量：%d\n", User[Ui].MyGoods[mid].weight);
//	printf("\t\t\t\t\t\t\t\t*           物品年份：%d\n", User[Ui].MyGoods[mid].years);
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	if (User[Ui].MyGoods[mid].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//	else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//	cout << endl;
//}
//
//
//void Revise_G_ID(int i, int n)///按物品编号查询
//{
//	int T_ID;
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t请输入你想查询背包里的 物品编号:\n");
//	scanf("%d", &T_ID);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (T_ID == User[i].MyGoods[k].G_ID)
//		{
//			printf("\t\t\t\t\t\t\t\t物品名字：%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*         物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*         物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*         物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*         物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*         物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//			else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_Name(int i, int n)///按物品名字查询
//{
//	char T_Name[20];
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t请输入你想查询背包里的 物品名称：");
//	scanf("%s", T_Name);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (!strcmp(T_Name, User[i].MyGoods[k].G_Name))
//		{
//			printf("\t\t\t\t\t\t\t\t物品编号：%d\n", User[i].MyGoods[k].G_ID);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("拍卖物品新旧： 旧\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*          物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*          物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*          物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*          物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*          物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//			else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_New_Old(int i, int n)///按物品新旧查询
//{
//	int choice;
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t1、以 新物品 来查找\n");
//	printf("\t\t\t\t\t\t\t\t2、以 旧物品 来查找\n");
//	printf("\t\t\t\t\t\t\t\t请输入：");
//	scanf("%d", &choice);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (choice == User[i].MyGoods[k].New_old)
//		{
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*           物品编号：%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t*           物品名称：%s\n", User[i].MyGoods[k].G_Name);
//			printf("\t\t\t\t\t\t\t\t*           物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*           物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*           物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*           物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*           物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//			else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_G_State(int i, int n)///按物品拍卖查询
//{
//	int choice;
//
//
//	printf("\t\t\t\t\t\t\t\t1、打印拍卖物品\n");
//	printf("\t\t\t\t\t\t\t\t0、打印不拍卖物品\n\t\t\t\t\t\t\t\t请输入：\n");
//	scanf("%d", &choice);
//	cout << endl;
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (User[i].MyGoods[k].State == choice)
//		{
//			printf("\t\t\t\t\t\t\t\t物品编号：%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t物品名称：%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*          物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*          物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*          物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*          物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*          物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//
//void Revise_All_G(int i, int n)///查看所有物品
//{
//
//
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		cout << endl;
//		printf("\t\t\t\t\t\t\t\t物品编号：%d\n", User[i].MyGoods[k].G_ID);
//		printf("\t\t\t\t\t\t\t\t物品名称：%s\n", User[i].MyGoods[k].G_Name);
//		if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//		else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*         物品描述：%s\n", User[i].MyGoods[k].Desc);
//		printf("\t\t\t\t\t\t\t\t*         物品类型：%s\n", User[i].MyGoods[k].size);
//		printf("\t\t\t\t\t\t\t\t*         物品估价：%d\n", User[i].MyGoods[k].Price);
//		printf("\t\t\t\t\t\t\t\t*         物品重量：%d\n", User[i].MyGoods[k].weight);
//		printf("\t\t\t\t\t\t\t\t*         物品年份：%d\n", User[i].MyGoods[k].years);
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//		else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//		cout << endl;
//		cout << endl;
//	}
//}
//
//
//void Revise_G_size(int i, int n)///物品类型
//{
//
//
//	char T_size[40];
//	printf("\t\t\t\t\t\t\t\t请输入物品的 类型: ");
//	scanf("%s", T_size);
//	for (int k = 0; k < User[i].Sum; k++)
//	{
//		if (!strcmp(T_size, User[i].MyGoods[k].size))
//		{
//			cout << endl;
//			printf("\t\t\t\t\t\t\t\t物品编号：%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t物品名称：%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//
//
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*             物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*             物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*             物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*             物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*             物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//			else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
//			cout << endl;
//			cout << endl;
//		}
//	}
//}
//
//
//void GoodTraverse(int i, int n)///查看物品
//{
//	system("cls");
//	int choice, choice2;
//	printf("\t\t\t\t\t\t\t\t目前你拥有 %d 物品\n", User[i].Sum);
//	if (!User[i].Sum)printf("\t\t\t\t\t\t\t\t背包为空，可以返回进行添加物品操作\n");
//	else
//	{
//		while (1)
//		{
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*                0、继续查看修改物品                     *\n");
//			printf("\t\t\t\t\t\t\t\t*                3、返回                                 *\n");
//			printf("\t\t\t\t\t\t\t\t*                5、退出程序                             *\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//			printf("\t\t\t\t\t\t\t\t请输入：");
//			scanf("%d", &choice);
//			if (choice == 3)break;
//			switch (choice)
//			{
//			case 5:
//				exit(0);
//			case 0:
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t*              1、按 物品编号 来查询                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              2、按 物品名字 来查询                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              3、按 物品新旧 来查询                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              4、按 物品参与 拍卖 来查询                *\n");
//				printf("\t\t\t\t\t\t\t\t*              5、按物品 类型 来查询                     *\n");
//				printf("\t\t\t\t\t\t\t\t*              6、查询 所有 物品                         *\n");
//				printf("\t\t\t\t\t\t\t\t*              7、二分 查找 物品                         *\n");
//				printf("\t\t\t\t\t\t\t\t*              8、修改物品信息                           *\n");
//				printf("\t\t\t\t\t\t\t\t*              9、查询 拍卖得到的 物品                   *\n");
//				printf("\t\t\t\t\t\t\t\t*              10、返回                                  *\n");
//				printf("\t\t\t\t\t\t\t\t*              11、退出程序                              *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//				printf("\t\t\t\t\t\t\t\t请输入：");
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
//					Change_Good(i, n);//改变物品信息
//					system("PAUSE");
//					system("cls");
//					break;
//				case 9:
//					Flag_Good(i, n);//拍卖得到的物品
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
//			printf("\t\t\t\t\t\t\t\t物品编号：%d\n", User[i].MyGoods[k].G_ID);
//			printf("\t\t\t\t\t\t\t\t物品名称：%s\n", User[i].MyGoods[k].G_Name);
//			if (User[i].MyGoods[k].New_old == 1)printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 新\n");
//			else printf("\t\t\t\t\t\t\t\t拍卖物品新旧： 旧\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t*         物品描述：%s\n", User[i].MyGoods[k].Desc);
//			printf("\t\t\t\t\t\t\t\t*         物品类型：%s\n", User[i].MyGoods[k].size);
//			printf("\t\t\t\t\t\t\t\t*         物品估价：%d\n", User[i].MyGoods[k].Price);
//			printf("\t\t\t\t\t\t\t\t*         物品重量：%d\n", User[i].MyGoods[k].weight);
//			printf("\t\t\t\t\t\t\t\t*         物品年份：%d\n", User[i].MyGoods[k].years);
//			printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//			printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//			if (User[i].MyGoods[k].State)printf("\t\t\t\t\t\t\t\t物品拍卖\n");
//			else printf("\t\t\t\t\t\t\t\t物品不拍卖\n");
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
//	printf("\t\t\t\t\t\t\t\t请输入你想改变信息的 物品 编号：");
//	scanf("%d", &e);
//	for (j = 0; j < User[Ui].Sum; j++)
//	{
//		if (User[Ui].MyGoods[j].G_ID == e)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\t没有该物品\n");
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的名字：");
//		scanf("%s", User[Ui].MyGoods[j].G_Name);
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的描述：");
//		scanf("%s", User[Ui].MyGoods[j].Desc);
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的类别：");
//		scanf("%s", User[Ui].MyGoods[j].size);
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的估价：");
//		scanf("%d", &User[Ui].MyGoods[j].Price);
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的年份：");
//		scanf("%d", &User[Ui].MyGoods[j].years);
//		printf("\t\t\t\t\t\t\t\t请重新输入你物品的重量（单位 克）：");
//		scanf("%d", &User[Ui].MyGoods[j].weight);
//		User[Ui].MyGoods[j].State = 0;
//		printf("\t\t\t\t\t\t\t\t修改成功\n");
//	}
//	WriteinFile(Un);
//
//
//}
//
//
//void Del_Goods(int i, int n)///删除物品
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
//	printf("\t\t\t\t\t\t\t\t输入你想删除物品的 编号：");
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
//	if (!flag)printf("\t\t\t\t\t\t\t\t你想删除的物品不存在 \n\t\t\t\t\t\t\t\t请退出操作 重新确认物品信息\n");
//	else if (flag == 2)printf("\t\t\t\t\t\t\t\t你想删除的物品拍卖中 \n\t\t\t\t\t\t\t\t不可以删除物品信息\n");
//
//
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t删除  物品 成功！\n");
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
//void Add_Goods(int i, int n)///增加物品
//{
//	T_G *p, *head = NULL, *tail = NULL, *p1, *p2 = NULL;
//	int j;
//	n = Read_U_All_File();
//	i = Read_U_Part_File(n);
//	//printf("  %d  \n",User[i].Sum);
//	if (User[i].Sum == 20)
//	{
//		printf("\t\t\t\t\t\t\t\t背包已满!\n");
//		printf("\t\t\t\t\t\t\t\t请先将不需拍卖的物品从背包下架\n");
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
//	printf("\t\t\t\t\t\t\t\t你想增加几件物品：");
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
//		printf("\t\t\t\t\t\t\t\t第%d间物品编号:  ", j + 1);
//		while (1)
//		{
//			p1 = head;
//			scanf("%d", &p->G_ID);
//			while (p1 != p)
//			{
//				if (p->G_ID == p1->G_ID&&p1 != p)
//				{
//					printf("\t\t\t\t\t\t\t\t  %d  ", p->G_ID);
//					printf("\t\t\t\t\t\t\t\t物品编号已经存在！\n");
//					printf("\t\t\t\t\t\t\t\t请重新输入物品编号:");
//					break;
//				}
//				p1 = p1->next;
//				if (p1 == p)break;
//			}
//			if (p1 == p)break;
//		}
//
//
//		printf("\t\t\t\t\t\t\t\t物品名称:");
//		scanf("%s", p->G_Name);
//
//
//		printf("\t\t\t\t\t\t\t\t(输入 1、 New or 2、 Old)\n\t\t\t\t\t\t\t\t物品新旧 :");
//		scanf("%d", &p->New_old);
//
//
//		printf("\t\t\t\t\t\t\t\t物品描述:");
//		scanf("%s", p->Desc);
//
//
//		printf("\t\t\t\t\t\t\t\t物品类型:");
//		scanf("%s", p->size);
//
//
//
//
//		printf("\t\t\t\t\t\t\t\t物品年份:");
//		scanf("%d", &p->years);
//		//printf("  %d ", p->years);
//
//
//		printf("\t\t\t\t\t\t\t\t物品估价:");
//		while (1)
//		{
//			scanf("%d", &p->Price);
//			if (p->Price > 0 && p->Price < 99999)break;
//			printf("\t\t\t\t\t\t\t\t输入价格有误！\n");
//			printf("\t\t\t\t\t\t\t\t重新输入价格：");
//		}
//
//
//		//printf("  %lf ", p->Price);
//
//
//		printf("\t\t\t\t\t\t\t\t物品重量（单位 克）:");
//		scanf("%d", &p->weight);
//		//printf("  %lf ", p->weight);
//
//
//		p->State = 0; //状态
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
//	printf("\t\t\t\t\t\t\t\t物品增加完成！\n");
//	system("Pause");
//}
//
//
//void Revise_User_Info()///修改用户信息
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
//	printf("\t\t\t\t\t\t\t\t*                你目前所有的信息：\n");
//	printf("\t\t\t\t\t\t\t\t*                名字：%s\n", User[i].Name);
//	printf("\t\t\t\t\t\t\t\t*                性别：%s\n", User[i].Sex);
//	printf("\t\t\t\t\t\t\t\t*                手机号码：%s\n", User[i].Pho_num);
//	printf("\t\t\t\t\t\t\t\t*                邮箱：%s\n", User[i].Mail);
//	printf("\t\t\t\t\t\t\t\t*                个性签名：%s\n", User[i].Spec);
//	printf("\t\t\t\t\t\t\t\t*                密码：%s\n", User[i].Password);
//	printf("\t\t\t\t\t\t\t\t*                目前背包物品数量：%d\n", User[i].Sum);
//	printf("\t\t\t\t\t\t\t\t*                信誉分：%d \n", User[i].score);
//	printf("\t\t\t\t\t\t\t\t*                地址：%s\n", User[i].Address);
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//	cout << endl;
//	printf("\t\t\t\t\t\t\t\t请输入你想进行的操作\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t*               1、修改手机号码                          *\n");
//	printf("\t\t\t\t\t\t\t\t*               2、修改邮箱                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               3、修改密码                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               4、个性签名                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               5、收货地址                              *\n");
//	printf("\t\t\t\t\t\t\t\t*               6、返回上一步                            *\n");
//	printf("\t\t\t\t\t\t\t\t*               0、退出程序                              *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//	printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//	printf("\t\t\t\t\t\t\t\t请输入：");
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
//void Revise_User_Info_Address(int i, int j)///修改地址
//{
//	printf("\t\t\t\t\t\t\t\t请重新输入你的地址: ");
//	scanf("%s", User[i].Address);
//	WriteinFile(j);
//}
//
//
//void Revise_User_Info_Spec(int i, int j)///修改个性签名
//{
//	printf("\t\t\t\t\t\t\t\t请重新输入你的个性签名: ");
//	scanf("%s", User[i].Spec);
//	WriteinFile(j);
//}
//
//
//void Revise_User_Info_Password(int i, int j)///修改密码
//{
//	char T_Password[20];
//	int count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t请输入你以前的密码：");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Password);
//		if (!strcmp(T_Password, User[i].Password))
//		{
//			flag = 0;
//			printf("\t\t\t\t\t\t\t\t请输入你的新密码:");
//			scanf("%s", T_Password);
//			strcpy(User[i].Password, T_Password);
//			break;
//		}
//		else
//		{
//			printf("\t\t\t\t\t\t\t\t密码输入错误 你还有%d次机会输入密码\n", count);
//			printf("\t\t\t\t\t\t\t\t请重新输入密码:");
//		}
//	}
//	if (!flag)
//	{
//		WriteinFile(j);
//		printf("\t\t\t\t\t\t\t\t修改密码成功！\n");
//	}
//	else printf("\t\t\t\t\t\t\t\t修改密码失败\n");
//	system("PAUSE");
//}
//
//
//void Revise_User_Info_Mail(int i, int j)///修改邮箱
//{
//	char T_Mail[20];
//	int k, count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t请输入你以前的邮箱：");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Mail);
//		if (!strcmp(T_Mail, User[i].Mail))
//		{
//			printf("\t\t\t\t\t\t\t\t请输入你新的邮箱：");
//			while (1)
//			{
//				scanf("%s", T_Mail);
//				for (k = 0; k <= j; k++)
//				{
//					if (!strcmp(T_Mail, User[k].Mail) && k != i)break;
//				}
//				if (k > j)
//				{
//					printf("\t\t\t\t\t\t\t\t修改邮箱成功！\n");
//					flag = 0;
//					break;
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\t邮箱已经被注册！\n");
//					printf("\t\t\t\t\t\t\t\t重新请输入你新的邮箱：");
//				}
//			}
//		}
//		if (!flag)break;
//		if (flag)printf("\t\t\t\t\t\t\t\t你还有%d次机会输入你以前的邮箱\n", count);
//	}
//	if (flag && !count)printf("\t\t\t\t\t\t\t\t修改邮箱失败\n");
//	if (!flag)//有可能bug
//	{
//		strcpy(User[i].Mail, T_Mail);
//		WriteinFile(j);
//		//printf("\t\t\t\t\t\t\t\t修改邮箱成功!\n");
//	}
//	system("Pause");
//}
//
//
//void Revise_User_Info_Pho_Num(int i, int j)///修改手机号码
//{
//	char T_Pho_Num[20];
//	int k, count = 4, flag;
//	printf("\t\t\t\t\t\t\t\t请输入你以前的手机号码：");
//	while (count--)
//	{
//		flag = 1;
//
//
//		scanf("%s", T_Pho_Num);
//		if (!strcmp(T_Pho_Num, User[i].Pho_num))
//		{
//			printf("\t\t\t\t\t\t\t\t请输入你新的手机号码：");
//			while (1)
//			{
//				scanf("%s", T_Pho_Num);
//				for (k = 0; k <= j; k++)
//				{
//					if (!strcmp(T_Pho_Num, User[k].Pho_num) && k != i)break;
//				}
//				if (k > j)
//				{
//					printf("\t\t\t\t\t\t\t\t修改手机号码成功！\n");
//					flag = 0;
//					break;
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\t手机号码已经存在！\n");
//					printf("\t\t\t\t\t\t\t\t重新请输入你新的手机号码：");
//				}
//			}
//		}
//		if (!flag)break;
//		if (flag)printf("\t\t\t\t\t\t\t\t你还有%d次机会输入你以前的手机号码\n", count);
//	}
//	if (flag && !count)printf("\t\t\t\t\t\t\t\t修改手机号码失败\n");
//	if (!flag)//有可能bug
//	{
//		strcpy(User[i].Pho_num, T_Pho_Num);
//		WriteinFile(j);
//		//printf("\t\t\t\t\t\t\t\t修改手机号码成功!\n");
//	}
//	system("PAUSE");
//}
//
//
//void Register()///注册账户
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
//		printf("\t\t\t\t\t\t\t\t服务器满载\n");
//		printf("\t\t\t\t\t\t\t\t等待系统升级\n");
//		system("pause");
//		return;
//	}
//	printf("\t\t\t\t\t\t\t\t请输入你的姓名：");
//	scanf("%s", User[i].Name);
//	printf("\t\t\t\t\t\t\t\t请输入你的性别：");
//	scanf("%s", User[i].Sex);
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的手机号码：");
//	while (k)
//	{
//		scanf("%s", User[i].Pho_num);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Pho_num, User[i].Pho_num))
//			{
//				printf("\t\t\t\t\t\t\t\t手机号码已经被注册！\n");
//				printf("\t\t\t\t\t\t\t\t请重新输入手机号码：");
//				break;
//			}
//		}
//		if (strlen(User[i].Pho_num) != 11)
//		{
//			k = 1;
//			printf("\t\t\t\t\t\t\t\t非法手机号码\n\t\t\t\t\t\t\t\t请重新输入手机号码:");
//		}
//		else if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的邮箱：");
//	k = 1;
//	while (k)
//	{
//		scanf("%s", User[i].Mail);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Mail, User[i].Mail))
//			{
//				printf("\t\t\t\t\t\t\t\t邮箱已经被注册！\n");
//				printf("\t\t\t\t\t\t\t\t请重新输入邮箱：");
//				break;
//			}
//		}
//		if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的地址：");
//	scanf("%s", User[i].Address);
//
//
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的个性签名：");
//	scanf("%s", User[i].Spec);
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的账号：");
//	k = 1;
//	while (k)
//	{
//		scanf("%s", User[i].Acc_num);
//		for (j = 0; j < i; j++)
//		{
//			if (!strcmp(User[j].Acc_num, User[i].Acc_num))
//			{
//				printf("\t\t\t\t\t\t\t\t账号已经被注册！\n");
//				printf("\t\t\t\t\t\t\t\t请重新输入账号：");
//				break;
//			}
//		}
//		if (j >= i)k = 0;
//	}
//
//
//	printf("\t\t\t\t\t\t\t\t请输入你的密码：");
//	//scanf("%s",User[i].Password);
//	Password_Undisplay(User[i].Password);
//
//
//	User[i].Sum = 0;
//	User[i].score = 5;//信誉积分
//	printf("\t\t\t\t\t\t\t\t\n背包物品数量为 0\n");
//	printf("\t\t\t\t\t\t\t\t初始用户信誉度积分为 5 分\n");
//	//User[i].MyGoods[1].G_ID=1;
//
//
//	printf("\t\t\t\t\t\t\t\t\n注册成功\n");
//
//
//	if ((fp = fopen("User.txt", "wb")) == NULL)
//	{
//		printf("\t\t\t\t\t\t\t\t文件不存在\n");
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
//void Login()///登录账户
//{
//	FILE *fp;
//	//USER User[100];
//	fp = fopen("User.txt", "rb");
//	int i = 0, flag1 = 0, count = 4;
//	printf("\t\t\t\t\t\t\t\t请输入你的 账号、邮箱或手机号码：");
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
//		else printf("\t\t\t\t\t\t\t\t账号不存在 你还有%d机会输入账号\n \t\t\t\t\t\t\t\t请重新输入你的 账号、邮箱或手机号码：", count);
//	}
//	fclose(fp);
//	if (count == -1)
//	{
//		printf("\n\t\t\t\t\t\t\t\t强制退出程序中...\n");
//		system("\t\t\t\t\t\t\t\tpause");
//		exit(0);
//	}
//	count = 4;
//	if (flag1)
//	{
//		while (count--)
//		{
//			printf("\t\t\t\t\t\t\t\t请输入你的密码：");
//			//scanf("%s",Tpassword);
//			Password_Undisplay(Tpassword);
//			//printf("%s  %s\n",Tpassword,User[i].Password);
//			//system("pause");
//			if (!strcmp(Tpassword, User[i].Password))
//			{
//				system("CLS");
//				Login_welcome();
//				printf("\t\t\t\t\t\t\t\t欢迎登陆 %s\n", User[i].Acc_num);
//				//for(int j=0;j<strlen(User[i].Acc_num);j++)T[j]=User[i].Acc_num[j];
//				strcpy(T, User[i].Acc_num);
//				UN = Un;
//				UI = i;
//				//printf("欢迎登陆 %s\n",T);
//				break;
//			}
//			else
//			{
//				system("CLS");
//				Login_Warning();
//				memset(Tpassword, '\0', sizeof(char));
//				printf("\t\t\t\t\t\t\t\t密码错误,请输入输入密码\n");
//				printf("\t\t\t\t\t\t\t\t你还有 %d 次输入机会\n", count);
//			}
//		}
//		//cout<<count<<endl;
//		if (count == -1)exit(0);
//	}
//	else
//	{
//		printf("\t\t\t\t\t\t\t\t手机电话 、 用户名 或 邮箱不存在或输入错误函数\n");
//		memset(T, '\0', sizeof(char));
//		//system("pause");
//		system("cls");
//	}
//
//
//}
//
//
//void Cancel()///注销
//{
//	memset(T, '\0', sizeof(char));
//	memset(Tpassword, '\0', sizeof(char));
//	printf("\t\t\t\t\t\t\t\t你已经退出了账号了\n");
//	system("pause");
//	system("CLS");
//}
//
//
//void Revise_Online()///直接查询
//{
//
//
//	int choice;
//	while (1)
//	{
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                1、查询 竞拍物品                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                2、查询 用户信息                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                3、查看 排行榜                          *\n");
//		printf("\t\t\t\t\t\t\t\t*                4、返回                                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                5、退出                                 *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//		printf("\t\t\t\t\t\t\t\t请输入：");
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
//void Revise_Online_Good()///直接查看竞拍物品
//{
//	int i, flag = 0;
//	int B_i, B_n;
//	char Bid_Name[20];
//	printf("\t\t\t\t\t\t\t\t请输入 你想 查询 物品的名称：");
//	scanf("%s", Bid_Name);
//	B_n = ReadALL_BFile();
//	B_i = Read_B_PartFile(B_n);
//	for (i = B_i; i < B_n; i++)
//	{
//		if (!strcmp(Bid_Name, Bidder[i].B_Name))
//		{
//			flag = 1;
//			printf("\t\t\t\t\t\t\t\t物品的 价格起价为：%d \n", Bidder[i].B_Price);
//			if (Bidder[i].B_H_Price == 1)
//			{
//				printf("\t\t\t\t\t\t\t\t物品支持一口价\n");
//				printf("\t\t\t\t\t\t\t\t物品一口价 ：%d \n", Bidder[i].B_H_Price);
//			}
//			else  printf("\t\t\t\t\t\t\t\t物品不支持一口价\n");
//			if (Bidder[i].Z_F == 1)printf("\t\t\t\t\t\t\t\t物品拍卖方式 为 正拍\n");
//			else printf("\t\t\t\t\t\t\t\t物品拍卖方式 为 反拍\n");
//			if (Bidder[i].M_M == 1)printf("\t\t\t\t\t\t\t\t物品价格信息实时更新\n");
//			else printf("\t\t\t\t\t\t\t\t物品价格信息最后公布\n");
//
//
//			printf("\t\t\t\t\t\t\t\t物品重量 %d g", Bidder[i].B_weight);
//			printf("\t\t\t\t\t\t\t\t物品年份 %d ", Bidder[i].B_years);
//			if (Bidder[i].B_New_old == 1)printf("\t\t\t\t\t\t\t\t物品新旧状况：新\n");
//			else printf("\t\t\t\t\t\t\t\t物品新旧状况：旧\n");
//			printf("\t\t\t\t\t\t\t\t物品描述 :%s \n", Bidder[i].B_Desc);
//
//
//			printf("\t\t\t\t\t\t\t\t物品将在 %04d %02d %02d %02d %02d %02d 开始拍卖\n", Bidder[i].B_Time.Year, Bidder[i].B_Time.Month, Bidder[i].B_Time.Day, Bidder[i].B_Time.Hour, Bidder[i].B_Time.Min, Bidder[i].B_Time.Sec);
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\t没有找到相关物品\n");
//	else printf("\t\t\t\t\t\t\t\t马上登陆 进行拍卖？\n");
//	system("pause");
//	system("cls");
//
//
//}
//
//
//void Revise_Online_User()///直接查看用户信息
//{
//	int Un, flag = 0;
//	char User_Name[20];
//	Un = Read_U_All_File();
//	printf("\t\t\t\t\t\t\t\t请输入你想查找 用户 的账号: ");
//	scanf("%s", User_Name);
//	for (int i = 0; i < Un; i++)
//	{
//		if (!strcmp(User_Name, User[i].Acc_num))
//		{
//			flag = 1;
//			printf("\t\t\t\t\t\t\t\t该用户信誉度：%d\n", User[i].score);
//			printf("\t\t\t\t\t\t\t\t该用户个性签名:%s\n", User[i].Spec);
//		}
//	}
//	if (!flag)printf("\t\t\t\t\t\t\t\t没有该用户信息\n");
//	system("pause");
//}
//
//
//void Menu()///开头目录
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
//	printf(" |||                                                                                                  【 1 】  用户登录                                                                                                                   |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  【 2 】  用户注册                                                                                                                   |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  【 4 】  查询                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  【 5 】  退出                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  【 6 】  帮助                                                                                                                       |||");
//	printf(" |||                                                                                                                                                                                                                                      |||");
//	printf(" |||                                                                                                  【 7 】  关于作者                                                                                                                   |||");
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
//void Help()///帮助
//{
//	int choice;
//	while (1)
//	{
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t*                 1、使用须知                            *\n");
//		printf("\t\t\t\t\t\t\t\t*                 2、领取礼品                            *\n");
//		printf("\t\t\t\t\t\t\t\t*                 3、返回                               *\n");
//		printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//		printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//
//
//		printf("\t\t\t\t\t\t\t\t请输入：");
//		scanf("%d", &choice);
//		if (choice == 3)break;
//		if (choice == 1)Mannel();//用户手册
//		if (choice == 2)Receive_rewards();//领取奖励
//		system("cls");
//	}
//}
//
//
//void Mannel()///用户手册
//{
//	printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      此平台用于各个用户自由拍卖自己的物品                     *\n");
//	printf("\t\t\t\t\t\t\t\t*      各个用户拥有自己的背包                                   *\n");
//	printf("\t\t\t\t\t\t\t\t*      背包的容量为20件物品 所以记得将不需拍卖的物品清空哦      *\n");
//	printf("\t\t\t\t\t\t\t\t*      各个用户通过竞拍获得 信誉度 的 提升                      *\n");
//	printf("\t\t\t\t\t\t\t\t*      相反 用户 如果 流拍 删除竞拍物品 信誉度 会 下降          *\n");
//	printf("\t\t\t\t\t\t\t\t*      删除自己背包物品 不会有任何影响                          *\n");
//	printf("\t\t\t\t\t\t\t\t*      信誉度不仅可以考虑 买家/卖家的 诚信程度                  *\n");
//	printf("\t\t\t\t\t\t\t\t*      信誉度还可以换取 一定的 奖品                             *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      每件物品竞拍时可以多次输入价钱  价高者得                 *\n");
//	printf("\t\t\t\t\t\t\t\t*      每件物品竞拍时  输入一次信息后就自动退出更新信息         *\n");
//	printf("\t\t\t\t\t\t\t\t*      每件物品竞拍时  可以 卡秒 进行 报价                      *\n");
//	printf("\t\t\t\t\t\t\t\t*      每件物品都拍卖时间为 60 秒                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      拍卖物品模式 为 Frist in Frist out                       *\n");
//	printf("\t\t\t\t\t\t\t\t*      前面竞拍物品的开始时间 比 后面物品 快>= 60s              *\n");
//	printf("\t\t\t\t\t\t\t\t*      下一件物品还没开始拍卖时 需要等待                        *\n");
//	printf("\t\t\t\t\t\t\t\t*      每件竞拍物品可以进行删除 但有时间限制                    *\n");
//	printf("\t\t\t\t\t\t\t\t*      删除后可以在自己背包中修改物品信息                       *\n");
//	printf("\t\t\t\t\t\t\t\t*      输入价格 范围为 1 到 99999                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      你可以通过注册账号进行进一步的了解                       *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      用户 账号 密码 性别  个性签名 最多可以存放 16 字符       *\n");
//	printf("\t\t\t\t\t\t\t\t*      用户 手机 一定是 11 位 数字                              *\n");
//	printf("\t\t\t\t\t\t\t\t*      用户 背包 物品信息 修改时 类似                           *\n");
//	printf("\t\t\t\t\t\t\t\t*      输入数据时 应该按照相关指引                              *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*      如果出现bug 那肯定不关本程序员的问题   逃~               *\n");
//	printf("\t\t\t\t\t\t\t\t*              肯定是 陈老偷偷加上去的                          *\n");
//	printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//	printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//
//
//	char Test[50];
//	printf("\t\t\t\t\t\t\t\t请输入 “ 我已阅读完毕 ”\n");
//	printf("\t\t\t\t\t\t\t\t请输入 ：");
//	scanf("%s", Test);
//
//
//	system("Pause");
//}
//
//
//void Receive_rewards()///领取奖励
//{
//	if (T[0] == '\0')
//	{
//		printf("\t\t\t\t\t\t\t\t请先进行登录操作\n");
//		system("Pause");
//		system("cls");
//	}
//	else
//	{
//		int Ui, choice;
//		//Un=Read_U_All_File();
//		//Ui=Read_U_Part_File(Un);
//		Ui = UI;
//		printf("\t\t\t\t\t\t\t\t0、打扰了\n");
//		printf("\t\t\t\t\t\t\t\t信誉度积分     奖品\n");
//		printf("\t\t\t\t\t\t\t\t1、5           男票\n");
//		printf("\t\t\t\t\t\t\t\t2、500         小米手环3\n");
//		printf("\t\t\t\t\t\t\t\t3、1500        GTX1080Ti\n");
//		printf("\t\t\t\t\t\t\t\t4、2500        俄罗斯世界杯总决赛门票\n");
//		printf("\t\t\t\t\t\t\t\t请输入：");
//		scanf("%d", &choice);
//		if (!choice)return;
//		if (choice == 1 && User[Ui].score >= 5)printf("\t\t\t\t\t\t\t\t正在送往 %s \n", User[Ui].Address);
//		else if (choice == 2 && User[Ui].score >= 500)printf("\t\t\t\t\t\t\t\t正在送往 %s \n", User[Ui].Address);
//		else if (choice == 3 && User[Ui].score >= 1500)printf("\t\t\t\t\t\t\t\t正在送往 %s \n", User[Ui].Address);
//		else if (choice == 4 && User[Ui].score >= 2500)printf("\t\t\t\t\t\t\t\t正在送往 %s \n", User[Ui].Address);
//		else printf("\t\t\t\t\t\t\t\t信誉度不够\n");
//		system("Pause");
//		system("cls");
//	}
//}
//
//
//void About_Author()///关于作者 可以扩展
//{
//	int choice, choice2;
//	char Admin[20];
//	printf("\t\t\t\t\t\t\t\t1、管理者登录\n");
//	printf("\t\t\t\t\t\t\t\t2、关于作者\n");
//	printf("\t\t\t\t\t\t\t\t请输入：");
//	scanf("%d", &choice);
//	if (choice == 1)
//	{
//		printf("\t\t\t\t\t\t\t\t请输入 管理验证码 :");
//		scanf("%s", Admin);
//		if (strlen(Admin) < 6 && (Admin[0] == 'A' || Admin[0] == 'a') && (Admin[1] == 'D' || Admin[1] == 'd') && (Admin[2] == 'M' || Admin[2] == 'm') && (Admin[3] == 'I' || Admin[3] == 'i') && (Admin[4] == 'N' || Admin[4] == 'n'))
//		{
//			printf("\t\t\t\t\t\t\t\t1、查看 所有 曾经放在 拍卖平台上的 物品信息\n");
//			printf("\t\t\t\t\t\t\t\t2、修改用户信息\n");
//			printf("\t\t\t\t\t\t\t\t请输入：");
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
//						printf("已经拍卖完成的物品：\n");
//						printf("物品名称：%s\n", Bidder[i].B_Name);
//						printf("物品起价：%d\n", Bidder[i].B_Price);
//						//printf("物品最高价：%d\n",Bidder[i].B_H_Price);
//						printf("物品年份：%d\n", Bidder[i].B_years);
//						printf("物品重量：%d\n", Bidder[i].B_weight);
//						printf("物品描述：%s\n", Bidder[i].B_Desc);
//
//
//						printf("物品原主人：%s\n", Bidder[i].Haver);
//						if (Bidder[i].Ber[0] != '\0')printf("物品得主：%s\n", Bidder[i].Ber);
//						if (Bidder[i].flag1 == 4)printf("物品 恢复 原来得主\n");
//						else if (Bidder[i].flag1 == 3 && Bidder[i].flag2 == 1)printf("物品被买走\n");
//						else if (Bidder[i].flag1 == 3 && Bidder[i].flag2 == 2)printf("物品流拍\n");
//						else if (Bidder[i].flag1 == 6)printf("物品以价格>=最高价被买走\n");
//						cout << endl;
//						if (Bidder[i].sum >= 1)
//						{
//							printf("竞拍人        竞拍价         竞拍时间 \n");
//							for (int j = 1; j <= Bidder[i].sum; j++)printf("%s        %d         %04d %02d %02d %02d %02d %02d\n", Bidder[i].Mark[j].Next_Haver_Name, Bidder[i].Mark[j].Money, Bidder[i].Mark[j].Ye, Bidder[i].Mark[j].Mo, Bidder[i].Mark[j].Da, Bidder[i].Mark[j].Ho, Bidder[i].Mark[j].Mi, Bidder[i].Mark[j].Se);
//						}
//					}
//					else
//					{
//						printf("已经开始 或 未开始 拍卖物品：\n");
//						printf("物品名称：%s\n", Bidder[i].B_Name);
//						printf("物品起价：%d\n", Bidder[i].B_Price);
//						//printf("物品最高价：%d\n",Bidder[i].B_H_Price);
//						printf("物品年份：%d\n", Bidder[i].B_years);
//						printf("物品重量：%d\n", Bidder[i].B_weight);
//						printf("物品描述：%s\n", Bidder[i].B_Desc);
//
//
//						printf("物品原主人：%s\n", Bidder[i].Haver);
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
//				printf("\t\t\t\t\t\t\t\t请输入你想修改 用户 信息的 账号:");
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
//					printf("\t\t\t\t\t\t\t\t请输入你想修改 用户 的 新密码：");
//					scanf("%s", User[Ui].Password);
//					WriteinFile(Un);
//					printf("\t\t\t\t\t\t\t\t修改成功\n");
//					system("pause");
//				}
//				else
//				{
//					printf("\t\t\t\t\t\t\t\t没有相关用户\n");
//					system("pause");
//				}
//			}
//		}
//		else
//		{
//			printf("\t\t\t\t\t\t\t\t输入错误\n");
//			system("pause");
//		}
//	}
//	else if (choice == 2)
//	{
//		char T[20];
//		printf("\t\t\t\t\t\t\t\t回答问题，触发彩蛋\n");
//		printf("\t\t\t\t\t\t\t\t请输入 作者名字：");
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
//			printf("\n\t\t\t\t\t\t\t\t正如  头号玩家 一样，彩蛋就是彩蛋\n\n\n");
//			printf("\t\t\t\t\t\t\t\t花费大量的时间与精力寻找彩蛋就是 玩游戏 的过程，“just for fun” \n\n\n");
//
//
//
//
//			printf("SCAU_17 0212 Luo.T4 \n");
//			system("pause");
//		}
//		else printf("输入错误 ！\n");
//	}
//}
//
//
//void delay(double second)///登录延迟
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
//void Password_Undisplay(char Pw[])///密码显示
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
//void Login_Warning()///密码错误
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
//void Login_welcome()///欢迎登录
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
/////用户信息
//int Read_U_All_File()///读取全部文件
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
//int Read_U_Part_File(int n)///读取关键文件
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
//void WriteinFile(int i)///写入文件
//{
//	FILE *fp;
//	fp = fopen("User.txt", "wb");
//	for (int k = 0; k < i; k++)fwrite(&User[k], sizeof(USER), 1, fp);
//	fclose(fp);
//}
//
//
/////竞拍物品
//int ReadALL_BFile()///读取拍卖物品文件
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
//void Write_B_inFile(int i)///写入文件
//{
//	FILE *fp;
//	fp = fopen("Bidder.txt", "wb");
//	for (int k = 0; k < i; k++)fwrite(&Bidder[k], sizeof(BIDDER), 1, fp);
//	fclose(fp);
//}
//
//
//int Read_B_PartFile(int B_n)///读取第一个flag1==1
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
//void Rank_Read(int Un)///读取用户信誉度
//{
//	for (int j = 0; j < Un; j++)
//	{
//		strcpy(Rank[j].Name, User[j].Acc_num);
//		Rank[j].score = User[j].score;
//	}
//}
//
//
//void Revise_Online_Rank()///查看排行榜
//{
//	int Un = Read_U_All_File(), n, j, k;
//	Rank_Read(Un);
//	Rank_Quick_Sort(Rank, 0, Un - 1);//排行榜
//	if (Un >= 20)n = 20;
//	else n = Un;
//	printf("以下是 信誉度 最高的 前 %d 位 用户\n", n);
//	printf("用户名                信誉分\n");
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
//void Jugel()///判断是否 支付 流拍
//{
//	Bn = ReadALL_BFile();
//	Bi = Read_B_PartFile(Bn);
//	int i, choice, flag = 0;
//	Overdue();//过期没人要的东西
//	Back_Bag();//回到背包；
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
//				printf("\t\t\t\t\t\t\t\t*       拍卖物品名字： %s\n", Bidder[i].B_Name);
//				printf("\t\t\t\t\t\t\t\t*       拍卖物品描述： %s\n", Bidder[i].B_Desc);
//				printf("\t\t\t\t\t\t\t\t*       拍卖物品类型： %s\n", Bidder[i].B_size);
//				printf("\t\t\t\t\t\t\t\t*       拍卖物品起拍价： %d\n", Bidder[i].B_Price);
//				printf("\t\t\t\t\t\t\t\t*       拍卖物品重量： %d\n", Bidder[i].B_weight);
//				printf("\t\t\t\t\t\t\t\t*                                                        *\n");
//				printf("\t\t\t\t\t\t\t\t**********************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//				printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//				printf("\t\t\t\t\t\t\t\t*                              1 、支付                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                              2 、流拍                         *\n");
//				printf("\t\t\t\t\t\t\t\t*                                                               *\n");
//				printf("\t\t\t\t\t\t\t\t*****************************************************************\n");
//				printf("\t\t\t\t\t\t\t\t请输入：");
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
//		printf("\t\t\t\t\t\t\t\t*                        So Sad！                               *\n");
//		printf("\t\t\t\t\t\t\t\t*                       你没有竞拍到物品                        *\n");
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
			a_map.erase(it);//删除指定
			cout << "删除" << id << "的值\n";
			flag = true;
		}
		else
		{
			cout << "没有值可以删除\n";
			flag = false;
		}
		
	}
	bool jingpai(int &f)//返回坐标的 竞拍成功
	{
		map<int, A*>::iterator it = a_map.begin();
		if (a_map.size() == 0)
		{
			return false;
		}
		for (; it != a_map.end(); it++)
		{
			temp.push_back(it->second->c);//排序
			//0 1 2 3 4  temp
			//1 2 3 4 5  key

			//1 0 3 2 4  value
			//cout << it->second->c;
		}
		//保存初始值大小  保证有10个
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

//队列  先进先出
int main()
{
	B b;
	//插入四个
	for (int i = 0; i < 10; i++)
	{
		A* a1 = new A;
		a1->id = i;
		a1->c = rand() % 10;//生成随机数
		b.insertgood(a1->id, a1);
	}
	std::cout << "初始化map\n";
	b.printmap();

	//设置时间 启动竞拍
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
		if(t1 == t2)//开始竞拍
		{
			while (1)//竞拍1分钟
			{
				struct tm t;
				time_t now;
				time(&now);
				localtime_s(&t, &now);
				long int t3 = t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec;
				int f = 0;//表示竞拍成功第几个
				falg = b.jingpai(f);
				if (falg)//如果竞拍
				{
					b.deletegood(f, flag1);//成功删除
					if (flag1)
					{
						cout << "竞拍成功" << count++ <<"次后map为\n";
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