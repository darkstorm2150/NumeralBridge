#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

/*
* 
* Fun project for converting arabic numerals to chinese numerals
* 
*/

using namespace std;

map<int, string> chineseDigits = {
	{0, "零"}, {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"},
	{5, "五"}, {6, "六"}, {7, "七"}, {8, "八"}, {9,"九"}
};

map<int, string> chineseUnits = {
	{0, ""},	// Ones place
	{1, "十"},	// Tens
	{2, "百"},	// Hudreds
	{3, "千"},	// Thousands
	{4,	"万"},	// Ten Thousands
	{5,	"十万"}, // Hundred Thousands
	{6,	"百万"}, // Millions
	{7,	"千万"}, // Ten Millions
	{8,	"亿"}    // Hundred Millions
	// Add more units if needed
};

string numberToChinese(int number) {
	if (number == 0) {
		return chineseDigits[0];
	}

	vector<string> parts;
	int unitIndex = 0;

	while (number > 0) {
		int digit = number % 10;
		string chineseDigit = chineseDigits[digit];
		string chineseUnit = chineseUnits[unitIndex];

		if (digit != 0) {
			parts.push_back(chineseDigit + chineseUnit);
		}
		else if (!parts.empty() && parts.back() != chineseDigits[0]){
			parts.push_back(chineseDigit);
		}
		
		number /= 10;
		unitIndex++;
	}

	reverse(parts.begin(), parts.end());

	string result;
	for (const string& part : parts) {
		for (size_t i = 0; i < part.size(); ) {
			size_t len = 1;
			if ((part[i] & 0x80) != 0) {  // If the top bit is set, it's a multi-byte character
				if ((part[i] & 0xE0) == 0xC0) len = 2;  // 110xxxxx: 2 bytes
				else if ((part[i] & 0xF0) == 0xE0) len = 3;  // 1110xxxx: 3 bytes
				else if ((part[i] & 0xF8) == 0xF0) len = 4;  // 11110xxx: 4 bytes
				// Note: UTF-8 can be up to 4 bytes. More than this is not valid UTF-8
			}

			result += part.substr(i, len);  // Append the character (which may be multi-byte)
			result += "\n";
			i += len;
		}
	}

	return result;
}

int main() {
	int number = {0};

	std::cout << "──────────────────────────────────\n";
	std::cout << "──────▄▀▀▄────────────────▄▀▀▄────\n";
	std::cout << "─────▐▒▒▒▒▌──────────────▌▒▒▒▒▌───\n";
	std::cout << "─────▌▒▒▒▒▐─────────────▐▒▒▒▒▒▐───\n";
	std::cout << "────▐▒▒▒▒▒▒▌─▄▄▄▀▀▀▀▄▄▄─▌▒▒▒▒▒▒▌──\n";
	std::cout << "───▄▌▒▒▒▒▒▒▒▀▒▒▒▒▒▒▒▒▒▒▀▒▒▒▒▒▒▐───\n";
	std::cout << "─▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌───\n";
	std::cout << "▐▒▒▒▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐───\n";
	std::cout << "▌▒▒▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌──\n";
	std::cout << "▒▒▐▒▒▒▒▒▒▒▒▒▄▀▀▀▀▄▒▒▒▒▒▄▀▀▀▀▄▒▒▐──\n";
	std::cout << "▒▒▌▒▒▒▒▒▒▒▒▐▌─▄▄─▐▌▒▒▒▐▌─▄▄─▐▌▒▒▌─\n";
	std::cout << "▒▐▒▒▒▒▒▒▒▒▒▐▌▐█▄▌▐▌▒▒▒▐▌▐█▄▌▐▌▒▒▐─\n";
	std::cout << "▒▌▒▒▒▒▒▒▒▒▒▐▌─▀▀─▐▌▒▒▒▐▌─▀▀─▐▌▒▒▒▌\n";
	std::cout << "▒▌▒▒▒▒▒▒▒▒▒▒▀▄▄▄▄▀▒▒▒▒▒▀▄▄▄▄▀▒▒▒▒▐\n";
	std::cout << "▒▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▐\n";
	std::cout << "▒▌▒▒▒▒▒▒▒▒▒▒▒▒▀▒▀▒▒▒▀▒▒▒▀▒▀▒▒▒▒▒▒▐\n";
	std::cout << "▒▌▒▒▒▒▒▒▒▒▒▒▒▒▒▀▒▒▒▄▀▄▒▒▒▀▒▒▒▒▒▒▒▐\n";
	std::cout << "▒▐▒▒▒▒▒▒▒▒▒▒▀▄▒▒▒▄▀▒▒▒▀▄▒▒▒▄▀▒▒▒▒▐\n";
	std::cout << "▒▓▌▒▒▒▒▒▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▐\n";
	std::cout << "▒▓▓▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌\n";
	std::cout << "▒▒▓▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─\n";
	std::cout << "▒▒▓▓▀▀▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──\n";
	std::cout << "▒▒▒▓▓▓▓▓▀▀▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▄▄▀▀▒▌─\n";
	std::cout << "▒▒▒▒▒▓▓▓▓▓▓▓▀▀▀▀▀▀▀▀▀▀▀▀▀▀▒▒▒▒▒▐─\n";
	std::cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌\n";
	std::cout << "Welcome to the Chinese Numeral Converter!\n";

	std::cout << "Enter a number:";
	std::cin >> number;

	string chineseNumber = numberToChinese(number);
	std::cout << "Simplified Chinese:\n" << chineseNumber << endl;

	return 0;
}