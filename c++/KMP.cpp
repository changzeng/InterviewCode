#include<iostream>
#include<string>

using namespace std;

int* preProcess(string pattern,int* next){
   int p_len = pattern.size();
   int i=0,j=0;

   next[0] = 0;
   next[1] = 0;

   for(i=1;i<p_len;i++){
        while(j!=0 && pattern[i]!=pattern[j])j=next[j];
        if(pattern[i]!=pattern[j]) j++;
        next[i+1] = j;
   }

   return next;
}

bool match(string pattern,string text){
    int p_len=pattern.size(),t_len=text.size();

    int next[p_len+1];
    preProcess(pattern,next);

    /*
    for(int i=0;i<=p_len;i++)
        cout<<next[i]<<" ";
    cout<<endl;
    */

    int j=0;
    for(int i=0;i<t_len;i++){
        if(text[i] == pattern[j])
            j++;
        else
            while(j != 0 && text[i] != pattern[j])
                j = next[j];

        if(j == p_len)
            return true;
    }

    return false;
}

int main(){
    cout<<match("aaaffegrgt","agcafaaaJJaaaJaaaffegrgtsdfdsf")<<endl;

    return 0;
}
