// LinearSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "SearchPerform.h"
#include "LinearSearch.h"
#include "afxdialogex.h"
#include "Random.h"


// CLinearSearch 对话框

IMPLEMENT_DYNAMIC(CLinearSearch, CDialogEx)

CLinearSearch::CLinearSearch(CWnd* pParent /*=NULL*/)
: CDialogEx(CLinearSearch::IDD, pParent)
{

}

CLinearSearch::~CLinearSearch()
{
}

void CLinearSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_Text0, m_Text0);
	DDX_Control(pDX, IDC_Text1, m_Text1);
	DDX_Control(pDX, IDC_Text2, m_Text2);
	DDX_Control(pDX, IDC_Text3, m_Text3);
	DDX_Control(pDX, IDC_Text4, m_Text4);
	DDX_Control(pDX, IDC_Text5, m_Text5);
	DDX_Control(pDX, IDC_Text6, m_Text6);
	DDX_Control(pDX, IDC_Text7, m_Text7);
	DDX_Control(pDX, IDC_Text8, m_Text8);
	DDX_Control(pDX, IDC_Text9, m_Text9);
	DDX_Control(pDX, IDC_TEXT_TARGET, m_TextTarget);
	DDX_Control(pDX, IDC_CHECK, m_Single);
	DDX_Control(pDX, IDC_BUTTON_START, m_BtnStart);
	DDX_Control(pDX, IDC_BUTTON_START, m_BtnStart);
	DDX_Control(pDX, IDC_COUNT, m_SearchCount);
	DDX_Control(pDX, IDC_RESULT, m_SearchResult);
}


BEGIN_MESSAGE_MAP(CLinearSearch, CDialogEx)
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_START, &CLinearSearch::OnBnClickedButtonStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK, &CLinearSearch::OnBnClickedCheck)
END_MESSAGE_MAP()


// CLinearSearch 消息处理程序

BOOL CLinearSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ColorBlue = RGB(0, 0, 255);
	m_ColorYellow = RGB(255, 255, 0);
	InitData();
	ShowNum();

	return true;
}

void CLinearSearch::InitData()
{
	m_CurrentTextID = 0;

	m_TextVec.push_back(&m_Text0);
	m_TextVec.push_back(&m_Text1);
	m_TextVec.push_back(&m_Text2);
	m_TextVec.push_back(&m_Text3);
	m_TextVec.push_back(&m_Text4);
	m_TextVec.push_back(&m_Text5);
	m_TextVec.push_back(&m_Text6);
	m_TextVec.push_back(&m_Text7);
	m_TextVec.push_back(&m_Text8);
	m_TextVec.push_back(&m_Text9);

	m_TextID.push_back(IDC_Text0);
	m_TextID.push_back(IDC_Text1);
	m_TextID.push_back(IDC_Text2);
	m_TextID.push_back(IDC_Text3);
	m_TextID.push_back(IDC_Text4);
	m_TextID.push_back(IDC_Text5);
	m_TextID.push_back(IDC_Text6);
	m_TextID.push_back(IDC_Text7);
	m_TextID.push_back(IDC_Text8);
	m_TextID.push_back(IDC_Text9);
}


void CLinearSearch::ShowNum()
{
	CRandom * p_Random = new CRandom();
	m_NumVec = p_Random->CreateRandowNum();
	for (int i = 0; i < 10; i++)
	{
		str.Format(_T("%d"), m_NumVec[i]);
		m_TextVec[i]->SetWindowTextW(str);
	}
	str.Format(_T("%d"), m_NumVec[10]);
	m_TextTarget.SetWindowTextW(str);
}


HBRUSH CLinearSearch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (pWnd->GetDlgCtrlID() == IDC_TEXT_TARGET)
		pDC->SetTextColor(RGB(255, 0, 0));
	for (int i = 0; i < 10; i++)
	{
		if (pWnd->GetDlgCtrlID() == m_TextID[i])
			pDC->SetBkColor(m_ColorYellow);
	}

	if (pWnd->GetDlgCtrlID() == m_CurrentTextID)
	{
		pDC->SetBkColor(m_ColorBlue);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CLinearSearch::OnBnClickedButtonStart()
{
	// TODO:  在此添加控件通知处理程序代码
	m_CurrentTextID = 0;
	RedrawWindow();
	m_Index = 0;
	m_HadFound = false;
	m_HadStarted = true;
	m_SearchCount.SetWindowTextW(_T("0"));
	m_SearchResult.SetWindowTextW(_T(""));
	if (!m_Single.GetCheck())
		SetTimer(0, 1000, NULL);
}


void CLinearSearch::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_Single.GetCheck() && m_HadStarted && !m_HadFound)
		Search();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CLinearSearch::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Search();

	CDialogEx::OnTimer(nIDEvent);
}


void CLinearSearch::Search()
{
	m_CurrentTextID = m_TextID[m_Index];
	RedrawWindow();

	str.Format(_T("%d"), m_Index + 1);
	m_SearchCount.SetWindowTextW(str);

	if (m_NumVec[m_Index] == m_NumVec[10])
	{
		KillTimer(0);
		str.Format(_T("%d"), m_Index);
		m_SearchResult.SetWindowTextW(_T("在第") + str + _T("位查找到对象"));
		m_HadFound = true;
		m_HadStarted = false;
	}

	if (m_Index == 9 && !m_HadFound)
	{
		KillTimer(0);
		m_SearchResult.SetWindowTextW(_T("未找到对象"));
		m_HadStarted = false;
	}

	m_Index++;
}

void CLinearSearch::OnBnClickedCheck()
{
	// TODO:  在此添加控件通知处理程序代码
	m_HadFound = false;
	m_HadStarted = false;
	KillTimer(0);
}
