#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const map<int, string> simplifiedChineseDigits = {
	{0, "零"}, {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"},
	{5, "五"}, {6, "六"}, {7, "七"}, {8, "八"}, {9, "九"}
};

const map<int, string> simplifiedChineseUnits = {
	{0, ""}, {1, "十"}, {2, "百"}, {3, "千"}, {4, "万"},
	{5, "十万"}, {6, "百万"}, {7, "千万"}, {8, "亿"}
};

const map<int, string> traditionalChineseDigits = {
	{0, "零"}, {1, "壹"}, {2, "貳"}, {3, "參"}, {4, "肆"},
	{5, "伍"}, {6, "陸"}, {7, "柒"}, {8, "捌"}, {9, "玖"}
};

const map<int, string> traditionalChineseUnits = {
	{0, ""}, {1, "拾"}, {2, "佰"}, {3, "仟"}, {4, "萬"},
	{5, "拾萬"}, {6, "佰萬"}, {7, "仟萬"}, {8, "億"}
};

vector<int> extractDigits(int number) {
	vector<int> digits;
	while (number > 0) {
		digits.push_back(number % 10);
		number /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

string getChineseDigit(int digit, const map<int, string>& chineseDigits) {
	return chineseDigits.at(digit);
}

string getChineseUnit(int index, const map<int, string>& chineseUnits) {
	return chineseUnits.at(index);
}

vector<string> buildChineseNumber(const vector<int>& digits, const map<int, string>& chineseDigits, const map<int, string>& chineseUnits) {
	vector<string> parts;
	int unitIndex = digits.size() - 1;
	bool zeroFlag = false;

	for (int digit : digits) {
		string chineseDigit = getChineseDigit(digit, chineseDigits);
		string chineseUnit = unitIndex > 0 ? getChineseUnit(unitIndex, chineseUnits) : "";

		if (digit != 0) {
			if (!(digit == 1 && unitIndex > 0 && (unitIndex != digits.size() - 1 || digits.size() == 2))) {
				parts.push_back(chineseDigit);
			}
			parts.push_back(chineseUnit);
			zeroFlag = false;
		}
		else if (!zeroFlag && !parts.empty()) {
			parts.push_back(chineseDigits.at(0)); // Add '零' for zero
			zeroFlag = true;
		}

		unitIndex--;
	}

	// Remove trailing '零', if any
	if (!parts.empty() && parts.back() == chineseDigits.at(0)) {
		parts.pop_back();
	}

	return parts;
}


int main() {
	
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
	
	cout << "Welcome to the Chinese Numeral Converter!\n";

	while (true) {
		string input;
		cout << "Enter a number or type 'quit' to exit: ";
		cin >> input;

		if (input == "quit") {
			break;
		}

		int number = stoi(input);
		vector<int> digits = extractDigits(number);

		vector<string> simplifiedChineseNumber = buildChineseNumber(digits, simplifiedChineseDigits, simplifiedChineseUnits);
		vector<string> traditionalChineseNumber = buildChineseNumber(digits, traditionalChineseDigits, traditionalChineseUnits);

		cout << "Simplified Chinese:\n";
		for (const auto& part : simplifiedChineseNumber) {
			cout << part;
		}

		cout << "\nTraditional Chinese:\n";
		for (const auto& part : traditionalChineseNumber) {
			cout << part;
		}
	}

	return 0;
}