class Solution
{
    int LDS(int[] nums, int[] dec) {
        int len = 1;
        int n = nums.length;
        for(int i = n-1; i>=0; i--) dec[i] = 1;
        for(int ind = n-1; ind>=0; ind--) {
            for(int prev = n-1; prev> ind; prev--)  {
                if(nums[prev]<nums[ind]) 
                    dec[ind] = Math.max(dec[ind],dec[prev]+1);
                len = Math.max(len,dec[ind]);
            }
        }
        return len;
    }
    int LIS(int[] nums, int[] inc) {
        int len = 1;
        int n = nums.length;
        for(int i = 0; i<n; i++) inc[i] = 1;
        for(int ind = 1; ind<n; ind++) {
            for(int prev = 0; prev<ind; prev++)  {
                if(nums[prev]<nums[ind]) 
                    inc[ind] = Math.max(inc[ind],inc[prev]+1);
                len = Math.max(len,inc[ind]);
            }
        }
        return len;
    }
    public int LongestBitonicSequence(int[] nums)
    {
        int n = nums.length;
        int inc[] = new int[n];
        int dec[] = new int[n];
        int ilen = LIS(nums,inc);
        int dlen = LDS(nums,dec);
        int res = Math.max(ilen,dlen);
        for(int i = 0; i<n; i++) {
            res = Math.max(res, dec[i] + inc[i] - 1);
        }
        // System.out.println(Arrays.asList(dec));
        return res;
    }
}
