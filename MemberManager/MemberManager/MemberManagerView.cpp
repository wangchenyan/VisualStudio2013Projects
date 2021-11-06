
// MemberManagerView.cpp : CMemberManagerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MemberManager.h"
#endif

#include "MemberManagerDoc.h"
#include "MemberManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemberManagerView

IMPLEMENT_DYNCREATE(CMemberManagerView, CView)

BEGIN_MESSAGE_MAP(CMemberManagerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMemberManagerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMemberManagerView ����/����

CMemberManagerView::CMemberManagerView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMemberManagerView::~CMemberManagerView()
{
}

BOOL CMemberManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMemberManagerView ����

void CMemberManagerView::OnDraw(CDC* /*pDC*/)
{
	CMemberManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMemberManagerView ��ӡ


void CMemberManagerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMemberManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMemberManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMemberManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CMemberManagerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMemberManagerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMemberManagerView ���

#ifdef _DEBUG
void CMemberManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CMemberManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMemberManagerDoc* CMemberManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMemberManagerDoc)));
	return (CMemberManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMemberManagerView ��Ϣ�������
