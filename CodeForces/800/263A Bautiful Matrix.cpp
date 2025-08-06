#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string matrix[5];
    int row, column, steps;
    for(int i = 0; i<5; i++){
        getline(cin, matrix[i]);
    }
    for(int j =0; j<5; j++){
        if(matrix[j].find('1') !=string::npos){
            row = j;
            column = matrix[j].find('1')/2;
        }   
    }
    steps = abs(2-row)+abs(2-column);
    cout<<steps;
    return 0;
}
