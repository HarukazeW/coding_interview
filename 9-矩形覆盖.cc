//与跳台阶的题目类似，但此处规定numbers是0时为0
class Solution {
public:
    int rectCover(int number) {
	int v[]={1,1};
        for(int i=2;i<number;i++)
            v[i&1]=v[0]+v[1];
        return number<2?number:v[0]+v[1];
    }
};
