#include "BaseMatrixNxM.h"

BaseMatrixNxM::BaseMatrixNxM() :
	_rows(0), _cols(0), _data(vector<vector<int>>()), _base10Values(vector<int>()) {}

BaseMatrixNxM::BaseMatrixNxM(vector<vector<int>> v = { {0} }) :
	_rows(v.size()), _cols(v[0].size()), _data(v) {
	_GenerateBase10Values();
}

bool BaseMatrixNxM::IsValid() {
	for (int j = 0; j < _cols; j++) {
		for (int i = 0; i < _rows; i++) {
			if (_data[i][j] >= j + _C) {
				std::cout << "Invalid" << '\n';
				return false;
			}
		}
	}
	std::cout << "Valid" << '\n';
	return true;
}

void BaseMatrixNxM::Print() {
	for (auto& row : _data) {
		for (auto& val : row) {
			std::cout << val << ' ';
		}
		std::cout << '\n';
	}
}

void BaseMatrixNxM::PrintBase10Values() {
	for (auto& val : _base10Values) {
		std::cout << val << ' ';
	}
	std::cout << '\n';
}

void BaseMatrixNxM::_GenerateBase10Values() {
	for (int j = 0; j < _cols; j++) {
		int base10Val = 0;
		int targetBase = j + _C;
		for (int i = 0, n = _rows - 1; i < _rows; i++, n--) {
			if (_data[i][j] >= targetBase) {
				base10Val = 0;
				break;
			}
			base10Val += _data[i][j] * static_cast<int>(pow(targetBase, n));
		}
		_base10Values.push_back(base10Val);
	}
}
