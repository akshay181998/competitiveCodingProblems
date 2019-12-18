#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x,op,p=0,m,var1,var2;
    multiset<int>st;
    multiset<int,greater<int>>st2;
    multiset<int> :: iterator it;
    multiset<int,greater<int>> :: iterator it2;
    cin>>n;
    while(n--){
        if(cin>>op,op == 1){
            cin>>x;
            st.insert(x);
            p++;
            if(p % 3 == 0){
                it = st.end();
                it--;
                // cout<<*it<<" ";
                st2.insert(*it);
                st.erase(it);
            }else if(p > 3){
                it = st.end();
                it--;
                it2 = st2.end();
                // it--;
                it2--;
                if(*it2 < *it){
                    var1 = *it;
                    var2 = *it2;
                    // st2.insert(*it);
                    // st.insert(*it2);
                    st2.erase(it2);
                    st.erase(it);
                    st2.insert(var1);
                    st.insert(var2);
                }
            }
            // if(p % 3 == 0 && p != 3){
            //     it++;
            // }
        }else{
            if(p < 3){
                cout<<"No reviews yet\n";
            }else{
                it2 = st2.end();
                it2--;
                cout<<*it2<<endl;
            }
        }
    }
}