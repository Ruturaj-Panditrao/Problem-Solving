#include <vector>
#include <iostream>
using namespace std;

void print(vector<int>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void targetSubsetSum(int index, vector<int>&arr, vector<int>&ds, int sum, int target)
{
    if(index == arr.size() )
    {   
        if(sum == target)
        {
        print(ds);
        }
        return;
    }

    ds.push_back(arr[index]);
    targetSubsetSum(index+1,arr,ds,sum+arr[index],target);
    ds.pop_back();
    targetSubsetSum(index+1,arr,ds,sum,target);
    return;
}

int main()
{
    vector<int>arr = {10,20,30,40,50};
    int target = 60;
    vector<int>ds;
    int sum = 0;
    targetSubsetSum(0,arr,ds,sum,target);
}
