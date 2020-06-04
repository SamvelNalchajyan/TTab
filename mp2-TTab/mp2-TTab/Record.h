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
	TRecord(TKey _key);
	TRecord(TKey _key, TValue _val);

	void SetKey(TKey _key);
	TKey GetKey();
	void SetValue(TValue _val);
	TValue GetValue();
	virtual bool operator==(const TRecord& rec);
	virtual bool operator!=(const TRecord& rec);
	virtual bool operator<(const TRecord& rec);
	virtual bool operator>(const TRecord& rec);

	friend ostream& operator<<(ostream& os, const TRecord& rec)
	{
		return os << rec.key << " - " << rec.val;
	}

	friend class TArrayTable;
	friend class TScanTable;
};

TRecord::TRecord(TKey _key)
{
	key = _key;
}

TRecord::TRecord(TKey _key, TValue _val)
{
	key = _key;
	val = _val;
}

void TRecord::SetKey(TKey _key)
{
	key = _key;
}

TKey TRecord::GetKey()
{
	return key;
}

void TRecord::SetValue(TValue _val)
{
	val = _val;
}

TValue TRecord::GetValue()
{
	return val;
}

bool TRecord::operator==(const TRecord& rec)
{
	return key == rec.key;
}

bool TRecord::operator!=(const TRecord& rec)
{
	return key != rec.key;
}

bool TRecord::operator<(const TRecord& rec)
{
	return key < rec.key;
}

bool TRecord::operator>(const TRecord& rec)
{
	return key > rec.key;
}