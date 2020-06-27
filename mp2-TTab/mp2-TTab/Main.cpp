#include <iostream>
#include <clocale>
#include <cstdlib>
#include "ScanTable.h"
#include "SortTable.h"
#include "ArrayHash.h"
#include "TreeTable.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*--------------------------------------------------*/
	TScanTable table1;
	TSortTable table2;
	TArrayHashTable table3;
	TTreeTable table4;
	TKey k1 = 1, k2 = 2, k3 = 3, k4 = 4;
	TValue v1 = "aaa", v2 = "bbb", v3 = "ccc", v4 = "ddd";
	table1.InsRecord(k4, v4);
	table2.InsRecord(k4, v4);
	table3.InsRecord(k4, v4);
	table4.InsRecord(k4, v4);
	table1.InsRecord(k2, v2);
	table2.InsRecord(k2, v2);
	table3.InsRecord(k2, v2);
	table4.InsRecord(k2, v2);
	table1.InsRecord(k3, v3);
	table2.InsRecord(k3, v3);
	table3.InsRecord(k3, v3);
	table4.InsRecord(k3, v3);
	table1.InsRecord(k1, v1);
	table2.InsRecord(k1, v1);
	table3.InsRecord(k1, v1);
	table4.InsRecord(k1, v1);
	if (table1.FindRecord(k1) && table2.FindRecord(k1) && table3.FindRecord(k1) && table4.FindRecord(k1))
	{
		cout << "EZ!" << endl;
	}
	table1.DelRecord(k1);
	table2.DelRecord(k1);
	table3.DelRecord(k1);
	table4.DelRecord(k1);
	if (!table1.FindRecord(k1) && !table2.FindRecord(k1) && !table3.FindRecord(k1) && !table4.FindRecord(k1))
	{
		cout << "EEE" << endl;
	}
	//cout << table1 << endl;
	//cout << table2 << endl;
	cout << table4 << endl;
	table4.PrintTab();
	table4.DrawTab();
	/*--------------------------------------------------*/
	system("pause");
	return 0;
}