package 链表;

//链表反转
public class ReverNodeLinklist {
	//递归方式
	public static ListNode reverseList(ListNode head) {
		if (head == null || head.next == null) return head;
		
		ListNode reverseHead = reverseList(head.next);
		head.next.next = head;
		head.next = null;
		return reverseHead;
	}
	//遍历方式
	public static ListNode reverseList2(ListNode head) {
		if (head == null || head.next == null) return head;
		
		ListNode reverseHead = null;
		while (head != null) {
			ListNode tmpListNode = head.next;
			head.next = reverseHead;
			reverseHead = head;
			head = tmpListNode;
		}
		return reverseHead;
	}
	public static void main(String[] args) {
		ListNode taiListNode = new ListNode(1, null);
		ListNode cListNode = new ListNode(2, taiListNode);
		ListNode bListNode = new ListNode(3, cListNode);
		ListNode headListNode = new ListNode(4, bListNode);
		headListNode = reverseList(headListNode);
		 while(headListNode!=null){
			 System.out.println(headListNode.data);
			 headListNode=headListNode.next;
		}
//		 headListNode = reverseList2(headListNode);
//		 while(headListNode!=null){
//			 System.out.println(headListNode.data);
//			 headListNode=headListNode.next;
//		}
	}
}
