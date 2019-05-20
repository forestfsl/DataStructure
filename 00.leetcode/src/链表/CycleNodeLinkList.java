package 链表;

public class CycleNodeLinkList {
	public static boolean hasCycle(ListNode head) {
		if (head == null || head.next == null) return false;
		
		ListNode slow = head;
		ListNode fast = head.next;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
			if (slow == fast) return true;
			
		}
		return false;
	}

	public static void main(String[] args) {
		ListNode taiListNode = new ListNode(1, null);
		ListNode cListNode = new ListNode(2, taiListNode);
		ListNode bListNode = new ListNode(3, cListNode);
		ListNode headListNode = new ListNode(4, bListNode);
		//测试环
		cListNode.next = bListNode;
//		 while(headListNode!=null){
//			 System.out.println(headListNode.data);
//			 headListNode=headListNode.next;
//		}
		 System.out.println( hasCycle(headListNode));
		 
	}
}
