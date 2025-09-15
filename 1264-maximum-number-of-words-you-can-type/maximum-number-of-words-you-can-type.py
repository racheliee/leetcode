class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        letters = list(brokenLetters)
    
        ret = len(words)
        for w in words:
            for l in letters:
                if l in w:
                    ret -= 1
                    break
        
        return ret