#pragma once


// CTimerSampleDlg 对话框
#define MAX_FILE_LEN 2000

class CTimerSampleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTimerSampleDlg)

public:
	CTimerSampleDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTimerSampleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_staticTime;
	CTime m_BeginTime;
	

	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnTimer(UINT nIDEvent);
	CEdit m_Content;
	afx_msg void OnButtonRead();
	afx_msg void OnButtonWrite();
};
