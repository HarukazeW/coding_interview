class Solution
{
    int occur[256];
    int index=0;

public:
    Solution() {
    	for(int i=0;i<256;i++)
       		occur[i]=-1;
	}
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(occur[ch]==-1)
            occur[ch]=index++;
        else
            occur[ch]=-2;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	int min_index=-1;
        int seq=INT_MAX;
        for(int i=0;i<256;i++)
            if(occur[i]>=0 && (occur[i]<seq)){
                seq=occur[i];
                min_index=i;
            }
        return min_index>=0?min_index:'#';
        
    }

};
