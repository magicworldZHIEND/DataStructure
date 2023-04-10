#include <stdio.h>
#include <stdlib.h>

// 存在重复元素
// 给你一个整数数组 nums 。
// 如果任一值在数组中出现 至少两次 ，返回 true ；
// 如果数组中每个元素互不相同，返回 false 。
#define true 1
#define false 0
typedef int bool;

struct node {
  int data;
  int conut;
  struct node *next;
}; // 链表

bool containsDuplicate(int *nums, int numsSize) {
  // 1. 结构体指针申请容量
  struct node *temp = malloc(sizeof(struct node) * numsSize);

  // 2. 将链表初始化
  for (int i = 0; i < numsSize; i++) {
    temp[i].data = 0;
    temp[i].conut = 0;
    temp[i].next = NULL;
  }

  // 3. 使用哈希存储的方式将 数组中的元素存入到 链表中去
  //    此处的哈希函数为:
  //    abs(nums[i]%numsSize),这样存储的地址一定不会让指针越界,
  for (int i = 0; i < numsSize; i++) {
    // 如果 temp[abs(nums[i]%numsSize)].conut==0,说明这个位置没有元素
    if (temp[abs(nums[i] % numsSize)].conut == 0) {
      temp[abs(nums[i] % numsSize)].data = nums[i];
      temp[abs(nums[i] % numsSize)].conut++;
    }
    // 反之, 如果 temp[abs(nums[i]%numsSize)].conut !=0 说明此时的nums[i] 与
    // 过去某个数 与numsSize取余是相同的数
    else {
      struct node *p =
          &temp[abs(nums[i] % numsSize)]; // 取出目前在这个位置的元素
      struct node *prev = p;
      while (p != NULL) {
        if (p->data == nums[i]) // 比较, 如果它与nums[i]相等, 说明与之前有相同的
          return true;
        else {
          prev = p;    // prev 记录 null前的最后一个节点
          p = p->next; // p后移
        }
      }
      struct node *new = malloc(sizeof(struct node));
      new->data = nums[i];
      new->next = NULL;
      prev->next = new; // 因为prev 是null前最后一个节点
    }
  }

  free(temp);
  return false;
}
