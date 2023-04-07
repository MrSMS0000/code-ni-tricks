1500 vada prasno no approach : 

BRUTE FORCE

DP
ans[i] = max(ans[i]+ans[i-2], ans[i-1]);

DFS
variables vectors global levana.
reference pass karvano nai bhulvano.

GREEDY
cant describe - https://codeforces.com/contest/545/problem/C 
atyar na i parnu dicision khali next 1 ne j asar kartu tu, dp nu minimization

SETTING
darek input mate output try kari juo.
undhethi try kari juo.
every possible ans mate que par javanu

TWO POINTER
sort karine start ane end
while(start<n && end <n){
    if(rangesum < d){
        update the ans to return    ans = max(ans,end-start)
        end++
        update the var and range    rangesum += v[end];
    }
    else{
        update the var and range    startsum -= v[start]
        start++
    }
}
return ans;

DHYAN RAKHO
vector ne initialize karo tyare size api devani
n==1 mate alag thi vicharvanu
10^9 vada var no sum karva vada var ne, return karva vada var ne ll levano