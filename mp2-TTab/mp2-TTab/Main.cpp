#include <iostream>
#include <clocale>
#include <cstdlib>
#include "ScanTable.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*--------------------------------------------------*/
	TScanTable table(80);
	/*--------------------------------------------------*/
	system("pause");
	return 0;
}