#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef int TKey;
typedef string TValue;

class TRecord
{
protected:
	TKey key;
	TValue val;
public:
	TRecord() {}
	TRecord(TKey _key)
	{
		key = _key;
	}
	TRecord(TKey _key, TValue _val)
	{
		key = _key;
		val = _val;
	}

	void SetKey(TKey _key)
	{
		key = _key;
	}
	TKey GetKey()
	{
		return key;
	}
	void SetValue(TValue _val)
	{
		val = _val;
	}
	TValue GetValue()
	{
		return val;
	}
	virtual bool operator==(const TRecord& rec)
	{
		return key == rec.key;
	}
	virtual bool operator!=(const TRecord& rec)
	{
		return key != rec.key;
	}
	virtual bool operator<(const TRecord& rec)
	{
		return key < rec.key;
	}
	virtual bool operator>(const TRecord& rec)
	{
		return key > rec.key;
	}

	friend ostream& operator<<(ostream& os, const TRecord& rec)
	{
		return os << rec.key << " - " << rec.val;
	}

	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class THashTable;
	friend class TArrayHashTable;
	friend class TTreeNode;
	friend class TTreeTable;
};