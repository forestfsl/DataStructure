package 链表;

//删除给定链表节点
public class DeleteNodeLinklist {
	public static void deleteNode(ListNode node) {
		node.data = node.next.data;
		node.next = node.next.next;
	}
	
	public static void main(String[] args) {
		ListNode taiListNode = new ListNode(1, null);
		ListNode cListNode = new ListNode(2, taiListNode);
		ListNode bListNode = new ListNode(3, cListNode);
		ListNode headListNode = new ListNode(4, bListNode);
		deleteNode(cListNode);
		 while(headListNode!=null){
			 System.out.println(headListNode.data);
			 headListNode=headListNode.next;
		}
	}
}
