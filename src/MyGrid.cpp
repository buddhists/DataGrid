///////////////////////////////////////
// MyGrid.cpp

#include "stdafx.h"
#include "MyGrid.h"
#include "resource.h"

const int ciINITMAXROWS=11;
// Definitions for the CMyGrid class
CMyGrid::CMyGrid(UINT nResID, CWnd* pParent)
	: CDialog(nResID, pParent)
{
 
}

CMyGrid::~CMyGrid()
{
 
}

INT_PTR CMyGrid::DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	switch (uMsg)
//	{
		//Additional messages to be handled go here
//	}

	// Pass unhandled messages on to parent GridProc
	return DialogProcDefault(uMsg, wParam, lParam);
}


BOOL CMyGrid::PreTranslateMessage(MSG* pMsg) 
{ 
	// TODO: Add your specialized code here and/or call the base class 
	 if (pMsg->hwnd == m_hdataGrid.GetSafeHwnd()) 
	{
		if(pMsg->message == WM_KEYDOWN) 
		{ 
			//::GetDlgItem(m_hWnd,IDC_STATIC1)->SetFocus(); 
			switch(pMsg->wParam) 
			{ 
				case VK_UP: 
				case VK_DOWN: 
				case VK_LEFT: 
				case VK_RIGHT: 
				case VK_ESCAPE: 
				case VK_RETURN:
					//m_hdataGrid.moveNext();
					//m_hdataGrid.Update();
					// ::PostMessage(m_hdataGrid.GetWindowHandle(), WM_KEYDOWN, (WPARAM)VK_DOWN, pMsg->lParam);
					 ::SendMessage(m_hdataGrid.GetSafeHwnd(), WM_KEYDOWN, pMsg->wParam, pMsg->lParam );
					return TRUE; 
					//break; 
				//default: 
				//	return TRUE; 
			} 
			//m_opgl->DrawTerrain(); 
		} 
		else if(pMsg->message == WM_CHAR)
        {
			::SendMessage(m_hdataGrid.GetSafeHwnd(), WM_CHAR, pMsg->wParam, pMsg->lParam );
		}
	}
	 if (pMsg->hwnd == m_hdataGrid.GetEditSafeHwnd()) 
	{
		if(pMsg->message == WM_KEYDOWN) 
		{ 
			//::GetDlgItem(m_hWnd,IDC_STATIC1)->SetFocus(); 
			switch(pMsg->wParam) 
			{ 
				case VK_UP: 
				case VK_DOWN: 
				case VK_LEFT: 
				case VK_RIGHT: 
				case VK_ESCAPE: 
				case VK_RETURN:
					//m_hdataGrid.moveNext();
					//m_hdataGrid.Update();
					// ::PostMessage(m_hdataGrid.GetWindowHandle(), WM_KEYDOWN, (WPARAM)VK_DOWN, pMsg->lParam);
					 ::SendMessage(m_hdataGrid.GetEditSafeHwnd(), WM_KEYDOWN, pMsg->wParam, pMsg->lParam );
					return TRUE; 
					//break; 
				//default: 
				//	return TRUE; 
			} 
			//m_opgl->DrawTerrain(); 
		} 
		//else if(pMsg->message == WM_CHAR)
  //      {
		//	::SendMessage(m_hdataGrid.GetEditSafeHwnd(), WM_CHAR, pMsg->wParam, pMsg->lParam );
		//}
	}
	return CDialog::PreTranslateMessage(pMsg); 
} 


BOOL CMyGrid::OnCommand(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	//switch (LOWORD(wParam))
 //   {
	//case IDC_BUTTON1:
	//	OnButton();
	//	return TRUE;
	//case IDC_RADIO1:
	//	OnRadio1();
	//	return TRUE;
	//case IDC_RADIO2:
	//	OnRadio2();
	//	return TRUE;
	//case IDC_RADIO3:
	//	OnRadio3();
	//	return TRUE;
	//case IDC_CHECK1:
	//	OnCheck1();
	//	return TRUE;
	//case IDC_CHECK2:
	//	OnCheck2();
	//	return TRUE;
	//case IDC_CHECK3:
	//	OnCheck3();
	//	return TRUE;
 //   } //switch (LOWORD(wParam))

	return FALSE;
}

BOOL CMyGrid::OnInitDialog()
{
	// Set the Icon
	SetIconLarge(IDW_MAIN);
	SetIconSmall(IDW_MAIN);

	HWND hWndStatic;
	RECT rect;
	// Create DataGrid child window

	hWndStatic= ::GetDlgItem(m_hWnd,IDC_STATICGRID1);
	::GetClientRect(hWndStatic,&rect);
	m_hdataGrid.Create( rect, hWndStatic, 3 );
	//::MapWindowPoints(hWndStatic, m_hWnd, (LPPOINT)&rect, 2);

	//m_hdataGrid.InitDataGrid( rect, m_hWnd, hWndStatic, 3 );

	//m_hdataGrid.SetReadOnlybgColor(true);
	// Set DataGrid column info
	m_hdataGrid.SetColumnInfo( 0, _T("ID"),60, DGTA_CENTER );
	m_hdataGrid.SetColumnInfo( 1, _T("country"), 120, DGTA_CENTER );
	m_hdataGrid.SetColumnInfo( 2, _T("capital"),120, DGTA_CENTER );

	TCHAR szItem[20];

	int row;
	int iLeft;
	for (  row=0; row<ciINITMAXROWS; row++ )
	{

		_stprintf( szItem, _T("%d"), row+1 );
		m_hdataGrid.InsertItem( szItem, DGTA_CENTER );
		m_hdataGrid.SetItemInfo( row, 0, szItem, DGTA_RIGHT, true ,row+1);//SetRow ItemData to -1, means no Product
		m_hdataGrid.SetItemInfo( row, 1, _T("2"), DGTA_RIGHT, false );
		m_hdataGrid.SetItemInfo( row, 2, _T("3"), DGTA_RIGHT, false );

	
		iLeft=row % 3;
		switch (iLeft)
		{
		case 0:
			m_hdataGrid.SetItemBgColor( row, RGB(250,220,220) );
			break;
		case 1:
			m_hdataGrid.SetItemBgColor( row, RGB(220,250,220) );
			break;
		case 2:
			m_hdataGrid.SetItemBgColor( row, RGB(250,250,220) );
			break;
		}
	}


	LOGFONT lf;
	m_hdataGrid.GetColumnFont(&lf);
	lf.lfWeight = FW_BOLD;
	m_hdataGrid.SetColumnFont(&lf);
	m_hdataGrid.Update();


	return true;
}

void CMyGrid::OnOK()
{
		
	int iSelectedRow=m_hdataGrid.GetSelectedRow();
	if (iSelectedRow==-1)//选中的是空行，直接退出
	{
		MessageBox(_T("You should select one line"),_T("Error"),MB_OK|MB_ICONINFORMATION);
		return;
	}
	int iData=m_hdataGrid.GetItemData(iSelectedRow);
	TCHAR szTemp[255];
	_stprintf(szTemp,_T("Current Line is %d ItemData is %d"),iSelectedRow,iData);
	MessageBox(szTemp,_T("Grid Sample"),MB_OK|MB_ICONINFORMATION);
	//::MessageBox(NULL, _T("OK Button Pressed.  Program will exit now."), _T("Button"), MB_OK);
	//CDialog::OnOK();
}
