
// SearchPerformDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "vector"
#include "iostream"
using namespace std;
#include "LinearSearch.h"
#include "TwoSearch.h"
#include "afxcmn.h"


// CSearchPerformDlg �Ի���
class CSearchPerformDlg : public CDialogEx
{
// ����
public:
	CSearchPerformDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SEARCHPERFORM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CLinearSearch m_LinearSearch;
	CTwoSearch m_TwoSearch;
	CTabCtrl m_Tab;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
