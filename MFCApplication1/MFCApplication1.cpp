
// MFCApplication1.cpp: 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication1.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include"MFCDiaLog.h"
#include"CTimerSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App

BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMFCApplication1App::OnAppAbout)
	ON_COMMAND(IDM_ABOUTBOX, OnTestDlg)
	ON_COMMAND(ID_LB,OnTestLBDlg)
	ON_COMMAND(ID_T,OnTestTime)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CMFCApplication1App 构造

CMFCApplication1App::CMFCApplication1App() noexcept
{
	m_bHiColorIcons = TRUE;

	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApplication1.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的 CMFCApplication1App 对象

CMFCApplication1App theApp;


// CMFCApplication1App 初始化

BOOL CMFCApplication1App::InitInstance()
{
	//// 如果一个运行在 Windows XP 上的应用程序清单指定要
	//// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	////则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	//INITCOMMONCONTROLSEX InitCtrls;
	//InitCtrls.dwSize = sizeof(InitCtrls);
	//// 将它设置为包括所有要在应用程序中使用的
	//// 公共控件类。
	//InitCtrls.dwICC = ICC_WIN95_CLASSES;
	//InitCommonControlsEx(&InitCtrls);

	//CWinAppEx::InitInstance();


	//// 初始化 OLE 库
	//if (!AfxOleInit())
	//{
	//	AfxMessageBox(IDP_OLE_INIT_FAILED);
	//	return FALSE;
	//}

	//AfxEnableControlContainer();

	//EnableTaskbarInteraction();

	//// 使用 RichEdit 控件需要 AfxInitRichEdit2()
	//// AfxInitRichEdit2();

	//// 标准初始化
	//// 如果未使用这些功能并希望减小
	//// 最终可执行文件的大小，则应移除下列
	//// 不需要的特定初始化例程
	//// 更改用于存储设置的注册表项
	//// TODO: 应适当修改该字符串，
	//// 例如修改为公司或组织名
	//SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	//LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	//InitContextMenuManager();

	//InitKeyboardManager();

	//InitTooltipManager();
	//CMFCToolTipInfo ttParams;
	//ttParams.m_bVislManagerTheme = TRUE;
	//theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
	//	RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	//// 注册应用程序的文档模板。  文档模板
	//// 将用作文档、框架窗口和视图之间的连接
	//CMultiDocTemplate* pDocTemplate;
	//pDocTemplate = new CMultiDocTemplate(IDR_MFCApplication1TYPE,
	//	RUNTIME_CLASS(CMFCApplication1Doc),
	//	RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
	//	RUNTIME_CLASS(CMFCApplication1View));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);

	//// 创建主 MDI 框架窗口
	//CMainFrame* pMainFrame = new CMainFrame;
	//if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	//{
	//	delete pMainFrame;
	//	return FALSE;
	//}
	//m_pMainWnd = pMainFrame;


	//// 分析标准 shell 命令、DDE、打开文件操作的命令行
	//CCommandLineInfo cmdInfo;
	//ParseCommandLine(cmdInfo);



	//// 调度在命令行中指定的命令。  如果
	//// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;
	//// 主窗口已初始化，因此显示它并对其进行更新
	//pMainFrame->ShowWindow(m_nCmdShow);
	//pMainFrame->UpdateWindow();

	//return TRUE;
	AfxEnableControlContainer();
#ifdef _AFXDLL  //判断是否定义了AFXDLL
	//Enable3dControls();
#else
	Enable3dControlsStatic();
#endif
	//设置注册表键
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)，即加载标准配置设置

	// 注册应用程序的文档模板。  文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CMultiDocTemplate* pDocTemplate;  //定义多文档变量
	pDocTemplate = new CMultiDocTemplate(IDR_MFCApplication1TYPE,
		RUNTIME_CLASS(CMFCApplication1Doc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CMFCApplication1View));
	//pDocTemplate = new CMultiDocTemplate(IDR_MENU3,
	//	RUNTIME_CLASS(CMFCApplication1Doc),
	//	RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
	//	RUNTIME_CLASS(CMFCApplication1View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate); //增加到文档模板集合

	// 创建主 MDI 框架窗口
	CMainFrame* pMainFrame = new CMainFrame;  //定义 CMainFrame 类
	//装载框架
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;  //为主窗口类赋值


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;  //定义命令行信息变量
	ParseCommandLine(cmdInfo);  //解析命令行



	// 调度在命令行中指定的命令。  如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	//处理命令
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 主窗口已初始化，因此显示它并对其进行更新
	pMainFrame->ShowWindow(m_nCmdShow);  //显示主窗口
	pMainFrame->UpdateWindow();  //刷新主窗口

	return TRUE;
}

int CMFCApplication1App::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CMFCApplication1App 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg(CWnd* pParent = NULL);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnClickedButtonTest();
	// 测试控价对象的操作
	CButton m_button_test;
	CListBox listbox;
	afx_msg void OnDoubleclickedButtonTest();
	afx_msg void OnSelChangeListTest();
	
	CString m_strTestAoubtName;
};
CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/) :CDialogEx(IDD_ABOUTBOX, pParent), m_strTestAoubtName(_T(""))
{
	
}
//CAboutDlg::CAboutDlg()noexcept : CDialogEx(IDD_ABOUTBOX)
//{
//}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_button_test);
	DDX_Text(pDX,IDC_STATIC_ABOUTNAME, m_strTestAoubtName);
	DDX_Control(pDX, IDC_LIST_ABOUT, listbox);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, &CAboutDlg::OnMcnSelchangeMonthcalendar1)
 	ON_BN_CLICKED(IDC_BUTTON_TEST, &CAboutDlg::OnClickedButtonTest)
	ON_BN_DOUBLECLICKED(IDC_BUTTON_TEST, &CAboutDlg::OnDoubleclickedButtonTest)
    ON_BN_CLICKED(IDC_BUTTON_TEST, &CAboutDlg::OnClickedButtonTest)
	//列表框测试
	ON_LBN_SELCHANGE(IDC_LIST_ABOUT, OnSelChangeListTest)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CMFCApplication1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCApplication1App 自定义加载/保存方法
void CMFCApplication1App::OnTestLBDlg()
{
	MFCDiaLog testlog;
	testlog.DoModal();
}

void CMFCApplication1App::OnTestTime()
{
	CTimerSampleDlg timeDlg;
	timeDlg.DoModal();
}
void CMFCApplication1App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
	
}

void CMFCApplication1App::LoadCustomState()
{
}

void CMFCApplication1App::SaveCustomState()
{
}

// CMFCApplication1App 消息处理程序
BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_strTestAoubtName.LoadString(ID_MY_NAME);
	UpdateData(FALSE);
	listbox.AddString(L"测试");
	CString items[3] = { _T("广州"),_T("上海"),_T("北京") };
	for (int i = 0; i < 3; i++)
	{
		listbox.AddString(items[i]);
	}
	return TRUE;
 }




void CAboutDlg::OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

//改变列表框选择消息处理函数
void CAboutDlg::OnSelChangeListTest()
{
	int index = listbox.GetCurSel(); //获取当前选择的列表项
	CString result;  //定义结果显示变量
	listbox.GetText(index, result);  //获取选择的列表项到变量中
	MessageBox(result, L"当前列表框选择的内容");
}


void CAboutDlg::OnDoubleclickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"双击击了测试按钮", L"提示");
}


void CAboutDlg::OnClickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"单击了测试按钮", L"提示");
}


//静态控件和编辑控件测试
class CStaticAndEditSampleDlg :public CDialogEx  //对话框类声明
{
public:
	void WriteLog(CString message, CString title);//记录日志函数声明
	CStaticAndEditSampleDlg(CWnd* pParent = NULL);//标准构造函数
	//{{AFX_DATA(CStaticAndEditSampleDlg)
	enum 
	{
		IDD = IDD_STATICANDEDITSAMPLE_DIALOG
	};
	CEdit m_editTestScroll; //带滚动条的编辑控件对应的对象
	CEdit m_editTest; //测试编辑控件对应的对象
	CStatic m_staticLog; //日志静态框
//	CListBox m_listbox;
	CComboBox m_comboTest;
	//}}AFX_DATA
	//{{AFX_VIRTUAL(CStaticAndEditSampleDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX); //DDX/DDV 支持
	//}}AFX_VIRTUAL
protected:
	HICON m_hIcon;  //图标变量
	//{{AFX_MSG(CStaticAndEditSampleDlg)//消息映射
	virtual BOOL OnTestInitDialog(); //初始化对话框函数声明
	//void InitListBoxData();//初始化列表框
public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);//系统命令函数声明
	afx_msg void OnPaint(); //重绘函数声明
	afx_msg HCURSOR OnQueryDragIcon(); //查询拖放图标函数声明
	afx_msg void OnChangeEditTest();  //改变编辑框内容函数声明
	afx_msg void OnErrspaceEditTest();  //擦除编辑框内容函数声明
	afx_msg void OnKillfocusEditTest();  //编辑框失去焦点函数声明
	afx_msg void OnMaxtextEditTest();   //编辑框内容达到最大值函数声明
	afx_msg void OnSetfocusEditTest();  //设置编辑框检点函数声明
	afx_msg void OnUpdateEditTest();  //更新编辑框函数声明
	afx_msg void OnHscrollEditTestScroll();  //水平滚动条滚动事件函数声明
	afx_msg void OnVscrollEditTestScroll();  //垂直滚动条滚动事件函数声明
	afx_msg void OnButtonGetedittext();  //获取文本内容时间函数声明
	afx_msg void OnButtonSetedittext(); //设置文本内容事件函数声明
	afx_msg void OnButtonGetline(); //获取文本行内容事件函数声明
	afx_msg void OnButtonGetsel();  //获取选择的文本内容事件函数声明
	afx_msg void OnButtonSetsel();  //设置选择的文本内容事件函数声明
	afx_msg void OnButtonReplacesel();  //替换选择的文本内容事件函数声明
	afx_msg void OnStaticTest();  //静态控件测试事件函数声明
	afx_msg void OnButtoGetstate();//选择按钮测试
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()  //结束消息映射
public:
	/*DECLARE_MESSAGE_MAP()
	afx_msg void OnEnChangeEditTest();
	afx_msg void OnBnClickedButtonGetline();
	afx_msg void OnEnChangeEditTestscroll();*/
	/*afx_msg void OnAboutbox();
	afx_msg void OnStnClickedStaticLog();*/
	CListBox testlist;
};


//对话框初始化函数
CStaticAndEditSampleDlg::CStaticAndEditSampleDlg(CWnd* pParent/*=NULL*/) :CDialogEx(CStaticAndEditSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaticAndEditSampleDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIconW(IDR_MAINFRAME); //装载应用程序图标

}

//数据交换函数
void CStaticAndEditSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); //执行基类的数据交换函数
									//{{AFX_DATA_MAP(CStaticAndEditSampleDlg) //控件和数据映射对应关系
	DDX_Control(pDX, IDC_EDIT_TESTSCROLL, m_editTestScroll);
	DDX_Control(pDX, IDC_EDIT1_TEST, m_editTest);
	//日志静态框变量声明
	DDX_Control(pDX, IDC_STATIC_LOG, m_staticLog);
	//列表框和组合框
	//  DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Control(pDX, IDC_COMBO_TEST, m_comboTest);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LIST1, testlist);
}BEGIN_MESSAGE_MAP(CStaticAndEditSampleDlg, CDialogEx) //消息映射表开始
//{{AFX_MSG_MAP(CStaticAndEditSampleDlg)

ON_WM_SYSCOMMAND()  //系统命令消息
ON_WM_PAINT() //重绘消息
ON_WM_QUERYDRAGICON()  //查询拖动图标消息
//编辑框内容改变消息映射
ON_EN_CHANGE(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnChangeEditTest)
//编辑框内容擦除消息映射
ON_EN_ERRSPACE(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnErrspaceEditTest)
//编辑框失去焦点消息映射
ON_EN_KILLFOCUS(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnKillfocusEditTest)
//编辑框内容改变消息映射
ON_EN_MAXTEXT(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnMaxtextEditTest)
//编辑框获得焦点消息映射
ON_EN_SETFOCUS(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnSetfocusEditTest)
//编辑框内容更新消息映射
ON_EN_UPDATE(IDC_EDIT1_TEST, &CStaticAndEditSampleDlg::OnUpdateEditTest)
//水平滚动消息映射
ON_EN_HSCROLL(IDC_EDIT_TEST_SCROLL, &CStaticAndEditSampleDlg::OnHscrollEditTestScroll)
//垂直滚动消息
ON_EN_VSCROLL(IDC_EDIT_TEST_VSCROLL, &CStaticAndEditSampleDlg::OnVscrollEditTestScroll)
//获取文本消息
ON_BN_CLICKED(IDC_BUTTON_GETEDITTEXT, &CStaticAndEditSampleDlg::OnButtonGetedittext)
//设置文本消息
ON_BN_CLICKED(IDC_BUTTON_SETEDITTEXT, &CStaticAndEditSampleDlg::OnButtonSetedittext)
ON_BN_CLICKED(IDC_BUTTON_GETLINE, &CStaticAndEditSampleDlg::OnButtonGetline) //获取行
//获取选择内容
ON_BN_CLICKED(IDC_BUTTON_GETSEL, &CStaticAndEditSampleDlg::OnButtonGetsel)
//设置选择内容
ON_BN_CLICKED(IDC_BUTTON_SETSEL, &CStaticAndEditSampleDlg::OnButtonSetsel)
//文本替换
ON_BN_CLICKED(IDC_BUTTON_REPLACESEL, &CStaticAndEditSampleDlg::OnButtonReplacesel)
//信息提示
ON_BN_CLICKED(IDC_STATIC_TEST, &CStaticAndEditSampleDlg::OnStaticTest)
//按钮测试
ON_BN_CLICKED(IDC_BUTTON_CH, &CStaticAndEditSampleDlg::OnButtoGetstate)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMFCApplication1App::OnTestDlg()
{
	CStaticAndEditSampleDlg aboutDlg;
	aboutDlg.DoModal();
}
//初始对话框
BOOL CStaticAndEditSampleDlg::OnTestInitDialog()
{
	//调用基类对话框初始化函数
	CDialogEx::OnInitDialog();
	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);  //判断是否关于命令
	//ASSERT(IDM_ABOUTBOX < 0xF000);
	//CMenu* pSysMenu = GetSystemMenu(FALSE);
	//if (pSysMenu != NULL)
	//{
	//	//定义存放菜单名称的字符串变量
	//	CString strAboutMenu;
	//	strAboutMenu.LoadStringW(IDD_STATICANDEDITSAMPLE_DIALOG); //装载对话框的菜单
	//	if (!strAboutMenu.IsEmpty())
	//	{
	//		pSysMenu->AppendMenu(MF_SEPARATOR);//增加分隔符
	//		//增加“关于”菜单命令
	//		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	//	}
	//}
	//SetIcon(m_hIcon, TRUE); //设置大图标
	//SetIcon(m_hIcon, FALSE); //设置小图标
	////列表框数据组
	UpdateData(FALSE);
	CString items[3] = { _T("广州"),_T("上海"),_T("北京") };
	for (int i = 0; i < 3; i++)
	{
		testlist.AddString(items[i]);
	}
	return TRUE;
}

void CStaticAndEditSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)  //判断单击选择的命令是否为“关于”命令
	{
		CStaticAndEditSampleDlg dlgAbout; //定义关于对话框
		dlgAbout.DoModal();  //显示“关于”对话框
	}
	else
		CDialog::OnSysCommand(nID, lParam);  //如果不是“关于”命令，则处理命令消息
}

void CStaticAndEditSampleDlg::OnPaint()  //对话框绘制函数
{
	if (IsIconic())  //判断是否是图标状态
	{
		CPaintDC dc(this);  //进行绘制的设备上下文
		//发送图标背景绘制消息
		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);
		//将图标放置在客户端矩形中间
		int cxIcon = GetSystemMetrics(SM_CXICON);//获取小图标的x长度
		int cyIcon = GetSystemMetrics(SM_CYICON);//获取小图标的y高度
		CRect rect; //定义矩形区域
		GetClientRect(&rect);  //获取客户区矩形
		int x = (rect.Width() - cxIcon + 1) / 2;  //计算客户区中心点的X值
		int y = (rect.Height() - cyIcon + 1) / 2;  //计算客户区中心点y值
		dc.DrawIcon(x, y, m_hIcon);  //绘制图标
	}
	else
		CDialog::OnPaint();
}

//获取拖动图标消息处理函数
HCURSOR CStaticAndEditSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

//文本内容改变消息处理函数
void CStaticAndEditSampleDlg::OnChangeEditTest()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	WriteLog(L"接收到ON_EN_CHANGE消息", CString("左边的编辑控件"));
	// TODO:  在此添加控件通知处理程序代码
}
//文本内容擦除消息处理函数
void CStaticAndEditSampleDlg::OnErrspaceEditTest()
{
	WriteLog(L"接收到ON_EN_ERRSPACE消息", CString("左边的编辑控件"));
}
//失去焦点消息处理函数
void CStaticAndEditSampleDlg::OnKillfocusEditTest()
{
	WriteLog(L"接收到ON_EN_KILLFOCUS消息", CString("左边的编辑控件"));
}
//达到最大文本数消息处理函数
void CStaticAndEditSampleDlg::OnMaxtextEditTest()
{
	WriteLog(L"接收到ON_EN_MAXTEXT消息", CString("左边的编辑控件"));
}
//获取焦点 消息处理函数
void CStaticAndEditSampleDlg::OnSetfocusEditTest()
{
	WriteLog(L"接收到ON_EN_SETFOCUS消息", CString("左边的编辑控件"));
}
//更新消息处理函数
void CStaticAndEditSampleDlg::OnUpdateEditTest()
{
	WriteLog(L"接收到ON_EN_UPDATE消息", CString("左边的编辑控件"));
}
//水平滚动消息处理函数
void CStaticAndEditSampleDlg::OnHscrollEditTestScroll()
{
	WriteLog(L"接收到ON_EN_HSCROLL消息", CString("右边的编辑控件"));
}
//垂直滚动消息处理函数
void CStaticAndEditSampleDlg::OnVscrollEditTestScroll()
{
	WriteLog(L"接收到ON_EN_VSCROLL消息", CString("右边的编辑控件"));
}
//显示日志函数
void CStaticAndEditSampleDlg::WriteLog(CString message, CString title)
{
	//获取当前日志静态框的文本内容
	m_staticLog.SetWindowText(title + "--" + message);
}
//获取编辑框内容处理函数
void CStaticAndEditSampleDlg::OnButtonGetedittext()
{
	CString content; //定义编辑框内容字符串
	m_editTest.GetWindowText(content);
	//在弹出对话框中显示获取的编辑内容
	MessageBox(content, L"获取左边编辑框的内容");
}
//设置编辑框内容处理函数
void CStaticAndEditSampleDlg::OnButtonSetedittext()
{
	m_editTest.SetWindowText(L"你好，这是在测试");
}
//获取编辑框指定行内容处理函数
void CStaticAndEditSampleDlg::OnButtonGetline()
{
	TCHAR content[256]; //存放内容的字符串变量
	memset(content, 0x00, sizeof(content));//初始化字符串数组
	int iCount = m_editTest.GetLine(1, content, sizeof(content));//获取第二行的内容
	if (iCount > 0)
		MessageBox(content, L"GETLINE 获取第二行内容");
	else
		MessageBox(L"失败", L"GETLINE 获取第二行内容");
}
//获取选择的内容
void CStaticAndEditSampleDlg::OnButtonGetsel()
{
	int iStart = 0, iEnd = 0;  //定义开始位置和结束位置的变量
	//获取选择的内容所在的开始位置和结束位置
	m_editTest.GetSel(iStart, iEnd);
	CString log;  //日志字符串
	log.Format(L"选择的内容从%d个字符到第%d个字符", iStart, iEnd);//格式化信息提示
	MessageBox(log, L"GetSel");
}
//设置选择的内容
void CStaticAndEditSampleDlg::OnButtonSetsel()
{
	m_editTest.SetSel(5, 10, TRUE);//设置选择第6~11个字符
	MessageBox(L"选择第6个字符到第11个字符", L"SetSel");//显示提示信息
}
//文本替换命令
void CStaticAndEditSampleDlg::OnButtonReplacesel()
{
	m_editTest.ReplaceSel(L"若道天涯无回路，漫漫黄沙掩枯骨");
}
//静态控件处理函数
void CStaticAndEditSampleDlg::OnStaticTest()
{
	MessageBox(L"如果使用 SS_NOTIFY 创建静态控件， \n则可以接收单击事件，\n此处就是  例子。", L"静态控件");
}
//单选按钮和复选框测试
void CStaticAndEditSampleDlg::OnButtoGetstate()
{
	//颜色选择
	UINT iColor[] = { IDC_RADIO_RED,IDC_RADIO_GREEN,IDC_RADIO_BLUE };
	CString sColor[] = { L"红色",L"绿色",L"蓝色" };
	CString sResualtColor;
	CButton *pBtn = NULL;
	for (int i = 0; i < 3; i++)
	{
		pBtn = (CButton*)GetDlgItem(iColor[i]);
		if (!pBtn)
			continue;
		if (pBtn->GetCheck() == 1)
			sResualtColor = L"颜色选择：" + sColor[i];
	}

	//性别选择
	UINT iSex[] = { IDC_RADIO_BOY,IDC_RADIO_GIRL };
	CString sSex[] = { L"男",L"女" };
	CString sResualtSex;
	for (int i = 0; i < 2; i++)
	{
		pBtn = (CButton*)GetDlgItem(iSex[i]);
		if (!pBtn)
			continue;
		if (pBtn->GetCheck() == 1)
			sResualtSex = L"\n性别选择：" + sSex[i];
	}

	//喜好选择
	UINT iLike[] = { IDC_CHECK_BOOK,IDC_CHECK_MUSIC,IDC_CHECK_SPORT,IDC_CHECK_DANCE };
	CString sLike[] = { L"读书",L"听音乐",L"运动",L"跳舞" };
	CString sResualtLike = L"\n爱好：";
	for (int i = 0; i < 4; i++)
	{
		pBtn = (CButton*)GetDlgItem(iLike[i]);
		if (!pBtn)
			continue;
		if (pBtn->GetCheck() == 1)
			sResualtLike = sResualtLike + sLike[i] + L"、";
	}

	//总结输出
	MessageBox(sResualtColor + sResualtSex + sResualtLike, L"选择结果");
}
//初始化列表框中的数据
//void CStaticAndEditSampleDlg::InitListBoxData()
//{
//	//列表框数据组
//	CString items[3] = { L"广州",L"上海",L"北京" };
//	for (int i = 0; i < 3; i++)
//	{
//		m_listTest.AddString(items[i]);
//	}
//}
