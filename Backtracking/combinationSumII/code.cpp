void combinationalSum(vector<vector<int>> &res,vector<int> a, vector<int> &temp,int pos,int sum)
{
    if(sum==0)
    {
        res.push_back(temp);
        return;
    }
    if(pos>=a.size())
        return;
    if(a[pos]<=sum)
    {
        temp.push_back(a[pos]);
        combinationalSum(res,a,temp,pos+1,sum-a[pos]);
        temp.pop_back();
        combinationalSum(res,a,temp,pos+1,sum);
    }
    else if(a[pos]>sum)
    {
        combinationalSum(res,a,temp,pos+1,sum);
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> temp;
    combinationalSum(res,A,temp,0,B);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}
