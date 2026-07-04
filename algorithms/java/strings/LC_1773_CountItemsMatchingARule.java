// https://leetcode.com/problems/count-items-matching-a-rule/description/

import java.util.List;

public class LC_1773_CountItemsMatchingARule {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int i = getIndexOfRuleKey(ruleKey);
        int cnt = 0;

        for (var item: items) {
            if (item.get(i).equals(ruleValue)) {
                cnt++;
            }
        }

        return cnt;
    }

    private int getIndexOfRuleKey(String ruleKey) {
        return switch (ruleKey) {
            case "type" -> 0;
            case "color" -> 1;
            case "name" -> 2;
            default -> -1;
        };
    }
}
