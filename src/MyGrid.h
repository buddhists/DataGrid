///////////////////////////////////////
// MyGrid.h

#ifndef MYGrid_H
#define MYGrid_H

#include "DataGrid/DataGrid.h"


// Declaration of the CMyGrid class
class CMyGrid : public CDialog
{
public:
	CMyGrid(UINT nResID, CWnd* pParent = NULL);
	virtual ~CMyGrid();

protected:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual INT_PTR DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnOK();

private:
	//void OnButton();
	//void OnRadio1();
	//void OnRadio2();
	//void OnRadio3();
	//void OnCheck1();
	//void OnCheck2();
	//void OnCheck3();

	//HMODULE m_hInstRichEdit;
	CDataGrid m_hdataGrid;
};

#endif //MYGrid_H
