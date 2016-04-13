#include "CMem.h"



/************************************************************************
	Date:		2016/4/13  
	Time:		13:55
	Author:		Mr.Z
	
	Purpose:	CMem
*************************************************************************/
CMem* CMem::Create(CMem** pHead, unsigned int nMax, unsigned int uSize)
{
	CMem* pBuff = (CMem*)new char[sizeof(CMem) + nMax * uSize];
	pBuff->pNext = *pHead;
	*pHead = pBuff;
	return pBuff;
}

void* CMem::Data()
{
	return this + 1;
}

void CMem::FreeDataChain()
{
	CMem* pThis = this;
	while (pThis)
	{
		CMem* pNext = pThis->pNext;
		char* pTemp = (char*)pThis;
		delete[] pTemp;
		pThis = pNext;
	}
}