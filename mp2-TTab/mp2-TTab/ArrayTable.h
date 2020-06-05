#pragma once
#include "Table.h"

//enum TDataPos {FIRST_POS, CURRENT_POS, LAST_POS};

class TArrayTable : public TTable
{
protected:
	TRecord* pRecs;
	int TabSize;
	int CurrPos;
public:
	TArrayTable(int Size = TabMaxSize);
	~TArrayTable();

	virtual bool IsFull() const;
	int GetTabSize() const;
	virtual TKey GetKey() const
	{
		//return GetKey(CURRENT_POS);
		return pRecs[CurrPos].GetKey();
	}
	virtual TValue GetValue() const
	{
		//return GetValue(CURRENT_POS);
		return pRecs[CurrPos].GetValue();
	}
	//virtual TKey GetKey(TDataPos mode) const;
	//virtual TValue GetValue(TDataPos mode) const;

	virtual int Reset();
	virtual int IsEnd() const;
	virtual int GoNext();
	virtual int SetCurrentPos(int pos);

	friend class TSortTable;
};