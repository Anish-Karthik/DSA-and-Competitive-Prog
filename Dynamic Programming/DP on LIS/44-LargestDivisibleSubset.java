class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int len = 1, start = 0;
        int seq[] = new int[n];
        int loc[] = new int[n];
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i<n; i++) {seq[i] = 1;loc[i] = i;}

        for(int ind = 1; ind<n; ind++) {
            for(int prev = 0; prev<ind; prev++)  {
                if(nums[ind]%nums[prev] == 0) {
                    if(seq[ind] < seq[prev] + 1) loc[ind] = prev;
                    seq[ind] = Math.max(seq[ind],seq[prev]+1);
                }
                if(len<seq[ind]) start = ind;
                len = Math.max(len,seq[ind]);
            }
        }
        while(loc[start] != start) {
            res.add(nums[start]);
            start = loc[start];
        }
        res.add(nums[start]);
        // Collections.reverse(res);
        return res;
    }
}
