// MyListView.cpp : ʵ���ļ�
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


// CMyListView ���

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


// CMyListView ��Ϣ�������


void CMyListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	// ��ʼ��ListView
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_List.InsertColumn(0, _T("��Ա��"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(1, _T("��Ա�ȼ�"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(2, _T("����"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(3, _T("�Ա�"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(4, _T("���֤��"), LVCFMT_CENTER, 90);
	m_List.InsertColumn(5, _T("�������"), LVCFMT_CENTER, 90);
	UpdateListView();
}


void CMyListView::OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ҳ����λ��   
	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	m_List.ScreenToClient(&point);

	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;

	//��ȡ�к���Ϣ
	int nItem = m_List.HitTest(&lvinfo);
	if (nItem != -1){
		CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
		CMyFormView* p_MyFormView = (CMyFormView*)MainFrame->m_SplitterWnd2.GetPane(0, 0);
		p_MyFormView->OnListItemClick(lvinfo.iItem);
	}

	*pResult = 0;
}


// ����ListView
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
	// ����TreeView
	UpdateTreeView();
}


// ɾ��һ����Ա
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
		AfxMessageBox(_T("ɾ���ɹ���"));
	}
}


// ����TreeView
void CMyListView::UpdateTreeView()
{
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyTreeView* p_MyTreeView = (CMyTreeView*)MainFrame->m_SplitterWnd1.GetPane(0, 0);
	p_MyTreeView->UpdateTreeView();
}
