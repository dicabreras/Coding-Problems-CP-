#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--){
        char* num;
        cin>>num;
        
        for(int i =0; i<sizeof(num); i++){
            char* number = num*[i];

            cout<<atoi(number)<<"\n";
        }
    }
    return 0;
}
