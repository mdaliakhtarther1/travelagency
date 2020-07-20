#pragma once


// insert dialog

class insert : public CDialogEx
{
	DECLARE_DYNAMIC(insert)

public:
	insert(CWnd* pParent = nullptr);   // standard constructor
	virtual ~insert();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString pass_id;
	CString name;
	CString source;
	CString dest;
	CString d_o_t;
};
