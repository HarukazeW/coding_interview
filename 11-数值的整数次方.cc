//此题关键要考虑负数情况，考虑exponent为负值时如何计算
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent<0){
            exponent*=-1;
            base=1/base;
        }
        return recur(base,exponent);
    }
    double recur(double base,int exponent){
        if(exponent==0)
            return 1;
    	double t=recur(base,exponent/2);
        return exponent&1?t*t*base:t*t;
    }
};
