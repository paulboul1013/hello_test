#include <iostream>
#include <cmath>
#include <vector>
#include <windef.h>
#include <algorithm>
#include <stdbool.h>
#include "Math.h"
#include "Math.cpp"





using namespace std;

void print_matrix(const Math::matrix_4x4 & out){
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<out.m[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-----------------"<<endl;

}

void print_v4(const Math::vector_4 &out){
    cout<<"vector of 4"<<endl;
    cout<<out.x<<endl;
    cout<<out.y<<endl;
    cout<<out.z<<endl;
    cout<<out.w<<endl;
    cout<<"-----------------"<<endl;

}

void print_v3(const Math::vector_3 &out){
    cout<<"vector of 3"<<endl;
    cout<<out.x<<endl;
    cout<<out.y<<endl;
    cout<<out.z<<endl;
    cout<<"-----------------"<<endl;

}

void print_v2(const Math::vector_2 &out){
    cout<<"vector of 2"<<endl;
    cout<<out.x<<endl;
    cout<<out.y<<endl;
    cout<<"-----------------"<<endl;
}


int main(){
   
    cout<<"hello"<<endl;

    Math::matrix_4x4 m4;
    Math::matrix_4x4 m4_4;

    Math::vector_2 v2(2.0,4.0);
    Math::vector_2 v2_2(8.0,6.0);
    Math::vector_2 v2_4(0.0,0.0);
    Math::vector_3 v3(1.0,32.0,44.0);
    Math::vector_3 v3_3(5.0,11.0,8.0);
    Math::vector_3 v3_temp(4.0,5.0,7.0);
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


    cout<<"m4"<<endl;

    m4.set_column(2,{3,3,3,4});
    m4.set_column(0,{4,4,1,7});
    m4.set_column(3,{6,7,7,5});
    print_matrix(m4);


    m4_4.set_row(1,{3,3,3,3});
    m4_4.set_row(2,{6,6,6,6});
    print_matrix(m4_4);

    Math::matrix_4x4 save_mul=Math::matrix_multiply(m4,m4_4);

    print_matrix(save_mul);

    Math::vector_4 save_temp_mul=Math::matrix_multiply(m4,v4);
    print_v4(save_temp_mul);
    

    print_matrix(m4);

    m4=Math::matrix_transpose(m4);


    print_matrix(m4);
    
    v2_4=Math::clamp(v2_4,v2,v2_2);


    print_v2(v2_4);


    v3_temp=Math::clamp(v3_temp,v3,v3_3);
    
    print_v3(v3_temp);


    

    return 0;
}