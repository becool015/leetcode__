// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
// Example:
// 
// Given nums = [2, 7, 11, 15], target = 9,
// 
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

//Approach 1:brute force :we may take an element and for each element we check sum with each of rest of the elements
// but this is an O(n*n) approach 

//  Another way to approach:(if we need not return the indices of the array elements) we may sort the array and 
// take the two outer elements and move inwards. If sum>target ,decrease right pointer by 1
//If sum<target,increase left pointer by 1

//Approach 3: So we create an unordered_map that maps the element to its index and hence we may retrieve the element in O(1)
//time,hence it would be an optimal approach to the problem.
//So, we iterate over the elements of the array,and check if we find (sum-arr[i]) in the already constucted map
//else we add this existing element to the map and it maps to its index in the array

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2,0);
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(um.count(diff)>0)
            {
                return{i,um[diff]};
            }
            um[nums[i]]=i;
        }
        return v;
    }
};
