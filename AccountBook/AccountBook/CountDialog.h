#pragma once
#include "afxwin.h"
#include "algorithm"
#include "SettingDialog.h"


// CCountDialog 对话框

class CCountDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CCountDialog)

public:
	CCountDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCountDialog();

// 对话框数据
	enum { IDD = IDD_COUNT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	void InitData();
private:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonCount();
	bool Contain(vector<CString> vec, CString str);
	void ShowResult(TreeItem countItem);
	CComboBox m_ComboBoxStart;
	CComboBox m_ComboBoxEnd;
	CButton m_ButtonCount;
	CStatic m_TextFood;
	CStatic m_TextLife;
	CStatic m_TextElectric;
	CStatic m_TextOthers;
	CStatic m_TextSum;
	CStatic m_TextFoodPer;
	CStatic m_TextLifePer;
	CStatic m_TextElectricPer;
	CStatic m_TextOthersPer;
	CStatic m_TextSumPer;
	vector<CString> timeVec;
};
