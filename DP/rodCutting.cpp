// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

// Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

// Notes:

// Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
// N can be upto 109.
// For example,

// N = 6
// A = [1, 2, 5]

// If we make cuts in order [1, 2, 5], let us see what total cost would be.
// For first cut, the length of rod is 6.
// For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
// For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
// So, total cost is 6 + 5 + 4.

// Cut order          | Sum of cost
// (lexicographically | of each cut
//  sorted)           |
// ___________________|_______________
// [1, 2, 5]          | 6 + 5 + 4 = 15
// [1, 5, 2]          | 6 + 5 + 4 = 15
// [2, 1, 5]          | 6 + 2 + 4 = 12
// [2, 5, 1]          | 6 + 4 + 2 = 12
// [5, 1, 2]          | 6 + 5 + 4 = 15
// [5, 2, 1]          | 6 + 5 + 2 = 13


// So, we return [2, 1, 5].


using ll = long long;
ll MinCost(int st, int end, vector<int> &cuts, vector<vector<ll> > &dp, vector<vector<int> > &cut){
    if(abs(end - st) <= 1)
        return 0;
    if(dp[st][end] != -1)
        return dp[st][end];
    ll ans = -1;
    for(int i = st + 1; i < end; i ++){
        ll a = cuts[end] - cuts[st] + MinCost(st, i, cuts, dp, cut) + MinCost(i, end, cuts, dp, cut);
        if((ans == -1LL) || (ans > a)){
            cut[st][end] = i;
            ans = a;
        }
    }
    dp[st][end] = ans;
    return ans;
}

void Fill(vector<int> &ans, vector<vector<int > > &cut, vector<int> &cuts, int st, int end){
    if(abs(end - st) <= 1)
        return;
    ans.push_back(cuts[cut[st][end]]);
    Fill(ans, cut, cuts, st, cut[st][end]);
    Fill(ans, cut, cuts,cut[st][end], end);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(), B.end());
    int m = B.size();
    vector<vector<ll> > dp(m, vector<ll>(m, -1));
    vector<vector<int> > cut(m, vector<int>(m));
    MinCost(0, m - 1, B, dp, cut);
    vector<int> ans;
    Fill(ans, cut, B, 0, m - 1);
    return ans;
}
