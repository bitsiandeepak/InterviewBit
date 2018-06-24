bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allParts(vector<vector<string>> &res, vector<string> &oneString, int start, int n,string str)
{
    if(start>=n)
    {
        res.push_back(oneString);
        return;
    }
    for(int i=start; i<n; i++)
    {
        if(isPalindrome(str,start,i))
        {
            oneString.push_back(str.substr(start,i-start+1));
            allParts(res,oneString,i+1,n,str);
            oneString.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.length();
    vector<vector<string>> res;
    vector<string> oneString;
    allParts(res,oneString,0,n,A);
    //sort(res.begin(),res.end());
    return res;
}
