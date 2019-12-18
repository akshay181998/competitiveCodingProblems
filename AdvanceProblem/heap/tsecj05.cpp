#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,k,res,tmp;
    multiset<int,greater<int>>st1;
    multiset<int>st2;
    multiset<int> :: iterator it2;
    multiset<int,greater<int>> :: iterator it1;
    cin>>t;
    while(t--){
        cin>>k>>n;
        for(int i=0 ; i<n ; i++){
            cin>>tmp;
            if(i<k-1){
                cout<<"-1 ";
                st1.insert(tmp);
            }else if(k-1 == i){
                st1.insert(tmp);
                it1 = st1.end();
                it1--;
                cout<<*it1<<" ";
            }else{
                st2.insert(tmp);
                it2 = st2.end();
                it1 = st1.end();
                it1--;
                it2--;
                if(*it1 < *it2){
                    int v1 = *it1;
                    int v2 = *it2;
                    st2.erase(it2);
                    st1.erase(it1);
                    st2.insert(v1);
                    st1.insert(v2);
                }
                it1 = st1.end();
                it1--;
                cout<<*it1<<" ";
            }
        }
        cout<<endl;
        st1.clear();
        st2.clear();
    }
}