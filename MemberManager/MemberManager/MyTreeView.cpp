// MyTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "MemberManager.h"
#include "MyTreeView.h"

extern vector<MemberInfo> memberInfoVec;

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CFormView)

CMyTreeView::CMyTreeView()
: CFormView(CMyTreeView::IDD)
{

}

CMyTreeView::~CMyTreeView()
{
}

void CMyTreeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_Tree);
}

BEGIN_MESSAGE_MAP(CMyTreeView, CFormView)
END_MESSAGE_MAP()


// CMyTreeView 诊断

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyTreeView 消息处理程序


void CMyTreeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	// 更新TreeView
	UpdateTreeView();
}


// 更新TreeView
void CMyTreeView::UpdateTreeView()
{
	m_Tree.DeleteAllItems();
	vector<CString> rootVec;
	rootVec.push_back(_T("高级会员"));
	rootVec.push_back(_T("中级会员"));
	rootVec.push_back(_T("初级会员"));
	for (CString str : rootVec)
	{
		HTREEITEM hRoot = m_Tree.InsertItem(str);
		for (MemberInfo memberInfo : memberInfoVec)
		{
			if (str.Compare(memberInfo.grade) == 0)
			{
				HTREEITEM nameRoot = m_Tree.InsertItem(memberInfo.name, hRoot, TVI_LAST);
				m_Tree.InsertItem(_T("会员号：") + memberInfo.no, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("性别：") + memberInfo.sex, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("身份证号：") + memberInfo.id, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("入会日期：") + memberInfo.date, nameRoot, TVI_LAST);
			}
		}
	}
}
