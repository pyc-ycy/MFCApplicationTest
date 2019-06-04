
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//{{AFX_MSG_MAP(CClassView)
	ON_COMMAND(ID_STATU, OnMenuitemStatu)
	ON_UPDATE_COMMAND_UI(ID_STATU, OnUpdateMenuitemStatu)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FIRST_INPUT,OnReName)
	ON_COMMAND(ID_FIRST_CHANGE,OnCreateNewFile)
	//}}AFX_MSG
END_MESSAGE_MAP() 

// CMFCApplication1View 构造/析构
void CMFCApplication1View::OnMenuitemStatu()
{//状态测试命令消息处理函数
	if (bToosCheck)
		bToosCheck = FALSE;  //切换菜单项的选择状态变量值
	else
		bToosCheck = TRUE;
}
void CMFCApplication1View::OnUpdateMenuitemStatu(CCmdUI* pCmdUI)
{
	//状态测试命令更新消息处理函数
	if (bToosCheck)  //判断菜单项状态变量
	{
		pCmdUI->SetCheck(1);  //如果选中，则设置菜单状态为选中
		pCmdUI->SetText(L"选择，单击取消");
	}
	else
	{
		pCmdUI->SetCheck(0);  //如果未选，则设置菜单选项状态为未选
		pCmdUI->SetText(L"未选择，单击选择");//设置菜单项文本
	}
}
void CMFCApplication1View::OnRButtonDown(UINT  nFlags, CPoint point)
{
	POINT screenPoint = point; //定义屏幕坐标
	ClientToScreen(&screenPoint); //将传入的客户区域坐标转换为屏幕坐标
	CMenu menu;  //定义菜单对象
	VERIFY(menu.LoadMenuW(IDR_MENU3));//验证装载的菜单项
	CMenu* pPopup = menu.GetSubMenu(0);//获取弹出菜单
	ASSERT(pPopup != NULL);//验证获取的弹出菜单
	//显示弹出式菜单
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, screenPoint.x, screenPoint.y, AfxGetMainWnd());
	CView::OnRButtonDown(nFlags, point);
}
//弹出式重命名菜单项处理函数
void CMFCApplication1View::OnReName()
{
	CDC* pDC = GetDC();  //获取设备上下文
	pDC->TextOut(0, 0, L"无边落木萧萧下，不尽长江滚滚来");
}
void CMFCApplication1View::OnCreateNewFile()
{
	CDC* pDC = GetDC();
	wchar_t s[] = L"天道无情，以万物为刍狗；人自多情，将爱恨尽演绎";
	pDC->TextOut(0, 0, s);
}

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication1View 打印


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
	
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序
