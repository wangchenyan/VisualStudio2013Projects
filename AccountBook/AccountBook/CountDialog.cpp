// CountDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AccountBook.h"
#include "CountDialog.h"
#include "afxdialogex.h"

extern vector<ListItem> listVec;

// CCountDialog 对话框

IMPLEMENT_DYNAMIC(CCountDialog, CDialogEx)

CCountDialog::CCountDialog(CWnd* pParent /*=NULL*/)
: CDialogEx(CCountDialog::IDD, pParent)
{

}

CCountDialog::~CCountDialog()
{
}

void CCountDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_START, m_ComboBoxStart);
	DDX_Control(pDX, IDC_COMBO_END, m_ComboBoxEnd);
	DDX_Control(pDX, IDC_BUTTON_COUNT, m_ButtonCount);
	DDX_Control(pDX, IDC_STATIC_FOOD, m_TextFood);
	DDX_Control(pDX, IDC_STATIC_LIFE, m_TextLife);
	DDX_Control(pDX, IDC_STATIC_ELECTRIC, m_TextElectric);
	DDX_Control(pDX, IDC_STATIC_OTHERS, m_TextOthers);
	DDX_Control(pDX, IDC_STATIC_SUM, m_TextSum);
	DDX_Control(pDX, IDC_STATIC_FOOD_PER, m_TextFoodPer);
	DDX_Control(pDX, IDC_STATIC_LIFE_PER, m_TextLifePer);
	DDX_Control(pDX, IDC_STATIC_ELECTRIC_PER, m_TextElectricPer);
	DDX_Control(pDX, IDC_STATIC_OTHERS_PER, m_TextOthersPer);
	DDX_Control(pDX, IDC_STATIC_SUM_PER, m_TextSumPer);
}


BEGIN_MESSAGE_MAP(CCountDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_COUNT, &CCountDialog::OnBnClickedButtonCount)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CCountDialog 消息处理程序

BOOL CCountDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitData();

	return TRUE;
}


HBRUSH CCountDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1 || pWnd->GetDlgCtrlID() == IDC_STATIC2 || pWnd->GetDlgCtrlID() == IDC_STATIC3)
	{
		COLORREF m_ColorGrey = RGB(128, 128, 128);
		pDC->SetTextColor(m_ColorGrey);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_FOOD || pWnd->GetDlgCtrlID() == IDC_STATIC_FOOD_PER ||
		pWnd->GetDlgCtrlID() == IDC_STATIC_LIFE || pWnd->GetDlgCtrlID() == IDC_STATIC_LIFE_PER ||
		pWnd->GetDlgCtrlID() == IDC_STATIC_ELECTRIC || pWnd->GetDlgCtrlID() == IDC_STATIC_ELECTRIC_PER ||
		pWnd->GetDlgCtrlID() == IDC_STATIC_OTHERS || pWnd->GetDlgCtrlID() == IDC_STATIC_OTHERS_PER ||
		pWnd->GetDlgCtrlID() == IDC_STATIC_SUM || pWnd->GetDlgCtrlID() == IDC_STATIC_SUM_PER)
	{
		COLORREF m_ColorBlue = RGB(0, 0, 255);
		pDC->SetTextColor(m_ColorBlue);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CCountDialog::OnBnClickedButtonCount()
{
	// TODO:  在此添加控件通知处理程序代码
	CString start, end;
	m_ComboBoxStart.GetWindowTextW(start);
	m_ComboBoxEnd.GetWindowTextW(end);
	if (start.GetLength() == 0 || end.GetLength() == 0)
	{
		return;
	}
	if (start.Compare(end) > 0)
	{
		return;
	}
	TreeItem countItem;
	countItem.food = 0;
	countItem.life = 0;
	countItem.electric = 0;
	countItem.others = 0;
	for (int i = 0; i < listVec.size(); i++)
	{
		if (listVec[i].date.Compare(start) >= 0 && listVec[i].date.Compare(end) <= 0)
		{
			CSettingDialog* m_Setting = new CSettingDialog();
			countItem = m_Setting->Transform(countItem, listVec[i]);
		}
	}
	ShowResult(countItem);
}


void CCountDialog::InitData()
{
	timeVec.clear();
	m_ComboBoxStart.ResetContent();
	m_ComboBoxEnd.ResetContent();
	for (int i = 0; i < listVec.size(); i++)
	{
		if (!Contain(timeVec, listVec[i].date))
		{
			timeVec.push_back(listVec[i].date);
		}
	}
	sort(timeVec.begin(), timeVec.end());

	for (int i = 0; i < timeVec.size(); i++)
	{
		m_ComboBoxStart.InsertString(i, timeVec[i]);
		m_ComboBoxEnd.InsertString(i, timeVec[i]);
	}
	m_ComboBoxStart.SetCurSel(0);
	m_ComboBoxEnd.SetCurSel(timeVec.size() - 1);
}


void CCountDialog::ShowResult(TreeItem countItem)
{
	CString str;
	str.Format(_T("%d"), countItem.food);
	m_TextFood.SetWindowTextW(str + _T("元"));
	str.Format(_T("%d"), countItem.life);
	m_TextLife.SetWindowTextW(str + _T("元"));
	str.Format(_T("%d"), countItem.electric);
	m_TextElectric.SetWindowTextW(str + _T("元"));
	str.Format(_T("%d"), countItem.others);
	m_TextOthers.SetWindowTextW(str + _T("元"));
	str.Format(_T("%d"), countItem.sum);
	m_TextSum.SetWindowTextW(str + _T("元"));

	str.Format(_T("%d"), 100 * countItem.food / countItem.sum);
	m_TextFoodPer.SetWindowTextW(str + _T("%"));
	str.Format(_T("%d"), 100 * countItem.life / countItem.sum);
	m_TextLifePer.SetWindowTextW(str + _T("%"));
	str.Format(_T("%d"), 100 * countItem.electric / countItem.sum);
	m_TextElectricPer.SetWindowTextW(str + _T("%"));
	str.Format(_T("%d"), 100 * countItem.others / countItem.sum);
	m_TextOthersPer.SetWindowTextW(str + _T("%"));
	str.Format(_T("%d"), 100 * countItem.sum / countItem.sum);
	m_TextSumPer.SetWindowTextW(str + _T("%"));
}


bool CCountDialog::Contain(vector<CString> vec, CString str)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].Compare(str) == 0)
		{
			return true;
		}
	}
	return false;
}
