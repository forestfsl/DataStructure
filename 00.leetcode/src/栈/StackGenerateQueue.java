package 栈;
import java.util.Stack;
/**
 * 栈实现队列
 * @author songlin
 *
 */
@SuppressWarnings("unused")
public class StackGenerateQueue {

	private Stack<Integer>inStack;
	private Stack<Integer>outStack;
	
	public StackGenerateQueue() {
		inStack = new Stack<>();
		outStack = new Stack<>();
	}
	/**
	 * 入队
	 */
	public void push(int x) {
		inStack.push(x);
	}
	/**
	 * 出队
	 */
	public int pop() {
		checkOutStack();
		return outStack.pop();
	}
	/**
	 * 获取头部元素
	 */
	public int peek() {
		return outStack.peek();
	}
	
	/**
	 * 是否为空
	 */
	public boolean empty() {
		return inStack.isEmpty() && outStack.isEmpty();
	}
	
	private void checkOutStack() {
		if (outStack.isEmpty()) {
			while (!inStack.isEmpty()) {
				outStack.push(inStack.pop());
			}
		}
	}
}
