///////////////////////////////////////
// GridApp.h 

#ifndef GridAPP_H
#define GridAPP_H

#include "MyGrid.h"


// Declaration of the CGridApp class
class CGridApp : public CWinApp
{
public:
	CGridApp(); 
	virtual ~CGridApp();
	virtual BOOL InitInstance();
	CMyGrid& GetGrid() {return m_MyGrid;}

private:
	CMyGrid m_MyGrid;
};

// returns a reference to the CGridApp object
inline CGridApp& GetGridApp() { return *((CGridApp*)GetApp()); }


#endif // define GridAPP_H

