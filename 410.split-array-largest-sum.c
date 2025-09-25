// @leet start
int splitArray(int *nums, int numsSize, int k) {

  int left = 0;
  int right = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > left) {
      left = nums[i];
    }
    right += nums[i];
  }

  while (left < right) {
    int mid = left + (right - left) / 2;
    int count = 1;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
      sum += nums[i];
      if (sum > mid) {
        count += 1;
        sum = nums[i];
      }
      if (count > k)
        break;
    }
    if (count > k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}
// @leet end
