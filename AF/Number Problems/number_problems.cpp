#include "number_problems.h";

void PrintDigitsSumPair(int n = 100) {
	for (int i = n; i >= 0; i--) {
		std::cout << DititSum(i) << ' ' << i << '\n';
	}
}

void PrintCountOfNumsEqualToFirstReversed(int n = 7, std::vector<int> vec{ 213, 78, 132, 30, 132, 8, 132 }) {
	int count{};

	if (vec.empty()) {
		std::cout << "0\n";
		return;
	}

	int reversed = Reversed(vec[0]);

	for (int i = 1; i < vec.size; i++) {
		if (vec[i] == reversed) {
			count++;
		}
	}

	std::cout << count << '\n';
}

void PrintPalindromesBetween(int a = 100, int b = 200) {
	int count{};

	for (int i = a; i <= b; i++) {
		if (IsPalindrome(i)) {
			count++;
			std::cout << i << ' ';
		}
	}

	std::cout << count << '\n';
}

void PrintMaxGcdPair(int n = 3, std::vector<std::pair<int, int>> vec{ {12, 10}, { 45,35 }, { 23,74 } }) {
	std::pair<int, int> max{};

	for (auto pair : vec) {
		if (Gcd(pair.first, pair.second) > Gcd(max.first, max.second)) {
			max = pair;
		}
	}

	std::cout << "Max pair: " << max.first << ' ' << max.second << '\n';
}

void PrintTwinPrimesBetween(int k = 2) {
	if (k < 1 || k > 9) {
		return;
	}

	for (int i = pow(10, k - 1); i < pow(10, k) - 1; i++) {
		if (IsPrime(i - 1) && IsPrime(i + 1)) {
			std::cout << i << ' ';
		}
	}
}

void PrintMinified(int num = 1204192) {
	int digits[10] = { 0 };
	int minified{};

	while (num) {
		digits[num % 10]++;
		num /= 10;
	}

	for (int i = 0; i < 10; i++) {
		while (digits[i]) {
			minified = minified * 10 + digits[i];
			digits[i]--;
		}
	}

	std::cout << minified << '\n';
}

bool DigitsInArithmeticProgression(int num = 2468) {
	if (num < 10) {
		return false;
	}

	int r = num % 10 - (num / 10) % 10; // 2

	while (num) {
		if (num % 10 - r != (num / 10) % 10) {
			return false;
		}
		num /= 10;
	}

	return true;
}
void EraseOcurrances(int num = 2345324, int digit = 2) {
	int erased{};

	while (num) {
		if (num % 10 != digit) {
			erased = erased * 10 + num % 10;
		}
		num /= 10;
	}

	std::cout << Reversed(erased);
}

void SwapDigitsPositions(int num = 12345678) {
	int swapped{};

	while (num) {
		int a = (num % 100) / 10;
		int b = num % 10;
		int c = a * 10 + b;
		swapped = swapped * 100 + c;
		num /= 100;
	}

	std::cout << Reversed(swapped);
}

void PrintMaxNumberAfterErasingDigit(int num = 45329)
{
	if (num <= 1000) {
		std::cout << "Number must be greater than 1000.";
		return;
	}

	int div = 1000;
	while (num / div >= 10) {
		div *= 10;
	}
	int max = num % div;
	while (div / 10 > 0) {
		int tempMax = ((num / div) * (div / 10)) + (num % (div / 10));
		if (tempMax > max) {
			max = tempMax;
		}
		div /= 10;
	}
	std::cout << "The maximum number is: " << max << '\n';
}

int DigitsSum(int num) {
	int sum{};

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int Reversed(int num) {
	int reversed{};

	while (num) {
		reversed *= 10 + num % 10;
		num /= 10;
	}

	return reversed;
}

bool IsPalindrome(int num) {

	if (num < 0) {
		return false;
	}

	if (num >= 0 && num <= 9) {
		return true;
	}

	int reversed{};
	int temp = num;

	while (temp) {
		reversed += temp % 10;
		temp /= 10;
	}

	return reversed == num ? true : false;
}

int Gcd(int a, int b) { 

	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int Gcd(int a, int b, bool recursive) {
	return b == 0 ? a : Gcd(b, a % b);
}

bool IsPrime(int num) {
	if (num < 0 || num % 2 == 0) {
		return false;
	}

	if (num >= 1 && num <= 3) {
		return true;
	}

	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) {
			return false
		}
	}

	return true;
}