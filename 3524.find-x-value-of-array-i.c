// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
// (A*B)%k=((A%k)*(B%k))%k
long long *resultArray(int *nums, int numsSize, int k, int *returnSize) {
  *returnSize = k;
  long long *result = malloc(sizeof(long long) * k);
  if (!result) {
    return NULL;
  }
  for (int i = 0; i < k; i++)
    result[i] = 0;

  long long *dp = malloc(sizeof(long long) * k);
  if (!dp) {
    return NULL;
  }
  for (int i = 0; i < k; i++)
    dp[i] = 0;

  int remainer = nums[0] % k;
  result[remainer] += 1;
  dp[remainer] += 1;

  for (int i = 1; i < numsSize; i++) {
    long long *new_dp = malloc(sizeof(long long) * k);
    for (int i = 0; i < k; i++) {
      new_dp[i] = 0;
    }
    int re_new = nums[i] % k;
    result[re_new] += 1;
    new_dp[re_new] += 1;
    for (int j = 0; j < k; j++) {
      remainer = (re_new * j) % k;
      result[remainer] += dp[j];
    }
    for (int j = 0; j < k; j++) {
      remainer = (re_new * j) % k;
      new_dp[remainer] += dp[j];
      // 即使每轮初始化new_dp也应该用+=而不是=,
      // 因为多个j可能对应同一个remainer,应该累加而非覆盖
    }
    memcpy(dp, new_dp, sizeof(long long) * k);
    for (int i = 0; i < k; i++) {
      dp[i] = new_dp[i];
    }
    free(new_dp);
  }
  return result;
}
// @leet end
