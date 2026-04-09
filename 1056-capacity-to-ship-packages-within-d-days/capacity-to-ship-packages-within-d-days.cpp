class Solution {
public:
  int funct(vector<int>&weights, int cap){
     int days = 1 ; 
     int load = 0  ; 
    for(int i = 0 ; i < weights.size(); i++){
        if(load + weights[i] > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
  }
    int shipWithinDays(vector<int>& weights, int days) {
        // for getting max element  
        int low = *max_element(weights.begin(), weights.end());
        // for getting sum of that vector:STL functions 
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high)/2;
            int numofdays = funct(weights, mid);
            if(numofdays <= days){
                high = mid - 1;
            }
            else{
                low = mid +  1 ; 
            }   
        }
        return low; 
    }
};