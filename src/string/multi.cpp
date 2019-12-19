#include <string/multi.h>
#include <iostream>
std::string string_multi_op(std::string& num1, std::string& num2){
	if (num1 == "0" || num2 == "0") return "0";
	size_t l1 = num1.length();
	size_t l2 = num2.length();
	std::string res(l1 + l2, '0');
	for (int i = l1 - 1; i >= 0; i--) {
		int step_carry = 0;
		for (int j = l2 - 1; j >= 0; j--) {
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = res[i+j+1] - '0' + step_carry + (mul % 10);
			res[i+j+1] = (sum % 10) + '0';
			step_carry = sum / 10 + mul / 10;
			// std::cout <<(mul % 10)<<"  "<<(sum % 10)<<" ->"<< step_carry << std::endl;
		}
		res[i] += step_carry;
	}
	for (int i = 0; i < l1 + l2; i++) {
		if (res[i] != '0') return res.substr(i);
	}
	return "0";
}

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
std::vector<std::string> split(std::string work, char delim, int rep) {
	std::vector<std::string> flds;
    std::string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

std::string strToUpper(std::string& s) {
	std::string ret = s;
	for(int i = 0; i < ret.size(); i++) ret[i] = std::toupper(ret[i]);
	return ret;
}