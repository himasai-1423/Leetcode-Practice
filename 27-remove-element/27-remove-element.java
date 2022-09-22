class Solution
{
    public int removeElement(int[] nums, int val) 
    {
        int i, j=0, cnt=0;
        int n=nums.length;
        for(i=0;i<n;i++)
        {
            if(nums[i]!=val){
                nums[j] = nums[i];
                j++;
                cnt++;
            }
        }
        return cnt;
    }
}