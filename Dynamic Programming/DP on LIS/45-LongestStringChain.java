class Solution {
    boolean strcmp1diff(String s1, String s2) {
        if(s1.length() - s2.length() != 1) return false;
        int diff = 0;
        int j = 0,i = 0;
        for(i = 0;i<s1.length()-1; i++) {
            if(s1.charAt(i) != s2.charAt(i-diff)) diff++;
            if(diff > 1) return false;
        }
        if(s1.charAt(i)!=s2.charAt(i-1))
        diff++; 
        if(diff > 1) return false;
        return true;
    }
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparing(s->s.length()));
        int n = words.length;
        int len = 1, start = 0;
        int seq[] = new int[n];
        int loc[] = new int[n];
        List<String> res = new ArrayList<>();
        for(int i = 0; i<n; i++) {seq[i] = 1;loc[i] = i;}

        for(int ind = 1; ind<n; ind++) {
            for(int prev = 0; prev<ind; prev++)  {
                if(strcmp1diff(words[ind],words[prev])) {
                    if(seq[ind] < seq[prev] + 1) loc[ind] = prev;
                    seq[ind] = Math.max(seq[ind],seq[prev]+1);
                }
                if(len<seq[ind]) start = ind;
                len = Math.max(len,seq[ind]);
            }

        }
        // To print sequence
        // while(loc[start] != start) {
        //     res.add(words[start]);
        //     start = loc[start];
        // }
        // res.add(words[start]);
        // Collections.reverse(res);
        // System.out.println(res);
        // return res;
        return len;
    }
}
