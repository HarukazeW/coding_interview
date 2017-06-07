//此题要考虑n为负数的情况，当n为负数时，此算法亦成立
//若要依次移位判断个数，可以移1不可移n,因为n为负数时，移位会保留使其符号位始终为1,而不停的多出来一位
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         while(n){
             n&=n-1;
             count++;
         }
         return count;
     }
};
