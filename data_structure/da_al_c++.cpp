#include <iostream>
#include <vector>

#include "intcell.h"

using namespace std;





int main(){

    IntCell m(33);
    m.write(5);
    cout<<"Cell contents: "<<m.read()<<endl;




    return 0;
}