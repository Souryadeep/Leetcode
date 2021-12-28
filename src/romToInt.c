/*
	program: romToInt.c
	leetcode: https://leetcode.com/problems/roman-to-integer/
	A better solution would be to use a hashmap, in terms of time complexity
	The solution to that will be posted at a later time	
	
*/


#include <stdio.h>

struct romans{
    char rom;
    int val;
};
    
struct romans keytab[8] = {'\0',0,'I',1,'V',5,'X',10,'L',50,'C',100,'D',500,'M',1000};

struct pair{
    int val;
    int flag;
};

struct pair checkPos(char x, char y){

    int pos1;
    int pos2;
    struct pair result;

    for (int i=0;i<8;i++){

        if (keytab[i].rom == x)
            pos1 = i;
        if (keytab[i].rom == y)
            pos2 = i;
    }

    if(pos1 < pos2){
        result.flag = -1;
        result.val = keytab[pos1].val;
    }

    else{
        result.flag = 1;
        result.val = keytab[pos1].val;
    }

    return result;
}

int romanToInt(char * s){

    int result = 0;

    while(*s!='\0'){

        char romtemp = *s;
        char romtempnext = *(s+1);

        struct pair temppair = checkPos(romtemp,romtempnext);

        result = result + temppair.val * temppair.flag;

        s++;
    }

    return result;
}

int main(int argc,char *argv[]){

	char s[15];
	printf("Enter string: ");
	gets(s);

	int result = romanToInt(s);

	printf("Roman to numeral is: %d\n",result);


}
