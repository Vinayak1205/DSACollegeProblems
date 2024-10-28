#include <stdio.h>
#define MAX 100
int queue[MAX];


void display(int *front,int *rear){


    if(*front == -1 &&  *rear == -1){
        printf("\nStack is Empty");
    }
    else{
        printf("\nQueue Contains: ");
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", queue[i]);
        }
        
    }
}

void delete(int *front,int *rear){

    if(*front==-1 && *rear == -1)
        printf("\nUnderflow");
    else
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }
    else
        (*front)++;
}

void insert(int *front,int *rear,int *val){

        if(*rear == MAX-1){
            printf("\nOverflow");
        }
        else
        if(*front == -1 && *rear == -1){
            *front = 0;
            *rear = 0;
            queue[*rear] = *val;
        }
        else{
            (*rear)++;
            queue[*rear] = *val;
        }
}



int main(){


    int front = -1,rear = -1;
    int val;
    int choice;
    int a;


    while(1){

        printf("\n1 For Insertion");
        printf("\n2 For Deletion");
        printf("\n3 For Display");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    printf("\nEnter the value to Insert: ");
                    scanf("%d",&val);
                    insert(&front,&rear,&val);
                    break;
            case 2:
                    delete(&front,&rear);
                    break;
            
            case 3:
                    display(&front,&rear);
                    break;

            default:
                    break;
        }

        printf("\nPress 1 to Continue...Press 0 to Stop: ");
        scanf("%d",&a);

        if(a == 0)
            break;
    }


    return 0;

}
