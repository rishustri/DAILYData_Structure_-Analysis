#include<stdio.h>
#define MAX 100
int tree[MAX];

void insert(int index, int value){
    if(index>=MAX){
        printf("Tree is full\n");
        return;
    }
    tree[index]=value;
    
}
void display(){
int i;
printf("\nArray Representation of Tree:\n");
for(i=0; i<MAX; i++){
    if(tree[i]!=0)
    printf("%d",tree[i]);
    }
printf("\n");
}

//Main function
int main(){
    int n,i,value;
    for(i=0; i<MAX; i++)
    tree[i]=0;

    printf("Enter the elements of nodes: ");
    scanf("%d",&n);

    //Read the node values
    printf("Enter node values in level order:\n");
    for(i=0; i<n; i++){
        scanf("%d",&value);
        insert(i,value);
    }


    //Display the array
    display();
    printf("\nRoot node: %d",tree[0]);

    if(n>1)
    printf("\nLeft child of Root: %d",tree[1]);

    if(n>2)
    printf("\nRight child of Root: %d",tree[2]);
    return 0;

}