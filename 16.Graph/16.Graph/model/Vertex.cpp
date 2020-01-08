//
//  Vertex.cpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#include "Vertex.hpp"



template <class V,class E>
int Vertex<V,E>::hashCode(int value){
    int hashCode = V::hashName(value);

    return hashCode ^ (hashCode >> 16);
}



template <class V,class E>
void Vertex<V,E>::funcA()
{
    
}
