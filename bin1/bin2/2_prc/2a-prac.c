#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void bubble_ac(int *a,int n)

{int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
        }
    }
}
void bubble_dc(int *a,int n){
    int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
            }
        }
    }



int main(){

    int n;
    printf("Enter Number of element you want to enter: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   int pid=fork();
if(pid==0){

    printf("before terminating parent\n");
    printf("I am child my PID is %d\n",getpid());
    printf("I am Parent my PID is %d\n",getppid());
 sleep(5);
    printf("after terminating parent\n");
    printf("I am child my PID is %d\n",getpid());
    printf("I am Parent my PID is %d\n",getppid());
}
else{
    // system("ps -el | grep Z");
    // sleep(5);
    // int i = wait(0);
    // printf("The PID of terminated child is: %d\n",i);
    // printf("I am parent and my PID is : %d\n",getpid());
    // printf("I am parents parent and my PID is : %d\n",getppid());
    bubble_dc(a,n);
    printf("List of arrays in Decending: ");
    for(int p=0;p<n;p++){
        printf("%d ",a[p]);
    }
    printf("\n");
    printf("terminating parent.............\n");
    exit(0);
}


    return 0;
}
