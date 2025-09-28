#include <stdlib.h>
// @leet start
int compare(void const *a, void const *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;
  return (x < y) - (x > y);
}
int largestPerimeter(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int res = 0;
  for (int i = 0; i < numsSize - 2; i++) {
    int a = nums[i], b = nums[i + 1], c = nums[i + 2];
    if (a < b + c) {
      res = a + b + c;
      break;
    }
  }
  return res;
}
// @leet end
