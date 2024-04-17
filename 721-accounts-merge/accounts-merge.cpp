class Solution {
public:
    int findparent(vector<int> &parent, int node)
        {
            if (parent[node] == node)
            {
                return node;
            }
            return parent[node] = findparent(parent, parent[node]); // path compression by storing parent[node] so that it can be used later// recursion to reach main parent node (whose parent is node itself)
        }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
        {
            u = findparent(parent, u);
            v = findparent(parent, v);
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                // increase rank of parent
                rank[v]++;
            }
            else
            {
                // when individual node present or other condition of "if"
                parent[v] = u;
                rank[u]++;
            }
        }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //We will use disjoint sets
        //we will map each id with index(name) and when same id will come we will merge it
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        unordered_map<string, int>mp;
        for(int i = 0; i < n; i++){
            auto account = accounts[i];
            //0th index is name (no need) and from 1 is mail id's
            for(int j = 1; j < account.size(); j++){
                string&mail = account[j];
                auto it = mp.find(mail);
                if(it == mp.end()){
                    //not found
                    //push in map
                    mp[mail] = i; //index as a reference for name
                }
                else{
                    //when found
                    //same mail but different index or name --> merge them
                    unionSet(i, it->second, parent, rank);
                }
            }
        }
        //we will create another map to map index to all mails (int, set); set used so that mail can be in sorted order
        //Then push them in vector to return ans
        unordered_map<int, set<string>> preAns;
        for(auto it : mp){
            int accountNo = it.second;
            auto mail = it.first;
            accountNo = findparent(parent, accountNo); //as we have merged 
            preAns[accountNo].insert(mail);
        }
        vector<vector<string>>ans;
        for(auto it : preAns){
            auto accountNo = it.first;
            auto st = it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]); //pushing name
            for(auto mails : st){
               v.push_back(mails);
            }
            ans.push_back(v);
        }
        return ans;
    }
};