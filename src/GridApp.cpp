///////////////////////////////////////
// GridApp.cpp

#include "stdafx.h"
#include "GridApp.h"
#include "resource.h"


// Definitions for the CGridApp class
CGridApp::CGridApp() : m_MyGrid(IDD_DIALOG1)
{
}

BOOL CGridApp::InitInstance()
{
	//Display the Modal Grid
	m_MyGrid.DoModal();

	//End the program
	::PostQuitMessage(0);

	return TRUE;
}

CGridApp::~CGridApp()
{
}

