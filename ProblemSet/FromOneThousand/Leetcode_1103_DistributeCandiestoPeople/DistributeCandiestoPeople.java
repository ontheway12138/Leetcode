package Leetcode_1103_DistributeCandiestoPeople;

/*
	�����������ǹ���	
	��������һЩ�ǹ� candies����������Ƿָ��źöӵ� n = num_people ��С���ѡ�	
	����һ��С���� 1 ���ǹ����ڶ���С���� 2 �ţ��������ƣ�ֱ�������һ��С���� n ���ǹ���	
	Ȼ�������ٻص��������㣬����һ��С���� n + 1 ���ǹ����ڶ���С���� n + 2 �ţ�
	�������ƣ�ֱ�������һ��С���� 2 * n ���ǹ���	
	�ظ��������̣�ÿ�ζ�����һ�ζ����һ���ǹ�������������յ���ٴδӶ�����㿪ʼ����
	ֱ�����Ƿ������е��ǹ���ע�⣬�����������е�ʣ���ǹ�������������ǰһ�η������ǹ��ࣩ��
	��Щ�ǹ�Ҳ��ȫ��������ǰ��С���ѡ�
	����һ������Ϊ num_people��Ԫ��֮��Ϊ candies �����飬
	�Ա�ʾ�ǹ������շַ�������� ans[i] ��ʾ�� i ��С���ѷֵ����ǹ�������
		
	ʾ�� 1��	
		���룺candies = 7, num_people = 4
		�����[1,2,3,1]
		���ͣ�
		��һ�Σ�ans[0] += 1�������Ϊ [1,0,0,0]��
		�ڶ��Σ�ans[1] += 2�������Ϊ [1,2,0,0]��
		�����Σ�ans[2] += 3�������Ϊ [1,2,3,0]��
		���ĴΣ�ans[3] += 1����Ϊ��ʱֻʣ�� 1 ���ǹ��������������Ϊ [1,2,3,1]��
	
	ʾ�� 2��	
		���룺candies = 10, num_people = 3
		�����[5,2,3]
		���ͣ�
		��һ�Σ�ans[0] += 1�������Ϊ [1,0,0]��
		�ڶ��Σ�ans[1] += 2�������Ϊ [1,2,0]��
		�����Σ�ans[2] += 3�������Ϊ [1,2,3]��
		���ĴΣ�ans[0] += 4�����������Ϊ [5,2,3]��
	 
	
	��ʾ��	
		1 <= candies <= 10^9
		1 <= num_people <= 1000
 */
public class DistributeCandiestoPeople {
	// 1103.���ǹ� II
	public int[] distributeCandies(int candies, int num_people) {
		int i = 1;
		int[] ans = new int[num_people];
		while (i < candies) {
			ans[(i - 1) % num_people] += i;
			candies -= i;
			i++;
		}
		ans[(i - 1) % num_people] += candies;
		return ans;

	}
}