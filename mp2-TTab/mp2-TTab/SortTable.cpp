#include "SortTable.h"

template <class T>
void Swap(T& a, T& b)
{
	T c;
	a = c;
	a = b;
	b = c;
}

void TSortTable::SortData()
{
	//SelectSort();
	QuickSort();
}

void TSortTable::SelectSort()
{
	int index = 0;
	for (int i = 0; i < DataCount; i++)
	{
		index = i;
		for (int j = i + 1; j < DataCount; j++)
		{
			Efficiency++;
			if (pRecs[j] < pRecs[index])
			{
				index = j;
			}
		}
		if (i != index)
		{
			Efficiency++;
			Swap(pRecs[i], pRecs[index]);
		}
	}
}

void TSortTable::QuickSort()
{
	QuickSorter(0, DataCount - 1);
}

void TSortTable::QuickSorter(int first, int last)
{
	TKey x = pRecs[first].GetKey();
	int i = first, j = last;
	while (i <= j)
	{
		while (pRecs[i].GetKey() < x)
		{
			Efficiency++;
			i++;
		}
		while (pRecs[j].GetKey() > x)
		{
			Efficiency++;
			j--;
		}
		if (i <= j)
		{
			Swap(pRecs[i], pRecs[j]);
			Efficiency++;
			i++;
			j--;
		}
	}
	if (j > first)
	{
		QuickSorter(first, j);
	}
	if (i < last)
	{
		QuickSorter(i, last);
	}
}

TSortTable::TSortTable(const TScanTable& tab)
{
	*this = tab;
}

TSortTable& TSortTable::operator=(const TScanTable& tab)
{
	if (pRecs != NULL)
	{
		delete[] pRecs;
		pRecs = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new TRecord[TabSize];
	for (int i = 0; i < DataCount; i++)
	{
		pRecs[i] = tab.pRecs[i];
	}
	SortData();
	CurrPos = 0;
	return *this;
}

bool TSortTable::FindRecord(TKey _key)
{
	int i, i1 = 0, i2 = DataCount - 1;
	while (i1 <= i2)
	{
		i = (i1 + i2) / 2;
		Efficiency++;
		if (pRecs[i].GetKey() == _key)
		{
			i1 = i + 1;
			i2 = i;
			break;
		}
		Efficiency++;
		if (pRecs[i].GetKey() > _key)
		{
			i2 = i - 1;
		}
		else
		{
			i1 = i + 1;
		}
	}
	Efficiency++;
	if ((i2 < 0) || (pRecs[i2].GetKey() < _key))
	{
		i2++;
		CurrPos = i2;
	}
	if ((i2 < DataCount) && (pRecs[i].GetKey() == _key))
	{
		Efficiency++;
		return true;
	}
	return false;
}

int TSortTable::InsRecord(TKey _key, TValue _val)
{
	if (IsFull())
	{
		return TabFull;
	}
	if (!FindRecord(_key))
	{
		for (int i = DataCount - 1; i >= CurrPos; i--)
		{
			Efficiency++;
			pRecs[i + 1] = pRecs[i];
		}
		pRecs[CurrPos].SetKey(_key);
		pRecs[CurrPos].SetValue(_val);
		DataCount++;
		return TabOK;
	}
	else
	{
		return TabRecDbl;
	}
}

int TSortTable::DelRecord(TKey _key)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	if (FindRecord(_key))
	{
		for (int i = CurrPos; i < DataCount; i++)
		{
			Efficiency++;
			pRecs[i] = pRecs[i + 1];
		}
		DataCount--;
		return TabOK;
	}
	else
	{
		return TabNoRec;
	}
}