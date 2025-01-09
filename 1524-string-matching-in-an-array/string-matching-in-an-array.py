class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        length = len(words)
        ret = set()
        for i in range(length):
            for j in range(i+1, length):
                if(len(words[i]) < len(words[j])):
                    if words[i] in words[j]:
                        ret.add(words[i])
                else:
                    if words[j] in words[i]:
                        ret.add(words[j])

        return list(ret)

            