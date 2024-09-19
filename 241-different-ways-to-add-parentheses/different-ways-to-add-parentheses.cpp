class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;

        for(int i = 0; i < expression.size(); i++){
            int ch = expression[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                vector<int>leftPart = diffWaysToCompute(expression.substr(0,i));
                vector<int>rightPart = diffWaysToCompute(expression.substr(i+1));

            for(const auto& left: leftPart){
                for(const auto& right: rightPart){
                    if(ch == '+'){
                        result.push_back(left+right);
                    }
                    else if(ch == '-'){
                        result.push_back(left-right);
                    }
                    else{
                        result.push_back(left*right);
                    }
                }
            }
        }

        }
            //base case
            if(result.size()==0){
                result.push_back(stoi(expression));
            }

        return result;
    }
};