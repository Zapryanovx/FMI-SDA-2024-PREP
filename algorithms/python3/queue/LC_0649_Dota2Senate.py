# https://leetcode.com/problems/dota2-senate/description

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        r = []
        d = []

        for i in range(0, len(senate)):
            if senate[i] == 'R':
                r.append(i)
            else:
                d.append(i)

        while len(r) > 0 and len(d) > 0:
            radiant = r.pop(0)
            dire = d.pop(0)

            if radiant < dire:
                r.append(radiant + len(senate))
            else:
                d.append(dire + len(senate))

        return "Radiant" if len(r) > 0 else "Dire"