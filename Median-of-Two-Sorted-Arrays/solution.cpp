/*
 * Must compile the code with -std=c++11
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			vector<int> tmp;
			int i = 0, j = 0, m = nums1.size(), n = nums2.size();
			
			if (m == 0 && n == 0) exit(0);
			if (m == 0) {
				return n % 2 == 0 ? (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0 : nums2[n / 2];
			}
			if (n == 0) {
				return m % 2 == 0 ? (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0 : nums1[m / 2];
			}

			for (; i + j != (m + n) / 2 + 1;) {
				
				if (i == m) {
					int t = (m + n) / 2 - (i + j);
					for (int k = 0; k <= t; k++) tmp.push_back(nums2[j+k]);
					break;
				}

				if (j == n) {
					int t = (m + n) / 2 - (i + j);
					for (int k = 0; k <= t; k++) tmp.push_back(nums1[i+k]);
					break;
				}
				
				if (nums1[i] <= nums2[j]) {
					tmp.push_back(nums1[i++]);
				} else {
					tmp.push_back(nums2[j++]);
				}
			}
			int s = tmp.size();
			if ((m + n) % 2 == 0) return (tmp[s-1] + tmp[s-2]) / 2.0;
			else return tmp[s-1];
		}
};

int main(int argc, char **argv)
{
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {3, 4};
	Solution solution;
	std::cout << "The median is " << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
}
