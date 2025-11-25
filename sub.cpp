#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

void parseIp(char str[], int ip[]){
    sscanf(str, "%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
}

void printip(int ip[]){
    cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
}


void incrip(int ip[],int val){
    for(int i = 3; i>=0; i--){
        ip[i] += val;
        val = ip[i]/256;
        ip[i] %= 256;
    }
}


int prefix(int host){
    int bit_need = ceil(log2(host));
    return 32-bit_need;
}


int main(){
    int numnet;
    char ipstr[20];
    int hosts;
    int ip[4], start[4],end[4];


    cout<<"Enter the num of networks: ";
    cin>>numnet;
    cout<<endl;
    cout<<"Enter the number hosts: ";
    cin>>hosts;
    cout<<endl;
    cout<<"Enter the baseIP like (192.168.0.0) ";
    cin>>ipstr;
    cout<<endl;

    int pre = prefix(hosts);
    int blocksize = pow(2,32-pre);
    parseIp(ipstr,ip);

    int current[4] = {ip[0],ip[1],ip[2],ip[3]};

    for(int i = 0; i<numnet; i++){
        cout<<"Network "<<i+1<<": "; 


        for(int j=0; j<4; j++){
            start[j] = current[j];
        }

        incrip(current,blocksize-1);

        for(int j=0; j<4; j++){
            end[j] = current[j];
        }

        incrip(current,1);

        printip(start);
        cout<<"/"<<pre<<"  -  ";
        printip(end);
        cout<<"/"<<pre<<"\n";
    }

}

