// MemberInfo.h : CMemberInfo 类的实现



// CMemberInfo 实现

// 代码生成在 2014年12月21日, 17:43

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
// #error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
	// RFX_Text() 和 RFX_Int() 这类宏依赖的是
	// 成员变量的类型，而不是数据库字段的类型。
	// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[m_no]"), m_m_no);
	RFX_Text(pFX, _T("[m_grade]"), m_m_grade);
	RFX_Text(pFX, _T("[m_name]"), m_m_name);
	RFX_Text(pFX, _T("[m_sex]"), m_m_sex);
	RFX_Text(pFX, _T("[m_id]"), m_m_id);
	RFX_Text(pFX, _T("[m_date]"), m_m_date);

}
/////////////////////////////////////////////////////////////////////////////
// CMemberInfo 诊断

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


