#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ADN_chain;
    int lengthiest = 1, cont=1; 
    char letter_to_compare;
    cin>>ADN_chain;
    letter_to_compare = ADN_chain[0];
    for(int i = 1; i<ADN_chain.size(); i++){
        if (ADN_chain[i] == letter_to_compare)
        {
            cont++;
        }

        if (ADN_chain[i] != letter_to_compare || i==ADN_chain.size()-1){
            if(cont>lengthiest){
                lengthiest= cont; 
            }
            cont = 1;                                      
        }        
        letter_to_compare = ADN_chain[i];  
    }

    cout<<lengthiest;
    return 0;
}
