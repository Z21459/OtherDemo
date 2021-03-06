#pragma once


// CTab1 对话框
//学生节点
typedef struct _STU
{
	char arrStuNum[10];
	char arrStuName[10];
	int  iStuScore;
	_STU* pNext;
} STUNODE;

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTab1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButadd();

public:

	//添加一个学生的信息
	void AddStuMSG(char *arrStuNum, char arrStuName[10], int iStuScore);

	//链表头添加一个节点
	void AddStuMSGToLinkHead(char *arrStuNum, char arrStuName[10], int iStuScore);

	//清空链表
	void FreeLinkData();

	//打印数据
	void ShowStuData();

	//显示指令
	void ShowOrder();

	//查找制定学生
	STUNODE* FindStuByNum(char* arrStuNum); //【】

	//指定位置插入节点
	void InsertNode(STUNODE* pTemp, char *arrStuNum, char arrStuName[10], int iStuScore);

	//删除指定学生
	void DeleteStuNode(STUNODE* pNode);

	//保存信息进文件
	void SaveStuToFile();

	//读取文件中学生信息
	void ReadStuFromFile();

private:
	int nOrder; //nOrder iOrder  s db arr p
			 //初始化
	char arrStuNum[10];
	char arrStuName[10];
	int  iStuScore;

	int nFlag;

	STUNODE* pTemp;
public:
	afx_msg void OnBnClickedButfind();
	afx_msg void OnBnClickedButsave();


	afx_msg void OnBnClickedButshowdata();
	CListCtrl m_list;
	afx_msg void OnBnClickedButdelete();
	afx_msg void OnBnClickedButmodify();
};

