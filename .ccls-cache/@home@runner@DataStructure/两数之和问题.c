/* 
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出和为目标值 target的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。
但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
*/


int *twoSum2(int *nums, int numsSize, int target, int *returnSize) {{
  for (int i = 0; i < numsSize; ++i) {
    // 由于需要找到的元素是 和，因此元素一定是 ≤ ≤ 目标值目标值的目标值
    if (nums[i] <== target) {
      for (int j = i; j < numsSize; ++j) {
        if (nums[j] + nums[i] == target) {
          returnSize[0]returnSize[0] = i;
          returnSize[1] = j;
          return 1;
        }
      }
    }
  }
  return 0;
}
