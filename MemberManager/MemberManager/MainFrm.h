
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "MyFormView.h"
#include "MyListView.h"
#include "MyTreeView.h"
#include "MemberInfo.h"
#include "iostream"
#include "vector"
#include "afxdb.h"
using namespace std;

struct MemberInfo{
	CString no;
	CString grade;
	CString name;
	CString sex;
	CString id;
	CString date;
};

class CMainFrame : public CFrameWndEx
{

protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

	// ����
public:

	// ����
public:

	// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

	// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCToolBarImages m_UserImages;

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	afx_msg void OnDestroy();
	void ReadBatabase();
	void SaveDatabase();
	CSplitterWnd m_SplitterWnd1;
	CSplitterWnd m_SplitterWnd2;
	CMemberInfo m_MemberInfo;
};


