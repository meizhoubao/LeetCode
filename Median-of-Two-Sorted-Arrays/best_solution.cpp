/*
 * Best solution for this problem so far.
 * Must compile the code with -std=c++11.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int size1 = nums1.size();
			int size2 = nums2.size();
			int s = size1 + size2;
			int t = (s - 1) / 2;
			if (size1 == 0 && size2 == 0) {exit(0);}
			if (size1 == 0) {
				if (size2 % 2 == 0) {return (nums2.at(t) + nums2.at(t + 1)) / 2.0;}
				else return nums2.at(t);
			}
			if (size2 == 0) {
				if (size2 % 2 == 0) {return (nums1.at(t) + nums1.at(t + 1)) / 2.0;}
				else return nums1.at(t);
			}
			for (int i = 0; i < t; i++) {
				if (nums1.back() > nums2.back()) {nums1.pop_back();}
				else {nums2.pop_back();}
			}
			if (s % 2 == 1) {
				double r = nums1.back() > nums2.back() ? nums1.back() : nums2.back();
				return r;
			} else {
				if (nums1.back() > nums2.back()) {
					double r1 = nums1.back();
					nums1.pop_back();
					double r2 = nums1.back() > nums2.back() ? nums1.back() : nums2.back();
					return (r1 + r2) / 2.0;
				} else {
					double r1 = nums2.back();
					nums2.pop_back();
					double r2 = nums2.back() > nums1.back() ? nums2.back() : nums1.back();
					return (r1 + r2) / 2.0;
				}
			}
		}
};

int main(int argc, char **argv)
{
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {3, 4};
	Solution solution;
	std::cout << "The median is " << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
}
