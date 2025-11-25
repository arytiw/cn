#include<iostream>
#include<string>


using namespace std;

int main(){
    int router;
    cout<<"Enter the number of routers:" ;
    cin>>router;

    int cost[router][router];
    cout<<"Enter the cost matrix: "<<endl;

    for(int i = 0; i<router; i++){
        for(int j = 0; j<router; j++){
            cin>>cost[i][j];
        }
    }

    int n = router;
    int dist[n][n];
    int via[n][n];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dist[i][j] = cost[i][j]; 
            if(cost[i][j] != 1e9 && i != j){
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
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(dist[i][j] > cost[i][k] + dist[k][j]){
                        dist[i][j] = cost[i][k] + dist[k][j];
                        via[i][j] = k;
                        upd = true;
                    }
                }
            }
        }
    } while (upd);
    
    cout<<"The routing table: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<"Router "<<i<<" table:"<<endl;
        cout<<"Dest\tNext\tcost"<<endl;

        for(int j= 0; j<n; j++){

            if(i!=j){
                cout<<j<<"\t"<<via[i][j]<<"\t"<<dist[i][j]<<endl;
            }
        }
        cout<<endl;
    }

    int src,des;
    cout<<"Enter the src and dest: ";
    cin>> src>>des;

    if(src != des){
        cout<<"src\tvia\tdes\tPath Cost"<<endl;
        cout<<src<<"\t"<<via[src][des]<<"\t"<<des<<"\t"<<dist[src][des];
    }
}