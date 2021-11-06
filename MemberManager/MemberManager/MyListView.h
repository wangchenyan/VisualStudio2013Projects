#pragma once
#include "afxcmn.h"
#include "MainFrm.h"


// CMyListView ������ͼ

class CMyListView : public CFormView
{
	DECLARE_DYNCREATE(CMyListView)

protected:
	CMyListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyListView();

public:
	enum { IDD = IDD_LISTVIEW };
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
	afx_msg void OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult);
	void UpdateListView();
	void DeleteItem();
	void UpdateTreeView();
	CListCtrl m_List;
};


