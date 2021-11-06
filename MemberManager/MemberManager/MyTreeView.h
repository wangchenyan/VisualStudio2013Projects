#pragma once
#include "afxcmn.h"
#include "MainFrm.h"


// CMyTreeView ������ͼ

class CMyTreeView : public CFormView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void UpdateTreeView();
	CTreeCtrl m_Tree;
};


