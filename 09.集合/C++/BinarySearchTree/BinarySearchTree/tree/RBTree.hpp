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
#include "RBNode.hpp"

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
//    class RBNode:Node<E>{
//    public:
//        bool color = RED;
//        RBNode(E element,Node<E>* parent):Node<E>(element,parent){
//            
//        }
//         int id()
//        {
//           return 2;
//        }
//        
//    };
//    
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
        ((RBNode<E> *)node)->color = color;
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
        return node == nullptr ? BLACK : ((RBNode<E>*)node)->color;
    }
    
    
    Node<E>* createNode(E element,Node<E> *parent){
           RBNode<E> *rbNode = new RBNode<E>(element,parent);
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
    
    //删除节点，B数中删除元素删除的都是叶子节点，因为都是通过查找后继节点或者
//    前驱节点，从而删除的
    /*
     
           红<--------------黑-------------->红
         /   \                             /  \
        /     \                           /    \
    红<-黑->红   黑->红                  红<-黑     黑
   / \  |   / \ |    \                  /  |      |
   1  2 *  3  4 *     5                6   *      *
     数字代表删除节点是红色，*代表删除节点是黑色
     */
    void afterRemove(Node<E> *node){
        //如果删除的节点是红色
        //或者 用来取代删除节点的子节点是红色
        if (isRed(node)) {
            black(node);
            return;
        }
        Node<E> *parent = node->parent;
        //如果删除的是根节点
        if (parent == nullptr ) return;
        
        //如果删除的是黑色叶子节点(会产生下溢操作)
        //判断被删除的node是左还是右
        bool left = parent->left == nullptr || node->isLeftChild();
        Node<E>* sibling = left ? parent->right : parent->left;
        if (left) {//被删除的节点在左边，兄弟节点在右边
            if (isRed(sibling)) {//兄弟节点是红色
                //如果sibling是RED，则需将sibling染成BLACK，parent染成RED，进行旋转即可，于是又回到了sibling是BLACK的情况
                black(sibling);
                red(parent);
                this->rotateLeft(parent);
                //更换兄弟
                sibling = parent->right;
            }
            
//            处理完之后，兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                //兄弟节点没有一个红色子节点，父亲节点如果是黑的，还要像下跟兄弟合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    afterRemove(parent);
                }
            }else{
                //兄弟节点至少有一个红色子节点，向兄弟节点借元素
                //进行旋转操作，旋转之后的中心节点继承parent的颜色，旋转之后的左右节点染成BLACK
                //只有一个红色子节点，可能是左或者是右，如果兄弟节点的左边是黑色
                if (isBlack(sibling->right)) {
                    this->rotateRight(sibling);
                    sibling = parent->right;
                }
                color(sibling, colorOf(parent));
                black(sibling->right);
                black(parent);
                this->rotateLeft(parent);
            }
        }else{
            //被删除的节点在右边，兄弟节点在左边
            if (isRed(sibling)) { //兄弟节点是红色
                black(sibling);
                red(parent);
                this->rotateRight(parent);
                //更换兄弟
                sibling = parent->left;
            }
            //兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                //兄弟节点没有一个红色子节点，父节点需要向下跟兄弟节点合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    afterRemove(parent);
                }
            }else{//兄弟节点至少有一个红色子节点，向兄弟节点借元素
                //兄弟节点的左边是黑色，兄弟要先旋转
                if (isBlack(sibling->left)) {
                    this->rotateLeft(sibling);
                    sibling = parent->left;
                }
                color(sibling, colorOf(parent));
                black(sibling->left);
                black(parent);
                this->rotateRight(parent);
            }
        }
    }
    
    void subAfterRotate(Node<E> *grand,Node<E> *parent,Node<E> *child){
         
         this->afterRotate(grand,parent,child);
       
    }
};

#endif /* RBTree_hpp */
