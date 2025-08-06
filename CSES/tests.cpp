#include<bits/stdc++.h>
using namespace std;
int main()
{
string n;
cin>>n;
int a,sum=1;
for (int i=0;i<n.size();i++)
{
	if(n[i]==n[i+1]) sum++;
	else {
		if(a<sum) a=sum;
		sum=1;
	}
}
cout<<a;
}

/*

Repetitions CSES

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ADN_chain;
    int lengthiest = 0, cont=0; 
    char letter_to_compare;
    cin>>ADN_chain;
    letter_to_compare = ADN_chain[0];
    for(const auto &letter: ADN_chain){
        //cont++;
        cout<<letter<<"     "<<letter_to_compare<<"\n";
        if (letter != letter_to_compare){
                //cout<<cont<<"\n"; 
            if(cont>lengthiest){
                lengthiest= cont; 
            }
            cont = 0;  
            letter_to_compare = letter;                          
        } 
        cont++;
        cout<<cont<<"\n"; 
    

    }
    if(lengthiest==0)
        lengthiest += cont;    
    cout<<lengthiest;
    return 0;
}


*/