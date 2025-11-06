#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void bubble_ac(int *arr,int n){

    int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("[Parent] List of Array in Acending Order: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(int argc,char *argv[]){
    if(argc<3){
        fprintf(stderr,"Usability: %s <child program> <num1> <num2> \n",argv[0]);
        return 1;
    }

    int count=argc-2;
    int values[count];
    for(int i=0;i<count;i++){
        values[i]=atoi(argv[i + 2]);
    }

    bubble_ac(values,count);
    char *child_arg[argc];
    child_arg[0]=argv[1];

    for(int i=0;i<count;i++){
        child_arg[i+1]=malloc(12);
        sprintf(child_arg[i+1],"%d",values[i]);

    }
    child_arg[count+1]=NULL;
    pid_t pid=fork();

    if(pid==0){
    printf("[CHILD] Child PID is : %d\n",getpid());
    printf("[CHILD] Parent PID is: %d\n",getppid());
    execve(argv[1],child_arg,NULL);
    perror("execve failed");
    exit(EXIT_FAILURE);
    }
else if(pid>0){
  int i=  wait(0);

    printf("[PARENT] Terminated Childs PID is : %d\n[PARENT] The Parent PID is : %d\n",i,getpid());
}
else{
    perror("Fork failed");
    return 1;
}
for(int i=0;i<count;i++){
    free(child_arg[i+1]);
}
    return 0;
}
