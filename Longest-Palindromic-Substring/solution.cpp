/*
 *
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
	public:
		string longestPalindrome(string s) {
			if (s.empty()) return NULL;
			int cur_len = 0, i = 0;
			for (cur_len = s.size(); cur_len > 1; cur_len--) {
				for (i = 0; i <= s.size() - cur_len; i++) {
					for (int j = 0; j < cur_len / 2; j++) {
						if (s[i + j] != s[i + cur_len - j - 1]) break;
						if (j == cur_len / 2 - 1) return string(s, i, cur_len);
					}
				}
			}
			return string(s, 0, 1);
		}
};


int main(int argc, char **argv)
{
	string s("babad");
	Solution solution;
	std::cout << solution.longestPalindrome(s) << std::endl;
	return 0;
}
