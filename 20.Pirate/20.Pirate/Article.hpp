//
//  Article.hpp
//  20.Pirate
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Article_hpp
#define Article_hpp

#include <stdio.h>

struct Article{
public:
    int weight;
    int value;
    double valueDensity;
    Article(int weight,int value){
        this->weight = weight;
        this->value = value;
        this->valueDensity = value * 1.0 / weight;
    }
};

#endif /* Article_hpp */
