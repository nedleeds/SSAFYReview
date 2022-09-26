#include <stdio.h>
#include <string.h>

int main(){

  char s[10001];
  char* pS[10001]={NULL};

  while(1){
    printf("lee.dh >> ");
    gets(s);

    // printf("%s\n", s);
    char* ptr = strtok(s, " ");

    while(1){
      // shoot -> 5 4 3 2 1
      if (strcmp(ptr, "shoot") == 0){
        char* ptr = strtok(NULL, " ");
        int idx = 0;
        char numStr[10001] = "";
        while(*ptr != NULL){
          numStr[idx++] = *ptr++;
        }
        for (int a=(int)(*numStr)-48; a>0; a--){
          printf("%d ", a);
        }
        printf("\n");
      }
      break;
    }
   
  }


  return 0;
}
