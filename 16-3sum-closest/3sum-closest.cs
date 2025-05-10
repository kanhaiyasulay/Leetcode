public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {

       Array.Sort(nums);

       int melhor = nums[0] + nums[1]+ nums[2];

        if(melhor ==target){
            return melhor;
        }

        for(int i=0;i<nums.Length-2;i++){

            int anterior = i+1;
            int posterior = nums.Length-1;

            while(anterior < posterior){

                int atual = nums[anterior] + nums[i]+ nums[posterior];
                if (Math.Abs(target - atual) < Math.Abs(target - melhor)){
                    melhor = atual;
                }
                    
                if(atual < target){
                    anterior++;
                }
                else if(atual > target){
                    posterior--;
                }
                else{
                    return atual;
                }
            }
        }
        return melhor;
    }
}