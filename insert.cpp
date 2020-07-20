// insert.cpp : implementation file
//

#include "pch.h"
#include "travelagency.h"
#include "insert.h"
#include "afxdialogex.h"
#include "Header.h"


// insert dialog

IMPLEMENT_DYNAMIC(insert, CDialogEx)

insert::insert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT, pParent)
	, pass_id(_T(""))
	, name(_T(""))
	, source(_T(""))
	, dest(_T(""))
	, d_o_t(_T(""))
{

}

insert::~insert()
{
}

void insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, pass_id);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, source);
	DDX_Text(pDX, IDC_EDIT5, dest);
	DDX_Text(pDX, IDC_EDIT6, d_o_t);
}


BEGIN_MESSAGE_MAP(insert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &insert::OnBnClickedButton1)
END_MESSAGE_MAP()


// insert message handlers


void insert::OnBnClickedButton1()
{
	UpdateData(1);
	std::string values[5];
	
	values[0] = (CT2CA)pass_id;
	values[1] = (CT2CA)name;
	values[2] = (CT2CA)source;
	values[3] = (CT2CA)dest;
	values[4] = (CT2CA)d_o_t;
	Insert(values);
	sort_records();
	create_file();
	MessageBox(L"Done!");
	// TODO: Add your control notification handler code here
}
