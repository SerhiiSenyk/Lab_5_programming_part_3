#ifndef FANTZ_H
#define FANTZ_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#define BINARY_BASE 2
typedef unsigned int uint;
using namespace std;
using namespace boost::multiprecision;
int fantz(const string binaryInStr, const vector<string> & powsDecimal, map<string, int> & solution);
bool isPow(const string binaryInStr, const vector<string> powsDecimal);
void convertToBinary(const uint128_t decimal, string & binaryInStr);
vector<string> powerGenerator(uint128_t decimal, const int maxSize);
void readWithFile(string & str, uint & decimal, string path);
void writeToFile(const int result, string path);

#endif
