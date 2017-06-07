class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	long long i=1;  //it should be long long ,so it won't overflow when i*10 >Int_Max
        int count=0;
        for(;i<=n;i*=10){
            int a=n/i,b=n%i;
            count+=(a+8)/10*i+(a%10==1)*(b+1);
        }
        return count;
    }
};
