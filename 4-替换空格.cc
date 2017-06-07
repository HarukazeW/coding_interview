class Solution {
public:
    void replaceSpace(char *str,int length) {
        int sourceindex=length-1;
        int spacecount=0;
        for(int i=0;i<length;i++)
            if(str[i]==' ')
                spacecount++;
        int res_index=length+2*spacecount-1;
        str[res_index+1]='\0';
        while(sourceindex>=0){
            if(str[sourceindex]==' '){
                str[res_index--]='0';
                str[res_index--]='2';
                str[res_index--]='%';
                sourceindex--;
            }
            else
                str[res_index--]=str[sourceindex--];
        }
    }
};
