class Solution {
public:
    vector<string>ans;
    
    void solver(string digits, int i=0, string s=""){
        if(i==digits.length() and i!=0){
            ans.push_back(s);
            return;
        }
        
        if(digits[i]=='2'){
            for(char x = 'a' ; x<='c' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        
        if(digits[i]=='3'){
            for(char x = 'd' ; x<='f' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='4'){
            for(char x = 'g' ; x<='i' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='5'){
            for(char x = 'j' ; x<='l' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='6'){
            for(char x = 'm' ; x<='o' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='7'){
            for(char x = 'p' ; x<='s' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='8'){
            for(char x = 't' ; x<='v' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        if(digits[i]=='9'){
            for(char x = 'w' ; x<='z' ; ++x){
                solver(digits,i+1,s+x);
            }
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        solver(digits);
        return ans;    
    }
};