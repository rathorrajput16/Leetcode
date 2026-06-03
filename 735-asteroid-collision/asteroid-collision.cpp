class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        bool gt=false;
        for(int i=0;i<asteroids.size();i++){
          
            if(asteroids[i]>0){
                st.push(asteroids[i]);
                gt=true;
            }
            else{
                while(!st.empty()&&st.top()<abs(asteroids[i])) st.pop();
                if(st.empty()){
                  ans.push_back(asteroids[i]);
                }
                else{
                    int num=st.top();
                    st.pop();
                    int val=num+asteroids[i];
                    if(val==0){

                    }
                    else{
                        st.push(num);
                    }
                }

            }
        }
        vector<int>ans1;
        while(!st.empty()){
                     ans1.push_back(st.top());
                     st.pop();
        }
        for(int i=ans1.size()-1;i>=0;i--)ans.push_back(ans1[i]);
        return ans;
    }
};