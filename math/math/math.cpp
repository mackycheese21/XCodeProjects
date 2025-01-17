//
//  math.cpp
//  math
//
//  Created by Jack Armstrong on 8/12/18.
//  Copyright © 2018 Jack Armstrong. All rights reserved.
//

#include "math.hpp"

namespace math{
    
    int sign(float a){
        if(a<0)return -1;
        if(a==0)return 0;
        return 1;
    }
    
    float abs(float a){
        return a<0?-a:a;
    }
    
    float min(float a,float b){
        if(a<b)return a;
        return b;
    }
    
    float max(float a,float b){
        if(a>b)return a;
        return b;
    }
    
    float lin_norm(float t,float a,float b) {
        return (t-a)/(b-a);
    }
    
    float lerp(float t,float a,float b) {
        return a+t*(b-a);
    }
    
    
    float clamp(float t,float a,float b) {
        if(t<a)return a;
        if(t>b)return b;
        return t;
    }
    
    bool is_in_range(float t,float a,float b) {
        return t==clamp(t,a,b);
    }
    
    float lin_remap(float t,float s1,float e1,float s2,float e2) {
        return lerp(lin_norm(t,s1,e1),s2,e2);
    }
    
    bool solve_quadratic(float a,float b,float c,float&r1,float&r2){
        float discr=b*b-4*a*c;
        if(discr<0)return false;
        else if(discr==0)r1=r2=-b/a/2;
        else{
            float q=sqrt(discr);
            r1=(-b-q)/2/a;
            r2=(-b+q)/2/a;
        }
        return true;
    }
}
