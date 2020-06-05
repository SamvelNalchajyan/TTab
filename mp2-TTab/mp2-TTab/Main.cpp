#include <iostream>
#include <clocale>
#include <cstdlib>
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*--------------------------------------------------*/
	TScanTable table1;
	TSortTable table2;
	TKey k1 = 1;
	TValue v1 = "aaa";
	table1.InsRecord(k1, v1);
	table2.InsRecord(k1, v1);
	if (table1.FindRecord(k1) && table2.FindRecord(k1))
	{
		cout << "EZ!" << endl;
	}
	table1.DelRecord(k1);
	table2.DelRecord(k1);
	if (table1.IsEmpty() && table2.IsEmpty())
	{
		cout << "EEE" << endl;
	}
	/*--------------------------------------------------*/
	system("pause");
	return 0;
}