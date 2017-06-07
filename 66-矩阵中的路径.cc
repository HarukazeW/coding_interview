class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!matrix)
            return false;
    	for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
               	if(recur_path(matrix,i,j,rows,cols,str))
                    return true;
        return false;
    }
    
    bool recur_path(char* matrix,int i,int j, int rows, int cols, char* str) {
        bool result=false;
        if((matrix[i*cols+j])==*str) {
            matrix[i*cols+j]=-1;
            if( *(str+1)=='\0' || 
               (i+1<rows && recur_path(matrix,i+1,j,rows,cols,str+1)) || 
               (j+1<cols && recur_path(matrix,i,j+1,rows,cols,str+1)) ||
               i-1>=0 && recur_path(matrix,i-1,j,rows,cols,str+1)     ||
               j-1>=0 && recur_path(matrix,i,j-1,rows,cols,str+1))
                	result=true;
            matrix[i*cols+j]=*str;
        }
        return result;
    }
	
};
