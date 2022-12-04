
// SimpleCalcDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CSimpleCalcDlg dialog
class CSimpleCalcDlg : public CDialogEx
{
// Construction
public:
	CSimpleCalcDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMPLECALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	double m_num1;
	double m_num2;
	double m_result;
	int m_opcount;
	int m_opcode;
	bool m_flush;
	bool m_fullflush;

	int Compute(int arg = 0);
	void AddString(char str);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_expr;
	CMenu menu;
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedNine();
	CString m_fullexpr;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPow();
	afx_msg void OnBnClickedMod();
};
