class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        map_s = {}

        map_t = {}

        for i in s:
            if i in map_s:
                map_s[i] = map_s[i] + 1
            else: 
                map_s[i] = 1
        
        
        for i in t:
            if i in map_t:
                map_t[i] = map_t[i] + 1
            else: 
                map_t[i] = 1

        if len(map_s) != len(map_t):
            return False

        for key in map_s:
            if key not in map_t or (map_s[key] != map_t[key]):
                return False

        return True