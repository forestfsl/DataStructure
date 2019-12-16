//
//  RBNode.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/13.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef RBNode_hpp
#define RBNode_hpp

#include <stdio.h>
#include "Node.hpp"

template<class E>

class RBNode:Node<E>{
public:
    bool color = false;
    RBNode(E element,Node<E>* parent):Node<E>(element,parent){
        
    }
     int id()
    {
       return 2;
    }
    
};
#endif /* RBNode_hpp */
