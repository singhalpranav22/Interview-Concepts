// Recursive code to sort a stack(same as array)
#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int el)
{
    if(s.size()==0 || s.top()<=el)
      s.push(el);
    else
    {
        int temp=s.top();
        s.pop();
        insert(s,el);
        s.push(temp);
    }
    
}

void sort(stack<int> &s)
{
    if(s.size()==1)
     return;
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main()
{
    stack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        st.push(x);
    }
    sort(st);
    int a[n];
    for(int i=n-1;i>=0;i--)
    {
        a[i]=st.top();
        st.pop();
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<endl;
}