class Solution {
public:
    long long sq(long long mid){
        return mid * mid;
    }

    int mySqrt(int x) {
        int low = 1;
        int high = x;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long temp = sq(mid);

            if(temp == x) return mid;
            else if(temp > x) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};