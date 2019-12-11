//
//  RBTree.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/10.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

static bool RED = false;
static bool BLACK = true;

#include <stdio.h>

template<class E>
class RBTree : public BBST<E> {
    typedef int(*CompareElement)(int,int);
public:
    //默认设置节点node是red，是因为更加容易符合红黑树特性
    /*1.节点是RED或者BLACK
     *2.根节点是BLACK
     *3.叶子节点(外部节点，空节点都是BLACK)
     *4.RED节点的子节点都是BLACK（RED节点的parent都是BLACK，从根节点到叶子节点的所有路径上不能有两个连续的RED节点）
     *5.从任意节点到叶子节点的所有路径上不能有2个连续的RED节点
     *
     */
    class RBNode:Node<E>{
    public:
        bool color = RED;
        RBNode(E element,Node<E>* parent):Node<E>(element,parent){
            
        }
        
    };
    
    //函数指针
    CompareElement compareBlock;
    RBTree<E>(){
        RBTree(nullstr);
    }
    
    RBTree<E>(CompareElement compareBlock):BBST<E>(compareBlock){
        
    }
    
    
    //染色方法
    Node<E>* color(Node<E> *node,bool color){
        if (node == nullptr) return node;
        ((RBNode *)node)->color = color;
        return node;
    }
    
    //染成红色
    Node<E>* red(Node<E>* node){
        return color(node,RED);
    }
    
    //染成黑色
    Node<E>* black(Node<E> *node){
        return color(node,BLACK);
    }
    
    //节点是否是黑色
    bool isBlack(Node<E> *node){
        return colorOf(node) == BLACK;
    }
    
    //节点是否是红色
    bool isRed(Node<E> *node){
        return colorOf(node) == RED;
    }
    //返回节点的颜色
    bool colorOf(Node<E> *node){
        return node == nullptr ? BLACK : ((RBNode*)node)->color;
    }
    
    
    Node<E>* createNode(E element,Node<E> *parent){
           RBNode *rbNode = new RBNode(element,parent);
           return (Node<E>*)rbNode;
       }
    
    //红黑树的添加一共有12中情况，
    /*
     
        红<-黑->红 4种，两个红左右各两个
        黑->红  3种(黑色左边，红色左右)
        红<-黑 3种(黑死右边，红色左右)
        黑 2种(黑色左黑色右)
     
     上面的已经包含了添加的所有情况，因为一开始添加节点的时候默认是红色，这种情况下只有性质4不满足，所以从上面的12中情况可以看到，默认有4中情况满足红黑树的性质4，分别是往Black节点添加左右元素，其中前面4种属于B树节点上溢的情况，后面4种是属于简单的旋转
     */
    void afterAdd(Node<E> *node){
        //因为上溢操作也是当做新添加的节点插入的，所以如果上升到根节点或者添加的是根节点的话，节点是要染成黑色的，所以这里有一个parent的判断
        Node<E>*parent = node->parent;
        if (parent == nullptr) {
            black(node);
            return;
        }
        
        //默认4种不用处理得情况，父节点是Black
        if (isBlack(parent)) return;
        
        //处理剩下8种情况
        //判断是否是上溢情况，判定条件是叔父节点是否是Red颜色
        Node<E> *uncle = parent->sibling();
        //祖父节点
        Node<E>*grand = red(parent->parent);//这部操作是统一调用grand染成红色这一个步骤，具体可以参考pdf文档
        if (isRed(uncle)) {//叔父节点是红色(B树节点上溢)
            black(parent);
            black(uncle);
            //把祖父节点当做是新添加的节点
            afterAdd(grand);
            return;
        }
        
        //来到这里说明叔父节点不是红色
        if (parent->isLeftChild()) {//L
            if (node->isLeftChild()) {//LL
                black(parent);
            }else{//LR
                black(node);
                this->rotateLeft(parent);
            }
            this->rotateRight(grand);
        }else{//R
            if (node->isLeftChild()) {//RL
                black(node);
                this->rotateRight(parent);
            }else{//RR
                black(parent);
            }
            this->rotateLeft(grand);
        }
        
    }
    
    
};

#endif /* RBTree_hpp */
