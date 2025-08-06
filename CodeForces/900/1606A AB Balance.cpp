#include <bits/stdc++.h>

using namespace std; 

void print_new_chain(string chain, int last_index);
int main()
{
    string chain;
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>chain;
        int last_index = chain.size()-1;
        print_new_chain(chain, last_index);
    }
    return 0;
}

void print_new_chain(string chain, int last_index){
    int ABs = 0, BAs = 0;
    char first_char = chain[0];
    if(chain[last_index]==chain[0]){
        cout<<chain<<"\n";
    }
    else{
        switch (chain[0])
        {
        case 'a':
            cout<<chain.substr(0,last_index)+"a\n";
            break;
        
        case 'b':
            cout<<chain.substr(0,last_index)+"b\n";
            break;
        }
    }
  
}