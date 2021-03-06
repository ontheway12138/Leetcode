package Leetcode_283_MoveZeroes;

/*
	给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

	示例:	
		输入: [0,1,0,3,12]
		输出: [1,3,12,0,0]
	说明:	
		必须在原数组上操作，不能拷贝额外的数组。
		尽量减少操作次数。
*/
public class MoveZeroes {
	//283. 移动零
	public void moveZeroes(int[] nums) {
		// 统计零的个数
		int count = 0;
		// 遍历数组，删除0
		int length = nums.length;
		for (int i = 0; i < length; i++) {
			if (nums[i] == 0) {
				count++;
			} else {
				nums[i - count] = nums[i];
			}
		}

		// 补充数组
		for (int i = length - count; i < length; i++) {
			nums[i] = 0;
		}
	}
}
