#include "CMapPtrToPtr.h"


CMapPtrToPtr::CMapPtrToPtr(unsigned int memMax)
{
	m_pHash = 0;
	m_uiHashMax = 17;

	m_pMem = 0;
	m_uiMax = memMax;
	pFreeList = 0;
	m_uiCount = 0;

	InitHash();
}

CMapPtrToPtr::~CMapPtrToPtr()
{
	DestroyHash();

	if (m_pMem)
		m_pMem->FreeDataChain();
}

void*& CMapPtrToPtr::operator[](void* key)
{
	CElem* pElem = GetElem(key);
	if (pElem == 0)
	{
		pElem = NewElem();
		pElem->key = key;

		unsigned int hash = HASH_ADDRESS(key) % m_uiHashMax;
		pElem->pNext = m_pHash[hash];
		m_pHash[hash] = pElem;
	}

	return pElem->value;
}

void CMapPtrToPtr::InitHash()
{
	m_pHash = new CElem*[m_uiHashMax];
	memset(m_pHash, 0, m_uiHashMax * sizeof(CElem*));
}

void CMapPtrToPtr::DestroyHash()
{
	delete[] m_pHash;
}

CMapPtrToPtr::CElem* CMapPtrToPtr::NewElem()
{
	if (pFreeList == 0)
	{
		CMem* pMem = CMem::Create(&m_pMem, m_uiMax, sizeof(CElem));
		CElem* pElem = (CElem*)pMem->Data();
		pElem += m_uiMax - 1;
		
		for (unsigned int i = 0; i < m_uiMax; ++i)
		{
			pElem->pNext = pFreeList;
			pFreeList = pElem;

			--pElem;
		}
	}

	CElem* pNew = pFreeList;
	pFreeList = pFreeList->pNext;
	++m_uiCount;

	pNew->pNext = 0;
	pNew->key = 0;
	pNew->value = 0;

	return pNew;
}

CMapPtrToPtr::CElem* CMapPtrToPtr::GetElem(void* key)
{
	if (m_pHash == 0)
		InitHash();

	unsigned int hash = HASH_ADDRESS(key) % m_uiHashMax;
	for (CElem* pElem = m_pHash[hash]; pElem != 0; pElem = pElem->pNext)
	{
		if (pElem->key == key)
			return pElem;
	}

	return 0;
}

void CMapPtrToPtr::FreeElem(CElem* pElem)
{
	pElem->pNext = pFreeList;
	pFreeList = pElem;
	--m_uiCount;
}

void* CMapPtrToPtr::GetValue(void* key)
{
	CElem* pElem = GetElem(key);
	if (pElem == 0)
		return 0;

	return pElem->value;
}

void CMapPtrToPtr::SetValue(void* key, void* value)
{
	CElem* pElem = GetElem(key);
	if (pElem == 0)
	{
		pElem = NewElem();
		pElem->key = key;
		pElem->value = value;

		unsigned int hash = HASH_ADDRESS(key) % m_uiHashMax;
		pElem->pNext = m_pHash[hash];
		m_pHash[hash] = pElem;
	}
	else
	{
		pElem->value = value;
	}
}



