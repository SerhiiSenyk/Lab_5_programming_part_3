#include "fantz.h"

int minSplit(vector<uint> vect)
{
	if (vect.size() == 0)
		return -1;
	uint min = vect[0];
	for (int i = 0; i < vect.size(); ++i) {
		if (vect[i] < min && vect[i] != 0)
			min = vect[i];
	}
	return min;
}

int fantz(const string binaryInStr, const vector<string> & powsDecimal, map<string, int> & solution)
{
	if (isPow(binaryInStr, powsDecimal))
		return 1;
	vector<uint> allSplits;
	string key;
	for (int i = 1; i < binaryInStr.size(); ++i) {
		if (isPow(binaryInStr.substr(i, binaryInStr.size()), powsDecimal)) {
			key = binaryInStr.substr(i, binaryInStr.size());
			if (solution.find(key) == solution.end())
				allSplits.push_back(fantz(binaryInStr.substr(0, i), powsDecimal, solution) + 1);
			else
				allSplits.push_back(solution[key] + 1);
		}
	}
	solution[key] = minSplit(allSplits);
	return solution[key];
}

bool isPow(const string binaryInStr, const vector<string> powsDecimal)
{
	string binaryInSubStr = "";
	for (int i = 0; i < binaryInStr.size(); ++i) {
		if (binaryInStr[i] != '0') {
			binaryInSubStr = binaryInStr.substr(i, binaryInStr.size());
			break;
		}
	}
	for (int i = 0;
		(i < powsDecimal.size()) && powsDecimal[i].size() <= binaryInStr.size(); ++i) {
		if (powsDecimal[i] == binaryInSubStr)
			return true;
	}
	return false;
}

void convertToBinary(const uint128_t decimal, string & binaryInStr)
{
	if ((decimal / BINARY_BASE) > 0)
		convertToBinary(decimal / BINARY_BASE, binaryInStr);
	binaryInStr.push_back((decimal % BINARY_BASE) == 0 ? '0' : '1');
}

vector<string> powerGenerator(uint128_t decimal, const int maxSize)
{
	vector<string> powDecimal;
	uint128_t pow = decimal;
	string str = "";
	powDecimal.push_back("1");
	while (str.size() <= maxSize) {
		str = "";
		convertToBinary(pow, str);
		powDecimal.push_back(str);
		pow *= decimal;
	}
	return powDecimal;
}

void writeToFile(const int result, string path)
{
	ofstream out(path);
	if (out.is_open())
		out << result << endl;
	out.close();
}

void readWithFile(string & str, uint & decimal, string path)
{
	ifstream in(path);
	if (in.is_open()) {
		in >> str;
		in >> decimal;
		in.close();
	}
	else
		exit(0);
}
