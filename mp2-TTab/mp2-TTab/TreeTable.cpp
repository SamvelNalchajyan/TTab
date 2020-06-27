#include "TreeTable.h"
static int Level;

void TTreeTable::PrintTreeTab(TTreeNode* pNode)
{
	if (pNode)
	{
		for (int i = 0; i < Level; i++)
		{
			std::cout << " ";
		}
		std::cout << pNode->key << std::endl;
		Level++;
		PrintTreeTab(pNode->pRight);
		PrintTreeTab(pNode->pLeft);
		Level--;
	}
}

void TTreeTable::PrintTab()
{
	std::cout << "Table:" << std::endl;
	Level = 0;
	PrintTreeTab(pRoot);
}

void TTreeTable::DrawTreeTab(TTreeNode* pNode, int Level)
{
	if (pNode)
	{
		DrawTreeTab(pNode->pRight, Level + 1);
		for (int i = 0; i < 2 * Level; i++)
		{
			std::cout << "  ";
		}
		//std::cout << *pNode;
		std::cout << "Key:" << pNode->GetKey() << "  Value: " << pNode->GetValue();
		std::cout << std::endl;
		DrawTreeTab(pNode->pLeft, Level + 1);
	}
}

void TTreeTable::DrawTab()
{
	std::cout << "Table:" << std::endl;
	DrawTreeTab(pRoot, 0);
}

void TTreeTable::DelTreeTab(TTreeNode* pNode)
{
	if (pNode)
	{
		DelTreeTab(pNode->pLeft);
		DelTreeTab(pNode->pRight);
		delete pNode;
	}
}

bool TTreeTable::IsFull() const
{
	TTreeNode* pNode = new TTreeNode();
	if (pNode)
	{
		delete pNode;
		return false;
	}
	return true;
}

bool TTreeTable::FindRecord(TKey _key)
{
	pPrev = NULL;
	pCurr = pRoot;
	while (pCurr)
	{
		Efficiency++;
		if (pCurr->GetKey() == _key)
		{
			break;
		}
		pPrev = pCurr;
		if (pCurr->GetKey() < _key)
		{
			pCurr = pCurr->GetRight();
		}
		else
		{
			pCurr = pCurr->GetLeft();
		}
	}
	if (pCurr)
	{
		return true;
	}
	else
	{
		pCurr = pPrev;
		return false;
	}
}

int TTreeTable::InsRecord(TKey _key, TValue _val)
{
	if (IsFull())
	{
		return TabFull;
	}
	else
	{
		if (FindRecord(_key))
		{
			return TabRecDbl;
		}
		else
		{
			TTreeNode* tmp = new TTreeNode(_key, _val);
			if (!pRoot)
			{
				pRoot = tmp;
			}
			else
			{
				if (_key < pCurr->GetKey())
				{
					pCurr->pLeft = tmp;
				}
				else
				{
					pCurr->pRight = tmp;
				}
			}
			Efficiency++;
			DataCount++;
			return TabOK;
		}
	}
}

int TTreeTable::DelRecord(TKey _key)
{
	if (!FindRecord(_key))
	{
		return TabNoRec;
	}
	else
	{
		TTreeNode* pNode = pCurr;
		if (!pNode->GetRight())
		{
			if (!pPrev)
			{
				pRoot = pNode->GetLeft();
			}
			else
			{
				if (pPrev->GetRight() == pNode)
				{
					pPrev->pRight = pNode->pLeft;
				}
				else
				{
					pPrev->pLeft = pNode->pLeft;
				}
			}
			Efficiency++;
		}
		else
		{
			if (!pNode->GetLeft())
			{
				if (!pPrev)
				{
					pRoot = pNode->GetRight();
				}
				else
				{
					if (pPrev->GetRight() == pNode)
					{
						pPrev->pRight = pNode->pRight;
					}
					else
					{
						pPrev->pLeft = pNode->pRight;
					}
				}
				Efficiency++;
			}
			else
			{
				TTreeNode* pN = pNode->GetLeft();
				pPrev = pNode;
				while (pN->GetRight())
				{
					pPrev = pN;
					pN = pN->pRight;
					Efficiency++;
				}
				pNode->val = pN->val;
				pNode->key = pN->key;
				if (pPrev->GetRight() == pN)
				{
					pPrev->pRight = pN->pLeft;
				}
				else
				{
					pPrev->pLeft = pN->pLeft;
				}
				pNode = pN;
				Efficiency++;
			}
		}
		delete pNode;
		DataCount--;
		return TabOK;
	}
}

TKey TTreeTable::GetKey() const
{
	if (!pCurr)
	{
		throw NULL;
	}
	return pCurr->GetKey();
}

TValue TTreeTable::GetValue() const
{
	if (!pCurr)
	{
		throw NULL;
	}
	return pCurr->GetValue();
}

int TTreeTable::Reset()
{
	TTreeNode* pNode = pCurr = pRoot;
	while (!St.empty())
	{
		St.pop();
	}
	CurrPos = 0;
	while (pNode)
	{
		St.push(pNode);
		pCurr = pNode;
		pNode = pNode->pLeft;
	}
	return IsEnd();
}

int TTreeTable::IsEnd() const
{
	return CurrPos >= DataCount;
}

int TTreeTable::GoNext()
{
	if (!IsEnd() && (pCurr != NULL))
	{
		TTreeNode* pNode = pCurr = pCurr->pRight;
		St.pop();
		while (pNode)
		{
			St.push(pNode);
			pCurr = pNode;
			pNode = pNode->pLeft;
		}
		if ((pCurr == NULL) && !St.empty())
		{
			pCurr = St.top();
		}
		CurrPos++;
	}
	return IsEnd();
}