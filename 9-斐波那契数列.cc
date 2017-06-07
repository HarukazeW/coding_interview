class Solution {
public:
    int Fibonacci(int n) {
        vector<int> data{0,1};
        if(n<2)
            return n;
        for(int i=2;i<n;i++)
            data[i&1]=data[0]+data[1];
        return data[0]+data[1];
    }
};
