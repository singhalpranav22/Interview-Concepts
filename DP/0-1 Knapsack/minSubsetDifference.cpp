Given an integer array A containing N integers.

    You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

    Find and return this minimum possible absolute difference.

    NOTE :

    Subsets can contain elements from A in any
    order(not necessary to be contiguous)
        .Each element of A should belong to any one subset S1 or
    S2,
    not both.It may be possible that one subset remains empty.

        Problem Constraints 1 <= N <= 100

        1 <= A[i] <= 100

                     Input Format
                         First and only argument is an integer array A.

                     Output Format
                         Return an integer denoting the minimum possible difference among the sums of two subsets.

                     Example Input
                         Input 1 :

    A = [ 1, 6, 11, 5 ]

    Example Output
        Output 1 :

    1

    vector<int>
    subsetsum(vector<int> A, int B)
{
    int n = A.size();
    int t[n + 1][B + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int j = 1; j < B + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < B + 1; j++)
        {
            if (A[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - A[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> v;
    for (int i = 0; i < (B + 1); i++)
    {
        if (t[n][i] == true)
        {
            v.push_back(i);
        }
    }
    return v;
}
int Solution::solve(vector<int> &H)
{
    int sum = 0;
    for (int i = 0; i < H.size(); i++)
    {
        sum += H[i];
    }
    vector<int> z = subsetsum(H, sum / 2);
    int mn = INT_MAX;
    for (int i = 0; i < z.size(); i++)
    {
        mn = min(mn, sum - 2 * z[i]);
    }
    return mn;
}