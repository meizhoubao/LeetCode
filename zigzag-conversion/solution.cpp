/*
 * 2017/11/15
 * The best solution is worth reading!!!
 */


#include <iostream>
#include <string>

using std::string;

class Solution {
	public:
		string convert(string s, int numRows) {
			string sd;
			int len = s.size();
			if (len == 0 || numRows <= 0) return sd;
			if (numRows == 1 || len <= numRows) return s;
			for (int i = 0; i < numRows; i++) {
				if (i == 0 || i == numRows - 1) {
					for (int j = i; j < len; j = j + 2 * numRows - 2) {
						sd.append(1, s[j]);
					}
				} else {
					for (int j = i; j < len; j = j + 2 * numRows - 2) {
						sd.append(1, s[j]);
						int k = j + 2 * numRows - 1 - 2 * i - 1;
						if (k < len) sd.append(1, s[k]);
						else break;
					}
				}
			}
			return sd;
		}
};

int main(int argc, char **argv)
{
	string s = "PAYPALISHIRING";
	Solution solution;
	string sd = solution.convert(s, 3);
	std::cout << "The length is: " << sd.size() << std::endl;
	std::cout << sd << std::endl;
	return 0;
}
