/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
*/

#include<stdlib.h>

// 快速排序算法
void quick_sort(int *nums, int left, int right) {
    int i, j, pivot;

    // 1. 递归出口：如果数组中元素个数小于等于1，则无需排序
    if (left >= right) return 0;

    // 2. 选择基准值，选取数组最左边元素作为基准值
    pivot = nums[left];
    i = left;
    j = right;

    while (1) {
      // 3. 从右往左扫描，找到第一个小于基准值的元素
      while (i < j && nums[j] >= pivot){
        j--;
      } 
      if(i<j){
        nums[i] = nums[j];
      }

      // 4. 从左往右扫描，找到第一个大于基准的元素
      while(i<j&& nums[i] <= pivot){
        i++;
      }
      if(i<j){
        nums[j] = nums [i];
      }

      // 5. 当两个扫描汇集的时候，退出循环
      if(i == j){
        break;
      }
    }

    // 将基准值放到分界点（即 i 和 j 的相遇点）
    nums[i] = pivot;

    // 递归处理左侧分区和右侧分区
    quick_sort(nums, left, i - 1);
    quick_sort(nums, i + 1, right);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
  for(int i = 0; i < nums2Size; ++i){
    nums1[m+i] = nums2[i];
  }
  quick_sort(nums1,0,nums1Size-1);

}