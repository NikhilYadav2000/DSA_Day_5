/*
Binary Search Introduction :
https://www.naukri.com/code360/problems/binary-search_972?nps=true

Via Iteration
int search(vector<int> &nums, int target) {
    int n=nums.size(),l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]==target) return m;
        else if(nums[m]>target) h=m-1;
        else l=m+1; // the value is of m is smaller then the target so we have to search it amongst larger numbers so moving the low pointer
    }return -1;
}

Via Recurison
int f(vector<int> &nums,int t,int l,int h){
    if(l>h) return -1;
    int m=(l+h)/2;
    if(nums[m]==t) return m;
    else if(nums[m]>t) return f(nums,t,l,m-1);

    // else if(nums[m]<t) f(nums,t,m+1,h);
    return f(nums,t,m+1,h);
    // we can write the above code like this, bcoz if it doesnt go with the  nums[m]>t part then it will come here

}
int search(vector<int> &nums, int target) {
    int n=nums.size();
    f(nums,target,0,n-1);
}

// Lower Bound
int lowerBound(vector<int> arr, int n, int x) {
    int l=0,h=n-1,ans=n;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]>=x){
            ans=m;
            h=m-1; // so we've got the lowerbound, but we need to find the closest element that is bigger then x
            // so we'll be searching in the left side amongst the smaller values then a[m] rn
        }else l=m+1; // we got a value smaller then x, so we are searching in the right half amongst the larger values then a[m] rn
    } return ans;
}
Using C++ STL
lb=lower_bound(arr,arr+n,x)-arr.begin();

If we are asked to find between 2nd index and 6th index then
lb=lower_bound(arr+2,arr+7,x)-arr.begin();
[2,7) so basically it will be [2,6]

// Upper Bound
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// Search where to insert, if present then return the index if not then find the index where it should exist
int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// Floor
int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = arr[mid];
            //look for smaller index on the left
            low = mid + 1;
        }
        else {
            high = mid - 1; // look on the right
        }
    }
    return ans;
}

// Ceil
int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = arr[mid];
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// First Occurence
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

// Last Occurence
int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}

// If the number exists then returning the value
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

// Returning the count
int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1); // +1 bcoz its 0 based indexing
}

// Search in Rotated Sorted Array I
class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0,h=a.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==target) return m;
            else if(a[l]<=a[m]){ // if left is sorted
                if(a[l]<=target && target<=a[m]) h=m-1; // bring h behind the curr index of m as m!=k and search in this half
                else l=m+1; // though this half was sorted but we dont have the answer here so moving to the other half even though it is unsorted
            }
            else{ // right side is sorted
                if(a[m]<=target && target<=a[h]) l=m+1;
                else h=m-1;
            }
        }return -1;  // if not found
    }
};

// Search in Rotated Sorted Array II
class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,h=a.size()-1,ans=INT_MAX;
        while(l<=h){
            int m=(l+h)/2;
            if(a[l]<=a[h]){
                ans=min(ans,a[l]); // this subarray is sorted from l to h
                break;
            }
            if(a[l]<=a[m]){
                ans=min(ans,a[l]);
                l=m+1;
            }else{
                h=m-1;
                ans=min(ans,a[m]);
            }
        }return ans;
    }
};

class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,h=a.size()-1,ans=INT_MAX;
        while(l<=h){
            int m=(l+h)/2;
            if(a[l]<=a[h]){
                // ans=min(ans,a[l]); // this subarray is sorted from l to h
                if(a[l]<ans){
                    ind=l;
                    ans=a[l];
                }
                break;
            }
            if(a[l]<=a[m]){
                // ans=min(ans,a[l]);
                if(a[l]<ans){
                    ind=l;
                    ans=a[l];
                }
                l=m+1;
            }else{
                h=m-1;
                // ans=min(ans,a[m]);
                if(a[m]<ans){
                    ind=m;
                    ans=a[m];
                }
            }
        }return ind;
    }
};

// Single Element in Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        if(a[0]!=a[1]) return a[0];
        if(a[n-1]!=a[n-2]) return a[n-1];
        int l=1,h=n-2;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]!=a[m+1] && a[m]!=a[m-1]) return a[m];
            if(m%2==1 && a[m]==a[m-1] || m%2==0 && a[m]==a[m+1]) // odd index, so checking that the left value which is the even index has the same value or not
            // if we have same value this means the single element lies on the right side. Both are same things
            // standing on the left and checking for the right and viceversa
            {
                l=m+1;
            }else{
                h=m-1;
            }
        }return -1;
    }
};

// Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;
        if(a[0]>a[1]) return 0;
        if(a[n-1]>a[n-2]) return n-1;
        int l=1,h=n-2;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]>a[m-1] && a[m]>a[m+1]) return m;
            else if(a[m]>a[m-1]) l=m+1; // its the increasing slope so check in the right half
            else h=m-1; // For both 1. If its the decreasing slope then check in the left half 2. if its the Valley like case then check in either of the halves but we chose the right half
        } return -1;
    }
}; 

// Find square root of a number in log n
long long int floorSqrt(long long int x) 
{
   long long l=1,h=x,ans=1;
   while(l<=h){
       long long m=(l+h)/2;
       if(m*m<=x){
           ans=m;
           l=m+1;
       }else h=m-1;
   }return ans;
}

	
// Find the Nth root of a number using binary search
public:
	int func(int mid,int n,int m){
	    long long ans=1;
	    for(int i=1;i<=n;i++){
	        ans*=mid;
	        if(ans>m) return 2; // checking in between if nth value is greater then m then stop it or else it will give TLE
	    }
	   if(ans==m) return 1; // we are waiting till the loop ends to know if the nth value is equal to m or not
	   return 0; // if nth value is smaller then m
	}
	int NthRoot(int n, int m)
	{
	    int l=1,h=m;
	    while(l<=h){
	        int mid=(l+h)/2;
	        int midVal=func(mid,n,m);
	        if(midVal==1) return mid;
	        else if(midVal==0) l=mid+1;
	        else h=mid-1;
	   }return -1; // if we dont find the value
	}  
};

// Koko Eating Bananas
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minEatingSpeed(vector<int> &v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}
};

// Minimum days to make M bouquets
bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    //apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
} // TC : O(log(max(arr[])-min(arr[])+1) * N), SC : [min(arr[]), max(arr[])]

// Find the Smallest Divisor Given a Threshold
int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
} // TC : : O(log(max(arr[]))*N), SC : [1, max(arr[])]

// Capacity to Ship Packages within D Days
int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
} // TC : : O(N * log(sum(weights[]) - max(weights[]) + 1)), SC : [max(weights[]), sum(weights[])]

// Split Array - Largest Sum 
// Painter's partition
class Solution {
public:
int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}
    int splitArray(vector<int>& a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
}; // TC : O(N * log(sum(arr[])-max(arr[])+1)
*/