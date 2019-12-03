#include "fantz.h"

int main() 
{
	const string file_in = "test_in.txt";
	const string file_out = "test_out.txt";
	string binaryInStr = "";
	uint decimalValue;
	readWithFile(binaryInStr, decimalValue, file_in);
	const set<string> powsDecimal = powerGenerator(decimalValue, binaryInStr.size());
	map<string, int>  solution;
	int minSplit = fantz(binaryInStr, powsDecimal, solution);
	cout << "Min split = " << minSplit << endl;
	writeToFile(minSplit, file_out);
	system("pause");
	return 0;
}