#include <stdio.h>

int main(){


	int n;
	long int fact=1;
	printf("enter the number: ");
	scanf("%d",&n);
	int i=n;
	while(i){
	
		fact=fact*i;
		i--;
	}
	printf("factorial of %d is %ld\n",n,fact);
	return 0;
	


}
