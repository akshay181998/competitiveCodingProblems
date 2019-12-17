#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
	int t,n,tmp,tmp2,sz;
	vector<int>v,tmpVector,k;
	multiset<int>h;
	cin>>t;
	while(t--){
	    cin>>n;
	    sz = pow(2,n);
    	for(int i=0 ; i<sz ; i++){
    	    cin>>tmp;
    	    h.insert(tmp);
    	}
    	auto it = h.begin();
    	tmp = *it;
   //  	cout<<tmp<<" "<<v.size()<<endl;
    	h.erase(it);
    	while(v.size() != n){
    	    it = h.begin();
    	    tmp = *it;
    	    h.erase(it);
    	 //  cout<<tmp<<" "<<v.size()<<endl;
    	    for(int i=0 ; i<tmpVector.size() ; i++){
    	        tmp2 = tmp + tmpVector[i];
    	        k.push_back(tmp2);
    	        it = h.find(tmp2);
    	       // cout<<*it<<" ";
    	        h.erase(it);
    	    }
    	    //cout<<endl;
    	    for(int i=0 ; i<k.size() ;  i++){
    	        tmpVector.push_back(k[i]);
    	       // cout<<k[i]<<" ";
    	    }
    	    k.clear();
    	    tmpVector.push_back(tmp);
    	    v.push_back(tmp);
    	}
    	for(int i=0 ; i<v.size() ; i++){
    	    cout<<v[i]<<" ";
    	}
    	cout<<endl;
    	k.clear();
    	v.clear();
    	h.clear();
    	tmpVector.clear();
	}
	return 0; 
} 
