// include :
#include <bits/stdc++.h>
using namespace std;
int main(){

}
// fast io :
ios::sync_with_stdio(0);
cin.tie(0);
// formulas :
fibonaki : 1/root(5) (((1+root(5))/2)^n - ((1-root(5))/2)^n);
geometric sum : a (r^n - 1)/(r -1) ;
arithmetic sum : n/2 (2a + (n-1)d) = n(a+b)/2;
// complexities :
n! - 10, 2^n - 20, n^3 - 500, n^2 - 5000, nlogn - 10^6, logn, 1
// kadane :
int best=0, sum=0;
for(int i=0; i<n; i++){
    sum = max(sum, sum+a[i]);
    best = max(sum,best);
}
return best;
// sorting :
****link****
own structure :
struct comp{
    int x,y;
    bool operator<(const comp &c){
        if(x==c.x)  return y<c.y;
        return x<c.x;
    }
};

own func :
sort(c,c+n,comp);
static bool comp(int a, int b)
    return a<b;

// binary search :
lower_bound(a, a+n, x) : pointer to first array ele. whose val is "at least" x.
upper_bound(a, a+n, x) : pointer to first array ele. whose val is "greater than" x.

// data structures :
****pfb****
priority queue own fun :
priority_queue<int,vector<int>,greater<int>> q; (make own class and overload () operator instead of greater<int>)

// complete search :
subsets:
1)
void make(int i){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    make(i+1);
    temp.push_back(a[i]);
    make(i+1);
    temp.pop_back(a[i]);
}
2)
for(int b=0; b<(1<<n); b++){
    vector<int> subset;
    for(int i=0; i<n; i++){
        if(b & (1<<i))  subset.push_back(a[i]);
    }
}
permutation:
void permute(){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(visit[i])    continue;
        visit[i] = true;
        temp.push_back(a[i]);
        permute();
        visit[i]=false;
        temp.pop_back();
    }
}
N-Queen:
void put(int i){
    if(i==n)    return;
    for(int j=0; j<m; j++){
        if(col[j] || d1[i+j] || d2[n-i+j-1])    continue;
        grid[i][j]=col[j]=d1[i+j]=d2[n-i+j-1]=1;
        put(i+1);
        grid[i][j]=col[j]=d1[i+j]=d2[n-i+j-1]=0;
    }
}
// greedy avde
// dp e avde
// two pointer na avde
// nearest smaller
for(int i=0; i<n; i++){
    while(s.size() && a[s.top]>=a[i])   s.pop();
    ans[i] = s.size() ? a[s.top()] : -1;
    s.push(i);
}
// sliding window minimum
for(int i=0; i<n; i++){
    if(q.size() && q.front() == i-k+1)   q.pop_front();
    while(q.size() && a[q.back()]>=a[i])   q.pop_back();
    q.push_back(i);
    if(i>=k-1)
        ans[i-k+1]=a[q.front()];
}
// range queries
static :
sum - prefix sum
min - sparse table (kth ancestor vadi method)
-----haji baki-----(adhuru ane khotu chhe skip)
int log = log2(n)+1, ans[n][log];
for(int j=0; j<n; j++)  ans[j][0]=a[j];
for(int i=1; i <log; i++){
    int len = pow(2,i);
    for(int j=0; j+len-1<n; j++){
        ans[j][i] = min(ans[j][i-1], ans[j+len/2][i-1]);
    }
}
int len = b-a+1, k=(int)(log2(len));
cout<<min(ans[a][k], ans[b-pow(2,k)+1][k]);

// binary indexed tree (fenwick):
skip
// segment tree :
int tree[2*n];
int make(i,tree,a){
    if(i>=n)    tree[i]=a[i-n];
    else    tree[i] = make(2*i,tree,a) + make(2*i+1,tree,a);
    return tree[i];
}
make(1,tree,a);
int sum(int a, int b){
    int s=0;
    a+=n;   b+=n;
    while(a<=b){
        if(a%2) s+=tree[a++];
        if(b%2==0)  s+=tree[b--];
        a/=2; b/=2;
    }
    return s;
}
void update(int i, int add){
    i+=n;
    tree[i]+=add;
    for(i/=2; i>=1; i/=2)
        tree[i] = tree[2*i] + tree[2*i+1];
}
// bit
-----baki-----
// masters theorem
T(n) = a T(n/b) + o(n^k * log^p n)  a>=1, b>1, k>=0, p is real.
1) if(a > b^k)  T(n) = o(n^logb a);
2) if(a == b^k)
    if(p>-1)    T(n) = o(n^logb a * log^p+1 n);
    if(p==-1)   T(n) = o(n^logb a * log^p+1 n);
    if(p<-1)    T(n) = o(n^logb a);
3) if(a < b^k)
    if(p>=0)    T(n) = o(n^k log^p n);
    if(p<0)     T(n) = o(n^k);
// tree from in-post
(example laine karvo j)
TreeNode* make(vector<int> &pre, vector<int> &in, unordered_map<int, int> &ino, int i, int j, int *pi){
    if(j<i) return NULL;
    int ii=ino[pre[*pi]], value = pre[(*pi)--];
    (aiya pella right pachi j left)
    (pi ne ghatadine call kayro)
    TreeNode *right = make(pre, in, ino, ii+1, j, pi), *left = make(pre, in, ino, i, ii-1, pi);
    return new TreeNode(value, left, right);
}

TreeNode* buildTree(vector<int>& in, vector<int>& pre) {
    unordered_map<int, int> ino;
    int pi=in.size()-1;
    for(int i=0; i<in.size(); i++)
        ino[in[i]]=i;
    return make(pre, in, ino, 0, in.size()-1, &pi);
}
// graph
dfs:
void dfs(int s){
    if(visit[s])    return;
    visit[s]=true;
    for(auto u:adj[s]){
        dfs(u);
    }
}
bfs:
void bfs(){
    queue<int> q;
    q.push(s);
    visit[s]=true;
    while(!q.empty()){
        int t=q.front(); q.pop();
        for(auto u:adj[t]){
            if(visit[u])    continue;
            visit[u]=true;
            q.push(u);
        }
    }
}
bellmen ford:
vector<int> dis(n,INT_MAX);
dis[s]=0;
for(int i=1; i<n; i++){
    for(auto u:edges){
        int a,b,w;
        tie(a,b,w) = u;
        dis[b]=min(dis[b],dis[a]+w);
    }
}
floyd-warshall:
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i==j)    dis[i][j]=0;
        else if(adj[i][j])  dis[i][j]=adj[i][j];
        else    dis[i][j]=INT_MAX;
    }
}
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
    }
}
// trees
traversal :
void dfs(int s, int p){
    count[s]=1;
    for(auto u:adj[s]){
        if(u==p)    continue;
        dfs(u,s);
        count[s]+=count[u];
    }
}
disjoint sets :
for(int i=1; i<=n; i++){
    link[i]=i;
    size[i]=1;
}
int find(int x){
    while(x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a, int b){
    a=find(a);  b=find(b);
    if(size[a]<size[b]) swap(a,b);
    link[b]=a;
    size[a]+=size[b];
}

// z algo
vector<int> z(n);
int x=0, y=0;
for(int i=1; i<n; i++){
    z[i] = max(0, min(z[i-x], y-i+1));
    while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
        x = i;
        y = i+z[i];
        z[i]++;
    }

}
// math
fmod(a,b)   float ma a%b karva

prime :
for(int i=2; i*i<=n; i++){
    if(n%i==0)  return false;
}
return true;

factor:
for(int i=2; i*i<=n; i++){
    while(n%i==0){
        factor.push_back(i);
        n/=i;
    }
}
if(n>1) factor.push_back(n);

sieve:
for(int i=2; i<n; i++){
    if(sieve[i])    continue;
    for(int j = 2*i; j<=n; j+=i)
        sieve[j]=i;
}

gcd:
if(b==0)    return a;
return gcd(b,a%b);

Geometry:
heron = root((s)(s-a)(s-b)(s-c));
cross pro = (conj(a)*b).Y;
(p-p1)x(p-p2)>0 - p is on left of p1p2...
(a-c)x(b-c)/2 - area of triangle
(p1-p)x(p2-p)/abs(p2-p1) - dist of p from p1p2
