#pragma once
#include "ScanTable.h"

class TSortTable : public TScanTable
{
protected:
	void SortData();
	void SelectSort();
	void QuickSort();
	void QuickSorter(int first, int last);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {}
	~TSortTable() {}
	TSortTable(const TScanTable& tab);

	TSortTable& operator=(const TScanTable& tab);

	virtual bool FindRecord(TKey _key);
	virtual int InsRecord(TKey _key, TValue _val);
	virtual int DelRecord(TKey _key);
};