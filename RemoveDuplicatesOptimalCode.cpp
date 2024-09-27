class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
     int count=0;
     int prevUniqueIndex=-1;

     for(int i=0; i<nums.size(); i++){

        if(prevUniqueIndex == -1){
            count++;
            prevUniqueIndex++;
        }
        else
        if(nums[i] != nums[prevUniqueIndex]){
          
            nums[count] = nums[i];
            count++;
            prevUniqueIndex++;
        }
     }

     return count;
    
    }
};
