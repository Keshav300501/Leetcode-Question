class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> ans(nums.size());
        stack<int> nextGreaterStack;
        int pass = 0;
        while (pass < 2) {
            for (int i = (int) nums.size() - 1; i >= 0; i--) {
                if (nextGreaterStack.empty()) {
                    ans.at(i) = -1;
                    nextGreaterStack.push(nums.at(i));
                } else {
                    while (true) {
                        if (nextGreaterStack.empty()) {
                            ans.at(i) = -1;
                            nextGreaterStack.push(nums.at(i));
                            break;
                        } else if (nextGreaterStack.top() > nums.at(i)) {
                            ans.at(i) = nextGreaterStack.top();
                            nextGreaterStack.push(nums.at(i));
                            break;
                        } else {
                            nextGreaterStack.pop();
                        }
                    }
                }
            }
            pass++;
        }
        return ans;
    }
};