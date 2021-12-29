/*

	program: lcp.c
	leetcode longest common prefix in set of strings
	https://leetcode.com/problems/longest-common-prefix/

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longesetstr(char **strs,int strsSize){

	  int longest = 0;
	  for (int i=0;i<strsSize;++i){


	  if(longest < strlen(strs[i]))
	    longest = strlen(strs[i]);

	  }
	  return longest;
}

char * longestCommonPrefix(char ** strs, int strsSize){

	  int longest = longesetstr(strs,strsSize);

	  char lcp[longest+1];
	  char *retstr = lcp;

	  char* str1;
	  char* str2;



	  if (strsSize != 1){
	  str1 = *strs;
	  str2 = *(strs+1);
	  }
	  else if (strsSize == 1 && strcmp(*strs,"")!=0){
	  return *strs;
	  }
	  else{
	  return "";
	  }


	  int i=0;
	  while (*str1 && *str2){

	  if (*str1 == *str2)
	    lcp[i++] = *str1;
	  else
	    break;

	  str1++;
	  str2++;
	  }
	  lcp[i] = '\0';

	  for(i=2;i<strsSize;++i){

	  char *temp1 = strs[i];
	  char *temp2 = lcp;

	  int i=0;
	  while (*temp1 && *temp2){

	    if (*temp1 == *temp2)
		lcp[i++] = *temp1;
	    else
		break;

	    temp1++;
	    temp2++;
	  }
	  lcp[i] = '\0';
	  }

	  return retstr;
}

int main(int argc,char *argv[]){

	char* strs[] = {"flower","flow","flowership"};
	char* str = longestCommonPrefix(strs,3);

	printf("%s\n",str);
}
