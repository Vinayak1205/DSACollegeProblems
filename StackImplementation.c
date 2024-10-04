#include <stdio.h>
#include <stdlib.h>


int push(int *arr[],int n,int top,int ele){


    if(top == n-1){
        printf("\nStack is Full or Stack Overflow: ");
        return -1;
    }

    top++;
    int newTop = top;
    arr[top] = ele;

    printf("\nElement %d added to Stack ",ele);
    printf("\nCurrently Stack Contains: ");

     while(newTop != -1){

        printf("%d ",arr[newTop]);
        newTop--;
    }


    return top;

}


int pop(int *arr[],int top){


    if(top == -1){
        printf("Stack UnderFlow or Stack is Empty");
        return -1;
    }

    printf("\nElement %d popped to Stack",arr[top]);
    top--;
    int newTop = top;

     printf("\nCurrently Stack Contains: ");

     while(newTop != -1){

        printf("%d ",arr[newTop]);
        newTop--;
    }


    return top;

}

void display(int *arr[],int top){

    int newTop = top;


    printf("\nCurrently Stack Contains: ");
    while(newTop != -1){

        printf("%d ",arr[newTop]);
        newTop--;
    }
}

int main()
{
        int n;
        printf("Enter the size of stack: ");
        scanf("%d",&n);
        int arr[n];

        int top = -1;
        int choice;
        int ele;
        int flag;
        int res;
        while(1){

            printf("\nEnter 1 for PUSH");
            printf("\nEnter 2 for POP");
            printf("\nEnter 3 for DISPLAY");
            printf("\nEnter your Choice: ");
            scanf("%d",&choice);

            switch(choice){

                case 1:
                        printf("\nEnter the value: ");
                        scanf("%d",&ele);
                        res = push(arr,n,top,ele);
                        if(res != -1)
                            top++;
                        break;

                case 2:
                        res = pop(arr,top);
                        if(res != -1)
                            top--;
                        else
                            top = -1;
                        break;

                case 3:
                        display(arr,top);
                        break;
                default:
                        break;




            }

            printf("\nPress 1 to continue... Press 0 to Continue: ");
            scanf("%d",&flag);

            if(!flag)
                break;

        }

      return 0;
}
