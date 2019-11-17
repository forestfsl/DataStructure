//
//  BinaryTreeLevelOrderPrinter.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/11/16.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef BinaryTreeLevelOrderPrinter_hpp
#define BinaryTreeLevelOrderPrinter_hpp


#include <stdio.h>
#include <iostream>
#include "BinarySearchTree.hpp"
#include <string>
#include "Node.hpp"
#include <queue>

using namespace std;



template <class E>
class BinaryTreeLevelOrderPrinter{
public:
    static class LevelOrderNode{
    public:
        static class BSLevelInfo{
        public:
            int _leftX;
            int _rightX;
            BSLevelInfo(LevelOrderNode *leftNode,LevelOrderNode *rightNode){
                this->_leftX = leftNode->leftBound();
                this->_rightX = rightNode->rightBound();
            }
        };

        int _x;
        int _y;
        int _width;
        int _treeHeight;
        string _string;
        Node<E> *_btNode;
        BinarySearchTree<E> *tree;
        LevelOrderNode *_left;
        LevelOrderNode *_right;
        LevelOrderNode *_parent;
       
        static int const TOP_LINE_SPACE = 1;
        //尾字符的下一个位置
        int rightX(){
            return _x + _width;
        }
        //顶部方向字符的X
        int topLineX(){
            int delta = _width;
            if (delta % 2 == 0) {
                delta--;
            }
            delta >>= 1;
            if (_parent && this == _parent->_left) {
                return this->rightX() - 1 - delta;
            }else{
                return _x + delta;
            }
        }
        //右边界的位置(rightX或者右字符节点topLineX的下一个位置)
        int rightBound(){
            if (!_right) {
                return this->rightX();
            }else{
                return _right->topLineX() + 1;
            }
        }
        //左边界的位置(x 或者 左子节点dtopLineX)
        int leftBound(){
            if (!_left) {
                return _x;
            }else{
                return _left->topLineX();
            }
        }
        
        //x ~ 左边界之间的长度(包括z左边界字符)
        int leftBoundLength(){
            return _x + this->leftBound();
        }
        /**
         * rightX ~ 右边界之间的长度（包括右边界字符）
         */
        int rightBoundLength(){
            return this->rightBound() - this->rightX();
        }
        //左边界可以清空的长度
        int leftBoundEmptyLength(){
            return this->leftBoundLength() - 1 - TOP_LINE_SPACE;
        }
        //右边界可以清空的长度
        int rightBoundEmptyLength(){
            return this->rightBoundLength() - 1 - TOP_LINE_SPACE;
        }
        void translateX(int deltaX){
            if (deltaX == 0) return;
            _x += deltaX;
            //如果是LineNode
            if (!_btNode) return;
            if (_left) _left->translateX(deltaX);
            if (_right) _right->translateX(deltaX);
        }
        
        //让left和right基于this对称
        void balance(LevelOrderNode *left,LevelOrderNode *right){
            if (!left || !right) return;
             // 【left的尾字符】与【this的首字符】之间的间距
            int deltaLeft = _x - left->rightX();
             // 【this的尾字符】与【this的首字符】之间的间距
            int deltaRight = right->_x - this->rightX();
            int delta = max(deltaLeft,deltaRight);
            int newRightX = this->rightX() + delta;
            right->translateX(newRightX - left->_x);
            
            int newLeftX = _x - delta - left->_width;
            left->translateX(newLeftX - left->_x);
        }
        
        int treeHeight(LevelOrderNode *node){
            if (!node) return 0;
            if (node->_treeHeight) return node->_treeHeight;
            node->_treeHeight = 1 + max(this->treeHeight(node->_left),this->treeHeight(node->_right));
            return node->_treeHeight;
        }
        
        
        BSLevelInfo * levelInfo(int level){
            if (level < 0) return nullptr;
            int levelY = _y + level;
            if (level >= this->treeHeight(this)) return nullptr;
            vector<LevelOrderNode *>*list;
            
            queue<LevelOrderNode*> *queue;
            queue->push(this);
            while (queue->size()) {
                LevelOrderNode *node = queue->front();
                queue->pop();
                if (levelY == node->_y) {
                    list->push_back(node);
                }else if (node->_y > levelY) break;
                if (node->_left){
                    queue->push(node->_left);
                }
                if (node->_right) {
                    queue->push(node->_right);
                }
            }
            LevelOrderNode *left = list->front();
            LevelOrderNode *right = list->back();
            return BSLevelInfo(left, right);
        }
        int minLevelSpaceToRight(LevelOrderNode *right){
            int thisHeight = this->treeHeight(this);
            int rightHeight = this->treeHeight(this);
            int minSpace = INT_MAX;
            for (int i = 0; i < thisHeight && i < rightHeight; i++) {
                int space = (right->levelInfo(i))->_leftX - (this->levelInfo(i)->_rightX);
                minSpace = min(minSpace,space);
            }
            return minSpace;
        }

        LevelOrderNode(string string){
            if (string.size() == 0) {
                string = " ";
            }
            this->_string = string;
            this->_width = string.size();
        }
      
        LevelOrderNode(Node<E> *btNode,BinarySearchTree<E> *tree){
            LevelOrderNode(tree->nodeElement(btNode));
            this->_btNode = btNode;
        }
    };
    
    
    LevelOrderNode * _root;
    int _maxWidth;
    int _minX;
    BinarySearchTree<E>*tree;
    vector<vector<LevelOrderNode *> *> *_nodes;
    static int const MIN_SPACE = 1;
    BinaryTreeLevelOrderPrinter(BinarySearchTree<E> *tree){
        this->_root = LevelOrderNode(tree->rootNode(),tree);
        this->_maxWidth = this->_root->_width;
    }
    
    void _fillNodes(){
        //第一行
        vector<LevelOrderNode *>*firstRowNodes;
        firstRowNodes->push_back(_root);
        _nodes->push_back(firstRowNodes);
        
        //其他行
        while (true) {
            vector<LevelOrderNode *> *preRowNodes = _nodes->back();
            vector<LevelOrderNode *> *rowNodes;
            bool notNull = false;
            for (LevelOrderNode *node : preRowNodes) {
                if (node == nullptr || node == NULL) {
                    rowNodes->push_back(nullptr);
                    rowNodes->push_back(nullptr);
                }else{
                    LevelOrderNode *left = _addNode(rowNodes, this->tree->leftNode(node->_btNode));
                    if (left) {
                        node->_left = left;
                        left->_parent = node;
                        notNull = true;
                    }
                    LevelOrderNode *right = _addNode(rowNodes, this->tree->rightNode(node->_right));
                    if (right) {
                        node->_right = right;
                        right->_parent = node;
                        notNull = true;
                    }
                }
            }
            //全是null,就退出
            if (!notNull) break;
            _nodes->push_back(rowNodes);
        }
    }
    
    void _cleanNodes(){
        int rowCount = (int)_nodes->size();
        if (rowCount < 2) return;
        //最后一行的节点数量
        int lastRowNodeCount = _nodes->back()->size();
        //每个节点之间的间距
        int nodeSpace = _maxWidth + 2;
        //最后一行的长度
        int lastRowLength = lastRowLength * _maxWidth + nodeSpace * (lastRowNodeCount - 1);
        //空集合
        for (int i = 0; i < rowCount; i++) {
            vector<LevelOrderNode *>*rowNodes = _nodes[i];
            int rowNodeCount = (int)rowNodes->size();
            int allSpace = lastRowLength - (rowNodeCount - 1) * nodeSpace;
            int cornerSpace = allSpace / rowNodeCount - _maxWidth;
            cornerSpace >>= 1;
            int rowLength = 0;
            for (int j = 0; j < rowNodeCount; j++) {
                if (j) {
                    //每个节点之间的间距
                    rowLength += nodeSpace;
                }
                rowLength += cornerSpace;
                LevelOrderNode *node = rowNodes[j];
                if (node) {
                    //居中(由于奇偶数的问题，可能有1个符号的误差)
                    int deltaX = (_maxWidth - node->_width) >> 1;
                    node->_x = rowLength + deltaX;
                    node->_y = i;
                }
                rowLength += _maxWidth;
                rowLength += cornerSpace;
            }
            vector<LevelOrderNode *>*tempList;
            //删除所有的null
            for (int i = 0; i <rowNodes->size(); i++) {
                if (rowNodes[i] != nullptr || rowNodes[i] != NULL) {
                    tempList->push_back(rowNodes[i]);
                }
            }
            rowNodes->clear();
            rowNodes = tempList;
           
        }
    }
    
    LevelOrderNode *_addNode(vector<LevelOrderNode *>*nodes,Node<E>*btNode){
        LevelOrderNode *node = nullptr;
        if (btNode) {
            node = LevelOrderNode(btNode,this->_tree);
            _maxWidth = max(_maxWidth,node->_width);
            nodes->push_back(node);
        }else{
            nodes->push_back(nullptr);
        }
        return node;
    }
    
    void _addXLineNode(vector<LevelOrderNode *>*curRow,LevelOrderNode *parent,int x){
        LevelOrderNode *line = LevelOrderNode("-");
        line->_x = x;
        line->_y = parent->_y;
        curRow->push_back(line);
    }
    LevelOrderNode *_addLineNode(vector<LevelOrderNode *>*curRow,vector<LevelOrderNode *>*nextRow ,LevelOrderNode *parent, LevelOrderNode *child){
        if (!child) return nullptr;
        LevelOrderNode *top = nullptr;
        int topX = child->topLineX();
        if (child == parent->_left) {
            top = LevelOrderNode("┌");
            curRow->push_back(top);
            for (int x = topX + 1; x < parent->_x; x++) {
                _addXLineNode(curRow, parent, x);
            }
        }else{
            for (int x = parent->rightX(); x < topX; x++) {
                _addXLineNode(curRow, parent, x);
            }
            top = LevelOrderNode("┐");
            curRow->push_back(top);
        }
        //坐标
        top->_x = topX;
        top->_y = parent->_y;
        child->_y = parent->_y + 2;
        _minX = min(_minX,child->_x);
        
        //竖线
        LevelOrderNode *bottom = LevelOrderNode("|");
        bottom->_x = topX;
        bottom->_y = parent->_y + 1;
        nextRow->push_back(bottom);
    }
    void _addLineNodes(){
        vector<LevelOrderNode *>*newNodes;
        int rowCount =(int) _nodes->size();
        if (rowCount < 2 ) return;
        _minX = _root->_x;
        for (int i = 0; i < rowCount; i++) {
            vector<LevelOrderNode *>rowNodes = _nodes[i];
            if (i == rowCount - 1) {
                newNodes->push_back(rowNodes);
                continue;
            }
            vector<LevelOrderNode *>*newRowNodes;
            newNodes->push_back(newRowNodes);
            vector<LevelOrderNode *>lineNodes;
            newNodes->push_back(lineNodes);
            for (LevelOrderNode *node : rowNodes) {
//                  newRowNodes -->curRow 存放点内容是[┌ ----] lineNodes-->nextRow 存放内容是[|]
                _addLineNode(newRowNodes, lineNodes, node, node->_left);
                newRowNodes->push_back(node);
                _addLineNode(newRowNodes, lineNodes, node, node->_right);
            }
        }
        _nodes->clear();
        //转换完之后，最后_nodes 存放的是(MJLOLevelOrderNodePNode)(x,y,width,string)┌____111
        _nodes = newNodes;
    }
    
    string *printString(){
        
    }
    
};

#endif /* BinaryTreeLevelOrderPrinter_hpp */
