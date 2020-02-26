//#include "stdafx.h"
#include <iostream>
#include <objbase.h>
#include "../interface/interface.cpp"
#include <tchar.h>

//Клиент
int main()
{
	HRESULT hr;
	trace("Get a pointer to Iunknown");
	IUnknown* pIUnknown = CreateInstance();
	trace("Get a pointer to IY");	
	IY* pIY = NULL;
	hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
	if (SUCCEEDED(hr))
	{
		trace("IX gotcha successfully!");
		pIY->Fy();
	}

	IX* pIX = NULL;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if (SUCCEEDED(hr))
	{
		trace("IX gotcha successfully!");
		pIX->Fx(9);
	}
	//delete pIUnknown;
	return 0;
}
