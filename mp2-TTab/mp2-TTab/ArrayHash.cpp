#include "ArrayHash.h"

TArrayHashTable::TArrayHashTable(int Size, int Step) : TabSize(Size), HashStep(Step)
{
	pRecs = new TRecord[TabSize];
	Empty = TRecord(-1);
	Mark = TRecord(-2);
	for (int i = 0; i < TabSize; i++)
	{
		pRecs[i] = Empty;
	}
}

TArrayHashTable::~TArrayHashTable()
{
	delete[] pRecs;
}

bool TArrayHashTable::FindRecord(TKey _key)
{
	bool result = false;
	FreePos = -1;
	CurrPos = HashFunc(_key) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		Efficiency++;
		if (pRecs[CurrPos] == Empty)
		{
			break;
		}
		else
		{
			if (pRecs[CurrPos] == Mark)
			{
				if (FreePos == -1)
				{
					FreePos = CurrPos;
				}
			}
			else
			{
				if (pRecs[CurrPos].GetKey() == _key)
				{
					result = true;
					break;
				}
			}
		}
		CurrPos = GetNextPos(CurrPos);
	}
	return result;
}

int TArrayHashTable::InsRecord(TKey _key, TValue _val)
{
	if (IsFull())
	{
		return TabFull;
	}
	if (!FindRecord(_key))
	{
		Efficiency++;
		if (FreePos != -1)
		{
			CurrPos = FreePos;
		}
		pRecs[CurrPos] = TRecord(_key, _val);
		DataCount++;
		return TabOK;
	}
	else
	{
		return TabRecDbl;
	}
}

int TArrayHashTable::DelRecord(TKey _key)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	if (FindRecord(_key))
	{
		pRecs[CurrPos] = Mark;
		DataCount--;
		return TabOK;
	}
	else
	{
		return TabNoRec;
	}
}

int TArrayHashTable::Reset()
{
	CurrPos = 0;
	while (CurrPos < TabSize)
	{
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
		{
			break;
		}
		else
		{
			CurrPos++;
		}
	}
	return IsEnd();
}

int TArrayHashTable::IsEnd() const
{
	return CurrPos >= TabSize;
}

int TArrayHashTable::GoNext()
{
	CurrPos++;
	while (CurrPos < TabSize)
	{
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
		{
			break;
		}
		else
		{
			CurrPos++;
		}
	}
	return IsEnd();
}

TKey TArrayHashTable::GetKey() const
{
	return pRecs[CurrPos].GetKey();
}

TValue TArrayHashTable::GetValue() const
{
	return pRecs[CurrPos].GetValue();
}