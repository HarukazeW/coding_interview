//即表示成(a^b)+((a&b)<<1)，用递归实现加法，((a&b)<<1)为0时递归终止
class Solution {
public:
    int Add(int num1, int num2)
    {
        if(!num2)
		return num1;            
	return Add(num1^num2,(num1&num2)<<1);
    }
};
