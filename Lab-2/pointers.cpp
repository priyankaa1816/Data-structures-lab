#include<stdio.h>
#include <stdlib.h>
#include <math.h>
//function to check if the number is palindrome
int IsPalindrome(int*num){
    int*temp=(int*)malloc(sizeof(int));
    int*reverse=(int*)malloc(sizeof(int));

    *temp=*num;
    *reverse=0;

    while(*temp>0){
        *reverse=((*reverse)*10)+(*temp%10);
        *temp/=10;
    }
    if((*reverse)==(*num)){
        return 1;
    }
    free(temp);
    free(reverse);
    return 0;
}
//function to check if the number is Armstrong NUmber
int IsArmstrong(int*num){
    int*temp=(int*)malloc(sizeof(int));
    int*count=(int*)malloc(sizeof(int));
    int*sum=(int*)malloc(sizeof(int));

    *temp=*num;
    *count=0;
    *sum=0;

    while(*temp>0){
        *temp/=10;
        (*count)++;
    }
    *temp=*num;
    while(*temp>0){
        *sum+=pow((*temp)%10,*count);
        *temp/=10;
    }
    if((*sum)==(*num)){
        return 1;
    }
    free(temp);
    free(count);
    free(sum);
    return 0;
}

int IsPerfect(int*num){
    int*temp=(int*)malloc(sizeof(int));
    int*i=(int*)malloc(sizeof(int));
    int*sum=(int*)malloc(sizeof(int));

    *temp=*num;
    *sum=0;
    for((*i)=1;(*i)<=(*num)/2;(*i)++){
        if((*num)%(*i)==0){
            *sum+=(*i);
        }
    }
    if((*sum)==(*num)){
        return 1;
    }
    free(temp);
    free(i);
    free(sum);
    return 0;
}

int main(){
    int *choice=(int*)malloc(sizeof(int));
    int *num1=(int*)malloc(sizeof(int));
    *num1=0;
//Getting the user input
    while(1){
        printf("Menu: \n");
        printf("1.Palindrome Number\n");
        printf("2.Armstrong Number\n");
        printf("3.Perfect Number\n");
        printf("4.Exit\n");

        scanf("%d",choice);
        if(*choice==1){
            
            printf("Enter a number: \n");
            scanf("%d",num1);
            if(IsPalindrome(num1)){
                printf("The number is Palindrome.\n");
            }
            else{
                printf("The number is not Palindrome.\n");
            }
        }
        else if(*choice==2){
            printf("Enter a number: \n");
            scanf("%d",num1);
            if(IsArmstrong(num1)){
                printf("The number is Armstrong Number.\n");
            }
            else{
                printf("The number is not Armstrong Number.\n");
            }
        }    
        else if(*choice==3){
            printf("Enter a number: \n");
            scanf("%d",num1);
            if(IsPerfect(num1)){
                printf("The number is Perfect Number.\n");
            }
            else{
                printf("The number is not Perfect Number.\n");
            }
        }
        else if(*choice==4){
            printf("Exiting....\n");
            break;
        }
        else{
            printf("Invalid value. Please try again");
            continue;
        }

    }
    return 0;
}