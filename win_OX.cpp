#include <bits/stdc++.h>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<"|"<<" ";
        if(i==2 || i==5 ){
            cout<<endl;
            cout<<"______________";
            cout<<endl;
        }
    }
    cout<<endl;
}

int input(int a[],int n){
    int input_index;
    cout<<"Enter index of X"<<endl;
    cin>>input_index;
    if(a[input_index]!=-1){
        cout<<"This index box is not empty....Please try again.. :)"<<endl;
        input_index=input(a,n);
    }
    a[input_index]=1;
    print(a,n);
    cout<<"Computer turn :- "<<endl;
    return input_index;
}

void win_stape_for_all(int a[],int n,int index){
    int i,j,k,l;
    if(index==1 || index==0) {
        i=8;j=5;k=6,l=7;
    }
    else if(index==7 || index==6){
        i=8;j=5;k=0,l=1;
    }
    else if(index==5 || index==8){
        i=0;j=1;k=6,l=3;
    }
    else{
        i=0;j=1;k=8,l=5;
    }
    a[i]=0;
    print(a,n);
    int input_index=input(a,n);
    if(input_index!=j){
        a[j]=0;
        print(a,n);
        cout<<"Computer win  !!"<<endl;
        return ;
    }
    a[k]=0;
    print(a,n);
    input_index=input(a,n);
    if(input_index==4){
        a[l]=0;
        print(a,n);
        cout<<"Computer win  !!"<<endl;
        return ;
    }
    else{
        a[4]=0;
        print(a,n);
        cout<<"Computer win  !!"<<endl;
        return ;
    }
}

void win_stape_for_4 (int a[],int n){
    a[6]=0;
    print(a,n);
    int privius_input=input(a,n);
    a[8-privius_input]=0;
    print(a,n);
    int input_index=input(a,n);
    int i;
    if(privius_input==3 || privius_input==1 || privius_input==8)
        i=0;
    else
        i=8;
    int j,k;
    if(privius_input==abs(i-1)){
        j=3;
        k=5;
    }
    else{
        j=1;
        k=7;
    }
    if(privius_input==abs(i-3) || privius_input==abs(i-1)){
        if(input_index!=abs(i-8)){
            a[abs(i-8)]=0;
            print(a,n);
            cout<<"Computer win  !!"<<endl;
            return ;
        }
        a[abs(i-0)]=0;
        print(a,n);
        input_index = input(a,n);
        if(input_index!=abs(i-j)){
            a[abs(i-j)]=0;
            print(a,n);
            cout<<"Computer win  !!"<<endl;
            return ;
        }
        a[abs(i-k)]=0;
        print(a,n);
        cout<<"Match will drow..."<<endl;
        return ;
    }
    else{
        if(input_index==abs(i-1))
            a[abs(i-3)]=0;
        else
            a[abs(i-1)]=0;
        print(a,n);
        cout<<"Computer win  !!"<<endl;
        return ;
    }
}

int main(){
    cout<<"Lets play O-X"<<endl;
    cout<<"tamare X karvani and mare O and hu 1st"<<endl;
    cout<<"tamare index nakhavani jya tamare X mukavi hoy eni \nE.X. \nniche badha box ni index 6e e pramane..: ) "<<endl;
    int n=9;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<" "<<i<<" "<<"|"<<" ";
        if(i==2 || i==5 ){
            cout<<endl;
            cout<<"_______________";
            cout<<endl;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        a[i]=-1;
    cout<<"Computer turn :-"<<endl;
    a[2]=0;
    print(a,n);
    int input_index=input(a,n);
    if(input_index!=4)
        win_stape_for_all(a,n,input_index);
    else 
        win_stape_for_4(a,n);
    return 0;
}