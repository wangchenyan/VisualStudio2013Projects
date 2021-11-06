// SettingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AccountBook.h"
#include "SettingDialog.h"
#include "afxdialogex.h"

vector<ListItem> listVec;

// CSettingDialog 对话框

IMPLEMENT_DYNAMIC(CSettingDialog, CDialogEx)

CSettingDialog::CSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDialog::IDD, pParent)
{

}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_Tree);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_EDIT_NAME, m_EditName);
	DDX_Control(pDX, IDC_EDIT_MONEY, m_EditMoney);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_ComboBoxType);
	DDX_Control(pDX, IDC_EDIT_DATE, m_EditDate);
	DDX_Control(pDX, IDC_STATIC_PIC, m_Pic);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_ButtonAdd);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_ButtonDelete);
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CSettingDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CSettingDialog::OnBnClickedButtonDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, &CSettingDialog::OnCbnSelchangeComboType)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSettingDialog 消息处理程序

BOOL CSettingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitData();

	return TRUE;
}


void CSettingDialog::InitData()
{
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_List.InsertColumn(0, _T("日期"), NULL, 140);
	m_List.InsertColumn(1, _T("类型"), NULL, 140);
	m_List.InsertColumn(2, _T("名称"), NULL, 140);
	m_List.InsertColumn(3, _T("金额"), NULL, 140);

	m_ComboBoxType.InsertString(0, _T("食品"));
	m_ComboBoxType.InsertString(1, _T("生活用品"));
	m_ComboBoxType.InsertString(2, _T("电器"));
	m_ComboBoxType.InsertString(3, _T("其他"));
	m_ComboBoxType.SetCurSel(0);

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP_FOOD);
	m_Pic.SetBitmap(bitmap);

	ReadData();
	InitListCtrl();
	UpdateTreeCtrl();
}


void CSettingDialog::OnBnClickedButtonAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	CString date, type, name, money;
	m_EditDate.GetWindowTextW(date);
	m_ComboBoxType.GetWindowTextW(type);
	m_EditName.GetWindowTextW(name);
	m_EditMoney.GetWindowTextW(money);
	int iMoney = _ttoi(money);
	if (date.GetLength() != 8 || type.GetLength() == 0 || name.GetLength() == 0 || iMoney == 0)
	{
		return;
	}
	ListItem item;
	item.date = date;
	item.type = type;
	item.name = name;
	item.money = iMoney;
	AddListItem(item);
	UpdateTreeCtrl();
}


void CSettingDialog::OnBnClickedButtonDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	while (m_List.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) != -1)
	{
		int nItem = m_List.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		m_List.DeleteItem(nItem);
		listVec.erase(listVec.begin() + nItem);
		UpdateTreeCtrl();
	}
}


void CSettingDialog::OnCbnSelchangeComboType()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	CBitmap bitmap;
	m_ComboBoxType.GetLBText(m_ComboBoxType.GetCurSel(), str);
	if (str.Compare(_T("食品")) == 0)
	{
		bitmap.LoadBitmapW(IDB_BITMAP_FOOD);
	}
	else if (str.Compare(_T("生活用品")) == 0)
	{
		bitmap.LoadBitmapW(IDB_BITMAP_LIFE);
	}
	else if (str.Compare(_T("电器")) == 0)
	{
		bitmap.LoadBitmapW(IDB_BITMAP_ELECTRIC);
	}
	else
	{
		bitmap.LoadBitmapW(IDB_BITMAP_OTHERS);
	}
	m_Pic.SetBitmap(bitmap);
}


void CSettingDialog::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
	WriteData();
}


void CSettingDialog::AddListItem(ListItem item)
{
	int raw = m_List.InsertItem(m_List.GetItemCount(), item.date);
	m_List.SetItemText(raw, 1, item.type);
	m_List.SetItemText(raw, 2, item.name);
	CString str;
	str.Format(_T("%d"), item.money);
	m_List.SetItemText(raw, 3, str);
	listVec.push_back(item);
}


void CSettingDialog::UpdateTreeCtrl()
{
	treeVec.clear();
	for (int i = 0; i < listVec.size(); i++)
	{
		bool exist = false;
		ListItem listItem = listVec[i];
		for (int j = 0; j < treeVec.size(); j++)
		{
			TreeItem treeItem = treeVec[j];
			if (listItem.date.Compare(treeItem.date) == 0)
			{
				exist = true;
				treeItem = Transform(treeItem, listItem);
				treeVec.erase(treeVec.begin() + j);
				treeVec.insert(treeVec.begin() + j, treeItem);
				break;
			}
		}
		if (exist == false)
		{
			TreeItem treeItem;
			treeItem.date = listItem.date;
			treeItem = Transform(treeItem, listItem);
			treeVec.push_back(treeItem);
		}
	}

	m_Tree.DeleteAllItems();
	for (int i = 0; i < treeVec.size(); i++)
	{
		TreeItem treeItem = treeVec[i];
		HTREEITEM hRoot = m_Tree.InsertItem(treeItem.date, 0, 0);
		CString str;
		str.Format(_T("%d"), treeItem.sum);
		m_Tree.InsertItem(_T("总消费数：") + str, 1, 1, hRoot, TVI_LAST);
		str.Format(_T("%d"), treeItem.food);
		m_Tree.InsertItem(_T("食品：") + str, 1, 1, hRoot, TVI_LAST);
		str.Format(_T("%d"), treeItem.life);
		m_Tree.InsertItem(_T("生活用品：") + str, 1, 1, hRoot, TVI_LAST);
		str.Format(_T("%d"), treeItem.electric);
		m_Tree.InsertItem(_T("电器：") + str, 1, 1, hRoot, TVI_LAST);
		str.Format(_T("%d"), treeItem.others);
		m_Tree.InsertItem(_T("其他：") + str, 1, 1, hRoot, TVI_LAST);
	}
}


TreeItem CSettingDialog::Transform(TreeItem treeItem, ListItem listItem)
{
	if (listItem.type.Compare(_T("食品")) == 0)
	{
		treeItem.food += listItem.money;
	}
	else if (listItem.type.Compare(_T("生活用品")) == 0)
	{
		treeItem.life += listItem.money;
	}
	else if (listItem.type.Compare(_T("电器")) == 0)
	{
		treeItem.electric += listItem.money;
	}
	else
	{
		treeItem.others += listItem.money;
	}
	treeItem.sum = treeItem.food + treeItem.life + treeItem.electric + treeItem.others;
	return treeItem;
}


void CSettingDialog::ReadData()
{
	//输出中文
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");

	CStdioFile oFile;
	if (oFile.Open(_T(".\\files\\history.txt"), CFile::modeRead))
	{
		int length;
		CString str;
		oFile.ReadString(str);
		length = _ttoi(str);
		for (int i = 0; i < length; i++)
		{
			ListItem listItem;
			oFile.ReadString(str);
			listItem.date = str;
			oFile.ReadString(str);
			listItem.name = str;
			oFile.ReadString(str);
			listItem.type = str;
			oFile.ReadString(str);
			int money = _ttoi(str);
			listItem.money = money;
			listVec.push_back(listItem);
		}
	}
	//输出中文
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
}


void CSettingDialog::WriteData()
{
	//输出中文
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");

	CStdioFile oFile;
	oFile.Open(_T(".\\files\\history.txt"), CFile::modeCreate | CFile::modeWrite);
	CString str;
	str.Format(_T("%d"), listVec.size());
	oFile.WriteString(str + _T("\n"));
	for (int i = 0; i < listVec.size(); i++)
	{
		oFile.WriteString(listVec[i].date + _T("\n"));
		oFile.WriteString(listVec[i].name + _T("\n"));
		oFile.WriteString(listVec[i].type + _T("\n"));
		str.Format(_T("%d"), listVec[i].money);
		oFile.WriteString(str + _T("\n"));
	}
	//输出中文
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);

	oFile.Close();
}


void CSettingDialog::InitListCtrl()
{
	for (int i = 0; i < listVec.size(); i++)
	{
		int raw = m_List.InsertItem(m_List.GetItemCount(), listVec[i].date);
		m_List.SetItemText(raw, 1, listVec[i].type);
		m_List.SetItemText(raw, 2, listVec[i].name);
		CString str;
		str.Format(_T("%d"), listVec[i].money);
		m_List.SetItemText(raw, 3, str);
	}
}
