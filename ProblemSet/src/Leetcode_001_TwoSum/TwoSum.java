package Leetcode_001_TwoSum;

/*
 	����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������
	����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�
	ʾ��
		���� nums = [2, 7, 11, 15], target = 9
		��Ϊ nums[0] + nums[1] = 2 + 7 = 9
		���Է��� [0, 1]
 */
public class TwoSum {
	//1.����֮��
	public int[] twoSum(int[] nums, int target) {
        int[] result = new int[] {-1,-1};
        for(int i = 0;i<nums.length-1;i++) {
        	for(int j = i+1;j<nums.length;j++) {
        		if(nums[i]+nums[j]==target) {
        			result[0] = i;
        			result[1] = j;
        		}
        	}
        }
        return result;
    }

}