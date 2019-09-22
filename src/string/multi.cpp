#include <string/multi.h>
#include <iostream>
std::string string_multi_op(std::string& num1, std::string& num2){
	if (num1 == "0" || num2 == "0") return "0";
	int l1 = num1.length();
	int l2 = num2.length();
	std::string res(l1 + l2, '0');
	for (int i = l1 - 1; i >= 0; i--) {
		int step_carry = 0;
		for (int j = l2 - 1; j >= 0; j--) {
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = res[i+j+1] - '0' + step_carry + (mul % 10);
			res[i+j+1] = (sum % 10) + '0';
			step_carry = sum / 10 + mul / 10;
			std::cout <<(mul % 10)<<"  "<<(sum % 10)<<" ->"<< step_carry << std::endl;
		}
		res[i] += step_carry;
	}
	for (int i = 0; i < l1 + l2; i++) {
		if (res[i] != '0') return res.substr(i);
	}
	return "0";
}