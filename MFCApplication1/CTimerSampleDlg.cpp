// CTimerSampleDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CTimerSampleDlg.h"
#include "afxdialogex.h"
#include<locale.h>

// CTimerSampleDlg 对话框

IMPLEMENT_DYNAMIC(CTimerSampleDlg, CDialogEx)

CTimerSampleDlg::CTimerSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CTimerSampleDlg::~CTimerSampleDlg()
{
}

void CTimerSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TIMELOG, m_staticTime);
	DDX_Control(pDX, IDC_EDIT_FILE, m_Content);
}


BEGIN_MESSAGE_MAP(CTimerSampleDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START,OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP,OnButtonStop)
	ON_WM_TIMER(IDC_BUTTON_STOP, OnTimer)
	ON_BN_CLICKED(IDC_BUTTON_READ,OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_WRITE,OnButtonWrite)
END_MESSAGE_MAP()


// CTimerSampleDlg 消息处理程序
BOOL CTimerSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}
void CTimerSampleDlg::OnButtonStart()
{
	SetTimer(100, 1000, NULL);
	m_BeginTime = CTime::GetCurrentTime();
}
void CTimerSampleDlg::OnButtonStop()
{
	KillTimer(100);
}
void CTimerSampleDlg::OnTimer(UINT nIDEvent)
{
	CTime m_EndTime = CTime::GetCurrentTime();
	CTimeSpan m_span = m_EndTime - m_BeginTime;
	CString log;
	log.Format(L"%d", m_span.GetSeconds());
	m_staticTime.SetWindowText(log);
	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}
void CTimerSampleDlg::OnButtonRead()
{
	CFile file;
	file.Open(L"data.txt", CFile::modeRead);  //打开文件
	//获取读取的内容的长度
	int len = min(file.GetLength(), MAX_FILE_LEN);
	char buf[MAX_FILE_LEN] = { 0 };
	char* pOldLocale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	file.Read(buf, len); //读取文件内容
	setlocale(LC_CTYPE, pOldLocale);
	free(pOldLocale);
	buf[len] = '\0';
	USES_CONVERSION;//转化为wchar_t* 可以使用CString的Format函数。
	wchar_t* temp = new wchar_t[len + 1];
	temp = A2T(buf);
	CString temp1;
	temp1.Format(_T("%s"), temp);
	/*m_Content.SetWindowText(temp);*/
	SetDlgItemText(IDC_EDIT_FILE, temp1);
	file.Close();
	UpdateData(FALSE);
} 
void CTimerSampleDlg::OnButtonWrite()
{
	UpdateData();
	CFile file;
	//打开文件
	file.Open(L"data.txt", CFile::modeCreate | CFile::modeWrite);
	//向文件写入内容
	CString temp;
	GetDlgItem(IDC_EDIT_FILE)->GetWindowText(temp);
	CStringA str_ANSI(temp.GetBuffer(0)); //将字符从UTF-8转成ANSI
	file.Write(str_ANSI.GetBuffer(), str_ANSI.GetLength());
	file.Close(); //关闭文件
	MessageBox(L"写入成功", L"提示");
}