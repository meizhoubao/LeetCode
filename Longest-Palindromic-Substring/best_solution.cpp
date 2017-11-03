/*
 * 2017/11/03
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
	public:
		string longestPalindrome(string s) {
			int n = s.length();
			if (n <= 1) return s;
			
			int min_start = 0, max_len = 1;
			for (int i = 0; i < n;) {
				int j = i, k = i;
				while (k < n - 1 && s[k] == s[k+1]) k++;
				i = k + 1;
				while (k < n - 1 && s[k+1] == s[j-1]) {
					k++;
					j--;
				}
				if (k - j + 1 > max_len) {
					max_len = k - j + 1;
					min_start = j;
				}
			}
			return s.substr(min_start, max_len);
		}
};


int main(int argc, char **argv)
{
	string s("babad");
	Solution solution;
	std::cout << solution.longestPalindrome(s) << std::endl;
	return 0;
}
