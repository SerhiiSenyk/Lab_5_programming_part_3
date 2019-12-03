#include "fantz.h"
//@Author Serhii Senyk 
//02.12.2019
int minSplit(set<uint> set)
{
	if (set.empty())
		return -1;
	for (const auto &min : set) {
		if (min <= *set.begin())
			return min;
	}
}

string ignoreNullInBegin(string binaryInStr)
{
	string binaryInSubStr = "";
	for (int i = 0; i < binaryInStr.size(); ++i) {
		if (binaryInStr[i] != '0') {
			binaryInSubStr = binaryInStr.substr(i, binaryInStr.size());
			break;
		}
	}
	return binaryInSubStr;
}

int fantz(const string binaryInStr, const set<string> & powsDecimal, map<string, int> & solution)
{
	if (isPow(binaryInStr, powsDecimal))
		return 1;
	set<uint> allSplits;
	string key;
	for (int i = 1; i < binaryInStr.size(); ++i) {
		if (isPow(binaryInStr.substr(i, binaryInStr.size()), powsDecimal)) {
			key = ignoreNullInBegin(binaryInStr.substr(i, binaryInStr.size()));
			if (solution.find(key) == solution.end())
				allSplits.insert(fantz(binaryInStr.substr(0, i), powsDecimal, solution) + 1);
			else
				allSplits.insert(solution[key] + 1);
		}
	}
	solution[key] = minSplit(allSplits);
	return solution[key];
}

bool isPow(const string binaryInStr, const set<string> powsDecimal)
{
	return (powsDecimal.find(ignoreNullInBegin(binaryInStr)) != powsDecimal.end()) ? true : false;
}

void convertToBinary(const uint128_t decimal, string & binaryInStr)
{
	if ((decimal / BINARY_BASE) > 0)
		convertToBinary(decimal / BINARY_BASE, binaryInStr);
	binaryInStr.push_back((decimal % BINARY_BASE) == 0 ? '0' : '1');
}

set<string> powerGenerator(uint128_t decimal, const int maxSize)
{
	set<string> powDecimal;
	uint128_t pow = decimal;
	string str = "";
	powDecimal.insert("1");
	while (str.size() <= maxSize) {
		str = "";
		convertToBinary(pow, str);
		powDecimal.insert(str);
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
