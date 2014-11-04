///////////////////////////////////////
// main.cpp

#include "stdafx.h"
#include "GridApp.h"
#include <vld.h>

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// Start Win32++
	CGridApp theApp;

	// Run the application
	return theApp.Run();
}

