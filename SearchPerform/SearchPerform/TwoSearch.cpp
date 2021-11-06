// TwoSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SearchPerform.h"
#include "TwoSearch.h"
#include "afxdialogex.h"
#include "Random.h"
#include "algorithm"


// CTwoSearch �Ի���

IMPLEMENT_DYNAMIC(CTwoSearch, CDialogEx)

CTwoSearch::CTwoSearch(CWnd* pParent /*=NULL*/)
: CDialogEx(CTwoSearch::IDD, pParent)
{

}

CTwoSearch::~CTwoSearch()
{
}

void CTwoSearch::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(CTwoSearch, CDialogEx)
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_START, &CTwoSearch::OnBnClickedButtonStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK, &CTwoSearch::OnBnClickedCheck)
END_MESSAGE_MAP()


// CTwoSearch ��Ϣ�������

BOOL CTwoSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ColorBlue = RGB(0, 0, 255);
	m_ColorYellow = RGB(255, 255, 0);
	InitData();
	ShowNum();

	return true;
}


void CTwoSearch::InitData()
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


void CTwoSearch::ShowNum()
{
	CRandom * p_Random = new CRandom();
	m_NumVec = p_Random->CreateRandowNum();
	CString str;
	for (int i = 0; i < 10; i++)
	{
		str.Format(_T("%d"), m_NumVec[i]);
		m_TextVec[i]->SetWindowTextW(str);
	}
	str.Format(_T("%d"), m_NumVec[10]);
	m_TextTarget.SetWindowTextW(str);
}


HBRUSH CTwoSearch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

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

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CTwoSearch::OnBnClickedButtonStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_CurrentTextID = 0;
	RedrawWindow();
	m_Index = 0;
	left = 0;
	right = 9;
	m_HadFound = false;
	m_HadStarted = true;
	m_SearchCount.SetWindowTextW(_T("0"));
	m_SearchResult.SetWindowTextW(_T(""));
	// ����ǰ����
	sort(m_NumVec.begin(), m_NumVec.end() - 1);
	CString str;
	for (int i = 0; i < 10; i++)
	{
		str.Format(_T("%d"), m_NumVec[i]);
		m_TextVec[i]->SetWindowTextW(str);
	}

	if (!m_Single.GetCheck())
		SetTimer(0, 1000, NULL);
}


void CTwoSearch::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_Single.GetCheck() && m_HadFound == false && m_HadStarted == true)
		Search();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CTwoSearch::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Search();

	CDialogEx::OnTimer(nIDEvent);
}

void CTwoSearch::Search()
{
	middle = (left + right) / 2;

	m_CurrentTextID = m_TextID[middle];
	RedrawWindow();

	m_Index++;
	str.Format(_T("%d"), m_Index);
	m_SearchCount.SetWindowTextW(str);

	if (m_NumVec[middle] > m_NumVec[10])
	{
		right = middle - 1;
	}
	else if (m_NumVec[middle] < m_NumVec[10])
	{
		left = middle + 1;
	}
	else
	{
		str.Format(_T("%d"), middle);
		m_SearchResult.SetWindowTextW(_T("�ڵ�") + str + _T("λ���ҵ�����"));
		m_HadFound = true;
		m_HadStarted = false;
		KillTimer(0);
	}

	if (left > right && m_HadFound == false)
	{
		KillTimer(0);
		m_SearchResult.SetWindowTextW(_T("δ�ҵ�����"));
		m_HadStarted = false;
	}

}


void CTwoSearch::OnBnClickedCheck()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_HadFound = false;
	m_HadStarted = false;
	KillTimer(0);
}