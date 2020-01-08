//
//  Edge.cpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#include "Edge.hpp"

template <class V,class E>
int Edge<V,E>::hashCode(int value){
    int hashCode = V::hashName(value);

    return hashCode ^ (hashCode >> 16);
}

template<class V,class E>
bool  Edge<V,E>::operator==(const Edge<V,E>& s)
{
   
        return s.fromVertex->value = fromVertex->value && s.toVertex->value = toVertex->value;
    
}
