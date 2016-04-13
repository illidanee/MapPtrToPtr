#ifndef __CMAPPTRTOPTR_H__
#define __CMAPPTRTOPTR_H__

#include <memory.h>
#include "CMem.h"

#define HASH_ADDRESS(p) ((unsigned int)(p) >> 4)
#define HASH_OTHER(o) ((unsigned int)(&o) >> 4)



/************************************************************************
	Date:		2016/4/13  
	Time:		14:30
	Author:		Mr.Z
	
	Purpose:	CMapPtrToPtr
*************************************************************************/
class CMapPtrToPtr
{
/************************************************************************	
	Note:	Base Structure
*************************************************************************/
private:
	struct CElem
	{
		CElem* pNext;
		void* key;
		void* value;
	};

	CElem** m_pHash;
	unsigned int m_uiHashMax;
	unsigned int m_uiCount;

	CMem* m_pMem;
	unsigned int m_uiMax;
	CElem* pFreeList;
	

public:
	CMapPtrToPtr(unsigned int max = 10);
	virtual ~CMapPtrToPtr();

	void*& operator[](void* key);
	
/************************************************************************	
	Note:	Inner Implement
*************************************************************************/
private:
	void InitHash();
	void DestroyHash();

	CElem* NewElem();
	CElem* GetElem(void* key);
	void FreeElem(CElem* pElem);

/************************************************************************	
	Note:	Public Interface
*************************************************************************/
public:
	void* GetValue(void* key);
	void SetValue(void* key, void* value);
};

#endif