#pragma once


// MFCDiaLog 对话框

class MFCDiaLog : public CDialog
{
	DECLARE_DYNAMIC(MFCDiaLog)

public:
	MFCDiaLog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCDiaLog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	
public:
	// 列表框测试
	CListBox m_listTest;
	afx_msg void OnSelChangeTest();
	// 组合框测试
	CComboBox m_combotest;
	afx_msg void OnSelChangeCombotest();
	// 微调控件测试
	CSpinButtonCtrl m_spin;
	// 滑块控件测试
	CSliderCtrl m_slider;
	// 进度条测试
	CProgressCtrl m_progress;
	afx_msg void OnReleasedcaptureSliderPercent(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonTimer();
	afx_msg void OnTimer(UINT nIDEvent);
	// 微调控件所附的编辑控件
	CEdit m_editPrecent;
	// 列表视图控件测试
	CListCtrl m_listview;
	// 树形视图控件测试
	CTreeCtrl m_filectrl;
};
