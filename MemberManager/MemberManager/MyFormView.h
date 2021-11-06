#pragma once
#include "MainFrm.h"
#include "afxwin.h"
#include "atlimage.h"
#include "afxdtctl.h"


// CMyFormView 窗体视图

class CMyFormView : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView)

protected:
	CMyFormView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyFormView();

public:
	enum { IDD = IDD_FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonOpen();
	void Reset();
	void OnListItemClick(int iItem);
	void LoadImage(CString path);
	bool CheckInfo(bool isAdd);
	CEdit m_EditNo;
	CComboBox m_ComboBoxGrade;
	CEdit m_EditName;
	CComboBox m_ComboBoxSex;
	CEdit m_EditId;
	CEdit m_EditDate;
	CStatic m_StaticPhoto;
	CImage image;
	CBitmap defaultHead;
};


