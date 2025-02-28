class circle{
    private:
        double girth;
        double area;
        double volume;
    public:
        int radius;
        int height;

        double get_area(){
            return radius*radius*3.14159;
        }

        double get_volume(){
            return get_area()*height;
        }

        double get_girth(){
            return radius * 2 * 3.14159;
        }
        int compare(circle c){
            int i=0;
            if (radius > c.radius){
                i=1;
            }else if (radius <c.radius){
                i=-1;
            }
            return i;
        }

        int compare_2(circle *pc){
            int i=0;
            if (radius > pc->radius){
                i=1;
            }else if (radius <pc->radius){
                i=-1;
            }
            return i;
        }
        int compare_3(circle &rc){
            int i=0;
            if (radius > rc.radius){
                i=1;
            }else if (radius < rc.radius){
                i=-1;
            }
            return i;
        }

        circle copy(){
            circle  c;
            c.radius=radius;
            return c;
        }

        void copy2(circle *c){
            c->radius=radius;
        }

        circle *copy3(circle *pc){
            pc->radius=radius;
            return pc;
        }

        circle & test(){
            circle c;
            return c;
        }
};