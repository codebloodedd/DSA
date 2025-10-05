class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #method 1
        # map = {} 

        # n = len(nums)

        # for i in nums:
        #     if i in map:
        #         return True
        #     else:
        #         map[i] = 1

        # return False 

        hashset = set()
        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)
        
        return False