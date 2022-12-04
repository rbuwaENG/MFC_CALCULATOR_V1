
// SimpleCalcDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "SimpleCalc.h"
#include "SimpleCalcDlg.h"
#include "afxdialogex.h"
#include <iostream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum Operation {
	OpPlus = 1, OpMinus, OpMultiply, OpDivide, OpPower,OpMod,
};


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimpleCalcDlg dialog



CSimpleCalcDlg::CSimpleCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIMPLECALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_expr);
	DDX_Text(pDX, IDC_EDIT3, m_fullexpr);
}

BEGIN_MESSAGE_MAP(CSimpleCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_ZERO, &CSimpleCalcDlg::OnBnClickedZero)
	ON_BN_CLICKED(ID_ONE, &CSimpleCalcDlg::OnBnClickedOne)
	ON_BN_CLICKED(ID_TWO, &CSimpleCalcDlg::OnBnClickedTwo)
	ON_BN_CLICKED(ID_THREE, &CSimpleCalcDlg::OnBnClickedThree)
	ON_BN_CLICKED(ID_FOUR, &CSimpleCalcDlg::OnBnClickedFour)
	ON_BN_CLICKED(ID_FIVE, &CSimpleCalcDlg::OnBnClickedFive)
	ON_BN_CLICKED(ID_SIX, &CSimpleCalcDlg::OnBnClickedSix)
	ON_BN_CLICKED(ID_SEVEN, &CSimpleCalcDlg::OnBnClickedSeven)
	ON_BN_CLICKED(ID_EIGHT, &CSimpleCalcDlg::OnBnClickedEight)
	ON_BN_CLICKED(ID_NINE, &CSimpleCalcDlg::OnBnClickedNine)
	ON_EN_CHANGE(IDC_EDIT3, &CSimpleCalcDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CSimpleCalcDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(ID_PLUS, &CSimpleCalcDlg::OnBnClickedPlus)
	ON_BN_CLICKED(ID_MINUS, &CSimpleCalcDlg::OnBnClickedMinus)
	ON_BN_CLICKED(ID_MUL, &CSimpleCalcDlg::OnBnClickedMul)
	ON_BN_CLICKED(ID_DIV, &CSimpleCalcDlg::OnBnClickedDiv)
	ON_BN_CLICKED(ID_C, &CSimpleCalcDlg::OnBnClickedC)
	ON_BN_CLICKED(IDOK, &CSimpleCalcDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_DOT, &CSimpleCalcDlg::OnBnClickedDot)
	ON_BN_CLICKED(ID_POW, &CSimpleCalcDlg::OnBnClickedPow)
	ON_BN_CLICKED(ID_MOD, &CSimpleCalcDlg::OnBnClickedMod)
END_MESSAGE_MAP()


// CSimpleCalcDlg message handlers

BOOL CSimpleCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	menu.LoadMenuW(IDR_MENU1);
	SetMenu(&menu);

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CSimpleCalcDlg::Compute(int arg)
{
	UpdateData(TRUE);
	if (m_expr.GetLength() == 0)
		return -1;
	m_num2 = _ttof(m_expr);
	if (m_num2 == 0)
		m_fullexpr += "0";
	else
		m_fullexpr += m_expr;
	UpdateData(FALSE);
	UpdateData(TRUE);

	if (m_opcode == OpPlus)
	{
		m_result = m_num1 + m_num2;
	}
	else if (m_opcode == OpMinus)
	{
		m_result = m_num1 - m_num2;
	}
	else if (m_opcode == OpMultiply)
	{
		m_result = m_num1 * m_num2;
	}
	else if (m_opcode == OpDivide)
	{
		m_result = m_num1 / m_num2;
	}
	else if (m_opcode == OpPower) {
		m_result = pow(m_num1,m_num2);
	}
	else if (m_opcode == OpMod) {
		m_result = fmod(m_num1,m_num2);
	}

	m_num1 = m_result;
	m_num2 = 0;
	m_opcount = 1;

	char buf[128];
	sprintf_s(buf, "%lf", m_result);
	m_expr = buf;
	m_flush = true;

	if (m_fullflush == true)
	{
		m_fullexpr += "=";
		m_fullexpr += m_expr;
		m_num1 = m_num2 = m_result = 0;
		m_opcode = m_opcount = 0;
	}
	UpdateData(FALSE);
	return 0;
}

void CSimpleCalcDlg::AddString(char str)
{
	UpdateData(TRUE);

	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		m_fullflush = false;
		m_flush = false;
	}
	else if (m_flush == true)
	{
		m_expr = "";
		m_flush = false;
	}

	m_expr += str;
	UpdateData(FALSE);
}

void CSimpleCalcDlg::OnBnClickedZero()
{
	AddString('0');
}


void CSimpleCalcDlg::OnBnClickedOne()
{
	AddString('1');
}


void CSimpleCalcDlg::OnBnClickedTwo()
{
	AddString('2');
}


void CSimpleCalcDlg::OnBnClickedThree()
{
	AddString('3'); 
}


void CSimpleCalcDlg::OnBnClickedFour()
{
	AddString('4');
}


void CSimpleCalcDlg::OnBnClickedFive()
{
	AddString('5');
}


void CSimpleCalcDlg::OnBnClickedSix()
{
	AddString('6');
}


void CSimpleCalcDlg::OnBnClickedSeven()
{
	AddString('7');
}


void CSimpleCalcDlg::OnBnClickedEight()
{
	AddString('8');
}


void CSimpleCalcDlg::OnBnClickedNine()
{
	AddString('9');
}


void CSimpleCalcDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSimpleCalcDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSimpleCalcDlg::OnBnClickedPlus()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}

	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpPlus; // plus
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "+";
		m_expr = "";
		m_opcode = OpPlus; // plus
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "+";
		m_opcode = OpPlus; // plus
	}

	UpdateData(FALSE);
}


void CSimpleCalcDlg::OnBnClickedMinus()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}
	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpMinus; // minus
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "-";
		m_expr = "";
		m_opcode = OpMinus; // minus
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "-";
		m_opcode = OpMinus; // minus

	}

	UpdateData(FALSE);
}


void CSimpleCalcDlg::OnBnClickedMul()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}
	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpMultiply; // MUL
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "*";
		m_expr = "";
		m_opcode = OpMultiply; // MUL
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "*";
		m_opcode = OpMultiply; // MUL
	}

	UpdateData(FALSE);
}


void CSimpleCalcDlg::OnBnClickedDiv()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}
	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpDivide; // DIV
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "/";
		m_expr = "";
		m_opcode = OpDivide; // DIV
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "/";
		m_opcode = OpDivide; // DIV
	}

	UpdateData(FALSE);
}


void CSimpleCalcDlg::OnBnClickedC()
{
	m_num1 = m_num2 = m_result = 0;
	m_expr = "";
	m_opcode = m_opcount = 0;
	UpdateData(FALSE);
}


void CSimpleCalcDlg::OnBnClickedOk()
{
	if (m_opcount == 0)
		return;
	m_fullflush = true;
	Compute(1);
	//CDialogEx::OnOK();
}


void CSimpleCalcDlg::OnBnClickedDot()
{
	UpdateData(TRUE);
	if (m_expr.Find('.') == TRUE)
		return;
	AddString('.');
}


void CSimpleCalcDlg::OnBnClickedPow()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}
	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpPower; // pow
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "^";
		m_expr = "";
		m_opcode = OpPower; // pow
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "^";
		m_opcode = OpPower; // pow
	}

	UpdateData(FALSE);
}




void CSimpleCalcDlg::OnBnClickedMod()
{
	UpdateData(TRUE);
	if (m_fullflush == true)
	{
		m_expr = "";
		m_fullexpr = "";
		UpdateData(FALSE);
		return;
	}
	if (m_flush == true)
	{
		m_flush = false;
		m_opcount = 1;
		m_expr = "";
		m_opcode = OpMod; // pow
	}
	else if (m_opcount == 0)
	{
		m_num1 = _ttof(m_expr);
		m_opcount = 1;
		m_fullexpr += m_expr;
		m_fullexpr += "%";
		m_expr = "";
		m_opcode = OpMod; // pow
	}
	else
	{
		if (Compute() < 0)
			m_fullexpr = m_fullexpr.Left(m_fullexpr.GetLength() - 1);
		m_fullexpr += "%";
		m_opcode = OpMod; // pow
	}

	UpdateData(FALSE);
}
