
// travelagencyDlg.h : header file
//

#pragma once


// CtravelagencyDlg dialog
class CtravelagencyDlg : public CDialogEx
{
// Construction
public:
	CtravelagencyDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAVELAGENCY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CString uname = CString(_T("ali"));
	CString upass = CString(_T("123"));

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	CString user;
	CString pass;
	afx_msg void OnEnChangeEdit1();
};
