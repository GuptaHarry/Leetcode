// class Solution {
// public:
//     string fractionToDecimal(int n, int d) {
        
//        double val = (double)n/(double)d;
//         string  ans = "";
//         ans+=to_string(val);

//         string res = "";
//         int point =-1;
//         for(int i=0;i<ans.size();i++){
//             if(ans[i]!='.'){
//                 res+=ans[i];
//             }else{
//             //    res+='.';
//                break;
//                point = i+1;

//             }
//         }

// // vector to map all the values 
// vector<int>m(10,-1);
// vector<int>temp;
//         while(point<ans.size()){
//             if(m[ans[point]-'0']==-1)
//             {
//                 m[ans[point]-'0']=0;
//                 m[ans[point]-'0']++;
//                 temp.push_back(ans[point]-'0'); // who arrive firwst 
//             }
//            point++;
//         }

//         // base case for excluding zero 
        
//         // add point and bracket
//         res+=".(";

//         for(int i=0;i<temp.size();i++){
//             if(m[temp[i]]!=-1){
//                res+=i;     
//             }
//         }

//         if(res[res.size()-1]=='0')
//         {
//             res.pop_back();
//             if(res[res.size()-1]=='(')
//             {
//                 res.pop_back();
//                 res.pop_back();
//                 return res;
//             }   

//         }

//         res+=")";

//         return res;
//     }
// };

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;

        // sign
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // integer part
        ans += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return ans; // no fractional part

        ans += ".";

        unordered_map<long long, int> seen; // remainder -> position in ans
        while (rem != 0) {
            if (seen.count(rem)) {
                // repeating detected
                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }
            seen[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }
        return ans;
    }
};
