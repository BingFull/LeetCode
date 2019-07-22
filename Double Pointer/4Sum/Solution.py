class Solution(object):
    def threeSum(self, nums, target):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []

        for i in range(len(nums)-3):
            target_i = target - nums[i]
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for left in range(i+1, len(nums)-2):
                mid  = left + 1
                right = len(nums) - 1
                tmp = target_i - nums[left]
                if left > i+1 and nums[left] == nums[left-1]:
                    continue
                while mid < right:
                    if nums[mid] + nums[right] == tmp:
                        temp_mid = nums[mid]
                        temp_right = nums[right]
                        result.append([nums[i], nums[left], nums[mid], nums[right]])
                        mid += 1
                        while mid < right and nums[mid] == temp_mid:
                            mid += 1
                            continue
                        right -= 1
                        while mid < right and nums[right] == temp_right:
                            right -= 1
                            continue
                    elif nums[mid] + nums[right] < tmp:
                        mid += 1
                    else:
                        right -= 1
        return result