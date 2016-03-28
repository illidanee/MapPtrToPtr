#ifndef __CMEM_H__
#define __CMEM_H__

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