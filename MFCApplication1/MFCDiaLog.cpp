// MFCDiaLog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCDiaLog.h"
#include "afxdialogex.h"
#include <afxinet.h>

// MFCDiaLog 对话框

IMPLEMENT_DYNAMIC(MFCDiaLog, CDialog)

MFCDiaLog::MFCDiaLog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

MFCDiaLog::~MFCDiaLog()
{
}

void MFCDiaLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listTest);
	DDX_Control(pDX, IDC_COMBO, m_combotest);
	DDX_Control(pDX, IDC_SPIN1, m_spin);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_EDIT2, m_editPrecent);
	DDX_Control(pDX, IDC_LISTVIEW, m_listview);
	DDX_Control(pDX, IDC_TREE1, m_filectrl);
}


BEGIN_MESSAGE_MAP(MFCDiaLog, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelChangeTest)
	ON_CBN_SELCHANGE(IDC_COMBO,OnSelChangeCombotest)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnReleasedcaptureSliderPercent)
	ON_BN_CLICKED(IDC_BUTTON1,OnButtonTimer)
	ON_WM_TIMER(IDC_PROGRESS1,OnTimer)
END_MESSAGE_MAP()


// MFCDiaLog 消息处理程序
BOOL MFCDiaLog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString items[5] = { L"地名",L"北京",L"上海",L"广州",L"肇庆" };
	for (int i = 0; i < 5; i++)
	{
		m_listTest.AddString(items[i]);
	}
	m_combotest.AddString(L"汉族");
	m_combotest.AddString(L"回族");
	m_combotest.AddString(L"满族");
	m_combotest.AddString(L"白族");
	m_combotest.AddString(L"其他");
	//初始化微调控件
	m_spin.SetRange(0, 100);
	m_spin.SetBase(10);
	m_spin.SetPos(0);
	//初始化微调控件参数
	m_slider.SetRange(0, 100, TRUE);
	m_slider.SetTic(10);
	m_slider.SetPos(10);
	//初始化进度条
	m_progress.SetRange(0, 100);
	m_progress.SetStep(10);
	m_progress.SetPos(0);
	//列表视图控件
	m_listview.InsertItem(0, L"张三", 0);
	m_listview.InsertItem(1, L"李四", 1);
	m_listview.InsertItem(2, L"王五", 2);
	//树形视图
	HTREEITEM hProvince = m_filectrl.InsertItem(L"广东省", 0, 0);
	HTREEITEM hcity1 = m_filectrl.InsertItem(L"肇庆市", 1, 1, hProvince);
	m_filectrl.InsertItem(L"端州区", 2, 2, hcity1);
	m_filectrl.InsertItem(L"星湖区", 2, 2, hcity1);
	m_filectrl.InsertItem(L"鼎湖区", 2, 2, hcity1);
	m_filectrl.InsertItem(L"高要区", 2, 2, hcity1);
	hcity1 = m_filectrl.InsertItem(L"汕尾市", 1, 1, hProvince);
	HTREEITEM city2 = m_filectrl.InsertItem(L"陆丰市", 2, 2, hcity1);
	m_filectrl.InsertItem(L"海丰县", 2, 2, hcity1);
	m_filectrl.InsertItem(L"城区", 2, 2, hcity1);
	m_filectrl.InsertItem(L"陆河县", 2, 2, hcity1);
	m_filectrl.InsertItem(L"河西街道", 3, 3, city2);
	return TRUE;
}
void MFCDiaLog::OnSelChangeTest()
{
	int index = m_listTest.GetCurSel();
	CString result;
	m_listTest.GetText(index, result);
	MessageBox(result, L"当前列表框选择的内容");
}
void MFCDiaLog::OnSelChangeCombotest()
{
	CString result;
	m_combotest.GetLBText(m_combotest.GetCurSel(),result);
	MessageBox(result, L"当前组合框选择的内容");
}
void MFCDiaLog::OnReleasedcaptureSliderPercent(NMHDR* pNMHDR, LRESULT* pResult)
{
	CString text;  //定义字符串变量
	//获取滑块控件当前位置
	text.Format(L"%d", m_slider.GetPos());
	//在编辑控件中显示当前选择值
	m_editPrecent.SetWindowText(text);
	*pResult = 0;
}
//定时器按钮
void MFCDiaLog::OnButtonTimer()
{
	m_progress.SetPos(0);
	SetTimer(100, 100, NULL);
}
//定时器处理函数
void MFCDiaLog::OnTimer(UINT nIDEvent)
{
	//如果定时器是滑块滑动定时器
	if (nIDEvent == 100)
	{
		int pos = m_progress.GetPos();//获取进度条位置
		if (pos < 100)
			m_progress.SetPos(m_progress.GetPos() + 1);
		else
			KillTimer(100);//关闭计时器
	}
	CDialog::OnTimer(nIDEvent);
}