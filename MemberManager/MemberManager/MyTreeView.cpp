// MyTreeView.cpp : ʵ���ļ�
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


// CMyTreeView ���

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


// CMyTreeView ��Ϣ�������


void CMyTreeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	// ����TreeView
	UpdateTreeView();
}


// ����TreeView
void CMyTreeView::UpdateTreeView()
{
	m_Tree.DeleteAllItems();
	vector<CString> rootVec;
	rootVec.push_back(_T("�߼���Ա"));
	rootVec.push_back(_T("�м���Ա"));
	rootVec.push_back(_T("������Ա"));
	for (CString str : rootVec)
	{
		HTREEITEM hRoot = m_Tree.InsertItem(str);
		for (MemberInfo memberInfo : memberInfoVec)
		{
			if (str.Compare(memberInfo.grade) == 0)
			{
				HTREEITEM nameRoot = m_Tree.InsertItem(memberInfo.name, hRoot, TVI_LAST);
				m_Tree.InsertItem(_T("��Ա�ţ�") + memberInfo.no, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("�Ա�") + memberInfo.sex, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("���֤�ţ�") + memberInfo.id, nameRoot, TVI_LAST);
				m_Tree.InsertItem(_T("������ڣ�") + memberInfo.date, nameRoot, TVI_LAST);
			}
		}
	}
}
