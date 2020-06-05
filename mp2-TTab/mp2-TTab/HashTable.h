#pragma once
#include "Table.h"

class THashTable : public TTable
{
protected:
	virtual unsigned int HashFunc(const TKey _key);
public:
	THashTable() : TTable() {}
};