class Solution(object):
    def threeSum(self, nums, target):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        min_sum = nums[0] + nums[1] + nums[2]
        if len(nums) < 3:
            return 0
        for left in range(len(nums)-2):
            mid = left+1
            right = len(nums)-1
            while mid < right:
                tem_sum = nums[mid] + nums[right] + nums[left]
                if tem_sum == target:
                    return tem_sum
                elif abs(tem_sum - target) < abs(target - min_sum):
                    min_sum = tem_sum
                elif tem_sum < target:
                    mid += 1
                else:
                    right -= 1
        return min_sum