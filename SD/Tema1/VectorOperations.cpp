#include "VectorOperations.h"

VectorOperations::VectorOperations() :
	_data(vector<int>()), _pairs(vector<pair<int, int>>()) {

}

VectorOperations::VectorOperations(vector<int> v) :
	_data(v), _pairs(vector<pair<int, int>>) {
}

VectorOperations::VectorOperations(vector<pair<int, int>> p) :
	_data(vector<int>()), _pairs(p) {

}

bool VectorOperations::IsSortedA()
{
	if (_nums.empty()) {
		return false;
	}

	for (int i = 0; i < _nums.size() - 1; i++) {
		if (_nums[i] >= _nums[i + 1]) {
			return false;
		}
	}

	return true;
}

bool VectorOperations::IsSortedB()
{
	if (_nums.empty()) {
		return false;
	}

	int mid = vec.size() / 2;

	for (int i = 0; i < mid; i++) {
		for (int j = mid; j < _nums.size(); j++) {
			if (_nums[i] >= _nums[j]) {
				return false;
			}
		}
	}

	return true;
}

bool VectorOperations::IsSuperior()
{
	float average = 0;
	int lowCount = 0;
	int highCount = 0;

	for (int i = 0; i < _nums.size(); i++) {
		average += _nums[i];
	}

	average /= _nums.size();

	for (int i = 0; i < _nums.size(); i++) {
		if (_nums[i] > average) {
			highCount++;
		}
		else {
			lowCount++;
		}
	}

	return highCount > lowCount;
}

int VectorOperations::MostFrequentNum(const int lowerBound = 30, const int upperBound = 80) {
	vector<int> freq(upperBound - lowerBound + 1, 0);
	pair<int, int> max{ 0,-1 };

	for (int i = 0; i < _nums.size(); i++) {
		int val = _nums[i];
		int valIndex = val - lowerBound;

		if (val < lowerBound || val > upperBound) {
			continue;
		}
		freq[valIndex]++;

		if (freq[valIndex] > max.first) {
			max.first = freq[valIndex];
			max.second = val;
		}
	}

	return max.second;
}

vector<int> VectorOperations::OddsRepeated(int times = 2) {
	std::vector<int> oddsDuplicated;

	for (auto& val : _nums) {
		if (_HasOnlyOddDigits(val)) {
			for (int i = 0; i < times; i++) {
				oddsDuplicated.push_back(val);
			}
		}
	}

	return oddDuplicated;
}

unordered_map<int, vector<pair<int, int>>> VectorOperations::EqualPairs() {

	unordered_map<int, vector<pair<int, int>>> base10Values;

	for (auto& num : _pairs) {
		if (!_IsValid(num)) {
			continue;
		}

		base10Values[_Base10Val(num)].push_back(num);
	}

	for (auto& kv : base10Values) {
		cout << kv.first << " = [";
		for (auto& pair : kv.second) {
			cout << '{' << pair.first << ", " << pair.second << '}';
		}
		cout << "]\n";
	}

	return base10Values;
}

// PRIVATE FUNCTIONS


bool VectorOperations::_HasOnlyOddDigits(int num) {
	while (num) {
		if (num % 2 == 0) {
			return false;
		}
		num /= 10;
	}
	return true;
}

bool VectorOperations::_IsValid(pair<int, int> num) {
	if (num.first <= 0) {
		return false;
	}

	if (num.first > 10) {
		cout << "Not implemented.\n";
		return false;
	}

	while (num.second) {
		if (num.second % 10 >= num.first) {
			return false;
		}
		num.second /= 10;
	}

	return true;
}

int VectorOperations::_Base10Val(pair<int, int> num) {
	if (num.first == 10) {
		return num.second;
	}

	int base10Val = 0;
	int exp = 0;

	while (num.second) {
		base10Val += num.second % 10 * pow(num.first, exp);
		num.second /= 10;
		exp++;
	}

	return base10Val;
}