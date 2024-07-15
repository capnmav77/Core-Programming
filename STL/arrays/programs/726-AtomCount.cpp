#include<iostream>
#include<bits/stdc++.h>

// reverse iterator
// class Solution {
// public:
//     string countOfAtoms(string formula) {
//         map<string,int> element_count;
//         string ans;
//         vector<string> placeholder = update_elem(formula , formula.length()-1 , element_count);
//         auto it = element_count.begin() ;
//         while(it!=element_count.end()){
//             ans = ans + it->first ;
//             if(it->second > 1){
//                ans = ans + std::to_string(it->second);
//             }
//             it++;
//         }
//         return ans;
        
//     }

// private:

//     vector<string> update_elem(string formula , int loc ,map<string,int>& elem_count ){
//         int multiplicity = 1;
//         vector<string> temp_elem;
//         vector<string> elems;
//         char part_elem = '1';
//         while(loc>=0){
//             if(formula[loc] == ')'){
//                 elems = update_elem(formula , loc-1 , elem_count);
//                 temp_elem.insert(temp_elem.end() , elems.begin(),elems.end());
//                 while(formula[loc] != '('){
//                     loc--;
//                 }
//                 for(int i=0 ; i<elems.size() ; i++){
//                     elem_count[elems[i]] *= multiplicity;
//                 }
//                 loc --;
//             }
//             else if(formula[loc] == '('){
//                 return temp_elem;
//             }
//             else if(formula[loc] >= '0' && formula[loc] <='9'){
//                 multiplicity = formula[loc]-'0';
//                 loc--;
//             }
//             else if (isupper(formula[loc])){
//                 string elemen ="" ; elemen += formula[loc];
//                 if(part_elem != '1'){
//                     elemen += part_elem;
//                 }
                
//                 if(elem_count[elemen]>0){
//                     elem_count[elemen] = multiplicity==1?elem_count[elemen]+1:elem_count[elemen]*multiplicity;
//                     loc--;
//                 }
//                 else{
//                     elem_count[elemen]++;
//                     temp_elem.push_back(elemen);
//                     loc--;
//                 }
//             }
//             else{
//                 part_elem = formula[loc];
//                 loc--;
//             }
//         }
//         return temp_elem;
        
//     }
// };

// another solution 
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> element_count;
        update_elem(formula, 0, formula.length(), 1, element_count);
        
        string ans;
        for (const auto& pair : element_count) {
            ans += pair.first;
            if (pair.second > 1) {
                ans += to_string(pair.second);
            }
        }
        return ans;
    }

private:
    int update_elem(const string& formula, int start, int end, int multiplier, map<string, int>& elem_count) {
        int i = start;
        while (i < end) {
            if (formula[i] == '(') {
                int j = find_closing_parenthesis(formula, i);
                int sub_multiplier = get_number(formula, j + 1, end);
                update_elem(formula, i + 1, j, multiplier * sub_multiplier, elem_count);
                i = j + 1;
                while (i < end && isdigit(formula[i])) i++;
            } else if (isupper(formula[i])) {
                int j = i + 1;
                while (j < end && islower(formula[j])) j++;
                string element = formula.substr(i, j - i);
                int count = get_number(formula, j, end);
                elem_count[element] += multiplier * (count == 0 ? 1 : count);
                i = j;
                while (i < end && isdigit(formula[i])) i++;
            } else {
                i++;
            }
        }
        return i;
    }

    int find_closing_parenthesis(const string& formula, int start) {
        int count = 0;
        for (int i = start; i < formula.length(); i++) {
            if (formula[i] == '(') count++;
            if (formula[i] == ')') count--;
            if (count == 0) return i;
        }
        return formula.length();
    }

    int get_number(const string& formula, int start, int end) {
        int result = 0;
        while (start < end && isdigit(formula[start])) {
            result = result * 10 + (formula[start] - '0');
            start++;
        }
        return result == 0 ? 1 : result;
    }
};


int main(){
  Solution s; 
  string ques = "Mg(OH)2";
  string ans = s.countOfAtoms(ques);
  cout<<ans;
  return 0;
}
