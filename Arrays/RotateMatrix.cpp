// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// You need to do this in place.

// Note that if you end up using an additional array, you will only receive partial score.

// Example:

// If the array is

// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:

// [
//     [3, 1],
//     [4, 2]
// ]

// Take transpose then Reverse the rows.

void Solution::rotate(vector<vector<int> > &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++){
         swap(a[i][j],a[j][i]); }// Transpose
    }
    for(int i=0;i<n;i++)
    {
        reverse(a[i].begin(),a[i].end());  // reverse each row
    }
}
