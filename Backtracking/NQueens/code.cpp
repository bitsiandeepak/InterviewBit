bool isSafe(vector<vector<int>> a,int row,int col)
{
    int i= row;
    int j=col;
    while(j>=0)
    {
        if(a[i][j]==1)
            return false;
        j--;
    }
    i=row;
    j=col;
    while(i>=0&&j>=0)
    {
        if(a[i][j]==1)
            return false;
        j--;
        i--;
    }
    i=row;
    j=col;
    while(i<a.size()&&j>=0)
    {
        if(a[i][j]==1)
            return false;
        j--;
        i++;
    }
    return true;
}

bool placequeens(vector<vector<string>> &str,vector<vector<int>> &a,int n,int col)
{
    if(col==n)
    {   
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=0;j<n;j++)
            {
                if(a[i][j] == 1)
                temp+='Q';
                else
                temp+='.';
            }
            s.push_back(temp);
        }
        str.push_back(s);
        
        return true;
    }
    bool res=false;
    for(int i=0; i<n;i++)
    {
        if(isSafe(a,i,col))
        {
            a[i][col] = 1;
            res=placequeens(str,a,n,col+1)||res;
            a[i][col]= 0;
        }
    }
    return res;
}

void printRes(vector<vector<int>> a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

bool board(int n,vector<vector<int>> &a, vector<vector<string>> &str)
{
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            temp.push_back(0);
        }
        a.push_back(temp);
    }
    bool res = placequeens(str,a,n,0);
    return true;
}


vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> a;
    vector<vector<string>> str;
    bool res = board(A,a,str);
    return str;
    
}
