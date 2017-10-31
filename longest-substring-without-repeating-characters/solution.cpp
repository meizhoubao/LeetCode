/**
 * compile the code: g++ solution.cpp
 * 2017/10/31
 */

#include <iostream>
#include <string>
using std::string;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.empty()) return 0;
			
			int start = 0, end = 1, length = 1, index = 0;
			if (end == s.size()) return length;

			for (; s.size() - start > length;) {
				index = start;
				// while(s[index++] != s[end]);		Wrong code!!!
				while (s[index] != s[end]) index++;
				if (index != end) start = index + 1;
				if (length < end - start + 1) length = end - start + 1;
				if (end++ == s.size() - 1) break;
			}
			
			return length;
		}
};


int main(int argc, char **argv)
{
	string s;
	Solution solution;
	std::cin >> s;
	int length = solution.lengthOfLongestSubstring(s);
	std::cout << s << ":" << length << std::endl;
	return 0;
}
