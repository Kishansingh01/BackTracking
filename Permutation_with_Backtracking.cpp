// Here sir is doing permutation but repetitions are not allowed.

// // Below code is for non repeating strings.

// #include<iostream>
// using namespace std;

// void permutations(string &str,int i){
//     if(i== str.size()-1){
//         cout<<str<<endl;
//         return;
//     }
//     for(int idx=i;idx < str.size();idx++){
//         swap(str[idx],str[i]);
//         permutations(str,i+1);
//        swap(str[idx],str[i]);// if i will remove the swapping process it will come again for the third.
//     // And this swap is the process of backtracking.
//     }
// }
// int main(){
//      string str="aba";
//      permutations(str,0);
//      return 0;
// }






// Below code is for  repeating strings.

#include<iostream>
#include<unordered_set>
using namespace std;

void permutations(string &str,int i){
    if(i== str.size()-1){
        cout<<str<<endl;
        return;
    }
    unordered_set<char> s; //for repeating  things i am doing backtracking.
    for(int idx=i;idx < str.size();idx++){
        if(s.count(str[idx])) continue;
        s.insert(str[idx]);

        swap(str[idx],str[i]);
        permutations(str,i+1);
       swap(str[idx],str[i]);// if i will remove the swapping process it will come again for the third.
    // And this swap is the process of backtracking.
    }
}
int main(){
     string str="aba";
     permutations(str,0);
     return 0;
}