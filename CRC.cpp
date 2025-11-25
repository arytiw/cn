#include<iostream>
#include<string>
using namespace std;

string Xor(string a, string b){
    int n = a.length();
    string r = "";
    for(int i = 1; i<n; i++){
        if(a[i] == b[i]){
            r += '0';
        }
        else{
            r += '1';
        }
    }
    return r;

}


string mod2div(string divid,string key){
    int n = divid.length();
    int pick = key.length();
    string temp = divid.substr(0,pick);

    while(pick < n){
        if(temp[0] == '1'){
            temp = Xor(key,temp) + divid[pick];
        }
        else{
            temp = Xor(string(key.length(),'0'),temp) + divid[pick];
        }
        pick++;
    }

    if(temp[0] == '1'){
        temp = Xor(key,temp);
    }
    else{
        temp = Xor(string(key.length(),'0'),temp);
    }

    return temp;
}

string encode(string data, string divisor) {
    int n = divisor.length();
    string paddedData = data + string(n - 1, '0'); 
    string remainder = mod2div(paddedData, divisor);
    return data + remainder; 
}

int recev(string rec,string key){
    string rem = mod2div(rec,key);
    return (rem == string(key.length()-1,'0'))? 1:0;
}

int main(){
    string sed;
    cout<<"Enter the sender side data: ";
    cin>>sed;
    cout<<endl;
    string key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<endl;
    cout<<"The encode data is: "<<encode(sed,key)<<endl;

    string rec;
    cout<<"Enter the data you recieved: ";
    cin>>rec;

    if(recev(rec,key)){
        cout<<"No error detected in the data"<<endl;

    }
    else{
        cout<<"Error detected in the data"<<endl;
    }


}