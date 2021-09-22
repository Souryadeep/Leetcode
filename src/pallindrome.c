/*
Leetcode math palindrome problem.

Analysis from leetcode:
Runtime: 46 ms, faster than 5.15% of C online submissions for Palindrome Number.
Memory Usage: 5.8 MB, less than 71.99% of C online submissions for Palindrome Number.
*/


#include <stdio.h>
#include <string.h>     //for strcmp
#include <stdbool.h>    //for bool data type
#include <stdlib.h>     

bool isPalindrome(int);

void main(int argc, char *argv[]){

    bool x;
    x = isPalindrome(121);

    if(x)
        printf("Is a pallindrome\n");
    else
        printf("Not a pallindrome\n");

}

bool isPalindrome(int x){

    
    int MAXLENGTH = 100; //assume that number of digits is not >100
    char s[MAXLENGTH];
    int i=0;
    int sign=x;
    
    do{
        s[i++]=abs(x%10) + '0';
    }while(x/=10);
    
    if (sign<0)
        s[i++]='-';
    
    s[i]='\0';
    printf("%s\n",s);
    
    //if x is 1234, s[] will not contain 4321\0
    //reverse the string s[]
    
    char reversed[MAXLENGTH];
    
    char *t = s + strlen(s) - 1;    //start from last character of string s and place in reversed array
    
    for (int i=0;i<strlen(s);i++){
        printf("%c\n",*t);
        reversed[i] = *t--;
    }
    reversed[i]='\0';

    if (strcmp(s,reversed)==0)
        return true;
    else
        return false;
}