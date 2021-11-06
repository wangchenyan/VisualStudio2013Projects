// MyListView.cpp : 实现文件
//

#include "stdafx.h"
#include "MemberManager.h"
#include "MyListView.h"

extern vector<MemberInfo> memberInfoVec;

// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CFormView)

CMyListView::CMyListView()
: CFormView(CMyListView::IDD)
{

}

CMyListView::~CMyListView()
{
}

void CMyListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
}

BEGIN_MESSAGE_MAP(CMyListView, CFormView)
	ON_NOTIFY(NM_CLICK, IDC_LIST, &CMyListView::OnNMClickList)
END_MESSAGE_MAP()


// CMyListView 诊断

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyListView 消息处理程序


void CMyListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	// 初始化ListView
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_List.InsertColumn(0, _T("会员号"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(1, _T("会员等级"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(2, _T("姓名"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(3, _T("性别"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(4, _T("身份证号"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(5, _T("入会日期"), LVCFMT_CENTER, 90);
	UpdateListView();
}


void CMyListView::OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	//找出鼠标位置   
	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	m_List.ScreenToClient(&point);

	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;

	//获取行号信息
	int nItem = m_List.HitTest(&lvinfo);
	if (nItem != -1){
		CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
		CMyFormView* p_MyFormView = (CMyFormView*)MainFrame->m_SplitterWnd2.GetPane(0, 0);
		p_MyFormView->OnListItemClick(lvinfo.iItem);
	}

	*pResult = 0;
}


// 更新ListView
void CMyListView::UpdateListView()
{
	m_List.DeleteAllItems();
	for (MemberInfo memberInfo : memberInfoVec)
	{
		int raw = m_List.InsertItem(m_List.GetItemCount(), memberInfo.no);
		m_List.SetItemText(raw, 1, memberInfo.grade);
		m_List.SetItemText(raw, 2, memberInfo.name);
		m_List.SetItemText(raw, 3, memberInfo.sex);
		m_List.SetItemText(raw, 4, memberInfo.id);
		m_List.SetItemText(raw, 5, memberInfo.date);
	}
	// 更新TreeView
	UpdateTreeView();
}


// 删除一个会员
void CMyListView::DeleteItem()
{
	while (m_List.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) != -1)
	{
		int nItem = m_List.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		m_List.DeleteItem(nItem);
		memberInfoVec.erase(memberInfoVec.begin() + nItem);

		UpdateTreeView();

		CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
		CMyFormView* p_MyFormView = (CMyFormView*)MainFrame->m_SplitterWnd2.GetPane(0, 0);
		p_MyFormView->Reset();
		AfxMessageBox(_T("删除成功！"));
	}
}


// 更新TreeView
void CMyListView::UpdateTreeView()
{
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyTreeView* p_MyTreeView = (CMyTreeView*)MainFrame->m_SplitterWnd1.GetPane(0, 0);
	p_MyTreeView->UpdateTreeView();
}
