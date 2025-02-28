#include "Math.h"

float Math::vec2_dot(const vector_2& vec1,const vector_2& vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y;
}

float Math::vec2_length(const vector_2 &vec){
    return sqrtf(vec.x*vec.x+vec.y*vec.y);
}

float Math::vec3_dot(const vector_3 &vec1,const vector_3 &vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
}

Math::vector_3 Math::vec3_cross(const vector_3 &vec1,const vector_3 &vec2){
    return vector_3(vec1.y*vec2.z-vec1.z*vec2.x,
                    vec1.z*vec2.x - vec1.x*vec2.z,
		            vec1.x*vec2.y - vec1.y*vec2.x);
}

float Math::vec3_length(const vector_3 &vec){
    return sqrtf(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

Math::vector_3 Math::vec3_reflect(const vector_3 &vec,const vector_3& axis){
    Math::vector_3 in=vec;
    Math::vector_3 out=(-1)*in+2*(in-vec3_dot(in,axis)/in.length()*axis);
    return out;
}


float Math::vec4_dot(const vector_4& vec1,const vector_4 & vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z+vec1.w*vec2.w;
}

float Math::vec4_length(const vector_4 &vec){
    return sqrtf(vec.x*vec.x+vec.y*vec.y+vec.y*vec.y+vec.z*vec.z);

}
