#pragma once


// optionsclass dialog

class optionsclass : public CDialogEx
{
	DECLARE_DYNAMIC(optionsclass)

public:
	optionsclass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~optionsclass();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
