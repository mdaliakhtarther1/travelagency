// optionsclass.cpp : implementation file
//

#include "pch.h"
#include "travelagency.h"
#include "optionsclass.h"
#include "afxdialogex.h"
#include "insert.h"
#include "search.h"
#include "kill.h"


// optionsclass dialog

IMPLEMENT_DYNAMIC(optionsclass, CDialogEx)

optionsclass::optionsclass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPTIONS, pParent)
{

}

optionsclass::~optionsclass()
{
}

void optionsclass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(optionsclass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &optionsclass::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &optionsclass::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &optionsclass::OnBnClickedButton3)
END_MESSAGE_MAP()


// optionsclass message handlers


void optionsclass::OnBnClickedButton1()
{
	insert in;
	in.DoModal();
	// TODO: Add your control notification handler code here
}


void optionsclass::OnBnClickedButton2()
{
	search se;
	se.DoModal();
	// TODO: Add your control notification handler code here
}


void optionsclass::OnBnClickedButton3()
{
	kill ki;
	ki.DoModal();
	// TODO: Add your control notification handler code here
}
