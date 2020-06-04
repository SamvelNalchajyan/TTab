#pragma once
#include "ArrayTable.h"

class TScanTable : public TArrayTable
{
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {}
	virtual bool FindRecord(TKey _key);
	virtual int InsRecord(TKey _key, TValue _val);
	virtual int DelRecord(TKey _key);
};