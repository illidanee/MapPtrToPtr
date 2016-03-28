#ifndef __CMAPPTRTOPTR_H__
#define __CMAPPTRTOPTR_H__

#include <memory.h>
#include "CMem.h"

#define HASH_ADDRESS(p) ((unsigned int)(p) >> 4)
#define HASH_OTHER(o) ((unsigned int)(&o) >> 4)

class CMapPtrToPtr
{
/************************************************************************	
	Note:	¹¹ÔìÎö¹¹
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

	CMem* m_pMem;
	unsigned int m_uiMax;
	CElem* pFreeList;
	unsigned int m_uiCount;

public:
	CMapPtrToPtr(unsigned int memMax = 10);
	virtual ~CMapPtrToPtr();

	void*& operator[](void* key);
	
/************************************************************************	
	Note:	Âß¼­
*************************************************************************/
private:
	void InitHash();
	void DestroyHash();

	CElem* NewElem();
	CElem* GetElem(void* key);
	void FreeElem(CElem* pElem);

public:
	void* GetValue(void* key);
	void SetValue(void* key, void* value);
};

#endif