#pragma once
#include "iostream"
using namespace std;
#include "vector"


struct ListItem{
	CString date;
	CString name;
	CString type;
	int money;
};

struct TreeItem{
	CString date;
	int sum = 0;
	int food = 0;
	int life = 0;
	int electric = 0;
	int others = 0;
};

// CSettingDialog 对话框

class CSettingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDialog)

public:
	CSettingDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDialog();

// 对话框数据
	enum { IDD = IDD_SETTING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	TreeItem Transform(TreeItem treeItem, ListItem listItem);
private:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnCbnSelchangeComboType();
	afx_msg void OnDestroy();
	void InitData();
	void AddListItem(ListItem item);
	void UpdateTreeCtrl();
	void ReadData();
	void WriteData();
	void InitListCtrl();
	CTreeCtrl m_Tree;
	CListCtrl m_List;
	CEdit m_EditName;
	CComboBox m_ComboBoxType;
	CEdit m_EditMoney;
	CEdit m_EditDate;
	CStatic m_Pic;
	CButton m_ButtonAdd;
	CButton m_ButtonDelete;
	vector <TreeItem> treeVec;
};
