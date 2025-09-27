// @leet start
#include <stdlib.h>
int lengthOfLongestSubstring(char *s) {
  // 记录每个字符上一次出现的位置，-1 表示没出现过
  int last[256];
  for (int i = 0; i < 256; i++)
    last[i] = -1;

  int ans = 0;
  int start = 0; // 当前无重复子串的起始位置
  for (int i = 0; s[i] != '\0'; i++) {
    unsigned char c = (unsigned char)s[i];
    // 如果该字符在当前窗口内出现过，就把窗口左端推进到上次位置的下一位
    if (last[c] >= start) {
      start = last[c] + 1;
    }
    last[c] = i;             // 更新最近位置
    int len = i - start + 1; // 窗口长度
    if (len > ans)
      ans = len; // 更新答案
  }
  return ans;
}
// @leet end
