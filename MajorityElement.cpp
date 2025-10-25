class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int req = arr[0];
        int ctr = 1;
        for (int i=1; i<arr.size(); i++){
            if (ctr == 0) {
                ctr++;
                req = arr[i];
            }
            else{
                if (arr[i] == req) ctr++;
                else{
                    ctr--;
                }
            }
        }
        return req;
    }
};
