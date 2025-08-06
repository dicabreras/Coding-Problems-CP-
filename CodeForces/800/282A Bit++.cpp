#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, X=0;
    string chain;
    cin>>n;
    for (int i = 0; i<n; i++){
        cin>>chain; 
        if(chain[1]=='+')
            X++;  
        
        else
             X--;               
    }
    cout<<X;
    return 0;
}
