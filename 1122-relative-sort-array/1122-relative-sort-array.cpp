class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int low = 0;
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr1.size(); j++){
                if(arr1[j] == arr2[i]){
                    int temp = arr1[low];
                    arr1[low] = arr1[j];
                    arr1[j] = temp;
                    low++;
                }
            }
        }
        
        sort(arr1.begin()+low, arr1.end());
        
        return arr1;
    }
};