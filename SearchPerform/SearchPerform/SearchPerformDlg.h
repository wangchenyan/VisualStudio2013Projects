
// SearchPerformDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "vector"
#include "iostream"
using namespace std;
#include "LinearSearch.h"
#include "TwoSearch.h"
#include "afxcmn.h"


// CSearchPerformDlg 对话框
class CSearchPerformDlg : public CDialogEx
{
// 构造
public:
	CSearchPerformDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SEARCHPERFORM_DIALOG };

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
private:
	CLinearSearch m_LinearSearch;
	CTwoSearch m_TwoSearch;
	CTabCtrl m_Tab;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
