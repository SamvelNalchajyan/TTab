#include "ScanTable.h"

bool TScanTable::FindRecord(TKey _key)
{
	for (int i = 0; i < DataCount; i++)
	{
		Efficiency++;
		if (pRecs[i].GetKey() == _key)
		{
			CurrPos = i;
			return true;
		}
	}
	CurrPos = DataCount;
	return false;
}

int TScanTable::InsRecord(TKey _key, TValue _val)
{
	if (IsFull())
	{
		return TabFull;
	}
	if (!FindRecord(_key))
	{
		pRecs[CurrPos].SetKey(_key);
		pRecs[CurrPos].SetValue(_val);
		DataCount++;
		Efficiency++;
		return TabOK;
	}
	else
	{
		return TabRecDbl;
	}
}

int TScanTable::DelRecord(TKey _key)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	if (FindRecord(_key))
	{
		pRecs[CurrPos].SetKey(pRecs[DataCount].GetKey());
		pRecs[CurrPos].SetValue(pRecs[DataCount].GetValue());
		DataCount--;
		Efficiency++;
		return TabOK;
	}
	else
	{
		return TabNoRec;
	}
}