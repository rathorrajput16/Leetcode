class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
       
        int n=arr.size();
         vector<int>ans (n);
        for(int i=2*n-1;i>=0;i--){
           while(!st.empty()&&arr[st.top()%n]<=arr[i%n]){
            st.pop();
           }
           if(i<n){
            if(!st.empty())ans[i]=arr[st.top()%n];
            else ans[i]=-1;
           }
           st.push(i);
        }
        return ans;
    }
};