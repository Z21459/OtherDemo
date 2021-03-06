
// StuManageDlg.h: 头文件
//
#include "CTab1.h"
#include "CTab2.h"
#include <iostream>
using namespace std;
#pragma once


// CStuManageDlg 对话框
class CStuManageDlg : public CDialogEx
{
// 构造
public:
	CStuManageDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUMANAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//
	CTabCtrl m_tab;//添加tab
	int m_CurselTab;
	CTab1 m1;
	CTab2 m2;
	CDialog *pDialog[2];//保存对话框对象

	//
	void ReSize(void);
	POINT old;

public:

	afx_msg void OnAbout();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

//学生结构体
struct Stu {//保存学生信息
	int StuId;
	char StuName[26];
	int StuScore;
	Stu *StuNext;
};