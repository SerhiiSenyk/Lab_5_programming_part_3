#include "fantz.h"

int main() 
{
	const string file_in = "test_in.txt";
	const string file_out = "test_out.txt";
	string binaryInStr;// "110011011";
	uint decimalValue;// = 5;
	readWithFile(binaryInStr, decimalValue, file_in);
	const vector<string> powsDecimal = powerGenerator(decimalValue, binaryInStr.size());
	map<string, int>  solution;
	int minSplit = fantz(binaryInStr, powsDecimal, solution);
	cout << "Min split = " << minSplit << endl;
	writeToFile(minSplit, file_out);
	system("pause");
	return 0;
}
