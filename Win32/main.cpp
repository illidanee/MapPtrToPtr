#include <stdio.h>
#include <windows.h>

#include "CMem.h"
#include "CMapPtrToPtr.h"



int main(int argc, char** argv)
{

	/************************************************************************	
		Note:	�ڴ����
	*************************************************************************/
	CMem* pData = NULL;

	CMem* pData1 = CMem::Create(&pData, 10, 10);
	
	CMem* pData2 = CMem::Create(&pData, 20, 10);

	pData->FreeDataChain();


	/************************************************************************	
		Note:	ӳ��
	*************************************************************************/

	char cDay[7][16] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	CMapPtrToPtr pMap ;
	
	pMap[cDay[0]] = "������\n";
	pMap[cDay[1]] = "����һ\n";
	pMap[cDay[2]] = "���ڶ�\n";
	pMap[cDay[3]] = "������\n";
	pMap[cDay[4]] = "������\n";
	pMap[cDay[5]] = "������\n";
	pMap[cDay[6]] = "������\n";

	for (int i = 0; i < 7; ++i)
	{
		OutputDebugString((char*)pMap[cDay[i]]);
	}

	pMap.SetValue(cDay[1], "�����");

	OutputDebugString((char*)pMap.GetValue(cDay[1]));

	return 0;
}