#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k1,k2,k3,tmp;
    multiset<int>st;
    int arr[10001];
    cin>>t;
    while(t--){
        auto it = st.begin();
        cin>>n>>k1>>k2>>k3;
        arr[0] = 0;
        for(int i=0 ; i<n ; i++){
            cin>>tmp;
            if(i == 0){
                arr[i] = tmp;
            }else{
                arr[i] = arr[i-1]+tmp;
            }
            if(st.size() == k3){
                it = st.begin();
                if(*it < tmp){
                    st.erase(it);
                    st.insert(tmp);
                }
            }else{
                st.insert(tmp);    
            }
            if(st.size() == k3 && i != 0){
                it = st.begin();
                if(*it < arr[i]){
                    st.erase(it);
                    st.insert(arr[i]);
                }
            }else{
                if(i != 0)
                st.insert(arr[i]);    
            }
        }
        for(int i = 0 ; i<n-1 ; i++){
            for(int j=i+2 ; j<n ; j++){
                tmp = arr[j] - arr[i];
                if(st.size() == k3){
                    it = st.begin();
                    if(*it < tmp){
                        st.erase(it);
                        st.insert(tmp);
                    }
                }else{
                        st.insert(tmp);
                }
            }
        }
        int t1 =1;
        it = st.end() ;
        it--;
        for(int i = 0 ; i<st.size() ; i++){
            if(t1 == k1){
                cout<<*it<<" ";
            }
            if(t1 == k2){
                cout<<*it<<" ";
            }
            if(t1 == k3){
                cout<<*it<<" ";
            }
            t1++;
            it--;
        }
        cout<<endl;
        st.clear();
    }
}