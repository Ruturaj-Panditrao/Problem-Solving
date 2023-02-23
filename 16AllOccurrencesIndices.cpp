#include <vector>
#include <iostream>
using namespace std;

vector<int> AllOccurrenceIndices(vector<int>arr, int index, int key)
{
    if(index == arr.size())
    {
        return {};
    }

    vector<int> aheadOccs = AllOccurrenceIndices(arr, index+1, key);
    if(arr[index] == key)
    {
        aheadOccs.push_back(index);
    }
    return aheadOccs;
}

int main()
{
    vector<int>arr = {2,3,6,9,8,3,2,3,6,4};
    vector<int>allIndices = AllOccurrenceIndices(arr,0,3); // 1 5 7
    for(auto i : allIndices) cout<<i<<" ";
}
