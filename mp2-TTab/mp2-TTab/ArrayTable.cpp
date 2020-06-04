#include "ArrayTable.h"

TArrayTable::TArrayTable(int Size)
{
	pRecs = new TRecord[Size];
	TabSize = Size;
	DataCount = 0;
	CurrPos = 0;
}

TArrayTable::~TArrayTable()
{
	delete[] pRecs;
}

bool TArrayTable::IsFull() const
{
	return DataCount >= TabSize;
}

int TArrayTable::GetTabSize() const
{
	return TabSize;
}

int TArrayTable::Reset()
{
	CurrPos = 0;
	return IsEnd();
}

int TArrayTable::IsEnd() const
{
	return CurrPos >= DataCount;
}

int TArrayTable::GoNext()
{
	if (!IsEnd())
	{
		CurrPos++;
	}
	return IsEnd();
}

int TArrayTable::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsEnd();
}