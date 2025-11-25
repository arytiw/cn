#include<iostream>
#include<string>

using namespace std;


int calpar(string a, bool even){
    int cntone = 0;

    for(char b :a){
        if(b == '1'){
            cntone++;
        }
    }

    if(even){
        return (cntone % 2 == 0)?0:1;
    }
    else{
        return (cntone % 2 == 0)?1:0;
    }
}


int main(){
    string str;

    cout<<"Enter the string";
    cin>>str;
    int ch;
    cout<<"Enter the choice\n1.Even\n2.Odd"<<endl;
    cin>>ch;

    bool even = (ch == 1)?true:false;

    int senparity = calpar(str,even);
    cout<<"Sent string is: "<<str<<senparity<<endl;

    string rec;
    cout<<"Enter the string";
    cin>>rec;

    int recpar = calpar(rec.substr(0,rec.length()-1),even);
    if(recpar == rec.back()-'0'){
        cout<<"No error detcted"<<endl;
    }
    else{
        cout<<"Error detected"<<endl;
    }

}