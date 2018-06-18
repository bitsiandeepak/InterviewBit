void subset(vector<int> a, vector<vector<int>> &res, int l,int count,int size);

vector<vector<int>> allSubsets(vector<int> &A)
{
    vector<vector<int>> res;
    subset(A,res,0,0,A.size());
    return res;
}

void subset(vector<int> a, vector<vector<int>> &res, int l,int count,int size)
{
    if(count==size)
        res.push_back(a);
    else
    {
        subset(a,res,l+1,count+1,size);
        a.erase(a.begin()+l);
        subset(a,res,l,count+1,size);
    }
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> res = allSubsets(A);
    int j=0,i;
    j=0;
    sort(res.begin(),res.end());
    return res;
}
