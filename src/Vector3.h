//
//  Vec.h
//  MyFramework
//
//  Created by Mathijs Hoving on 19/11/2018.
//

#ifndef Vec_h
#define Vec_h

using namespace std;

class Vector3 {
public:
    Vector3();
    Vector3(float x_, float y_, float z_);
    
    void Add(Vector3 a);
    
    void Subtract(Vector3 s);
    
    void ScalarMultiplication(float m);
    
    float Mag();
    
    void Normalize();
    
    float Dot(Vector3 d);
    
    void Lerp(Vector3 l, float t);
    
    float x;
    float y;
    float z;
};

#endif /* Vector3_h */
