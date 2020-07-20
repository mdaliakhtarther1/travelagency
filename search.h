#pragma once


// search dialog

class search : public CDialogEx
{
	DECLARE_DYNAMIC(search)

public:
	search(CWnd* pParent = nullptr);   // standard constructor
	virtual ~search();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeDisplay();
	afx_msg void OnBnClickedButton1();
	CString searchid;
};
