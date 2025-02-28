#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

#define IN 1
#define OUT 0

struct node {
    int data;
    struct node *next;
};

int countnodes(struct node * node){
    int count=1;
    struct node * curr=node;
    while(curr->next!=node){
        count++;
        curr=curr->next;
    }
    return count;
}

int countnodesinloop(struct node *head){
    struct node *slow=head,*fast=head;
    
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast){
            return countnodes(slow);
        }

    }
    return 0;

}

struct node * createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void exec_1_9(){
        int c,nl=0;

    int count_blank=0;
    int tab_count=0;
    while((c=getchar())!=EOF){
       if (c==' '){
        count_blank++;
       }
       else if(c==9){
        tab_count++;
       }
       else if (c=='\n'){
        nl++;
       }
    }
    printf("%d\t%d\t%d\n",nl,count_blank,tab_count);
}

void exec_1_10(){

    char c;

    while((c=getchar())!=EOF){
        if (c==' '){
            c='@';
        }
        else if ((int)c==9){
            c='\t';
        }
        else if(c==' '){
            c='\b';
        }
        else if (c=='\\'){
            c='\\';
        }
        putchar(c);
    }

}

void exec_11(){

/* count lines, words, and characters in input */

    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}


void exec_1_12(){
    char c='0';

    while ((c=getchar())!=EOF){
        if (c==' '||c=='\n'||c=='\t'){
            putchar('\n');

        }else{
            putchar(c);
        }
        
    }
}


int power(int base,int n){
    int i,p;

    p=1;
    for(i=1;i<=n;i++){
        p=p*base;
    }

    return p;
}

int isspace(int c){
    return ((unsigned char )c==' '||(unsigned char )c=='\t'||
    (unsigned char )c=='n'||(unsigned char )c=='\r'
    ||(unsigned char)c=='\f'||(unsigned char)c=='\v');
    
}

#define MAXLINE 1000
int getline_2(char line[],int maxline);
void copy_2(char to[],char from[]);



int main(){

    int len;
    int max;
    char  line[MAXLINE];
    char longest[MAXLINE];

    max=0;
    while((len=getline_2(line,MAXLINE))>0){
        if (len>max){
            max=len;
            copy_2(longest,line);
        }
    }

    if (max>0){
        printf("%s",longest);
    }

    return 0;
}


int getline_2(char s[],int lim){
    int c,i;
    for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++){
        s[i]=c;
        if (c=='\n'){
            s[i]=c;
            i++;
        }
    }


    s[i]='\0';
    return i;
}

void copy_2(char to[],char from[]){
    int i;
    i=0;
    while((to[i]=from[i])!='\0'){
        ++i;
    }
    
}