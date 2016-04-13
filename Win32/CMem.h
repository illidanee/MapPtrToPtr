#ifndef __CMEM_H__
#define __CMEM_H__



/************************************************************************
	Date:		2016/4/13  
	Time:		13:55
	Author:		Mr.Z
	
	Purpose:	CMem
*************************************************************************/
class CMem
{
public:
	static CMem* Create(CMem** pHead, unsigned int nMax, unsigned int uSize);

private:
	CMem* pNext;

public:
	void* Data();
	void FreeDataChain();
};

#endif