The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

string Solution::countAndSay(int n) {
    string a="1",b="1",c="";
    n--;
    int count=0,val;
    while(n--){
        int l=a.length();
        count=1;
        val=a[0]-'0';
        c="";
        for(int i=1;i<l;i++){
            if(a[i-1]==a[i]){
                count++;
                continue;
            }
            else{
                b="";
                while(count){
                    b+=(count%10+'0');
                    count=count/10;
                }
                reverse(b.begin(),b.end());
                c+=b;
                c+=(val+'0');
                val=a[i]-'0';
                count=1;
            }
        }
        b="";
        while(count){
            b+=(count%10+'0');
            count=count/10;
        }
        reverse(b.begin(),b.end());
        b+=(val+'0');
        c+=b;
        //cout<<c<<endl;
        a=c;
    }
    return a;
}
