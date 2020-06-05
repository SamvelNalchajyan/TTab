#pragma once
#include "HashTable.h"

#define TabHashStep 7

class TArrayHashTable : public THashTable
{
protected:
	TRecord* pRecs;
	int TabSize;
	int HashStep;
	int FreePos;
	int CurrPos;
	TRecord Mark;
	TRecord Empty;

	int GetNextPos(int pos)
	{
		return (pos + HashStep) % TabSize;
	}
public:
	TArrayHashTable(int Size = TabMaxSize, int Step = TabHashStep);
	~TArrayHashTable();

	virtual bool IsFull() const
	{
		return DataCount >= TabSize;
	}

	virtual bool FindRecord(TKey _key);
	virtual int InsRecord(TKey _key, TValue _val);
	virtual int DelRecord(TKey _key);

	virtual int Reset();
	virtual int IsEnd() const;
	virtual int GoNext();

	virtual TKey GetKey() const;
	virtual TValue GetValue() const;
};