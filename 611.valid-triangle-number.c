// @leet start
#include <stdlib.h>
int compare(const void *a, const void *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;
  return (x > y) - (x < y);
}
int triangleNumber(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int count = 0;
  for (int i = 2; i < numsSize; i++) {
    int left = 0, right = i - 1;
    while (left < right) {
      int s = nums[left] + nums[right];
      if (s > nums[i]) {
        count += (right - left);
        right--;
      } else {
        left++;
      }
    }
  }
  return count;
}
// @leet end
