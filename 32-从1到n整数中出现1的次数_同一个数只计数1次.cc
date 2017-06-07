#include<iostream>
using namespace std;

int NumberOf1Between1AndN(unsigned int n) {
	int num_1[15];
	num_1[0]=0;
	unsigned long long base=1;
	for(int i=1;i<14;i++) {
		num_1[i]=9*num_1[i-1]+base;
		base*=10;
	}
	
	int digits=0;
	base=1;
	while(base<=n){
		digits++;
		base*=10;
	}
	digits--;
	base/=10;

	unsigned number=n;
	int dig_num;
	int count=0;
	while(digits>=0){
		dig_num=number/base;
		number=number%base;
		if(dig_num==1){
			count+=num_1[digits]+number+1;
			break;
		}
		else if(dig_num>1){
			count+=num_1[digits]*(dig_num-1)+base;
		}
		base/=10;
		digits--;
	}
	return count;
}

int main() {
	int a;
	while(cin>>a)
		cout<<NumberOf1Between1AndN(a)<<endl;
	return 0;
}
	

