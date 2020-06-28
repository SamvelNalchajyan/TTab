#include <iostream>
#include <clocale>
#include <cstdlib>
#include "ScanTable.h"
#include "SortTable.h"
#include "ArrayHash.h"
#include "TreeTable.h"

using namespace std;

void TabMenu(TTable* table, int mode, int Count, int keys, int MemSize = TabMaxSize)
{
	TKey _key;
	TValue _val;
	switch (mode)
	{
	case 1:
	{
		table = new TScanTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			table->InsRecord(_key, _val);
		}
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}
	case 2:
	{
		table = new TSortTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			table->InsRecord(_key, _val);
		}
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}
	case 3:
	{
		table = new TArrayHashTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			table->InsRecord(_key, _val);
		}
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}
	}
	int op = 10;
	cout << "Введите опреацию:" << endl;
	while (op)
	{
		cout << "1 - поиск записи, 2 - вставка записи, 3 - удаление записи, 4 - печать таблицы, 0 - выход" << endl;
		cin >> op;
		if (op == 1)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			if (table->FindRecord(_Key))
			{
				cout << "Запись найдена" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			else
			{
				cout << "Запись отсутствует" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			table->ClearEfficiency();
		}
		if (op == 2)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			TValue _Val = "*";
			_Val += to_string(_Key);
			_Val += "*";
			table->ClearEfficiency();
			table->InsRecord(_Key, _Val);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 3)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			table->DelRecord(_Key);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 4)
		{
			cout << *table << endl;
		}
	}
}

void TreeTabMenu(TTreeTable* table, int Count, int keys)
{
	TKey _key;
	TValue _val;
	table = new TTreeTable();
	for (int i = 0; i < Count; i++)
	{
		_key = rand() % keys;
		_val = "*";
		_val += to_string(_key);
		_val += "*";
		table->InsRecord(_key, _val);
	}
	cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
	table->ClearEfficiency();
	int op = 10;
	cout << "Введите опреацию:" << endl;
	while (op)
	{
		cout << "1 - поиск записи, 2 - вставка записи, 3 - удаление записи, 4 - печать таблицы, 5 - печать таблицы ярусами, 0 - выход" << endl;
		cin >> op;
		if (op == 1)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			if (table->FindRecord(_Key))
			{
				cout << "Запись найдена" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			else
			{
				cout << "Запись отсутствует" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			table->ClearEfficiency();
		}
		if (op == 2)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			TValue _Val = "*";
			_Val += to_string(_Key);
			_Val += "*";
			table->ClearEfficiency();
			table->InsRecord(_Key, _Val);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 3)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			table->DelRecord(_Key);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 4)
		{
			cout << *table << endl;
		}
		if (op == 5)
		{
			table->PrintTab();
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*--------------------------------------------------*/
	TTable* table = NULL;
	TTreeTable* TreeTab = NULL;
	int mode;
	int Count;
	int keys;
	int MemSize = 0;
	cout << "Введите тип таблицы:" << endl;
	cout << "ScanTable - 1, SortTable - 2, ArrayHash - 3, TreeTable - 4" << endl;
	cin >> mode;
	if (mode != 4)
	{
		cout << "Введите:" << endl << "Количество записей, диапазон ключей, размер памяти" << endl;
		cin >> Count >> keys >> MemSize;
		TabMenu(table, mode, Count, keys, MemSize);
	}
	else
	{
		cout << "Введите:" << endl << "Количество записей, диапазон ключей" << endl;
		cin >> Count >> keys;
		TreeTabMenu(TreeTab, Count, keys);
	}
	/*--------------------------------------------------*/
	system("pause");
	return 0;
}