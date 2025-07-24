#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways
long long numberOfWays(string s){
    long long c =0;
    int  n = s.length();
    vector<int> z(n,0);
    vector<int>p(n,0);
    for(int i = n-1;i>=0;i--){
        if(s[i] == '0'){
            if(i == n-1){
                p[i] = 0;
                z[i] = 1;

            }
            else{
                z[i]=z[i+1]+1;
                p[i]=p[i+1];

            }

        }
        else{
            if(i == n-1){
                z[i] = 0;
                p[i] = 0;

            }
            else{
                z[i] = z[i+1];
                p[i]=p[i+1]+z[i];
            }

        }
    }
    for(int i =0;i<n;i++){
        if(s[i]=='1'){
            c=c+p[i];
        }
        z[i]=0;
        p[i]=0;
    }
    for(int i = n-1;i>=0;i--){
        if(s[i] == '1'){
            if(i == n-1){
                p[i] = 0;
                z[i] = 1;

            }
            else{
                z[i]=z[i+1]+1;
                p[i]=p[i+1];

            }

        }
        else{
            if(i == n-1){
                z[i] = 0;
                p[i] = 0;

            }
            else{
                z[i] = z[i+1];
                p[i]=p[i+1]+z[i];
            }

        }
    }
    for(int i =0;i<n;i++){
        if(s[i]=='0'){
            c=c+p[i];
        }
        z[i]=0;
        p[i]=0;
    }
    return c;

}
int main()
{
    // First test case
    string s = "00110";
    cout << numberOfWays(s) << endl;

    // Second test case
    s = "11100";
    cout << numberOfWays(s) << endl;

    // Third test case
    s = "0000";
    cout << numberOfWays(s) << endl;

    // Fourth test case
    s = "101";
    cout << numberOfWays(s);

    return 0;
}