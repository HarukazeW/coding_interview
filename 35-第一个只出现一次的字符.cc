class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		vector<int> times(256,0);
		for(auto c:str)
			times[c]++;
		for(int i=0;i<str.size();i++) {
			if(times[str[i]]==1)
				return i;
		}
		return -1;
	}
};
