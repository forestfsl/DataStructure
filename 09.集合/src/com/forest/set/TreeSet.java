package com.forest.set;

import com.forest.map.Map;
import com.forest.map.TreeMap;

public class TreeSet<E> implements Set<E> {
	Map<E,Object> map = new TreeMap<>();

	@Override
	public int size() {
		// TODO Auto-generated method stub
		return map.size();
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return map.isEmpty();
	}

	@Override
	public void clear() {
		// TODO Auto-generated method stub
		map.clear();
		
	}

	@Override
	public boolean contains(E element) {
		// TODO Auto-generated method stub
		return map.containsKey(element);
	}

	@Override
	public void add(E element) {
		// TODO Auto-generated method stub
		map.put(element, null);
		
	}

	@Override
	public void remove(E element) {
		// TODO Auto-generated method stub
		map.remove(element);
		
	}

	@Override
	public void traversal(Visitor<E> visitor) {
		// TODO Auto-generated method stub
		map.traversal(new Map.Visitor<E, Object>() {
			public boolean visit(E key,Object value) {
				return visitor.visit(key);

			}
		});
		
	}
	

}
