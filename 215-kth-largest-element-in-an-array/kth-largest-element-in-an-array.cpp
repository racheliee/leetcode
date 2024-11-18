class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heap을 유지하고 k개의 element만 유지
        priority_queue<int, vector<int>, greater<>> pq;

        for(int n: nums){
            pq.push(n);

            if(pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};