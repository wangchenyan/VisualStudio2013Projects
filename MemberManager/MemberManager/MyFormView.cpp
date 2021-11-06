// MyFormView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MemberManager.h"
#include "MyFormView.h"
#define HEAD_DIR _T(".\\image\\")//ͷ�񱣴�·��
#define JPG _T(".jpg")//ͷ���ʽ

extern vector<MemberInfo> memberInfoVec;

// CMyFormView

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

CMyFormView::CMyFormView()
: CFormView(CMyFormView::IDD)
{

}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NO, m_EditNo);
	DDX_Control(pDX, IDC_COMBO_GRADE, m_ComboBoxGrade);
	DDX_Control(pDX, IDC_EDIT_NAME, m_EditName);
	DDX_Control(pDX, IDC_COMBO_SEX, m_ComboBoxSex);
	DDX_Control(pDX, IDC_EDIT_ID, m_EditId);
	DDX_Control(pDX, IDC_EDIT_DATE, m_EditDate);
	DDX_Control(pDX, IDC_STATIC_PHOTO, m_StaticPhoto);
}

BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMyFormView::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMyFormView::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMyFormView::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CMyFormView::OnBnClickedButtonModify)
END_MESSAGE_MAP()


// CMyFormView ���

#ifdef _DEBUG
void CMyFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyFormView ��Ϣ�������


void CMyFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	// ��ʼ����Ͽ�
	m_ComboBoxGrade.InsertString(0, _T("�߼���Ա"));
	m_ComboBoxGrade.InsertString(1, _T("�м���Ա"));
	m_ComboBoxGrade.InsertString(2, _T("������Ա"));
	m_ComboBoxGrade.SetCurSel(0);
	m_ComboBoxSex.InsertString(0, _T("��"));
	m_ComboBoxSex.InsertString(1, _T("Ů"));
	m_ComboBoxSex.InsertString(2, _T("����"));
	m_ComboBoxSex.SetCurSel(0);

	// ��ʼ��ͼƬ
	defaultHead.LoadBitmapW(IDB_BITMAP_HEAD);
	m_StaticPhoto.SetBitmap(defaultHead);
}


// ���һ����Ա
void CMyFormView::OnBnClickedButtonAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!CheckInfo(true))
	{
		return;
	}

	MemberInfo memberInfo;
	m_EditNo.GetWindowTextW(memberInfo.no);
	m_ComboBoxGrade.GetWindowTextW(memberInfo.grade);
	m_EditName.GetWindowTextW(memberInfo.name);
	m_ComboBoxSex.GetWindowTextW(memberInfo.sex);
	m_EditId.GetWindowTextW(memberInfo.id);
	m_EditDate.GetWindowTextW(memberInfo.date);
	memberInfoVec.push_back(memberInfo);

	// ����ͷ��
	if (!image.IsNull())
	{
		image.Save(HEAD_DIR + memberInfo.no + JPG);
	}

	// ���ListView����ָ��,����ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->UpdateListView();

	Reset();
	AfxMessageBox(_T("����ɹ���"));
}


void CMyFormView::OnBnClickedButtonModify()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!CheckInfo(false))
	{
		return;
	}

	MemberInfo memberInfo;
	m_EditNo.GetWindowTextW(memberInfo.no);
	m_ComboBoxGrade.GetWindowTextW(memberInfo.grade);
	m_EditName.GetWindowTextW(memberInfo.name);
	m_ComboBoxSex.GetWindowTextW(memberInfo.sex);
	m_EditId.GetWindowTextW(memberInfo.id);
	m_EditDate.GetWindowTextW(memberInfo.date);

	// ɾ�������е�Ԫ��
	for (int i = 0; i < memberInfoVec.size(); i++)
	{
		if (memberInfoVec[i].no.Compare(memberInfo.no) == 0)
		{
			memberInfoVec.erase(memberInfoVec.begin() + i);
			break;
		}
	}
	memberInfoVec.push_back(memberInfo);

	// ����ͷ��
	if (!image.IsNull())
	{
		image.Save(HEAD_DIR + memberInfo.no + JPG);
	}

	// ���ListView����ָ��,����ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->UpdateListView();

	Reset();
	AfxMessageBox(_T("����ɹ���"));
}


// ɾ��һ����Ա
void CMyFormView::OnBnClickedButtonDelete()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ListView����ָ��,����ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->DeleteItem();
}


void CMyFormView::OnBnClickedButtonOpen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("ͼƬ�ļ�(*.jpg;*.png)|*.jpg;*.png||"));
	if (dialog.DoModal() == IDOK)
	{
		CString path = dialog.GetPathName();
		LoadImage(path);
	}
}


// ����
void CMyFormView::Reset()
{
	m_EditNo.SetWindowTextW(NULL);
	m_ComboBoxGrade.SetCurSel(0);
	m_EditName.SetWindowTextW(NULL);
	m_ComboBoxSex.SetCurSel(0);
	m_EditId.SetWindowTextW(NULL);
	m_EditDate.SetWindowTextW(NULL);
	m_StaticPhoto.SetBitmap(defaultHead);
	Invalidate();
}


void CMyFormView::OnListItemClick(int iItem)
{
	MemberInfo info = memberInfoVec[iItem];
	m_EditNo.SetWindowTextW(info.no);
	m_EditName.SetWindowTextW(info.name);
	m_EditId.SetWindowTextW(info.id);
	m_EditDate.SetWindowTextW(info.date);
	if (info.grade.Compare(_T("�߼���Ա")) == 0)
	{
		m_ComboBoxGrade.SetCurSel(0);
	}
	else if (info.grade.Compare(_T("�м���Ա")) == 0)
	{
		m_ComboBoxGrade.SetCurSel(1);
	}
	else
	{
		m_ComboBoxGrade.SetCurSel(2);
	}
	if (info.sex.Compare(_T("��")) == 0)
	{
		m_ComboBoxSex.SetCurSel(0);
	}
	else if (info.sex.Compare(_T("Ů")) == 0)
	{
		m_ComboBoxSex.SetCurSel(1);
	}
	else
	{
		m_ComboBoxSex.SetCurSel(2);
	}
	LoadImage(HEAD_DIR + info.no + JPG);
}


void CMyFormView::LoadImage(CString path)
{
	Invalidate();//�����ͼ
	m_StaticPhoto.SetBitmap(NULL);//���Ĭ��ͷ��
	image.Destroy();//����image
	image.Load(path);
	if (image.IsNull())
	{
		m_StaticPhoto.SetBitmap(defaultHead);
		return;
	}
	CRect rect;//���������
	int width = image.GetWidth();
	int height = image.GetHeight();
	m_StaticPhoto.GetClientRect(&rect);//���pictrue�ؼ����ڵľ�������
	CDC *pDc = m_StaticPhoto.GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	if (width <= rect.Width() && height <= rect.Height()) //СͼƬ��������
	{
		rect.MoveToXY((rect.Width() - width) / 2, (rect.Height() - height) / 2);//ʹͼƬ������ʾ
		rect = CRect(rect.TopLeft(), CSize(width, height));
	}
	else
	{
		float xScale = (float)rect.Width() / (float)width;
		float yScale = (float)rect.Height() / (float)height;
		float ScaleIndex = (xScale >= yScale ? xScale : yScale);
		rect = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex, (int)height*ScaleIndex));
	}
	image.Draw(pDc->m_hDC, rect); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
	ReleaseDC(pDc);//�ͷ�picture�ؼ���Dc
}


bool CMyFormView::CheckInfo(bool isAdd)
{
	CString no, grade, name, sex, id, date;
	m_EditNo.GetWindowTextW(no);
	m_ComboBoxGrade.GetWindowTextW(grade);
	m_EditName.GetWindowTextW(name);
	m_ComboBoxSex.GetWindowTextW(sex);
	m_EditId.GetWindowTextW(id);
	m_EditDate.GetWindowTextW(date);
	int iNo = _ttoi(no);
	int iId = _ttoi(id);
	int iDate = _ttoi(date);
	if (name.GetLength() == 0 || date.GetLength() != 8 || iNo == 0 || iId == 0 || iDate == 0)
	{
		AfxMessageBox(_T("��������ȷ����Ϣ��"));
		return false;
	}
	if (isAdd){
		for (MemberInfo memberInfo : memberInfoVec)
		{
			if (memberInfo.no.Compare(no) == 0)
			{
				AfxMessageBox(_T("��Ա���Ѵ��ڣ�"));
				return false;
			}
		}
	}
	return true;
}
