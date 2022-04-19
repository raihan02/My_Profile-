class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        
        deque <int> dq;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(dq.size() > 0 && i - k == dq.front()){
                dq.pop_front();
            }
            
            while(dq.size() > 0 && nums[dq.back()] < nums[i] ){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};

// Blog : http://www.shafaetsplanet.com/?p=2316
