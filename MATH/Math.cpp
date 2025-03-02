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

Math::matrix_4x4 Math::matrix_multiply(const matrix_4x4 & leftmatrix,const matrix_4x4 & rightmatrix){
    Math::matrix_4x4 outmat;
    for(UINT i=0;i<4;i++){
        for(UINT j=0;j<4;j++){
            Math::vector_4 row_i=leftmatrix.m[i];
            Math::vector_4 column_j={rightmatrix.m[0][j],rightmatrix.m[1][j],rightmatrix.m[2][j],rightmatrix.m[3][j]};
            outmat.m[i][j]=Math::vec4_dot(row_i,column_j);
        }
    }
    return outmat;
}


Math::vector_4 Math::matrix_multiply(const matrix_4x4 &leftmatrix,const vector_4 &rightcolumnvec){
    Math::vector_4 outvec;

    outvec.x=leftmatrix.m[0][0]*rightcolumnvec.x+leftmatrix.m[0][1]*rightcolumnvec.y+leftmatrix.m[0][2]*rightcolumnvec.z+leftmatrix.m[0][3]*rightcolumnvec.w;
    outvec.y=leftmatrix.m[1][0]*rightcolumnvec.x+leftmatrix.m[1][1]*rightcolumnvec.y+leftmatrix.m[1][2]*rightcolumnvec.z+leftmatrix.m[1][3]*rightcolumnvec.w;
    outvec.z=leftmatrix.m[2][0]*rightcolumnvec.x+leftmatrix.m[2][1]*rightcolumnvec.y+leftmatrix.m[2][2]*rightcolumnvec.z+leftmatrix.m[2][3]*rightcolumnvec.w;
    outvec.w=leftmatrix.m[3][0]*rightcolumnvec.x+leftmatrix.m[3][1]*rightcolumnvec.y+leftmatrix.m[3][2]*rightcolumnvec.z+leftmatrix.m[3][3]*rightcolumnvec.w;

    return outvec;
}

Math::matrix_4x4 Math::matrix_translation(float dx,float dy,float dz){
    Math::matrix_4x4 outmatrix;
    outmatrix.set_matrix(
        {
            {1,0,0,dx},
            {0,1,0,dy},
            {0,0,1,dz},
            {0,0,0,1}
        }
    );

    return outmatrix;
}

Math::matrix_4x4 Math::matrix_rotation_x(float angle){
    Math::matrix_4x4 outmatrix;

    outmatrix.set_matrix({
        {1,0,0,0},
        {0,cos(angle),-sin(angle),0},
        {0,sin(angle),cos(angle),0},
        {0,0,0,0}
    });
    return outmatrix;
}


Math::matrix_4x4 Math::matrix_rotation_y(float angle){
    Math::matrix_4x4 outmatrix;

    outmatrix.set_row(0,{cos(angle),0,sin(angle),0});
    outmatrix.set_row(1,{0,1,0,0});
    outmatrix.set_row(2,{-sin(angle),0,cos(angle),0});
    outmatrix.set_row(3,{0,0,0,1});


    return outmatrix;

}

Math::matrix_4x4 Math::matrix_rotation_z(float angle){
    Math::matrix_4x4 outmatrix;

    outmatrix.set_row(0,{cos(angle),-sin(angle),0,0});
    outmatrix.set_row(1,{sin(angle),cos(angle),0,0});
    outmatrix.set_row(2,{0,0,1,0});
    outmatrix.set_row(3,{0,0,0,1});


    return outmatrix;

}

Math::matrix_4x4 Math::matrix_yaw_pitch_rolll(float yaw_y,float pitch_x,float roll_z){
    //旋轉角度
    matrix_4x4 matrix_rotate_x;
    matrix_4x4 matrix_rotate_y;
    matrix_4x4 matrix_rotate_z;


    matrix_rotate_x=matrix_rotation_x(pitch_x);
    matrix_rotate_y=matrix_rotation_y(yaw_y);
    matrix_rotate_z=matrix_rotation_z(roll_z);

    matrix_4x4 out_matrix;

    out_matrix=matrix_multiply(matrix_rotate_y,matrix_multiply(matrix_rotate_x,matrix_rotate_z));

    return out_matrix;

}

Math::matrix_4x4 Math::matrix_perspective_projection(float angle_y,float aspec_ratio,float near_planz,float far_planez){
    float term11=1.0f/(aspec_ratio*tanf(angle_y/2.0f));
    float term22=1.0f/ tanf(angle_y/2.0f);
    float term33=1.0f /(far_planez-near_planz);
    float term34=-near_planz/(far_planez-near_planz);

    matrix_4x4 out_matrix;
    out_matrix.set_row(0,{term11,0,0,0});
    out_matrix.set_row(1,{0,term22,0,0});
    out_matrix.set_row(2,{0,0,term33,term34});
    out_matrix.set_row(3,{0,0,1,0});

    return out_matrix;
}

Math::matrix_4x4 Math::matrix_transpose(const matrix_4x4 & inmatrix){
    Math::matrix_4x4 out_matrix=inmatrix;

    std::swap(out_matrix.m[0][1],out_matrix.m[1][0]);
    std::swap(out_matrix.m[0][2],out_matrix.m[2][0]);
    std::swap(out_matrix.m[0][3],out_matrix.m[3][0]);
    std::swap(out_matrix.m[2][1],out_matrix.m[1][2]);
    std::swap(out_matrix.m[3][1],out_matrix.m[1][3]);
    std::swap(out_matrix.m[3][2],out_matrix.m[2][3]);

    return out_matrix;
}

UINT clamp(UINT val,UINT min,UINT max){
    if (val>max)val=max;
    if (val<min)val=min;
    return val;
}

inline  float Math::clamp(float val,float min,float max){
    if (val>max) val=max;
    if (val<min) val=min;
    return val;
}

Math::vector_2 Math::clamp(const vector_2 &val,const vector_2 &min,const vector_2 &max){
    float x=clamp(val.x,min.x,max.x);
    float y=clamp(val.y,min.y,max.y);
    Math::vector_2 out({x,y});
    return out;
}

Math::vector_3 Math::clamp(const vector_3 &val,const vector_3 &min,const vector_3 &max){
    float x=clamp(val.x,min.x,max.x);
    float y=clamp(val.y,min.y,max.y);
    float z=clamp(val.z,min.z,max.z);
    Math::vector_3 out({x,y,z});
    return out;
}

BYTE Math::lerp(BYTE start,BYTE end,float t){
    return char(start*(1.0f-t)+end*t);
}

float Math::lerp(float start,float end,float t){
    return start*(1.0f-t)+end*t;
}

Math::vector_2 Math::lerp(const vector_2 & start,const vector_2 &end ,float t){
    return Math::vector_2(lerp(start.x,end.x,t),lerp(start.y,end.y,t));
}

Math::vector_3 Math::lerp(const vector_3 & start,const vector_3 &end ,float t){
    return Math::vector_3(lerp(start.x,end.x,t),lerp(start.y,end.y,t),lerp(start.z,end.z,t));
}

BOOL Math::intersect_ray_aabb(const vector_3 & raystart,const vector_3 & rayend,const bounding_box & box,vector_3 &outintersectpoint,BOOL testfrontside){
    
    Math::vector_3 dir=Math::vector_3(rayend)-raystart;
    bool bPlaneXY=(dir.z!=0);
    bool bPlaneXZ=(dir.y!=0);
    bool bPlaneYZ=(dir.x!=0);

    std::vector<std::pair<Math::vector_3,float>> intersectResult;

    auto func_isPointInArea= [](const vector_2 &p,const vector_2 &min,const vector_2 &max)->BOOL
    {
        if (p.x>=min.x&&p.x<=max.x&&p.y>=min.y&&p.y<=max.y){
            return TRUE;
        }else{
            return FALSE;
        }
    };


    //compute intersect point, add to list if intersect succeed
	auto func_intersect = [&](float t, const vector_2& min, const vector_2& max, vector_3 faceNorm, BOOL testfrontside)
	{
		//if testFrontSide==TRUE && ray come from the back
		if (Math::vec3_dot(faceNorm, rayend-raystart) > 0.0f && testfrontside == TRUE)
		{
			return;
		}

		if (t >= 0.0f && t <= 1.0f)
		{
			Math::vector_3 intersectPoint = lerp(raystart, rayend, t);

			if (func_isPointInArea(
				vector_2(intersectPoint.x, intersectPoint.y),
				vector_2(min.x, min.y),
				vector_2(max.x, max.y)
				) == TRUE)
			{
				intersectResult.push_back(std::make_pair(intersectPoint,t));
			}
		}
	};

	float t = 0.0f;
	//then test  6 faces of bounding box
	if (bPlaneXY)
	{
		//lerp ratio 
		t = (box.min.z - raystart.z) / dir.z;
		func_intersect(
			t, 
			vector_2(box.min.x, box.min.y), 
			vector_2(box.max.x, box.max.y),
			vector_3(0,0,-1.0f),testfrontside
			);

		t = (box.max.z - raystart.z) / dir.z;
		func_intersect(t, 
			vector_2(box.min.x, box.min.y), 
			vector_2(box.max.x, box.max.y),
			vector_3(0, 0, 1.0f), testfrontside
			);
	}

	if (bPlaneXZ)
	{
		//lerp ratio 
		t = (box.min.y - raystart.y) / dir.y;
		func_intersect(t, 
			vector_2(box.min.x, box.min.z), 
			vector_2(box.max.x, box.max.z),
			vector_3(0, -1.0f,0), testfrontside
			);

		t = (box.max.y - raystart.y) / dir.y;
		func_intersect(t, 
			vector_2(box.min.x, box.min.z), 
			vector_2(box.max.x, box.max.z),
			vector_3(0, 1.0f,0), testfrontside
			);
	}

	if (bPlaneYZ)
	{
		//lerp ratio 
		t = (box.min.x - raystart.x) / dir.x;
		func_intersect(t, 
			vector_2(box.min.y, box.min.z), 
			vector_2(box.max.y, box.max.z),
			vector_3(-1.0f, 0, 0), testfrontside
			);

		t = (box.max.x - raystart.x) / dir.x;
		func_intersect(t, 
			vector_2(box.min.y, box.min.z), 
			vector_2(box.max.y, box.max.z),
			vector_3(1.0f,0,0),testfrontside
			);
	}

	//no intersect point
	if (intersectResult.size() == 0)
	{
		outintersectpoint = { 0,0,0 };
		return FALSE;
	}
	else
	{
		//find the nearest intersect result
		UINT nearestPointIndex = 0;
		for (UINT i = 0;i < intersectResult.size();++i)
		{
			static float smallestRatio = intersectResult.at(0).second;
			if(intersectResult.at(i).second<smallestRatio)
			{
				smallestRatio = intersectResult.at(i).second;
				nearestPointIndex = i;
			}
		}

		//finish traversal, output nearest point
		outintersectpoint = intersectResult.at(nearestPointIndex).first;
		return TRUE;
	}

}