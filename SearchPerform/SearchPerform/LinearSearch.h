#pragma once
#include "afxwin.h"
#include "vector"
#include "iostream"
using namespace std;

// CLinearSearch 对话框

class CLinearSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CLinearSearch)

public:
	CLinearSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLinearSearch();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCheck();
	COLORREF m_ColorBlue;
	COLORREF m_ColorYellow;
	CStatic m_Text0;
	CStatic m_Text1;
	CStatic m_Text2;
	CStatic m_Text3;
	CStatic m_Text4;
	CStatic m_Text5;
	CStatic m_Text6;
	CStatic m_Text7;
	CStatic m_Text8;
	CStatic m_Text9;
	vector<CStatic*> m_TextVec;
	vector<int> m_TextID;
	vector<int> m_NumVec;
	// 查找目标
	CStatic m_TextTarget;
	// 单步演示
	CButton m_Single;
	CButton m_BtnStart;
	// 查找次数
	CStatic m_SearchCount;
	// 查找结果
	CStatic m_SearchResult;
	BOOL m_HadFound;
	BOOL m_HadStarted;
	int m_CurrentTextID;
	int m_Index;
	void InitData();
	void ShowNum();
	//查找
	void Search();
	CString str;
};
