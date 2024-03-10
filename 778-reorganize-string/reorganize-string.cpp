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
    string reorganizeString(string s) {
     //map each character with its occurence(frequency)
     //create maxHeap of frequency and always take 2 element at a time to create ans (so that no adjacent element are same)
     //follow the step until the maxHeap become empty

     //create map
     int freq[26] = {0};
     for(int i = 0; i< s.length(); i++){
         char ch = s[i];
         freq[ch - 'a']++;  //maps to indices
     }
     
     priority_queue<Node, vector<Node>, compare>maxHeap;

     for(int i = 0; i<26; i++){
         if(freq[i] != 0){
             Node temp( i+'a', freq[i]);
             maxHeap.push(temp);
         }
     }
     string ans = "";
     while(maxHeap.size() > 1){
         //greater than 1 is used because we are fetching 2 elements at a time
         Node first = maxHeap.top();
         maxHeap.pop();
         Node second = maxHeap.top();
         maxHeap.pop();

         ans += first.data;
         ans += second.data;
         first.count--;
         second.count--;

         if(first.count != 0){
             maxHeap.push(first);
         }
         if(second.count != 0){
             maxHeap.push(second);
         }
     }
     if(maxHeap.size()==1){
         //one element is left behind
         Node temp = maxHeap.top();
         maxHeap.pop();
        if(temp.count == 1){
           ans += temp.data;
        }
        else{
            return "";
        }
     }
     return ans;
    }
};