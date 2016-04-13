#include <stdio.h>
#include <windows.h>

#include "CMem.h"
#include "CMapPtrToPtr.h"



int main(int argc, char** argv)
{

	/************************************************************************	
		Note:	内存管理
	*************************************************************************/
	CMem* pData = NULL;

	CMem* pData1 = CMem::Create(&pData, 10, 10);
	
	CMem* pData2 = CMem::Create(&pData, 20, 10);

	pData->FreeDataChain();


	/************************************************************************	
		Note:	映射
	*************************************************************************/

	char cDay[7][16] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	CMapPtrToPtr pMap ;
	
	pMap[cDay[0]] = "星期日\n";
	pMap[cDay[1]] = "星期一\n";
	pMap[cDay[2]] = "星期二\n";
	pMap[cDay[3]] = "星期三\n";
	pMap[cDay[4]] = "星期四\n";
	pMap[cDay[5]] = "星期五\n";
	pMap[cDay[6]] = "星期六\n";

	for (int i = 0; i < 7; ++i)
	{
		OutputDebugString((char*)pMap[cDay[i]]);
	}

	pMap.SetValue(cDay[1], "礼拜天");

	OutputDebugString((char*)pMap.GetValue(cDay[1]));

	return 0;
}