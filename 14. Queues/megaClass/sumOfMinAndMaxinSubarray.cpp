#include <iostream>
#include <queue>
using namespace std;

int maxAndMinSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq, dq2;
       int ans = 0;

       //process first window
       for(int i =0; i<k ; i++){
        int element = nums[i]; //store first element
        //remove the elements taht are smaller
        while(!dq.empty() &&nums[dq.back()] <= element){
            dq.pop_back();
        }
        while(!dq2.empty() &&nums[dq2.back()] >= element){
            dq2.pop_back();
        }
        //current element toh insert karna hi hai
        dq.push_back(i);
        dq2.push_back(i);
       } 
         //store the answers
        ans += nums[dq.front()]+ nums[dq2.front()];
        

       //process remaining windows
       for(int i=k ; i< nums.size(); i++){
        //removal;
        if(!dq.empty() && dq.front() < i-k+1){
            dq.pop_front();
        }
        if(!dq2.empty() && dq2.front() < i-k+1){
            dq2.pop_front();
        }
        int element = nums[i]; //store first element
        //remove the elements taht are smaller
        while(!dq.empty() &&nums[dq.back()] <= element){
            dq.pop_back();
        }
        while(!dq2.empty() &&nums[dq2.back()] >= element){
            dq2.pop_back();
        }
        //current element toh insert karna hi hai
        dq.push_back(i);
        dq2.push_back(i);

        ans += nums[dq.front()]+ nums[dq2.front()];

        
       }
       return ans;
}

int main(){
    
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int result = maxAndMinSlidingWindow(nums, k);
    cout << "Sum of max and min in all subarrays of size " << k << " is: " << result << endl;

    return 0;
}