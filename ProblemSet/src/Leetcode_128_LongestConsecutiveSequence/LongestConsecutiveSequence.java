package Leetcode_128_LongestConsecutiveSequence;

import java.util.HashSet;

/*
	给定一个未排序的整数数组，找出最长连续序列的长度。
	
	要求算法的时间复杂度为 O(n)。
	
	示例:	
		输入: [100, 4, 200, 1, 3, 2]
		输出: 4
		解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class LongestConsecutiveSequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	//128. 最长连续序列
	public int longestConsecutive(int[] nums) {
		HashSet<Integer> set = new HashSet<>();
		for(int num:nums) {
			set.add(num);
		}
		int res = 0;
		for(int num:nums) {
			if(set.contains(num-1)) {
				continue;
			}else {
				int curnums = num;
				int length = 1;
				while(set.contains(curnums+1)) {
					length++;
					curnums++;
				}
				res = Math.max(res, length);
			}
		}
		return res;
	}

}
