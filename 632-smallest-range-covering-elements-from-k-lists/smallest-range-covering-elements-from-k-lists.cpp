class Node{
    public:
        int data;
        int row;
        int col;
        Node(int val, int r, int c){
          data = val;
          row = r;
          col = c;
        }
};
class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        //use minHeap as elements are in increasing order and minHeap will be optimal
        priority_queue<Node*,vector<Node*>,compare>minHeap;
        int k = nums.size();
        for(int i = 0; i < k; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new Node(element,i,0));
        }

        //range is to be returned
        int ansStart = mini;
        int ansEnd = maxi;

        while(!minHeap.empty()){
            Node* top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            //mini upadat
            mini = topElement;
            //chech for answer
            if(maxi-mini < ansEnd-ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }

            //check for new element in the same list
            if(topCol+1 < nums[topRow].size()){
                maxi = max(maxi,nums[topRow][topCol+1]);
                Node* newNode = new Node(nums[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(newNode);
            }
            else{
                //let there is no element next to the list(any of the list)
                break; //as we have to find range 
            }

        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};