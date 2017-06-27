#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x != 0){
            if((result*10)/10 != result)
                return 0;
            result *= 10;
            result += x%10;

            x /= 10;
        }

        return result;
    }
};

int main(){
    Solution s;
    int r = s.reverse(1233222242);
    cout<<r<<endl;
}
