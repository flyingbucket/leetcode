#
# @lc app=leetcode.cn id=410 lang=python3
#
# [410] 分割数组的最大值
#

# @lc code=start
class Solution:
    @staticmethod
    def reachable(nums,k,sum):
        current=0
        current_k=k
        res=False
        for i in range(len(nums)):
            current+=nums[i]
            if current_k>0:
                if current<=sum:
                    current+=nums[i]
                else:
                    current=0
                    current_k-=1
            else:
                break
        else:
            res=True
        return res
    def splitArray(self, nums: List[int], k: int) -> int:
        
# @lc code=end

