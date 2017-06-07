class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* if_count=new bool[rows*cols];
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if_count[i*cols+j]=false;
        if(threshold<0 || rows<=0 || cols<=0)
            return 0;
       	return recur_move(threshold,0,0,rows,cols,if_count);
    }
    int recur_move(int threshold,int i,int j,int rows,int cols,bool* if_count){
        if(if_count[i*cols+j])
            return 0;
        if_count[i*cols+j]=true;
        int biti=sum_bit(i);
        int bitj=sum_bit(j);
        if(biti+bitj>threshold)
            return 0;
        
        int count=1;
        if(i+1<rows)
            count+=recur_move(threshold,i+1,j,rows,cols,if_count);
        if(i-1>=0)
            count+=recur_move(threshold,i-1,j,rows,cols,if_count);
        if(j+1<cols)
            count+=recur_move(threshold,i,j+1,rows,cols,if_count);
        if(j-1>=0)
            count+=recur_move(threshold,i,j-1,rows,cols,if_count);
        return count;
    }
    int sum_bit(int num) {
        int result=0;
        while(num) {
            result+=num%10;
            num/=10;
        }
        return result;
    }
};
