//
//  Knapsack.hpp
//  20.Pirate
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Knapsack_hpp
#define Knapsack_hpp

#include <stdio.h>
#include "Article.hpp"
#include <algorithm>
#include <set>

/*
 有n件物品和一个最大承重为W的背包，每间物品的重量是w1,价值是v1,
 在保证总重量不超过W的前提下，将哪几个物品装入背包，可以使得背包的总价值最大
 注意:每个物品只有1件，也就是每个物品只能选择0件或者1件，因此称为0-1背包问题
 
 
 如果采取贪心策略，有3个方案
 - 价值指导，优先选择价值最高的物品放进背包
 - 重量指导：优先选择重量最轻的物品放进背包
 - 价值密度指导：优选选择价值密度最高的物品放进背包(价值密度=价值/重量)
 */

class Knapsack {
public:
    class comp{
    public:
        bool operator()(const Article &s1,const Article &s2){
            //1.return s2.value - s1.value; 价值主导
            //2.重量主导 return a1.weight - a2.weight
            //3.价值密度指导 a2.valueDensity - a1.valueDensity;
            return s2.value - s1.value;
        }
       
    };
    void testSelect1(){
        select("价值主导");
    }
    void select(string title){
        Article article1 =  Article(35, 10);
        Article article2 =  Article(30, 40);
        Article article3 =  Article(60, 30);
        Article article4 =  Article(50, 50);
        Article article5 =  Article(40, 35);
        Article article6 =  Article(10, 40);
        Article article7 =  Article(25, 30);

        set<Article,comp> articles;
        articles.insert(article1);
        articles.insert(article2);
        articles.insert(article3);
        articles.insert(article4);
        articles.insert(article5);
        articles.insert(article6);
        articles.insert(article7);

       
        int capacity = 150,weight = 0,value = 0;
        set<Article> selectedArticles;
        for(auto it=articles.begin();it!=articles.end();it++){
              if (weight < capacity) {

                  int newWeight = weight + it->weight;
                 if (newWeight <= capacity) {
                     weight = newWeight;
                     value += it->value;
//                     selectedArticles.insert(&it);
                 }
              }
           }
       
        
        cout << "【" << title << "】" << endl;
        cout << "总价值" << value << endl;
        for(typename set<Article>::iterator iter = selectedArticles.begin(); iter != selectedArticles.end(); iter++){
            cout << "Article [weight=" << iter->weight << ", value=" << iter->value << ", valueDensity=" << iter->valueDensity << "]" << endl;
        }
        cout << "----------------------------------" << endl;
    }
    
};

#endif /* Knapsack_hpp */
