    #include <bits/stdc++.h>
    using namespace std;
     
    #define MAXN 20020
     
    int a[MAXN],t[4*MAXN];
     
    void build(int v , int tl , int tr)
    {
        if(tl == tr){
            t[v] = a[tl];
        }else{
            int tm = (tl+tr)/2;
            build(2*v , tl , tm);
            build(2*v + 1 , tm + 1 , tr);
            t[v] = (t[2*v]) & (t[2*v + 1]);
        }
    }
     
    int fn(int v , int tl , int tr , int l , int r)
    {
        if(l > r){
            return INT_MAX;
        }else{
            if(l == tl && r == tr){
                return t[v];
            }
            int tm = (tl+tr)/2;
            return fn(2*v , tl , tm , l , min(tm,r)) & fn(2*v+1 , tm+1 , tr , max(tm+1,l) , r);
        }
    }
     
    void update(int v, int tl ,int tr , int pos , int pos_val)
    {
        if(tl == tr){
            t[v] = pos_val;
        }else{
            int tm = (tr+tl)/2;
            if(pos <= tm)
                update(2*v , tl , tm , pos , pos_val);
            if(pos > tm)
                update(2*v+1 , tm+1 , tr , pos , pos_val);
            t[v] = t[2*v] & t[2*v + 1];
        }
    }
     
    int main() {
        int test,n,k,l1,l2,r1,r2;
        // cin>>test;
        scanf("%d",&test);
        while(test--){
            // cin>>n>>k;
            scanf("%d%d",&n,&k);
            for(int i=1 ; i<=n ; i++){
                // cin>>a[i];
                scanf("%d",&a[i]);
            }
            build(1,1,n);
            for(int i=1 ; i<= n ; i++){
                // if(i - min(n,k) <= 1 && i + min(n,k) >= n){
                //     l1 = 1;
                //     l2 = n;
                //     r1 = 1;
                //     r2 = n;
                // }else if(i - min(n,k) < 1 && i + min(n,k) <= n){
                //     l1 = n+(i-min(n,k)) ;
                //     l2 = n;
                //     r1 = 1;
                //     r2 = i + min(n,k);
                // }else if(i - min(n,k) >= 1 && i+min(n,k) > n){
                //     l1 = 1;
                //     l2 = (i + min(n,k))%n ;
                //     r1 = i - min(n,k);
                //     r2 = i;
                // }else{
                //     l1 = i - min(n,k);
                //     l2 = i;
                //     r1 = i;
                //     r2 = i + min(n,k);
                // }
                // // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
                // a[i] &= fn(1,1,n,l1,l2) & fn(1,1,n,r1,r2);
                if(k>n/2)
                    a[i] = fn(1,1,n,1,n);
                else{
                    if(i+k>=n+1){
                        a[i]=fn(1,1,n,i,n);
                        a[i] &=fn(1,1,n,1,(i+k)%n);
                    }
                    else
                        a[i]=fn(1,1,n,i,(i+k));
                    if(i-k<1){
                        a[i] &=fn(1,1,n,1,i);
                        a[i]&=fn(1,1,n,n-k+i,n);
                    }
                    else
                        a[i]&=fn(1,1,n,i-k,i);
                }
            }
            for(int i=1 ; i<=n ; i++){
                // cout<<a[i]<<" ";
                printf("%d ",a[i]);
            }
            // cout<<endl;
            printf("\n");
        }
    } 