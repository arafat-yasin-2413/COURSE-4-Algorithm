#include<bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    // for(int i = 0;i<nums.size(); i++) cout<<nums[i]<<" ";
    // cout<<endl;
    vector<int> result;
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i] == target)
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{

    vector<int> v = {1,2,5,2,3};
    int targ; cin>>targ;
    vector<int> res = targetIndices(v,targ);
    for(int i = 0; i<res.size();i++) cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}