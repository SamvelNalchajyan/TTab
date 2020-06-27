#pragma once
#include "Record.h"

class TTreeNode : public TRecord
{
protected:
	TTreeNode* pLeft;
	TTreeNode* pRight;
public:
	TTreeNode()
	{
		pLeft = NULL;
		pRight = NULL;
	}
	TTreeNode(TKey _key, TValue _val, TTreeNode* _pLeft = NULL, TTreeNode* _pRight = NULL) : TRecord(_key, _val), pLeft(_pLeft), pRight(_pRight) {}
	
	TTreeNode* GetLeft() const
	{
		return pLeft;
	}
	TTreeNode* GetRight() const
	{
		return pRight;
	}

	friend class TTreeTable;
};