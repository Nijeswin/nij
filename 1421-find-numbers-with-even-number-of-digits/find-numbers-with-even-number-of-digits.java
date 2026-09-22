class Solution {
    public int findNumbers(int[] nums) {
        int num=nums.length;
        int sum=0;
        for(int i=0;i<num;i++){
            int a=nums[i];
            int result=0;
            while(a>0){
                int rem=a/10;
                result++;
                a=rem;
            }
            if (result%2==0){
                sum++;
            }
        }
        return sum;
    }
}