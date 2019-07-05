package Leetcode_025_ReverseNodesinkGroup;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;

/*
	给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。	
	k 是一个正整数，它的值小于或等于链表的长度。	
	如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
	
	示例 :	
		给定这个链表：1->2->3->4->5	
		当 k = 2 时，应当返回: 2->1->4->3->5	
		当 k = 3 时，应当返回: 3->2->1->4->5
	
	说明 :	
		你的算法只能使用常数的额外空间。
		你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//25. K 个一组翻转链表
public class ReverseNodesinkGroup {
	public static void main(String[] args) {
		int[] arr = { 1, 2, 3, 4, 5 };
		int n = arr.length;
		ReverseNodesinkGroup rnkg = new ReverseNodesinkGroup();
		ListNode head = ListNodeUtils.creatNode(arr, n);
		ListNodeUtils.printList(head);
		head = rnkg.reverseKGroup(head, 2);
		ListNodeUtils.printList(head);
	}

	// 递归
	public ListNode reverseKGroup(ListNode head, int k) {
		// 找到第k个节点，尾结点
		ListNode hail = head;
		for (int i = 1; i < k && hail != null; i++) {
			hail = hail.next;
		}
		if (hail == null) {
			// 不够k个
			return head;
		}
		// 假头
		ListNode dummy = new ListNode(0);
		dummy.next = head;

		// 翻转k个节点
		ListNode cur = head;

		while (cur != hail) {
			ListNode next = cur.next;

			dummy.next = next;
			cur.next = hail.next;
			hail.next = cur;

			cur = next;

		}
		// 调整后的尾结点为头节点
		head.next = reverseKGroup(head.next, k);

		return dummy.next;
	}

}
