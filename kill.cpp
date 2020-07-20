// kill.cpp : implementation file
//

#include "pch.h"
#include "travelagency.h"
#include "kill.h"
#include "afxdialogex.h"
#include "Header.h"
#include<string>


// kill dialog

IMPLEMENT_DYNAMIC(kill, CDialogEx)

kill::kill(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE, pParent)
	, deleteid(_T(""))
	, deletename(_T(""))
{

}

kill::~kill()
{
}

void kill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, deleteid);
	DDX_Text(pDX, IDC_EDIT2, deletename);
}


BEGIN_MESSAGE_MAP(kill, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &kill::OnBnClickedButton1)
END_MESSAGE_MAP()


// kill message handlers


void kill::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString c;
	std::string s1, s2;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(c);
	s1 = (CW2A)c.GetString();
	CString d;
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(d);
	s2 = (CW2A)d.GetString();
	int res = del(s1, s2);
	if (res) {
		MessageBox(L"Found!!!");
		// TODO: Add your control notification handler code here
	}
	else
		MessageBox(L"Not found!");
	// TODO: Add your control notification handler code here
}
