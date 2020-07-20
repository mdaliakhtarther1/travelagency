#pragma once


// kill dialog

class kill : public CDialogEx
{
	DECLARE_DYNAMIC(kill)

public:
	kill(CWnd* pParent = nullptr);   // standard constructor
	virtual ~kill();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString deleteid;
	CString deletename;
	afx_msg void OnBnClickedButton1();
};
