//
//  FileInfo.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef FileInfo_hpp
#define FileInfo_hpp

#include <stdio.h>
#include<string>
#include<map>
#include<fstream>
#include<iostream>
#include <set>
#include <list>
using namespace std;

#define FILE_NAME "/Users/forest/work/Shell/sdk_script/pythonMethod/lexicon1.txt"

class FileInfo {
public:
    static map<string,int> fetchWorld(){
        ifstream in(FILE_NAME);
        map<string,int> words;
        string temp;
        //输入
        while(in>>temp)
            ++words[temp];
        //输出
        cout<<"单词总个数:"<< words.size() <<endl;
         
        for(map<string,int>::iterator it = words.begin();it!=words.end();++it)
            cout<<it->first<<":"<<it->second<<endl;
        return words;
    }
    
    static list<string> fetchListWorld(){
        ifstream in(FILE_NAME);
              list<string> words;
              string temp;
              //输入
              while(in>>temp)
                  words.push_back(temp);
              //输出
              cout<<"单词总个数:"<< words.size() <<endl;
              return words;
    }
    static set<string> fetchSetWorld(){
           ifstream in(FILE_NAME);
                 set<string> words;
                 string temp;
                 //输入
                 while(in>>temp)
                     words.insert(temp);
                 //输出
                 cout<<"单词总个数:"<< words.size() <<endl;
                 return words;
       }
};

#endif /* FileInfo_hpp */
