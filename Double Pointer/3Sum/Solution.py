class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for left in range(len(nums)):
            mid = left+1
            right = len(nums)-1
            if nums[left] > 0:
                break
            tmp = 0 - nums[left]
            if left > 0 and nums[left] == nums[left-1]:
                continue
            while mid < right:
                if nums[mid] + nums[right] == tmp:
                    temp_mid = nums[mid]
                    temp_right = nums[right]
                    result.append([nums[left], nums[mid], nums[right]])
                    mid += 1
                    while mid < right and nums[mid] == temp_mid:
                        mid += 1
                        continue
                    right -= 1
                    while mid < right and nums[right-1] == temp_right:
                        right -= 1
                        continue
                elif nums[mid] + nums[right] < tmp:
                    mid += 1
                else:
                    right -= 1
        return result