class Solution {
public:

    

    string largestNumber(vector<int>& nums) {
        
        if(nums.size() == 0) return "";
        if(nums.size() == 1) return to_string(nums[0]);
        string res = "";
        vector<int> myans = mergeSort(nums);
        for(int i = 0; i < myans.size() ; i ++){
            res += to_string(myans[i]);
        }
        while(res.length() > 1 && res[0] == '0'){
            res = res.substr(1);
        }
        return res;
        
    }
    
    vector<int> mergeSort(vector<int> arr){
        if(arr.size() == 1) return arr;
        else if(arr.size() == 2){
            int big = findBig(arr[0],arr[1]);
            int small = big == arr[0] ? arr[1] : arr[0];
            arr[0] = big;
            arr[1] = small;
            return arr;
        }
        
        vector<int> lo (arr.begin(), arr.begin() + (arr.size() - 1) / 2 + 1); 
        vector<int> hi (arr.begin() + (arr.size() - 1) / 2 + 1, arr.end());
        lo = mergeSort(lo);
        hi = mergeSort(hi);
        int ptr1 = 0, ptr2 = 0, ptr = 0;
        while(ptr1 < lo.size() && ptr2 < hi.size()){
            if(findBig(lo[ptr1], hi[ptr2]) == lo[ptr1]){
                arr[ptr++] = lo[ptr1++];
            }else{
                arr[ptr++] = hi[ptr2++];
            }
        }
        while(ptr < arr.size()){
            arr[ptr++] = (ptr2 < hi.size()) ? hi[ptr2++] : lo[ptr1++];
        }
        return arr;
    }
    
    int findBig(int x, int y){
        if(to_string(x) + to_string(y) >= to_string(y) + to_string(x)){
            return x;
        }else{
            return y;
        }
    }
    
};
