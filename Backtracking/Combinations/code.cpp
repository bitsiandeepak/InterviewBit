void combinations(vector<int> setInt,vector<vector<int>> &res,int A, vector<int> &com, int pos, int B)
{
    if(com.size()==B)
    {
        res.push_back(com);
        return;
    }
    if(pos>A||A-pos<B-com.size())
        return;
    combinations(setInt,res,A,com,pos+1,B);
    com.push_back(setInt[pos]);
    combinations(setInt,res,A,com,pos+1,B);
    com.pop_back();
}


vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> setInt;
    for(int i=1;i<=A;i++)
    setInt.push_back(i);
    vector<int> com;
    vector<vector<int>> res;
    combinations(setInt,res,A,com,0,B);
    sort(res.begin(),res.end());
    return res;
}
