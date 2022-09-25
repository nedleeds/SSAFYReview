#include <stdio.h>
#include <string.h>

int main(){

  char s[100];

  gets(s);

  char* pS = strtok(s, " ");

  while(pS != NULL){
    printf("%s\n", pS);
    pS = strtok(NULL, " "); // NULL !!
  }

  return 0; 
}
