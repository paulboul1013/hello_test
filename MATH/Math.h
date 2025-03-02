#pragma once

namespace Math{

    const float const_p=3.1415926f; //圓周率

    struct vector_2{ //向量，裡面只有兩個元素

        float x;//element
        float y;

        vector_2(){};
        vector_2(float X,float Y){x=X;y=Y;};
        vector_2(const float column[2]){ //單一向量建構子
            x=column[0];
            y=column[1];
        }

        float length(){ //向量長度x*x+y*y後再開根號
            return sqrt(x*x+y*y);
        }

        vector_2 & normalize(){ //一般化
            float len=length();
            if (len!=0){
                x/=len;
                y/=len;
            }else{
                x=0.0f;
                y=0.0f;
            }
            return *this;
        }

        BOOL operator==(const vector_2 &vec){
            if (vec.x==x&&vec.y==y){
                return true;
            }else{
                return false;
            }
        }

        vector_2 operator+(const vector_2 &vec){
            return vector_2(x+vec.x,y+vec.y);
        }

        vector_2 operator-(const vector_2 &vec){
            return vector_2(x+vec.x,y-vec.y);
        }

        vector_2 & operator+=(const vector_2& vec){
            x+=vec.x;
            y+=vec.y;
            return *this;
        }

        vector_2 & operator-=(const vector_2& vec){
            x-=vec.x;
            y-=vec.y;
            return *this;
        }

        vector_2 operator*(float scale_factor){
            return vector_2(scale_factor*x,scale_factor*y);
        }

        friend vector_2 operator*(float scale_factor,const vector_2 &vec){
            return vector_2(scale_factor*vec.x,scale_factor*vec.y);
        }

        vector_2 & operator*=(const float scale_factor){
            x*=scale_factor;
            y*=scale_factor;
            return *this;
        }

    };


    struct vector_3
    {
        float x;
        float y;
        float z;
        vector_3(){};
        vector_3(float X,float Y,float Z){
            x=X;
            y=Y;
            z=Z;
        }
        vector_3(const float column[3]){
            x=column[0];
            y=column[1];
            z=column[2];
        }

        float length(){ //向量長度x*x+y*y後再開根號
            return sqrt(x*x+y*y+z*z);
        }

        vector_3 & normalize(){ //一般化
            float len=length();
            if (len!=0){
                x/=len;
                y/=len;
                z/=len;
            }else{
                x=0.0f;
                y=0.0f;
                z=0.0f;

            }
            return *this;
        }

        BOOL operator==(const vector_3 &vec){
            if (vec.x==x&&vec.y==y&&vec.z==z){
                return true;
            }else{
                return false;
            }
        }

        vector_3 operator+(const vector_3 &vec){
            return vector_3(x+vec.x,y+vec.y,z+vec.z);
        }

        vector_3 operator-(const vector_3 &vec)const{
            return vector_3(x-vec.x,y-vec.y,z-vec.z);
        }

        vector_3 & operator+=(const vector_3& vec){
            x+=vec.x;
            y+=vec.y;
            z+=vec.z;
            return *this;
        }

        vector_3 & operator-=(const vector_3& vec){
            x-=vec.x;
            y-=vec.y;
            z-=vec.z;
            return *this;
        }

        vector_3 operator*(float scale_factor){
            return vector_3(scale_factor*x,scale_factor*y,scale_factor*z);
        }

        friend vector_3 operator*(float scale_factor,const vector_3 &vec){
            return vector_3(scale_factor*vec.x,scale_factor*vec.y,scale_factor*vec.z);
        }

        vector_3 & operator*=(const float scale_factor){
            x*=scale_factor;
            y*=scale_factor;
            z*=scale_factor;
            return *this;
        }


        

    };

    struct vector_4
    {
        float x;
        float y;
        float z;
        float w;
        vector_4(){};
        vector_4(float X,float Y,float Z,float W){
            x=X;
            y=Y;
            z=Z;
            w=W;
        }

        vector_4(const float column[4]){
            x=column[0];
            y=column[1];
            z=column[2];
            w=column[3];
        }

      
        float length(){ //向量長度x*x+y*y後再開根號
            return sqrt(x*x+y*y+z*z);
        }

        vector_4 & normalize(){ //一般化
            float len=length();
            if (len!=0){
                x/=len;
                y/=len;
                z/=len;
                w/=len;
            }else{
                x=0.0f;
                y=0.0f;
                z=0.0f;
                w=0.0f;
            }
            return *this;
        }

        BOOL operator==(const vector_4 &vec){
            if (vec.x==x&&vec.y==y&&vec.z==z&&vec.w==w){
                return true;
            }else{
                return false;
            }
        }

        vector_4 operator+(const vector_4 &vec){
            return vector_4(x+vec.x,y+vec.y,z+vec.z,w+vec.w);
        }

        vector_4 operator-(const vector_4 &vec){
            return vector_4(x-vec.x,y-vec.y,z-vec.z,w-vec.w);
        }

        vector_4 & operator+=(const vector_4& vec){
            x+=vec.x;
            y+=vec.y;
            z+=vec.z;
            w+=vec.w;
            return *this;
        }

        vector_4 & operator-=(const vector_4& vec){
            x-=vec.x;
            y-=vec.y;
            z-=vec.z;
            w-=vec.w;
            return *this;
        }

        vector_4 operator*(float scale_factor){
            return vector_4(scale_factor*x,scale_factor*y,scale_factor*z,scale_factor*w);
        }

        friend vector_4 operator*(float scale_factor,const vector_4 &vec){
            return vector_4(scale_factor*vec.x,scale_factor*vec.y,scale_factor*vec.z,scale_factor*vec.w);
        }

        vector_4 & operator*=(const float scale_factor){
            x*=scale_factor;
            y*=scale_factor;
            z*=scale_factor;
            w*=scale_factor;
            return *this;
        }


    };

    
    struct matrix_4x4
    {
        float m[4][4];

        inline void set_row(UINT row,float new_row[4]){
            if (row<4){
                for(UINT i=0;i<4;i++){
                    m[row][i]=new_row[i];
                }
            }
        }

        inline void set_row(UINT row,float(&&new_row)[4]){
            if (row<4){
                for(UINT i=0;i<4;i++){
                    m[row][i]=new_row[i];
                }
            }
        }

        inline void set_column(UINT col,float new_col[4]){
            if (col<4){
                for (UINT i=0;i<4;i++){
                    m[i][col]=new_col[i];
                }
            }
        }

        inline void set_column(UINT col,float (&&new_col)[4]){
            if (col<4){
                for (UINT i=0;i<4;i++){
                    m[i][col]=new_col[i];
                }
            }
        }

        void identity(){
            set_row(0,{1,0,0,0});
            set_row(1,{0,1,0,0});
            set_row(2,{0,0,1,0});
            set_row(3,{0,0,0,1});

            
        }
        matrix_4x4(){
            identity();
        }

        inline void set_matrix(vector_4 (&&row)[4]){ //向量轉變矩陣
            for(UINT i=0;i<4;i++){
                m[i][0]=row[i].x;
                m[i][1]=row[i].y;
                m[i][2]=row[i].z;
                m[i][3]=row[i].w;
            }
        }
    };

    struct bounding_box{
        bounding_box(){
            max={1,1,1};
            min={0,0,0};
        }
        vector_3 max;
        vector_3 min;
    };

    extern float vec2_dot(const vector_2& vec1,const vector_2& vec2);

    extern float vec2_length(const vector_2 &vec);

    extern float vec3_dot(const vector_3 &vec1,const vector_3 &vec2);

    extern vector_3 vec3_cross(const vector_3 &vec1,const vector_3 &vec2);

    extern float vec3_length(const vector_3 &vec);

    extern vector_3 vec3_reflect(const vector_3 &vec,const vector_3& axis);

    extern float vec4_dot(const vector_4& vec1,const vector_4 & vec2);

    extern float vec4_length(const vector_4 &vec);

    extern matrix_4x4 matrix_multiply(const matrix_4x4&leftmatrix,const matrix_4x4 & rightmatrix);
 
    extern vector_4 matrix_multiply(const matrix_4x4 &leftmatrix,const vector_4 &rightcolumnvec);

    extern matrix_4x4 matrix_translation(float dx,float dy,float dz);

    extern matrix_4x4 matrix_rotation_x(float angle);
    
    extern matrix_4x4 matrix_rotation_y(float angle);

    extern matrix_4x4 matrix_rotation_z(float angle);

    extern matrix_4x4 matrix_yaw_pitch_rolll(float yaw_y,float pitch_x,float roll_z);

    extern matrix_4x4 matrix_perspective_projection(float angle_y,float aspec_ratio,float near_planz,float far_planez);

    extern matrix_4x4 matrix_transpose(const matrix_4x4 & inmatrix);

    extern UINT clamp(UINT val,UINT min,UINT max);

    extern float clamp(float val,float min,float max);

    extern vector_2 clamp(const vector_2 &val,const vector_2 &min,const vector_2 &max);

    extern vector_3 clamp(const vector_3 &val,const vector_3 &min,const vector_3 &max);

    extern BYTE lerp(BYTE start,BYTE end,float t);
    
    extern float lerp(float start,float end,float t);

    extern vector_2 lerp(const vector_2 & start,const vector_2 &end ,float t);

    extern vector_3 lerp(const vector_3 & start,const vector_3 &end ,float t);

    extern BOOL intersect_ray_aabb(const vector_3 & raystart,const vector_3 & rayend,const bounding_box & box,vector_3 &outintersectpoint,BOOL testfrontside);

}