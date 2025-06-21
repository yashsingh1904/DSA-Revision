
    class DisjointSet {

        vector<int> par, rank, size;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            par.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i < n + 1; i++)
                par[i] = i;
        }

        // creating function for ultimate parets
        int findUP(int node) {

            if (node == par[node])
                return node;

            return par[node] = findUP(par[node]);
        }

        // union by rank
        
        void unionBySize(int u, int v) {
            int UP_u = findUP(u);
            int UP_v = findUP(v);

            // if belong to same coponent
            if (UP_u == UP_v)
                return;

            if (size[UP_u] > size[UP_v]) {
                // v is smaller one
                par[UP_v] = par[UP_u];
                size[UP_u] += size[UP_v];
            }

            else if (size[UP_u] < size[UP_v]) {
                // v is smaller one
                par[UP_u] = par[UP_v];
                size[UP_v] += size[UP_u];
            } else {
                par[UP_v] = par[UP_u];
                size[UP_u] += size[UP_v];
            }
        }
    };


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;

        //letd do mappimg 
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];

                //ignored j=0 because at j =0 we have names but here we need emails only 
                if(mpp.find(mail)!=mpp.end()){
                    //already found this mail earlier need to merge these two account 
                    ds.unionBySize(i,mpp[mail]);
                }
                else{
                    mpp[mail]=i;
                }
                
            }
        }


        //till now we have stored all the mails in the map
        vector<vector<string>>mergedmail(n);
        for(auto it : mpp){
            string curr_mail=it.first;
            int node=it.second;

            mergedmail[ds.findUP(node)].push_back(curr_mail);
        }


        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(!mergedmail[i].size()) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);//first string will be name 
            sort(mergedmail[i].begin(),mergedmail[i].end());
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }



        return ans;
    }
};
