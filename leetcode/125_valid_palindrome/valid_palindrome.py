import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp_str = re.sub("[^A-Za-z0-9]", "", s).lower()
        
        return temp_str == temp_str[::-1]