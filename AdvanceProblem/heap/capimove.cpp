#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,n,tmp,u,vo;
    map<int,vector<int>>mp;
    vector<int>v,p;
    multimap<int,int,greater<int>>st;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0 ; i<n ; i++){
            cin>>tmp;
            st.insert(make_pair(tmp,i));
            p.push_back(tmp);
        }
        for(int i=0 ; i<n-1 ; i++){
            cin>>u>>vo;
            mp[u].push_back(vo);
            mp[vo].push_back(u);
        }
        auto it = st.begin();
        for(int i = 1 ; i<= n ; i++){
                v.push_back(i-1);
                it = st.find( p[i - 1] );
                st.erase(it);
            for(int j = 0 ; j<mp[i].size() ; j++){
                // if(it->first == p[mp[i][j]-1]){
                //     v.push_back(j);
                //     st.erase(it);
                // }
                v.push_back(mp[i][j]-1);
                it = st.find( p[mp[i][j] - 1] );
                st.erase(it);
            }
            if(st.size() == 0){
                cout<<"0 ";
            }else{
                it = st.begin();
                cout<<it->second + 1<<" ";
                for(int j=0 ; j<v.size() ; j++){
                    st.insert(make_pair(p[v[j]] , v[j]));
                }
                v.clear();
            }
        }
        cout<<endl;
        st.clear();
        mp.clear();
        p.clear();
    }
    
}