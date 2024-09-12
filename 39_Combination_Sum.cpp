//   39..   

  // In basic term if we do like that we have to do in O(2^n).  Repetition number i can take. And repetition in array is not allowed

class Solution{
    public:
     vector<vector<int>> result; // Global

     void f(vector<int> &cand,int t,int idx,vector<int> &subset){
        if(t==0){
            // we found a subset which sums to target
            result.push_back(subset);
            return;
        }
        if(idx== cand.size()) return ;
        if(cand[idx] <= t){
            subset.push_back(cand[idx]);
            f(cand,t-cand[idx],idx,subset);
            subset.pop_back();
        }
        // avoid
        int j=idx+1;
      //  while(j < cand.size() and cand[j]==cand[j-1]) j++;
        f( cand,t,j,subset);
     }
     vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        result.clear();
        f(candidates,target,0,subset);
        return result;
     }
};