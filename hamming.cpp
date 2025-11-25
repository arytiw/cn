#include<iostream>
#include<string>

using namespace std;

int main(){
    int a[8] = {0};

    string str;
    cout<<"Enter the data bits D3 D5 D6 D7"<<endl;
    cin>>str;

    a[3] = str[0]-'0';
    a[5] = str[1]-'0';
    a[6] = str[2]-'0';
    a[7] = str[3]-'0';

    a[1] = a[3]^a[5]^a[7];
    a[2] = a[3]^a[6]^a[7];
    a[4] = a[5]^a[6]^a[7];

    cout<<"The Encode bits: "<<endl;
    for(int i = 1;i<=7; i++){
        cout<<a[i];
    }

    string rec;
    int r[8];
    cout<<"Enter Received bits:"<<endl;
    cin>>rec;

    for(int i = 1; i<=7; i++){
        r[i] = rec[i-1]-'0';
    }

    int s1 = r[1]^r[3]^r[5]^r[7];
    int s2 = r[2]^r[3]^r[6]^r[7];
    int s4 = r[4]^r[5]^r[6]^r[7];
    int s = s1*1 + s2*2 + s4*4;

    if(s==0){
        cout<<"No error detected"<<endl;
    }

    else{
        cout<<"Error found in bit position: "<<s<<endl;

    }
    
}