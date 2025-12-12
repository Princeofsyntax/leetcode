class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        map<int,vector<vector<string>>> mp;
        vector<int> ans(n,0);
        vector<bool> isOffline(n,false);
        map<int,vector<int>> offline;

        for(auto it:events){
            int time=stoi(it[1]);
            int temp=1;
            if(it[0]=="OFFLINE") temp=0;
            if(mp[time].empty()) mp[time]=vector<vector<string>>(2);
            mp[time][temp].push_back(it[2]);
        }
      
        for(const auto &vc:mp){
            auto it=offline.begin();
            while(it!=offline.end() && it->first<=vc.first){
                for(auto el:it->second) isOffline[el]=false;
                it=offline.erase(it);
            }

            for(const auto &off:vc.second[0]){
                int id=stoi(off);
                offline[vc.first+60].push_back(id);
                isOffline[id]=true;
            }

            for(const auto &msg:vc.second[1]){
                if(msg=="HERE" || msg=="ALL"){
                    for(int i=0;i<n;i++){
                        if(msg=="ALL" || !isOffline[i]) ans[i]++;
                    }
                }else{
                    int i=0;
                    while(i<msg.size()){
                        i+=2;
                        int temp=0;
                        while(i<msg.size() && isdigit(msg[i])){
                            temp=(temp*10)+(msg[i]-'0');
                            i++;
                        }
                        ans[temp]++;
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};