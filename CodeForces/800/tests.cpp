#include <bits/stdc++.h>
using namespace std;


int const_i = 0, const_j=0;

void insertion_sort(int a[], int n){
    for(int j = 1; j< n; j++){
        //cout<<"valor de j: "<<j<<"   valor key: "<<a[j]<<endl;
        int key = a[j];
        int i = j-1;
        while (i>=0 & a[i]>key)
        {
         //   cout<<"entre, valor a[i]:"<<a[i]<<endl;
            a[i+1] = a[i];
            i=i-1;
            const_i++;
        }
        a[i+1]=key;
        if(i>=0)const_i++;
       // cout<<"Value const_i: "<<const_i<<endl;        
    }

   // for(int i = 0; i<n; i++) cout<<a[i]<<" ";
}

void merge(int b[], int p, int q, int z){
    int l = q-p+1, r = z-q;
   // cout<<"p: "<<p<<"   q: "<<q<<"  z: "<<z<<endl; 
    int L[l], R[r];
    for(int i = 0; i<l; i++) L[i] = b[p+i];
    for(int i = 0; i<r; i++) R[i] = b[q+1+i];

   // for(int i = 0; i<r; i++) cout<<L[i];
    //cout<<endl;
    //for(int i = 0; i<r; i++) cout<<R[i];
    //cout<<endl;

    int i = 0, j=0, k = p;
    while(i<l & j<r){
        const_j++;
        if(L[i]<=R[j]){
            b[k] = L[i];
            i++;
        }
        else{
            b[k] = R[j];
            j++;
        }
        cout<<"b_"<<k<<":  "<<b[k]<<endl;
        //cout<<"const j:  "<<const_j<<endl;
        k++;
    }
    
    while(i<l){
        b[k]= L[i];
        cout<<"b_"<<k<<":  "<<b[k]<<endl;
        i++; k++;
    }

    while(j<r){
        b[k] = R[j];
        cout<<"b_"<<k<<":  "<<b[k]<<endl;
        j++; k++;
    }
   // const_j++;
}

void merge_sort(int b[], int p, int r ){
    //const_j++;
    if(p<r){
        int q = (p+r)/2;
        merge_sort(b, p, q);
        merge_sort(b, q+1, r);
        merge(b, p, q, r);
      //  for(int i = 0; i<8; i++) cout<<b[i]<<" ";
        //cout<<endl;
    }

}


int main(){
    int n; cin>>n;
    int a[n];
    int b[n];
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        a[i] = x;
        b[i] = x;

    }

   // insertion_sort(a, n);
    merge_sort(b, 0, n);

    cout<<"const i: "<<const_i<<'\n';
    cout<<"const j: "<<const_j<<'\n';
  //  cout<<"arreglo A: ";
  // for(int i = 0; i<n; i++) cout<<a[i]<<" ";
    cout<<"_______________________________"<<endl;
   // cout<<"arreglo B: ";
    for(int i = 0; i<n; i++) cout<<b[i]<<" ";
    return 0;
}