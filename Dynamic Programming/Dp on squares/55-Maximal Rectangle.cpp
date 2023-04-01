class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxA = 0;
        for(int i = 0; i<=n; i++) {
            int &x = heights[i];
            while(!st.empty() && (i==n || heights[st.top()]>= x)) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty()? i: i-st.top()-1;
                maxA = max(maxA, height*width);
            }
            st.push(i);
        }
        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxA = 0;
        int n = matrix.size(), m= matrix[0].size();
        vector<int> heights(m,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if (matrix[i][j]== '1') heights[j]++;
                else heights[j] = 0;
            }
            maxA = max(maxA, largestRectangleArea(heights));
        }
        return maxA;
    }
};
