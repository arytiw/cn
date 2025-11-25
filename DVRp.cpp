#include<iostream>
#include<string>

using namespace std;


int main(){
    int n;
    cout<<"Enter the number of routers ";
    cin>>n;

    int cost[n][n];
    cout<<"\nEnter the cost matrix: "<<endl;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>cost[i][j];
        }
    }

    int dist[n][n];
    int via[n][n];


    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = cost[i][j];

            if(cost[i][j] != 1e9 && i!=j){
                via[i][j] = j;
            }
            else{
                via[i][j] = -1;
            }
        }
    }

    bool upd;
    do
    {
        upd = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0;k<n; k++){
                    if(dist[i][j] > cost[i][k] + dist[k][j]){
                        dist[i][j] = cost[i][k] + dist[k][j];
                        via[i][j] = k;
                        upd  = true;
                    }
                }
            }
        }
    } while (upd);

    cout<<"The routing table is: "<<endl;

    for(int i = 0; i<n; i++){
        cout<<"Routing table for Router: "<<i<<endl;
        cout<<"Src\tNext\tDes\tCost: "<<endl;
        for(int j=0; j < n; j++){
            if(i!=j){
                cout<<i<<"\t"<<via[i][j]<<"\t"<<j<<"\t"<<dist[i][j]<<endl;
            }
        }
    }
    
}