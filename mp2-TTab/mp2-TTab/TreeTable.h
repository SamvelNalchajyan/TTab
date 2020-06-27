#pragma once
#include <stack>
#include "Table.h"
#include "TreeNode.h"

class TTreeTable : public TTable
{
protected:
	TTreeNode* pRoot;
	TTreeNode* pCurr;
	TTreeNode* pPrev;
	int CurrPos;
	std::stack<TTreeNode*> St;
	void PrintTreeTab(TTreeNode* pNode);
	void DrawTreeTab(TTreeNode* pNode, int Level);
	void DelTreeTab(TTreeNode* pNode);
public:
	TTreeTable() : TTable()
	{
		CurrPos = 0;
		pRoot = NULL;
		pCurr = NULL;
	}
	~TTreeTable()
	{
		DelTreeTab(pRoot);
	}

	virtual bool IsFull() const;
	virtual bool FindRecord(TKey _key);
	virtual int InsRecord(TKey _key, TValue _val);
	virtual int DelRecord(TKey _key);

	virtual TKey GetKey() const;
	virtual TValue GetValue() const;

	virtual int Reset();
	virtual int IsEnd() const;
	virtual int GoNext();

	void PrintTab();
	void DrawTab();
};
