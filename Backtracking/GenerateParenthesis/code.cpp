vector<string> res;

void printParenthesis(int pos,int n,int open, int close)
{
    static char s[100];
    if(close==n)
        {
            string temp;
            for(int i=0;i<2*n;i++)
            {
                temp=temp+s[i];
            }
            res.push_back(temp);
            //cout<<temp<<endl;
            return;
        }
    else
    {
        if(open>close)
        {
            s[pos]=')';
            printParenthesis(pos+1,n,open,close+1);
        }
        if(open<n)
        {
            s[pos]='(';
            printParenthesis(pos+1,n,open+1,close);
        }
    }

}


vector<string> Solution::generateParenthesis(int A) {
    res.clear();
    printParenthesis(0,A,0,0);
    sort(res.begin(),res.end());
    return res;
    
}
