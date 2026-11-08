//
// Created by sherman on 11/8/26.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum_0001(vector<int> &nums, int target) {
        unordered_map<int, int> m;

        for (auto i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (m.contains(nums[i])) {
                return vector<int>{m[nums[i]], i};
            }
            m[other] = i;
        }

        return vector{-1, -1};
    }

    ListNode *addTwoNumbers_0002(ListNode *l1, ListNode *l2) {
        auto *pre = new ListNode(0);
        auto *prob = pre;

        auto carry = 0;
        auto p1 = l1, p2 = l2;

        while (p1 || p2 || carry) {
            auto v1 = p1 ? p1->val : 0;
            auto v2 = p2 ? p2->val : 0;
            auto v = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;

            prob->next = new ListNode(v);

            prob = prob->next;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }

        return pre->next;
    }

    int lengthOfLongestSubstring_0003(string s) {
        int l = 0;
        int r = -1;
        int len = s.size();
        int maxLen = 1;
        unordered_map<char, int> freq;

        while (r + 1 < len) {
            if (r + 1 < len && !freq.contains(s[r + 1])) {
                freq[s[++r]]++;
            } else {
                char ch = s[l++];
                freq[ch]--;
                if (!freq[ch]) {
                    freq.erase(ch);
                }
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
