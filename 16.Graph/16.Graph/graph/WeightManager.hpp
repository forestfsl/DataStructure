//
//  WeightManager.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/14.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef WeightManager_hpp
#define WeightManager_hpp

#include <stdio.h>

class WeightManager {
public:
    int const compare(int w1,int w2){
        return w1 - w2;
    }
    
    int add(int w1, int w2){
        return w1 + w2;
    }
    
    int zero(){
        return 0;
    }
};

#endif /* WeightManager_hpp */
