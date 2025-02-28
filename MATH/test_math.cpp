#include <iostream>
#include <cmath>
#include <windef.h>
#include "Math.h"
#include "Math.cpp"
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   
    cout<<"hello"<<endl;

    Math::matrix_4x4 m4();

    Math::vector_2 v2(2.0,4.0);
    Math::vector_2 v2_2(4.0,6.0);
    Math::vector_3 v3(2.0,4.0,6.0);
    Math::vector_3 axis(3.0,5.0,1.0);
    Math::vector_4 v4(5.0,6.0,3.0,3.0);
    Math::vector_4 v4_4(8.0,6.0,8.0,1.0);

    float save_v3_dot=Math::vec3_dot(v3,axis);
    cout<<"v3_dot:"<<save_v3_dot<<endl;
    

    Math::vector_3 save_v3(0,0,0);
    save_v3=Math::vec3_cross(v3,axis);
    cout<<"vec3_cross"<<endl;
    cout<<save_v3.x<<endl;
    cout<<save_v3.y<<endl;
    cout<<save_v3.z<<endl;

    cout<<Math::vec3_length(v3)<<endl;
    cout<<Math::vec3_length(axis)<<endl;

    cout<<"reflect vector"<<endl;
    save_v3=Math::vec3_reflect(v3,axis);
    cout<<save_v3.x<<endl;
    cout<<save_v3.y<<endl;
    cout<<save_v3.z<<endl;

    
    cout<<"vec4_dot:";
    cout<<Math::vec4_dot(v4,v4_4)<<endl;
    
    cout<<"vec4_length:";
    cout<<Math::vec4_length(v4)<<endl;
    

    return 0;
}