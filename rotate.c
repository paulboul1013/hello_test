#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        int N, M;
        scanf("%d %d", &N, &M);
        int arr[N][N], direction=0, row=0, column=0, length=N, test=1, time=0;
        for(int j=0;j<N*N;j++) {
            arr[row][column]=j+1;
            test++;
            
            if(M==1)
                switch(direction) {
                    case 0:
                        column++;
                        break;
                    case 1:
                        row++;
                        break;
                    case 2:
                        column--;
                        break;
                    case 3:
                        row--;
                        break;
                }
            else if(M==2)
                switch(direction) {
                    case 0:
                        row++;
                        break;
                    case 1:
                        column++;
                        break;
                    case 2:
                        row--;
                        break;
                    case 3:
                        column--;
                        break;
                }

            if(test==length) {
                direction++;
                direction%=4;
                time++;
                test=1;
                if((time==3 && length==N) || (time==2 && length!=N)) {
                    length--;
                    time=0;
                }
            }
        }

        for(row=0;row<N;row++) {
            printf("%d", arr[row][0]);
            for(column=1;column<N;column++)
                    printf("%6d", arr[row][column]);

            printf("\n");
        }
        printf("\n");
    }
    return 0;
}