// 295. Find Median from Data Stream
// Hard

// 4236

// 80

// Add to List

// Share
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
 

// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.
 

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
class MedianFinder {
public:
    /** initialize your data structure here. */
   priority_queue<int, vector<int>, greater<int>> mn; // min heap
    priority_queue<int> mx; // max heap
    MedianFinder() {
       mn=priority_queue<int, vector<int>, greater<int>>();
        mx=priority_queue<int>();
    }
    
    void addNum(int num) {
       if(mx.size()==0 || ((mn.size()>0)?num<=mn.top():true))
           mx.push(num);
        else 
            mn.push(num);
        if(mx.size()>(mn.size()+1)){
            mn.push(mx.top());
            mx.pop();
        }
        else if((mx.size()+1) < mn.size())
        {
            mx.push(mn.top());
            mn.pop();
        }
      // cout<<"adddone\n";
    }
    
    double findMedian() {
        int sz = mx.size()+mn.size();
        if(sz==0) return 0;
        if(sz%2==0){
            double two=2;
            double a=mx.top(),b=mn.top();
            double ans=(a+b)/2;
            return ans;
        }
        else{
            if(mx.size()>mn.size()){
                double ans=mx.top();
                return ans;
            }
            else
            {
                double ans=mn.top();
                return ans;
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */