// MemberInfo.h : CMemberInfo ���ʵ��



// CMemberInfo ʵ��

// ���������� 2014��12��21��, 17:43

#include "stdafx.h"
#include "MemberInfo.h"
IMPLEMENT_DYNAMIC(CMemberInfo, CRecordset)

CMemberInfo::CMemberInfo(CDatabase* pdb)
: CRecordset(pdb)
{
	m_m_no = L"";
	m_m_grade = L"";
	m_m_name = L"";
	m_m_sex = L"";
	m_m_id = L"";
	m_m_date = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
// #error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMemberInfo::GetDefaultConnect()
{
	return _T("DBQ=.\\database\\MemberManager.mdb;DefaultDir=.\\database;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=.\\database\\MemberManager.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CMemberInfo::GetDefaultSQL()
{
	return _T("[MemberInfo]");
}

void CMemberInfo::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// RFX_Text() �� RFX_Int() �������������
	// ��Ա���������ͣ����������ݿ��ֶε����͡�
	// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[m_no]"), m_m_no);
	RFX_Text(pFX, _T("[m_grade]"), m_m_grade);
	RFX_Text(pFX, _T("[m_name]"), m_m_name);
	RFX_Text(pFX, _T("[m_sex]"), m_m_sex);
	RFX_Text(pFX, _T("[m_id]"), m_m_id);
	RFX_Text(pFX, _T("[m_date]"), m_m_date);

}
/////////////////////////////////////////////////////////////////////////////
// CMemberInfo ���

#ifdef _DEBUG
void CMemberInfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMemberInfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


