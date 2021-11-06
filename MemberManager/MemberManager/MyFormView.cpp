// MyFormView.cpp : 实现文件
//

#include "stdafx.h"
#include "MemberManager.h"
#include "MyFormView.h"
#define HEAD_DIR _T(".\\image\\")//头像保存路径
#define JPG _T(".jpg")//头像格式

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


// CMyFormView 诊断

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


// CMyFormView 消息处理程序


void CMyFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	// 初始化组合框
	m_ComboBoxGrade.InsertString(0, _T("高级会员"));
	m_ComboBoxGrade.InsertString(1, _T("中级会员"));
	m_ComboBoxGrade.InsertString(2, _T("初级会员"));
	m_ComboBoxGrade.SetCurSel(0);
	m_ComboBoxSex.InsertString(0, _T("男"));
	m_ComboBoxSex.InsertString(1, _T("女"));
	m_ComboBoxSex.InsertString(2, _T("其他"));
	m_ComboBoxSex.SetCurSel(0);

	// 初始化图片
	defaultHead.LoadBitmapW(IDB_BITMAP_HEAD);
	m_StaticPhoto.SetBitmap(defaultHead);
}


// 添加一个会员
void CMyFormView::OnBnClickedButtonAdd()
{
	// TODO:  在此添加控件通知处理程序代码
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

	// 保存头像
	if (!image.IsNull())
	{
		image.Save(HEAD_DIR + memberInfo.no + JPG);
	}

	// 获得ListView对象指针,更新ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->UpdateListView();

	Reset();
	AfxMessageBox(_T("保存成功！"));
}


void CMyFormView::OnBnClickedButtonModify()
{
	// TODO:  在此添加控件通知处理程序代码
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

	// 删除容器中的元素
	for (int i = 0; i < memberInfoVec.size(); i++)
	{
		if (memberInfoVec[i].no.Compare(memberInfo.no) == 0)
		{
			memberInfoVec.erase(memberInfoVec.begin() + i);
			break;
		}
	}
	memberInfoVec.push_back(memberInfo);

	// 保存头像
	if (!image.IsNull())
	{
		image.Save(HEAD_DIR + memberInfo.no + JPG);
	}

	// 获得ListView对象指针,更新ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->UpdateListView();

	Reset();
	AfxMessageBox(_T("保存成功！"));
}


// 删除一个会员
void CMyFormView::OnBnClickedButtonDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	// 获得ListView对象指针,更新ListView
	CMainFrame* MainFrame = (CMainFrame*)this->GetParent()->GetParent()->GetParent();
	CMyListView* p_MyListView = (CMyListView*)MainFrame->m_SplitterWnd2.GetPane(1, 0);
	p_MyListView->DeleteItem();
}


void CMyFormView::OnBnClickedButtonOpen()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("图片文件(*.jpg;*.png)|*.jpg;*.png||"));
	if (dialog.DoModal() == IDOK)
	{
		CString path = dialog.GetPathName();
		LoadImage(path);
	}
}


// 重置
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
	if (info.grade.Compare(_T("高级会员")) == 0)
	{
		m_ComboBoxGrade.SetCurSel(0);
	}
	else if (info.grade.Compare(_T("中级会员")) == 0)
	{
		m_ComboBoxGrade.SetCurSel(1);
	}
	else
	{
		m_ComboBoxGrade.SetCurSel(2);
	}
	if (info.sex.Compare(_T("男")) == 0)
	{
		m_ComboBoxSex.SetCurSel(0);
	}
	else if (info.sex.Compare(_T("女")) == 0)
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
	Invalidate();//清除绘图
	m_StaticPhoto.SetBitmap(NULL);//清除默认头像
	image.Destroy();//重置image
	image.Load(path);
	if (image.IsNull())
	{
		m_StaticPhoto.SetBitmap(defaultHead);
		return;
	}
	CRect rect;//定义矩形类
	int width = image.GetWidth();
	int height = image.GetHeight();
	m_StaticPhoto.GetClientRect(&rect);//获得pictrue控件所在的矩形区域
	CDC *pDc = m_StaticPhoto.GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	if (width <= rect.Width() && height <= rect.Height()) //小图片，不缩放
	{
		rect.MoveToXY((rect.Width() - width) / 2, (rect.Height() - height) / 2);//使图片居中显示
		rect = CRect(rect.TopLeft(), CSize(width, height));
	}
	else
	{
		float xScale = (float)rect.Width() / (float)width;
		float yScale = (float)rect.Height() / (float)height;
		float ScaleIndex = (xScale >= yScale ? xScale : yScale);
		rect = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex, (int)height*ScaleIndex));
	}
	image.Draw(pDc->m_hDC, rect); //将图片画到Picture控件表示的矩形区域
	ReleaseDC(pDc);//释放picture控件的Dc
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
		AfxMessageBox(_T("请输入正确的信息！"));
		return false;
	}
	if (isAdd){
		for (MemberInfo memberInfo : memberInfoVec)
		{
			if (memberInfo.no.Compare(no) == 0)
			{
				AfxMessageBox(_T("会员号已存在！"));
				return false;
			}
		}
	}
	return true;
}
