/*
Bruteforce Approach:
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

/*
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

/*
Time Complexity: O(n * k)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            int maxidx = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[maxidx]) maxidx = j;
            }
            swap(nums[i], nums[maxidx]);
        }
        return nums[k - 1];
    }
};

/*
Better Approach:
Time Complexity: O(n)
Space Complexity: O(log n)
*/

class Solution {
private:
    int partition(int low, int high, int pivot, vector<int>& nums) {
        int i = low, j = low;
        while (j <= high) {
            if (nums[j] <= pivot) 
              j++;
            else {
                swap(nums[i], nums[j]);
                i++; j++;
            }
        }
        return i;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k, int low, int high) {
        int idx = (rand() % (high - low + 1)) + low;
        if (idx != low) swap(nums[low], nums[idx]);
        int x = partition(low + 1, high, nums[low], nums);
        x--;
        swap(nums[low], nums[x]);
        if (x == k - 1) 
          return nums[k - 1];
        else if (k - 1 < x) 
          return findKthLargest(nums, k, low, x - 1);
        else 
          return findKthLargest(nums, k, x + 1, high);
    }
};


/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i = nums.size() - k;
        nth_element(nums.begin(), nums.begin() + i, nums.end());
        return nums[i];
    }
};
