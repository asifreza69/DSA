class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int i = 0;

        while(i < a.size()){
            if(st.empty()){
                st.push(a[i]);
            }
            else{
                bool destroyed = false;

                if(st.top() > 0 && a[i] < 0){

                    // pop all smaller positives
                    while(!st.empty() && st.top() > 0 && st.top() < abs(a[i])){
                        st.pop();
                    }

                    // equal case
                    if(!st.empty() && st.top() == abs(a[i])){
                        st.pop();
                        destroyed = true;
                    }
                    // bigger positive survives
                    else if(!st.empty() && st.top() > abs(a[i])){
                        destroyed = true;
                    }
                    // stack empty OR negative on top → current survives
                }

                if(!destroyed){
                    st.push(a[i]);
                }
            }
            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
