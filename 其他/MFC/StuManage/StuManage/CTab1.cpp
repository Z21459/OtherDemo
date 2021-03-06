// CTab1.cpp: 实现文件
//
////////////////////////////程序的每个函数执行开始的时候都应该判断函数的输入有效性////////////////////////////

#include "stdafx.h"
#include "StuManage.h"
#include "CTab1.h"
#include "afxdialogex.h"

	//声明链表的头和尾
STUNODE* g_pHead = NULL;  //O 
STUNODE* g_pEnd = NULL;

// CTab1 对话框

IMPLEMENT_DYNAMIC(CTab1, CDialogEx)

CTab1::CTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	nOrder = -1; //nOrder iOrder  s db arr p
				 //初始化
	arrStuNum[10] = { '\0' };
	arrStuName[10] = { '\0' };
	iStuScore = -1;

	nFlag = 1;

	pTemp = NULL;

	//读取文件中学生信息
	ReadStuFromFile();


}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);

	if (m_list.GetItemCount() == 0) {//IDC_LIST2  初始化
		m_list.InsertColumn(0, _T("学号"), LVCFMT_CENTER, 80);
		m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, 80);
		m_list.InsertColumn(2, _T("分数"), LVCFMT_CENTER, 80);
		//MessageBox(_T("123"), 0, 0);
	}

}


BEGIN_MESSAGE_MAP(CTab1, CDialogEx)
	ON_BN_CLICKED(IDC_ButAdd, &CTab1::OnBnClickedButadd)
	ON_BN_CLICKED(IDC_ButFind, &CTab1::OnBnClickedButfind)
	ON_BN_CLICKED(IDC_ButSave, &CTab1::OnBnClickedButsave)
	ON_BN_CLICKED(IDC_ButShowData, &CTab1::OnBnClickedButshowdata)
	ON_BN_CLICKED(IDC_ButDelete, &CTab1::OnBnClickedButdelete)
	ON_BN_CLICKED(IDC_ButModify, &CTab1::OnBnClickedButmodify)
END_MESSAGE_MAP()


// CTab1 消息处理程序


//添加一个学生的信息
void CTab1::AddStuMSG(char *arrStuNum, char arrStuName[10], int  iStuScore) //函数定义
{
	//逻辑
	//创建一个节点
	STUNODE* pTemp = (STUNODE*)malloc(sizeof(STUNODE));

	//第一步，检验参数的合法性
	if (NULL == arrStuNum || NULL == arrStuName || iStuScore < 0)
	{
		printf("学生信息输入错误!\n");
		return;
	}
	//节点成员符初始值
	strcpy_s(pTemp->arrStuNum, arrStuNum);//字符或者字符串使用  strcpy_s()//里面有三个参数
	strcpy_s(pTemp->arrStuName, arrStuName);
	pTemp->iStuScore = iStuScore;
	pTemp->pNext = NULL;

	//接在链表上
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		g_pHead = pTemp;
		//g_pEnd = pTemp;
	}
	else
	{
		g_pEnd->pNext = pTemp;  //链接
		//g_pEnd = pTemp;         //向后移动
	}
	g_pEnd = pTemp;
	//MessageBox(_T("11"), _T("添加成功"), MB_OK);
}


//清空链表
void CTab1::FreeLinkData()
{
	STUNODE* pTemp = g_pHead;
	while (g_pHead != NULL)
	{
		//记录节点
		pTemp = g_pHead;

		//向后移动了一个
		g_pHead = g_pHead->pNext;

		//删除节点
		free(pTemp);
	}
}

//打印数据
void CTab1::ShowStuData()
{
	STUNODE* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		printf("学号:%s, 姓名:%s, 分数:%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
		//向下走一步
		pTemp = pTemp->pNext;
	}
}

//显示指令
void CTab1::ShowOrder()
{
	printf("*******************学生信息管理系统*********************\n");
	printf("*******************本系统操作指令如下*******************\n");
	printf("***             1、 增加一个学生信息(尾添加)         ***\n");
	printf("***            11、 增加一个学生信息(头添加)         ***\n");
	printf("***           111、 增加一个学生信息(在指定位置添加) ***\n");
	printf("***             2、 查找指定学生的信息（姓名/学号）  ***\n");
	printf("***             3、 修改指定学生的信息               ***\n");
	printf("***             4、 保存业主的信息到文件中           ***\n");
	printf("***             5、 读取文件中的业主信息             ***\n");
	printf("***             6、 删除指定学生的信息               ***\n");
	printf("***             7、 恢复删除的学生的信息             ***\n");
	printf("***             9、 显示所有学生的信息               ***\n");
	printf("***             0、 退出系统                         ***\n");
	printf("********************************************************\n");
}

//链表头添加一个节点
void CTab1::AddStuMSGToLinkHead(char *arrStuNum, char arrStuName[10], int iStuScore)
{
	//创建一个节点
	STUNODE* pTemp = (STUNODE*)malloc(sizeof(STUNODE));

	//检测参数的合法性
	if (NULL == arrStuName || NULL == arrStuName || iStuScore < 0)
	{
		printf("学生信息输入错误!\n");
		return;
	}

	//c成员赋值
	//节点成员符初始值
	strcpy_s(pTemp->arrStuNum, arrStuNum);
	strcpy_s(pTemp->arrStuName, arrStuName);
	pTemp->iStuScore = iStuScore;
	pTemp->pNext = NULL;

	if (NULL == g_pHead || NULL == g_pEnd)
	{
		//链表为空
		//g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else
	{
		//新节点的下一个 指向头
		pTemp->pNext = g_pHead;
		//头向前挪动一个
		//g_pHead = pTemp;
	}
	g_pHead = pTemp;
}

//查找制定学生
STUNODE* CTab1::FindStuByNum(char* arrStuNum)  //200501013  1254
{
	STUNODE* pTemp = g_pHead;
	//检测参数的合法性
	if (NULL == arrStuNum)
	{
		printf("学号输入错误！\n");
		return NULL;
	}

	//判断链表是否是空
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		printf("链表为NULL！\n");
		return NULL;
	}

	//遍历链表	
	while (pTemp != NULL)
	{
		if (0 == strcmp(pTemp->arrStuNum, arrStuNum))
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}

	printf("查无此节点！\n");
	return NULL;
}

//指定位置插入节点
void CTab1::InsertNode(STUNODE* pTemp, char *arrStuNum, char arrStuName[10], int iStuScore)
{
	//创建节点
	STUNODE* pNewTemp = (STUNODE*)malloc(sizeof(STUNODE));

	//成员赋值
	strcpy_s(pNewTemp->arrStuNum, arrStuNum);
	strcpy_s(pNewTemp->arrStuName, arrStuName);
	pNewTemp->iStuScore = iStuScore;
	pNewTemp->pNext = NULL;    ///

	//插入
	if (pTemp == g_pEnd)  //是尾节点
	{
		g_pEnd->pNext = pNewTemp;
		g_pEnd = pNewTemp;
	}
	else
	{
		//
		pNewTemp->pNext = pTemp->pNext;
		pTemp->pNext = pNewTemp;
	}
}

//删除指定学生
void CTab1::DeleteStuNode(STUNODE* pNode)
{
	//只有一个节点
	if (g_pHead == g_pEnd)
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	//只有两个节点
	else if (g_pHead->pNext == g_pEnd)
	{
		if (g_pHead == pNode)
		{
			free(g_pHead);
			g_pHead = g_pEnd;
		}
		else
		{
			free(g_pEnd);
			g_pEnd = g_pHead;
			g_pHead->pNext = NULL;
		}
	}
	else // >=3
	{
		STUNODE* pTemp = g_pHead;
		//判断头
		if (g_pHead == pNode)
		{
			//记住头
			pTemp = g_pHead;
			g_pHead = g_pHead->pNext;
			free(pTemp);
			pTemp = NULL;
			return;  //结束
		}

		while (pTemp)
		{
			if (pTemp->pNext == pNode)
			{
				//删除
				if (pNode == g_pEnd)
				{
					free(pNode);
					pNode = NULL;
					g_pEnd = pTemp;
					g_pEnd->pNext = NULL;
					return;
				}
				else
				{
					//记住要删除的节点
					STUNODE* p = pTemp->pNext;
					//链接
					pTemp->pNext = pTemp->pNext->pNext;
					//释放节点
					free(p);
					p = NULL;
					return;
				}
			}

			pTemp = pTemp->pNext;
		}
	}
}

//保存信息进文件
void CTab1::SaveStuToFile()
{
	//判断链表是否是NULL
	FILE* pFile = NULL;
	STUNODE* pTemp = g_pHead;
	char strBuf[30] = { 0 };
	char strScore[10] = { 0 };

	if (NULL == g_pHead)
	{
		printf("没有学生\n");
		return;
	}

	//打开文件
	fopen_s(&pFile, "dat.dat", "wb+");
	if (NULL == pFile)
	{
		printf("文件打开失败\n");
		return;
	}
	//操作文件指针
	while (pTemp)
	{
		//学号赋值进去
		strcpy_s(strBuf, pTemp->arrStuNum);
		strcat_s(strBuf, ".");
		//姓名
		strcat_s(strBuf, pTemp->arrStuName);
		strcat_s(strBuf, ".");
		//分数
		_itoa_s(pTemp->iStuScore, strScore, 10);
		strcat_s(strBuf, strScore);

		fwrite(strBuf, 1, strlen(strBuf), pFile); //
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
	}

	//关闭文件
	fclose(pFile);
}

//读取文件中学生信息
void CTab1::ReadStuFromFile()
{
	FILE* pFile;
	fopen_s(&pFile, "dat.dat", "rb+"); //

	char strBuf[30] = { 0 };

	char strStuNum[10] = { 0 };
	char strStuName[10] = { 0 };
	char strStuScore[10] = { 0 };

	int nCount = 0;
	int j = 0;

	if (NULL == pFile)
	{
		printf("文件打开失败\n");
		return;
	}


	//操作指针，读取函数
	while (NULL != fgets(strBuf, 30, pFile))  //EOF  feof   3部分
	{
		int i = 0;
		nCount = 0;
		j = 0;
		for (i = 0; strBuf[i] != '\r'; i++)
		{
			if (0 == nCount) //没到'.'
			{
				strStuNum[i] = strBuf[i];
				if ('.' == strBuf[i])
				{
					strStuNum[i] = '\0';
					nCount++;
				}
			}
			else if (1 == nCount) //第一个'.'
			{
				strStuName[j] = strBuf[i];
				j++;
				if ('.' == strBuf[i])
				{
					strStuName[j] = '\0';
					nCount++;
					j = 0;
				}
			}
			else  //第二个'.' 2 == nCount
			{
				strStuScore[j] = strBuf[i];
				j++;
			}
		}
		//插入到链表
		AddStuMSG(strStuNum, strStuName, atoi(strStuScore));
	}


	fclose(pFile);
}

void CTab1::OnBnClickedButadd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Id;
	CString Name;
	CString Score;
	CEdit* pBoxOne, *pBoxTwo, *pBoxThree;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EditId);//得到编辑框的值
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EditName);//得到编辑框的值
	pBoxThree = (CEdit*)GetDlgItem(IDC_EditScore);//得到编辑框的值
	//赋值
	//pBoxOne-> SetWindowText( _T("FOO ") );
	//取值
	//CString str;
	pBoxOne->GetWindowText(Id);
	pBoxTwo->GetWindowText(Name);
	pBoxThree->GetWindowText(Score);
	//MessageBox(str, _T("程序运行结果"), MB_OK);
	//str.ReleaseBuffer(); 
	memcpy(arrStuNum, Id, Id.GetLength()); //CString转char []
	memcpy(arrStuName, Name, Name.GetLength()); //CString转char []
	iStuScore = _ttoi(Score);//CString转int    //反过来str.Format(_T("%d"), i);
	AddStuMSG(arrStuNum, arrStuName, iStuScore);
	Id.ReleaseBuffer();
	Name.ReleaseBuffer();
	Score.ReleaseBuffer();
	MessageBox(_T("添加成功"), 0, 0);
}

void CTab1::OnBnClickedButfind()
{
	// TODO: 在此添加控件通知处理程序代码
				//输入一个学号
	
	CString Id;

	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EditId);//得到编辑框的值

	//赋值
	//pBoxOne-> SetWindowText( _T("FOO ") );
	//取值
	//CString str;
	pBoxOne->GetWindowText(Id);

	//MessageBox(str, _T("程序运行结果"), MB_OK);
	//str.ReleaseBuffer(); 
	memcpy(arrStuNum, Id, Id.GetLength()); //CString转char []

	//printf("输入指定学号:");
	//scanf("%s", arrStuNum);
	//查找
	pTemp = FindStuByNum(arrStuNum);

	//打印
	if (NULL != pTemp)  //200501013  1254
	{
		//清空list
		m_list.DeleteAllItems();
		//MessageBox(_T("121"),0,0);
		//GetDlgItem(IDC_EditName)->SetWindowText(_T("121"));//设置 文件成功
		//printf("学号:%s, 姓名:%s, 分数:%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
		CString Id, Name, Score;;
		Id = pTemp->arrStuNum;
		Name = pTemp->arrStuName;
		Score.Format(_T("%d"), pTemp->iStuScore);
		int index = m_list.InsertItem(0xfff, _T(""));
		m_list.SetItemText(index, 0, Id);
		m_list.SetItemText(index, 1, Name);
		m_list.SetItemText(index, 2, Score);
		MessageBox(_T("查找成功"), 0, 0);
	}
	Id.ReleaseBuffer();

}

void CTab1::OnBnClickedButsave()
{
	// TODO: 在此添加控件通知处理程序代码
		//判断链表是否是NULL
	FILE* pFile = NULL;
	STUNODE* pTemp = g_pHead;
	char strBuf[30] = { 0 };
	char strScore[10] = { 0 };

	if (NULL == g_pHead)
	{
		printf("没有学生\n");
		MessageBox(_T("没有学生"), 0, 0);
		return;
	}

	//打开文件
	fopen_s(&pFile, "dat.dat", "wb+");
	if (NULL == pFile)
	{
		printf("文件打开失败\n");
		MessageBox(_T("文件打开失败"), 0, 0);
		return;
	}
	//操作文件指针
	while (pTemp)
	{
		//学号赋值进去
		strcpy_s(strBuf, pTemp->arrStuNum);
		strcat_s(strBuf, ".");
		//姓名
		strcat_s(strBuf, pTemp->arrStuName);
		strcat_s(strBuf, ".");
		//分数
		_itoa_s(pTemp->iStuScore, strScore, 10);
		strcat_s(strBuf, strScore);

		fwrite(strBuf, 1, strlen(strBuf), pFile); //
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
		
	}
	MessageBox(_T("保存成功"), 0, 0);
	//关闭文件
	fclose(pFile);
}

void CTab1::OnBnClickedButshowdata()
{
	
	// TODO: 在此添加控件通知处理程序代码  
	m_list.DeleteAllItems();//每次清空内容项
	STUNODE* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		CString Id;
		CString Name;
		CString Score;

		//char str[] = "hello";
		//CString c = str;
		Id = pTemp->arrStuNum; //直接等于
		Name = pTemp->arrStuName;
		//Id.Format(_T("%s"), pTemp->arrStuNum);//char[] 转CString  有乱码
		//Name.Format(_T("%ls"), pTemp->arrStuName);//char[] 转CString
		Score.Format(_T("%d"), pTemp->iStuScore);//int 转CString
		Id;
		Name;
		Score;

		int Index = m_list.InsertItem(0xffff, _T(""));
		
		m_list.SetItemText(Index, 0, Id);// char[] 转 CString    int转CString
		m_list.SetItemText(Index, 1, Name);
		m_list.SetItemText(Index, 2, Score);//

		
		printf("学号:%s, 姓名:%s, 分数:%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
		//向下走一步
		pTemp = pTemp->pNext;

		Id.ReleaseBuffer();
		Name.ReleaseBuffer();
		Score.ReleaseBuffer();
	}
}


void CTab1::OnBnClickedButdelete()
{
	// TODO: 在此添加控件通知处理程序代码
	//printf("输入要删除的学生学号:");
	//scanf("%s", arrStuNum);
	CString Id;
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EditId);//得到编辑框的值
	//赋值
	//pBoxOne-> SetWindowText( _T("FOO ") );
	//取值
	//CString str;
	pBoxOne->GetWindowText(Id);
	memcpy(arrStuNum, Id, Id.GetLength()); //CString转char []

	//查找
	pTemp = FindStuByNum(arrStuNum);

	//删除这个节点
	if (NULL != pTemp)  //200501013  1254
	{
		//调用删除学生的函数
		DeleteStuNode(pTemp);
		MessageBox(_T("删除成功"), 0, 0);
	}
	Id.ReleaseBuffer();
}


void CTab1::OnBnClickedButmodify()
{
	// TODO: 在此添加控件通知处理程序代码
	//输入一个学号
	//printf("输入指定学号:");
	//scanf("%s", arrStuNum);
	CString Id;
	CEdit *pBoxOne = (CEdit*)GetDlgItem(IDC_EditId);
	pBoxOne->GetWindowText(Id);
	memcpy(arrStuNum, Id, Id.GetLength());
	//查找
	pTemp = FindStuByNum(arrStuNum);

	//打印
	if (NULL != pTemp)  //200501013  1254
	{
		
		CString Id;
		CString Name;
		CString Score;
		CEdit* pBoxOne, *pBoxTwo, *pBoxThree;
		pBoxOne = (CEdit*)GetDlgItem(IDC_EditId);//得到编辑框的值
		pBoxTwo = (CEdit*)GetDlgItem(IDC_EditName);//得到编辑框的值
		pBoxThree = (CEdit*)GetDlgItem(IDC_EditScore);//得到编辑框的值
		//赋值
		//pBoxOne-> SetWindowText( _T("FOO ") );
		//取值
		//CString str;
		pBoxOne->GetWindowText(Id);
		pBoxTwo->GetWindowText(Name);
		pBoxThree->GetWindowText(Score);
		//MessageBox(str, _T("程序运行结果"), MB_OK);
		//str.ReleaseBuffer(); 
		memcpy(arrStuNum, Id, Id.GetLength()); //CString转char []
		memcpy(arrStuName, Name, Name.GetLength()); //CString转char []
		iStuScore = _ttoi(Score);//CString转int    //反过来str.Format(_T("%d"), i);
	
		
		//修改学号
		strcpy_s(pTemp->arrStuNum, arrStuNum);

		//修改名字、;
		strcpy_s(pTemp->arrStuName, arrStuName);

		//修改分数
		pTemp->iStuScore = iStuScore;

		//结束之后释放内存
		Id.ReleaseBuffer();
		Name.ReleaseBuffer();
		Score.ReleaseBuffer();
		MessageBox(_T("修改成功"), 0, 0);
	}

}
