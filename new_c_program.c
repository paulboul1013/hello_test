#include <stdio.h>
#include <string.h>



int main(){

    
    int total=0;
    int id;
    do{
        scanf("%d",&id);
        switch (id)
        {
            case 1:
            total+=90;
            break;
            case 2:
            total+=75;
            break;
            case 3:
            total+=89;
            break;

       
        }
    }while(id!=0);

    printf("total: %d\n",total);

    

    return 0;

}
