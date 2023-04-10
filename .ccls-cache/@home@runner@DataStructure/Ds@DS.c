#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

int main() {
  int nums[] = {1, 2, 3, 3};
  printf("%d", containsDuplicate(nums, 3));

  return 0;
}

// 存在重复元素
// 给你一个整数数组 nums 。
// 如果任一值在数组中出现 至少两次 ，返回 true ；
// 如果数组中每个元素互不相同，返回 false 。
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
/*
// 给你一个整数数组 nums
// ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
// 返回其最大和。子数组 是数组中的一个连续部分。

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

//=> 时间复杂度不过关
int maxSubArray(int *nums, int numsSize) {
  int sum = 0;       // 相邻和
  int max = nums[0]; // 最大和
  int addNum = 0;    // 除本体外额外加的数字数目
  for (addNum = 0; addNum < numsSize; ++addNum) {
    for (int i = 0; i < numsSize - addNum; ++i) {
      for (int j = i; j <= i + addNum; ++j) {
        sum += nums[j];
      }
      if (sum > max) {
        max = sum;
      }
      sum = 0;
    }
  }
  return max;
}

// 思路：从第一个元素作为子序列的开始,
// 依次与后的元素相加,当相加的sum为正数时,继续 向后加,
// 因为一个正序列加上任意正数, 都可以让这个序列变得更大, 而如果加上一个负数 若
// 序列变为负数,那么这个序列继续加会 让待加的数变小,
// 因此直接让sum归零,从下一个待加的数开始新的序列 期间用 max
// 记录子序列和的最大值

// 1. 是否有可能最大子序列B,
// 出现在已经被舍弃的序列A中的中间部分(即B头与A头不重合)? 不能, A子序列
// 在最后一个数加上去之前任何时候都是一个 正序列,
// 如果在其中某段出现了一个最大子序列B, 那么B加上B头到A头的剩余前段部分,
// 只会变得更大. 这样依然是从 A序列开头 的一个序列, 这个序列一定会被max 捕捉到

// 2. 是否有可能最大子序列B  出现在已经被舍弃的序列A与已经被舍弃的序列C之间?
// 不能, 假设A序列 由a(前段),b1(中后段),负数T(最后一个加数)组成, 已知: a + b1 +
// T <0, a > 0 则: b1+T < 0 恒成立, 因此 B = b1+T+ b2 <
// b2(在C前段中的B序列),矛盾, 因此不成立.
int maxSubArray2(int *nums, int numsSize) {
  int max = nums[0]; //最大子数组和
  int sum = 0;       // 子序列和
  for (int i = 0; i < numsSize; i++) {
    sum = sum + nums[i];
    if (sum > max) {
      max = sum; // max 用来进行记录
    }
    if (sum <
        0) { // 当子序列和已经为负数, 再加会让待加的数变小, 因此直接归零, 舍弃
      sum = 0;
    }
  }
  return max;
}

// 给定一个整数数组 nums 和一个整数目标值 target，
// 请你在该数组中找出和为目标值 target的那两个整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。
// 但是，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。*/

/* 输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。*/

/*
int *twoSum2(int *nums, int numsSize, int target, int *returnSize) {
  int *res = (int *)malloc(2 * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < target) {
      for (int j = i; j < numsSize; ++j) {
        if (nums[j] + nums[i] == target) {
          res[0] = i;
          res[1] = j;
          *returnSize = 2;
          return res;
        }
      }
    }
  }
  return NULL;
}
*/