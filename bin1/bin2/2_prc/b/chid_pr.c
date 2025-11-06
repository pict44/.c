#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void bubble_dc(int *arr,int n){

    int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("[CHILD] List of Array in Dcending Order: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(int argc,char *argv[]){
    if(argc<2){
        fprintf(stderr,"Usability: %s <child program> <num1> <num2> \n",argv[0]);
        return 1;
    }

    int count=argc-1;
    int values[count];
    for(int i=0;i<count;i++){
        values[i]=atoi(argv[i+1]);
    }

    bubble_dc(values,count);
    return 0;

}
