//
//  main.cpp
//  Trie
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#include <iostream>
#include "Trie.hpp"
#include <assert.h>
using namespace std;

void test1(){
    Trie<int> trie =  Trie<int>();
    trie.add("cat", 1);
//    cout << trie.get("cat") << endl;
    trie.add("dog",2);
    trie.add("catalog", 3);
    trie.add("cast", 4);
    trie.add("dogggy", 5);
      cout << trie.get("dogggy") << endl;
    assert(trie.fetchSize() == 5);
    assert(trie.startsWith("do"));
    assert(trie.startsWith("c"));
    assert(trie.startsWith("ca"));
    assert(trie.startsWith("cat"));
    assert(trie.startsWith("cata"));
    assert(!trie.startsWith("hehe"));
    assert(trie.get("dogggy") == 5);
    assert(trie.remove("cat") == 1);
    assert(trie.remove("catalog") == 3);
    assert(trie.remove("cast") == 4);
    assert(trie.fetchSize() == 2);
    assert(trie.startsWith("小"));
    assert(trie.startsWith("do"));
    assert(!trie.startsWith("c"));
    
}
int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
