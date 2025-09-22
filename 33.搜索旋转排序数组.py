#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#

# @lc code=start
class Solution:
    def get_k(self,nums):
        assert len(nums)>=2
        left=0
        right=len(nums)-1
        while left<right:
            mid=(left+right)//2
            if nums[mid]>=nums[0]:
                left=max(mid,mid+1)
                if nums[mid]>nums[mid+1]:
                    return mid
            else:
                right=min(mid,mid-1)
                if nums[mid-1]>nums[mid]:
                    return mid-1
        raise ValueError("did not return in while loop of get_k")
        
    def search(self, nums: List[int], target: int) -> int:
        if len(nums)==1:
            if nums[0]==target:
                return 0
            else:
                return -1
         
        def get_res(left,right,nums,target):
            while left<=right:
                mid=(left+right)//2
                if nums[mid]==target:
                    return mid
                if nums[mid]>target:
                    right=min(mid,mid-1)
                elif nums[mid]<target:
                    left=max(mid,mid+1)
            return -1
        if nums[0]<nums[-1]:
            res=get_res(0,len(nums)-1,nums,target)
            return res
        k=self.get_k(nums)
        # print(k)
        res=-1
        if target>=nums[0] and target<=nums[k]: # first big half
            # print("big half")
            res=get_res(0,k,nums,target)
        elif target>=nums[k+1] and target<=nums[-1]: # last small half
            # print("small half")
            res=get_res(k+1,len(nums)-1,nums,target)
        return res 
        
        
# @lc code=end

