//f(n,m)=[f(n-1,m)+m]%n
//此题为约瑟夫环问题
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        int result=0;
        for(int i=2;i<=n;i++)
            result=(result+m)%i;
        return result;
            
    }
};
