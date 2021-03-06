
// StuManageDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StuManage.h"
#include "StuManageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CStuManageDlg 对话框



CStuManageDlg::CStuManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUMANAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuManageDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_TAB, m_tab);
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CStuManageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_About, &CStuManageDlg::OnAbout)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CStuManageDlg::OnTcnSelchangeTab)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CStuManageDlg 消息处理程序

BOOL CStuManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	m_tab.InsertItem(0, _T("test1"));//添加页面
	m_tab.InsertItem(1, _T("test2"));

	//创建对话框
	m1.Create(IDD_DIALOG1, &m_tab);
	m2.Create(IDD_DIALOG2, &m_tab);
	//设定显示范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m1.MoveWindow(&rc);
	m2.MoveWindow(&rc);

	//保存 地址和初始化页面  记住当前保存
	pDialog[0] = &m1;
	pDialog[1] = &m2;
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	m_CurselTab = 0;

	//自适应
	//此处代码
	CRect rect;
	GetClientRect(&rect);     //取客户区大小  
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	//int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	//int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	//CRect rt;
	//SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);
	//cy = rt.bottom;
	//MoveWindow(0, 0, cx, cy);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStuManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStuManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStuManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStuManageDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg dlg;
	dlg.DoModal();//显示窗口
}


void CStuManageDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	//cout << "111111";
	//MessageBox(_T("11"),0, 0);
	//当前页面隐藏
	pDialog[m_CurselTab]->ShowWindow(SW_HIDE);
	//得到新页面索引
	m_CurselTab = m_tab.GetCurSel();
	//新页面显示
	pDialog[m_CurselTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


void CStuManageDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (cx == 0 || cy == 0) {
		return;
	}
	ReSize();//少一个判断

}

void CStuManageDlg::ReSize(void)
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角
	CPoint OldBRPoint, BRPoint; //右下角
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	old = Newp;
}