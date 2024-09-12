 
// Here sir has not used the concept of backtracking he only tells this 
// by using recursion not from backtracking. Here repetition is not allowed.

     #include<iostream>
     using namespace std;
    
    void permutations(string input,string output){
        if(input.size()==0){
            cout<<output<<endl;
            return;
        }
        for(int i=0;i<input.size();i++){
            char ch=input[i];
            string left=input.substr(0,i); // (It will take string from 0  i and "input.substr" is the reserved library)
            string right=input.substr(i+1);//  (It will take string from i and "input.substr" is the reserved library)
            string ros=left+right;
            permutations(ros,output+ch); //ros=rest of the string
        }
    }
     int main(){
        permutations("abc","");
        return 0;

     }

     // But it is not a good to make like this because i am making the new string 
     // so the memory will get full this recursion approach is not good in my approach.