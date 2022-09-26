#include "run.h"
#include <string.h>

int main(){
  
  int aa=100;
  int aA=10;
  int B=1234;
  char* variables = "aa aA B"; 

  char s[10001];
  printf("명령: ");
  gets(s);
  char* ptr = strtok(s, " ");
  
  if (strcmp(ptr, "show")==0)
  {
    printf("저장된 변수명: %s\n", variables);
  }
  else if (strcmp(ptr, "echo")==0)
  {
      ptr = strtok(NULL, " ");
      if (strcmp(ptr, "aa")==0){
        printf("%s is %d\n", ptr, aa);
      }else if (strcmp(ptr, "aA")==0){
        printf("%s is %d\n", ptr, aA);
      }else if (strcmp(ptr, "B")==0){
        printf("%s is %d\n", ptr, B);
      }else{
        printf("[ERROR] Wrong Variable\n");
      }
  }


  return 0;
}
