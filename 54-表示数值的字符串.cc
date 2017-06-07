class Solution {
public:
    bool isNumeric(char* str)
    {
        //notice 123.45e+6亦是合法的，前面的数可以是小数的
  		if(!str)
            return false;
        if(*str=='+' ||*str=='-')
            str++;
        //only digit
        while(isdigit(*str))
            str++;
        if(*str=='.') {
            str++;
            while(isdigit(*str))
                str++;
        }
        if(*str=='e' || *str=='E'){
            str++;
            if(*str=='-' || *str=='+')
                str++;
            if(!isdigit(*str))
                return false;
            while(isdigit(*str))
                str++;
        }
       	return !(*str);		
    }

};
