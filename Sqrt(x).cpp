class Solution {
public:
    int mySqrt(int x) {
        long long int i = 1;
        while(i * i <= x) {
            i++;
        }
        return i - 1;
    }
};


// the complexity of this code is sqrt(n)
