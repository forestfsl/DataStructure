import com.forest.*;
import com.forest.file.FileInfo;
import com.forest.file.Files;
import com.forest.map.Map;
import com.forest.map.TreeMap;
import com.forest.set.ListSet;
import com.forest.set.Set;
import com.forest.set.TreeSet;
import com.forest.util.Times;
import com.forest.util.Times.Task;

//test3 test4 test5
//import com.forest.map.Map.Visitor;
//test1 test2
import com.forest.set.Set.Visitor;

public class Main {
	static void test1() {
		Set<Integer> listSet = new ListSet<>();
		listSet.add(10);
		listSet.add(11);
		listSet.add(11);
		listSet.add(12);
		listSet.add(10);
		
		Set<Integer> treeSet = new TreeSet<>();
		treeSet.add(12);
		treeSet.add(10);
		treeSet.add(7);
		treeSet.add(11);
		treeSet.add(10);
		treeSet.add(11);
		treeSet.add(9);
		treeSet.traversal(new Visitor<Integer>() {
			@Override
			public boolean visit(Integer element) {
				System.out.println(element);
				return false;
			}
		});
		
	}
	
	static void testSet(Set<String> set, String[] words) {
		for (int i = 0; i < words.length; i++) {
			set.add(words[i]);
		}
		for (int i = 0; i < words.length; i++) {
			set.contains(words[i]);
		}
		for (int i = 0; i < words.length; i++) {
			set.remove(words[i]);
		}
	}
	//数据量越大的时候，treeSet效果越显著
	static void test2() {
		FileInfo fileInfo = Files.read("/Users/songlin/DataStructure",new String[]{"java"});
		
		System.out.println("文件数量：" + fileInfo.getFiles());
		System.out.println("代码行数：" + fileInfo.getLines());
		String[] words = fileInfo.words();
		System.out.println("单词数量：" + words.length);
		
		Times.test("ListSet", new Task() {
			public void execute() {
				testSet(new ListSet<>(), words);
			}
		});
		
		Times.test("TreeSet", new Task() {
			public void execute() {
				testSet(new TreeSet<>(), words);
			}
		});
	}
	
//	static void test3() {
//		Map<String,Integer>map = new TreeMap<>();
//		map.put("c",2);
//		map.put("a",5);
//		map.put("b",6);
//		map.put("a",8);
//		map.traversal(new Visitor<String,Integer>(){
//			public boolean visit(String key,Integer value) {
//				System.out.println(key + "_" + value);
//				return false;
//			}
//		});
//	}
//	static void test4() {
//		FileInfo fileInfo = Files.read("/Users/songlin/DataStructure/09.集合/src/com/forest",new String[]{"java"});
//		System.out.println("文件数量：" + fileInfo.getFiles());
//		System.out.println("代码行数：" + fileInfo.getLines());
//		String [] words = fileInfo.words();
//		System.out.println("单词数量:" + words.length);
//		
//		Map<String,Integer>map = new TreeMap<>();
//		for(int i = 0;i < words.length;i++) {
//			Integer count = map.get(words[i]);
//			count = (count == null) ? 1 : (count + 1);
//			map.put(words[i], count);
//		}
//		map.traversal(new Visitor<String,Integer>(){
//			public boolean visit(String key,Integer value) {
//				System.out.println(key + "_" + value);
//				return false;
//			}
//		});
//	}
//	static void test5() {
//		Set<String>set = new TreeSet<>();
//		set.add("c");
//		set.add("b");
//		set.add("c");
//		set.add("c");
//		set.add("a");
//		set.traversal(new Set.Visitor<String>() {
//			public boolean visit(String element) {
//				System.out.println(element);
//				return false;
//			}
//		});
//	}
	
	public static void main(String[] args) {
//		test1();
		test2();
	}
}
