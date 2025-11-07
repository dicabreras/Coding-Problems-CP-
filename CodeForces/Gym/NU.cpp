/*
Coded by Diego CabreraP
Codeforces username : GAL1LEO-DC
*/
#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;  
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

double weighted_avg  = 0;
double total = 0;
double total_loss = 0;
double total_gain = 0;


class Operation {
    private: 
        string operation;
        double unitCost;
        double quantity;
        double weight; 

        public:
        // Here I can declare some methods;

            void setOperation(int op){
                if(op == 1){
                    operation = "buy";
                }
                else if (op == 2){
                    operation = "sell";
                }
                else{
                    operation = "invalid";
                }
            }

            void setUnitCost(double uC){
                unitCost = uC;
            }
            void setQuantity(double q){
                quantity = q;
            }

            string getOperation(){
                return operation;
            }
            
            double getUnitCost(){
                return unitCost;
            }
            
            double getQuantity(){
                return quantity;
            }

            //Constructor Overloaded

            Operation(){
                operation = "No operation";
                unitCost = 0;
                quantity = 0; 
            }
            //Constructor
            Operation(int op, int uC, int q){
                setOperation(op);
                unitCost = uC;
                quantity = q; 
                weight = uC*q;

            }
};

class Tax{
    private: 
        double tax;
    
    public: 

        // Here I can declare some methods;

        void setTax(int tx){
            tax = tx;
        }

        double getTax(){
            return tax; 
        }

        //Constructor overloaded
        Tax(){
            tax = 0.2;
        }
        Tax(double tx){
            tax = tx;
        }

};


double selling(double n){
    double current_price = weighted_avg/total;
    return current_price*n;
}

double gain(double bought, double sold, double n){    
    double total_bought = bought*n, total_sold = sold*n;

    return total_sold - total_bought;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    Operation op1(1, 20, 1000);  //buy
    Operation op2(2, 20, 1050);  //sell
    Operation op3(1, 30, 1030); //buy;
    Operation op4(1, 40, 1000); //buy
    Operation op5(2, 20, 900); //sell

    Operation ops[5] = {op1, op2, op3, op4, op5};



    for(int i = 0; i<5; i++){
        if(ops[i].getOperation() == "sell"){
            double current = selling(ops[i].getQuantity());
            double current_gain = gain(ops[i].getUnitCost(), current, ops[i].getQuantity());
            double current_taxes;
            total_gain+=current_gain;
            if(total_gain> 0){
                Tax tx;
                current_taxes = total_gain*tx.getTax();
            }
            else{
                total_loss+=total_gain;
            }
            cout<<"for this operation your gain was: "<<current_gain<<ln;
            cout<<"for this operation your taxes sums: "<<current_taxes<<ln;

        }
        else{
            weighted_avg+=(ops[i].getQuantity()*ops[i].getUnitCost());
            total+=ops[i].getQuantity();
        }

    }


    return 0;
}
