#include <stdio.h>
#include <stdlib.h>

int main() {

  // 1. 数组中是否有重复元素
  /*
  int nums[] = {1, 2, 3, 3};
  printf("containsDuplicate = %d\n", containsDuplicate(nums, 3));
  */

  // 2. 求出最大子序列和
  /*
  int nums2[] = {1, 3, 4, 6, 3, -4, -6};
  printf("maxSubArray2 = %d\n", maxSubArray2(nums2, 7));
  /*

  // 3. 两数之和
  /*
  int nums3[] = {2,7,11,15,1,0,4,5};
  int *returnSize = (int *)malloc(sizeof(int));
  int *res = twoSum2(nums3, 8, 5, returnSize);
  for(int i =0 ; i < 2;i++){
   printf("%d \n",res[i]);
  }
  printf("ReturnSize = %d",*returnSize);
  */
  
  // 4. 合并两个数组，并且排序
  /* 
  int nums4[] = {1,2,3,0,0,0};
  int nums5[] = {2,5,6};
  merge(nums4, 6, 3, nums5, 3, 3);
  for(int i = 0; i< 6;i++){
    printf("%d, ",nums4[i]);
  }
  */
  return 0;
}

