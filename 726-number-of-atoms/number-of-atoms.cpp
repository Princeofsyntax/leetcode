class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push({});
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                map<string, int> top = stk.top();
                stk.pop();
                i++;
                int i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = i_start < i ? stoi(formula.substr(i_start, i - i_start)) : 1;
                
                for (auto &p : top) {
                    stk.top()[p.first] += p.second * multiplier;
                }
            } else {
                int i_start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = i_start < i ? stoi(formula.substr(i_start, i - i_start)) : 1;
                stk.top()[name] += count;
            }
        }
        
        map<string, int> &count = stk.top();
        string result;
        for (auto &p : count) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        
        return result;
    }
};