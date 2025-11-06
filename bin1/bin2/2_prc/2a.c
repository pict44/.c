#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void bubble_acs(int a[50],int n)
{
    int i,j,temp;
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void bubble_dcs(int a[50],int n)
{
    int i,j,temp;
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int pid;
    int i,n,a[50],j;
    printf("\nEnter the Number of elements:");
    scanf("%d",&n);
    printf("\nEnter List of Numbers:\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
    pid = fork();
    if(pid==0)

    {
         // printf("before terminating parent process\n");
        printf("I am child and my id is %d \n",getpid());
        printf("I am parent and my id is %d\n",getppid());
        // sleep(4);
        // printf("after terminating parent process\n");
        //system("ps -el|grep -w systemd");
        // system("ps -el|grep -w systemd");
        // printf("I am child and my id is %d \n",getpid());
        // printf("I am parent and my id is %d\n",getppid());
    }
    else
    {
        system("ps -el|grep Z");
        sleep(5);
        int i= wait(0);

        printf("The terminated child's pid is %d \n",i);
        printf("I am parent and my id is %d \n",getpid());
        printf("I am parent's parent and my id is %d",getppid());
        bubble_dcs(a,n);
        printf("\nList of Numbers in Descending Order:\n");
        for(j=0;j<n;j++)
        {
            printf("%d\n",a[j]);
        }
        // printf("Parent exiting immediately...\n");
        // exit(0);
    }

    return 0;
}
