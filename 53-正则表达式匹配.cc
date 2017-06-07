class Solution {
public:
    bool match(char* str, char* pattern)
    {
		if(!str || !pattern)
            return false;
        return recur_match(str,pattern,0,0);
    }
    
    bool recur_match(char *str,char *pattern,int sindex,int pindex) {
        if(str[sindex]=='\0' && pattern[pindex]=='\0')
            return true;
        if(pattern[pindex]=='\0')
            return false;
        if(pattern[pindex+1]=='*') {
            if(pattern[pindex]==str[sindex] || (pattern[pindex]=='.' && str[sindex]!='\0'))
                //notice check if it's '\0' is very important
                //to cope up with pattern: ".*",str:""
          		return recur_match(str,pattern,sindex,pindex+2)
                    || recur_match(str,pattern,sindex+1,pindex+2)
                    || recur_match(str,pattern,sindex+1,pindex);  
            //notice it's shoulb be 2,but we can let it plus 1 so to cope up  with the 
            //str[sindex+1] =='\0'
            return recur_match(str,pattern,sindex,pindex+2);
        }
        //notice it should be check if str[sindex]=='\0' when pattern[pindex]=='.'
        else if(pattern[pindex]==str[sindex] || (pattern[pindex]=='.' && str[sindex]!='\0'))
            return recur_match(str,pattern,++sindex,++pindex);
        return false;
    }
};
