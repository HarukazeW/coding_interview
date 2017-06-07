class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        //notice error data
        if(!numbers || length<=0)
            return false;
        for(int i=0;i<length;i++)
            if(numbers[i]>=length || numbers[i]<0)
                return false;
        int index=0;
        while(index<length){
            if(numbers[index]!=index) {
                if(numbers[numbers[index]]==numbers[index]) {
                    *duplication=numbers[index];
                    return true;
                }
                    //swap it
                int temp=numbers[numbers[index]];
                numbers[numbers[index]]=numbers[index];
                numbers[index]=temp;
            }
            else 
                //notice it
                index++;
        }
        return false;
    }
};
