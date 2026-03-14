class Solution {
public:
       bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
       }
    int maxVowels(string s, int k) {
       int right = 0 ;
       int left = 0 ; 
       int maxcount = 0; 
       int count = 0 ;
       while(right < s.size()){
         if(isVowel(s[right])) count ++;

         if(right - left + 1  > k){
          if(isVowel(s[left])){
            count --;
          }
            left ++;
         }
         if(right - left + 1 == k ){
            maxcount = max(maxcount , count);
         }
            right ++;
       }
        return maxcount;
    }
};