class Solution {
public:
         
    //here in next smaller we will store indices and in place of -1, we will store totalLength(as we want to calculate width)
    vector<int> nextSmaller(vector<int> &v)
    {
        stack<int> s;
        s.push(-1); 
        vector<int> ans(v.size());

        // right to left movement
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int curr = v[i];
            while ((s.top() != -1)  && (v[s.top()] >= curr))
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    //here in next smaller we will store indices and -1,(as we want to calculate width)
    vector<int> previousSmaller(vector<int> &v)
    {
        stack<int> s;
        s.push(-1); 
        vector<int> ans(v.size());

        // left to right movement
        for (int i = 0; i < v.size(); i++)
        {
            int curr = v[i];
            while ((s.top() != -1) && (v[s.top()] >= curr))
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& height) {
        int size = height.size();

    //step1: previous smaller element output
    vector<int>prev = previousSmaller(height);

    //step2: next smaller element output
    vector<int>next = nextSmaller(height);

    int maxArea = INT_MIN;

    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];
        if(next[i] == -1){
            next[i] = size; //because we do not need -1 in nextSmall, we need size value 
        }
        int width = next[i]-prev[i]-1;

        int area = length*width;
        maxArea = max(area,maxArea);
    }
    return maxArea;
  }

    int maximalRectangle(vector<vector<char>>& matrix) {
        //take help form largest rectangular area in histogram
        vector<vector<int>>v; //to take input of matrix as integer from character
        int n = matrix.size();//rows
        int m = matrix[0].size();//columns
        for(int i = 0; i<n ; i++){
            vector<int>t;
            for(int j = 0; j<m ;j++){
              t.push_back(matrix[i][j] - '0'); //converting to int
            }
            v.push_back(t);
        }

        int area = largestRectangleArea( v[0] );
        for(int i = 1; i<n; i++){
            for(int j=0; j<m ; j++){
                //lets update the current row with previous row
                if(v[i][j]) //v[i][j] is not 0
                {
                  v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};