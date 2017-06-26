#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> tmp;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            if(tmp.count(target - nums.at(i)) == 1){
                result.push_back(tmp[target - nums.at(i)]);
                result.push_back(i);
            }
            tmp[nums.at(i)] = i;
        }

        return result;
    }
};

int main(){
    Solution solution;

    int init[] = {1,2,3,4,5};
    vector<int> nums;
    for(int i=0;i<5;i++)
        nums.push_back(init[i]);

    vector<int> result = solution.twoSum(nums,3);

    cout<<result.at(0)<<" "<<result.at(1)<<endl;

    return 0;
}
