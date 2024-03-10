class Node{
public:
    char data;
    int count;
    Node(char d, int c){
       data = d;
       count = c;
    }
};

class compare{
public:
    bool operator()(Node a, Node b){
        return a.count < b.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //greedy approach
        //take max occuring character and try to fetch 2 at a time (at most 2 are only allowed w.r.t question)
        //create maxheap 
        priority_queue<Node, vector<Node>, compare>maxHeap;
        
        if(a > 0){
            Node temp('a',a);
            maxHeap.push(temp);
        }
        if(b > 0){
            Node temp('b',b);
            maxHeap.push(temp);
        }
        if(c > 0){
            Node temp('c',c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1){
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2){
                //add 2 times 
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else{
                //count is only 1 here
                ans += first.data;
                first.count--;
            }
            if(second.count >= 2 && second.count >= first.count){
                //add 2 times 
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else{
                //count is only 1 here
                ans += second.data;
                second.count--;
            }

            if(first.count > 0){
                maxHeap.push(first);
            }
            if(second.count > 0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size() == 1){
            Node temp = maxHeap.top();
            maxHeap.pop();
             if(temp.count >= 2){
                //add 2 times 
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else{
                //count is only 1 here
                ans += temp.data;
                temp.count--;
            }
        }
        return ans;
    }
};