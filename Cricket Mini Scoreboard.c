#include<stdio.h>
#include<stdlib.h>
#define MAX 12

int stack_arr[MAX];
int top = -1;

void push(int runs_pb);
int pop();
int peek();
int isEmpty();
int isFull();
void display(int,int);

int main()
{
        int choice,runs_pb,wicket=0,ball_type,score=0;
        while(1)
        {
            printf("\n1.Normal Ball\n2.Wicket\n3.Wide/No Ball\n");
            printf("\nEnter the type of ball : ");
            scanf("%d",&ball_type);
            if(ball_type==3)
            {
            //score=score+1;
            push(1);
            display(score,wicket);
        }
            else
                if(ball_type==2)
        {
            wicket=wicket+1;
            push(0);
            display(score,wicket);
        }
            else
            {
            
                printf("\n1.Update score after ball is bowled.\n");
                printf("2.Over Completed.\n");
                printf("3.Display Score for last ball\n");
                printf("4.Display Score for the current over\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1 :
                        printf("\nRuns for last ball : ");
                        scanf("%d",&runs_pb);
                        if(runs_pb>6){
                            printf("\nRuns cannot be greater than 6. Please try again.\n");
                            break;
                        }
                        push(runs_pb);
                        break;
                 case 2:
                        printf("\nOver Completed ! Here's the scoreboard :");
                        display(score,wicket);
                        exit(1);
                        break;
                 case 3:
                        printf("\nScore for last ball : %d/%d\n", peek(),wicket );
                        break;
                 case 4:
                        display(score,wicket);
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }
        }

        return 0;

}

void push(int runs_pb)
{
        if( isFull() )
        {
                printf("\nOver Completed. Please restart the scoreboard program.\n");
                return;
        }
        top = top+1;
        stack_arr[top] = runs_pb;
}

int pop()
{
        int runs_pb;
        if( isEmpty() )
        {
                printf("\nNo balls have been bowled\n");
                exit(1);
        }
        runs_pb = stack_arr[top];
        top = top-1;
        return runs_pb;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nNo balls have been bowled\n");
                exit(1);
        }
        return stack_arr[top];
}

int isEmpty()
{
        if( top == -1 )
                return 1;
        else
                return 0;
}

int isFull()
{
        if( top == MAX-1 )
                return 1;
        else
                return 0;
}

void display(int score,int wicket)
{
        int i;
        if( isEmpty() )
        {
                printf("\nNo balls have been bowled\n");
                return;
        }
    printf("\nScore:\n\n");
        for(i=top;i>=0;i--)
        {
                printf("Ball %d : %d/%d\n",top-i+1, stack_arr[i],wicket);
                score=score+stack_arr[i];
                
        }
printf("\nThe total score after the last ball is : %d/%d",score,wicket);

        
        printf("\n");
}

