    #include <bits/stdc++.h>
    using namespace std;
     
    #define MAXN 100001
     
    struct data {
        long long int ans,suff,puff,sum;
    };
     
    int a[MAXN];
    data t[4*MAXN];
     
     
    data make(long long int val)
    {
        data res ;
        res.ans = max(val,val);
        res.sum = val;
        res.suff = val;
        res.puff = val;
        return res;
    }
     
    data combine(data l , data r)
    {
        data res ;
        res.suff = max(r.sum + l.suff , r.suff);
        res.puff = max(l.puff , l.sum+r.puff);
        res.sum = l.sum + r.sum;
        res.ans = max(max(r.ans,l.ans),l.suff+r.puff);
        return res;
    }
     
    void build(int v , int start , int end )
    {
        if(start == end){
            t[v] = make(a[start]);
        }else{
            int md = (start + end)/2;
            build(2*v , start , md);
            build(2*v+1 , md+1 , end);
            t[v] = combine(t[2*v] , t[2*v + 1]);
        }
    }
     
    data sum(int v , int start , int end , int l , int r)
    {
        if(l>r){
            return make(-1000000000);
        }
        if(l == start && r == end){
            return t[v];
        }
        int md = (start + end)/2;
        // return max(sum(2*v , start , md , l , min(r,md)) + sum(2*v + 1 , md + 1 , end , max(l,md+1) , r) , max(sum(2*v , start , md , l , min(r,md)) 
        // ,sum(2*v + 1 , md + 1 , end , max(l,md+1) , r)));
        return combine(sum(2*v,start , md , l , min(r,md)) , sum(2*v + 1 , md + 1 , end , max(l,md+1) , r));
    }
     
     
    void update(int v , int tl , int tr , int pos , int pos_val)
    {
        if(tl == tr){
            t[v] = make(pos_val);
        }else{
            int tm = ( tl + tr )/2;
            if(pos <= tm){
                update(2*v , tl , tm , pos , pos_val);
            }else{
                update(2*v + 1 , tm + 1 , tr , pos , pos_val);
            }
            t[v] = combine(t[2*v] , t[2*v + 1]);
        }
    }
     
    int main() {
        long long int n,m,q,x,y,o;
        cin>>n;
        for(int i=1 ; i<=n ; i++){
            cin>>a[i];
        }
        build(1,1,n);
        cin>>q;
        while(q--){
            cin>>o>>x>>y;
            if(o == 1)
            cout<<sum(1,1,n,x,y).ans<<endl;
            else
                update(1,1,n,x,y);
        }
    } 