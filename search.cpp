// search.cpp : implementation file
//

#include "pch.h"
#include "travelagency.h"
#include "search.h"
#include "afxdialogex.h"
#include "Header.h"
#include<string>

// search dialog

IMPLEMENT_DYNAMIC(search, CDialogEx)

search::search(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH, pParent)
	, searchid(_T(""))
{

}

search::~search()
{
}

void search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, searchid);
}


BEGIN_MESSAGE_MAP(search, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &search::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_Display, &search::OnEnChangeDisplay)
	ON_BN_CLICKED(IDC_BUTTON1, &search::OnBnClickedButton1)
END_MESSAGE_MAP()


// search message handlers


void search::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void search::OnEnChangeDisplay()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void search::OnBnClickedButton1()
{
	UpdateData(TRUE);
	std::string key = CW2A(searchid.GetString());
	char* result = Search(key);
	if (result != NULL)
	{
		MessageBeep(1);
		CString c(result);
		GetDlgItem(IDC_Display)->SetWindowTextW(c);
	}
	else
		MessageBox(L"Search failed");
	// TODO: Add your control notification handler code here
}
