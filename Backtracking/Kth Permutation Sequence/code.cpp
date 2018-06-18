int fact(int n)
{
    if(n>=12)
        return INT_MAX;
    int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}
 
 
string permute(int B, vector<int> set)
{
    int n=set.size();
    if(n==0)
        return "";
    if(B>fact(n))
        return "";
    int f = fact(n-1);
    int pos = B/f;
    B=B%f;
    string ch = to_string(set[pos]);
    set.erase(set.begin() + pos);
    return ch + permute(B,set);
    
}
 
string Solution::getPermutation(int A, int B) {
    vector<int> set;
    for(int i=1;i<=A;i++)
        set.push_back(i);
    return permute(B-1,set);
}
