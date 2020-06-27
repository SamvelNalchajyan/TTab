#pragma once
#include "Record.h"
#define TabOK 0
#define TabEmpty -101
#define TabFull -102
#define TabNoRec -103
#define TabRecDbl -104
#define TabNoMem -105

#define TabMaxSize 50

class TTable
{
protected:
	int DataCount;
	int Efficiency;
public:
	TTable()
	{
		DataCount = 0;
		Efficiency = 0;
	}
	virtual ~TTable() {}

	int GetDataCount() const
	{
		return DataCount;
	}
	int GetEfficiency() const
	{
		return Efficiency;
	}
	void ClearEfficiency()
	{
		Efficiency = 0;
	}
	bool IsEmpty() const
	{
		return DataCount == 0;
	}
	virtual bool IsFull() const = 0;

	virtual bool FindRecord(TKey _key) = 0;
	virtual int InsRecord(TKey _key, TValue _val) = 0;
	virtual int DelRecord(TKey _key) = 0;

	virtual int Reset() = 0;
	virtual int IsEnd() const = 0;
	virtual int GoNext() = 0;

	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;

	friend ostream& operator<<(ostream& os, TTable& tab)
	{
		os << "Table:" << endl;
		for (tab.Reset(); !tab.IsEnd(); tab.GoNext())
		{
			os << "Key: " << tab.GetKey() << "   Value: " << tab.GetValue() << endl;
		}
		return os;
	}
};