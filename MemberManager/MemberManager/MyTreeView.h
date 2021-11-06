#pragma once
#include "afxcmn.h"
#include "MainFrm.h"


// CMyTreeView 窗体视图

class CMyTreeView : public CFormView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyTreeView();

public:
	enum { IDD = IDD_TREEVIEW };
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
	void UpdateTreeView();
	CTreeCtrl m_Tree;
};


