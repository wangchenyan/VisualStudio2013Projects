
// MainFrm.h : CMainFrame 类的接口
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

protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

	// 特性
public:

	// 操作
public:

	// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

	// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCToolBarImages m_UserImages;

	// 生成的消息映射函数
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


