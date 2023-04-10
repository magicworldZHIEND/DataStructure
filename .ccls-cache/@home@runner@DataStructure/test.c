#include <stdio.h>

int main(void) {
  printf("this is my first project");

  printf("How about update?\n");


  int num[4] = {1,2,3,4};

  int max,x;
  for(int i = 0;i<4;i++){
    max = num[i];
    x = i;
    for(int j = i;j<4;j++){
      if(num[j] > max){
        max = num[j];
        x = j;
        
      }
    }

    if(x != i){
      int temp = num[i];
      num[i] = num[x];
      num[x] = temp;
    }
  }

  for(int i =0 ; i<4;i++){
    printf("num [%d] = %d ",i,num[i]);
  }
  

  return 0;
}