#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    srand(time(0));

    int frame,ws;
    cout<<"Enter the number of frames and ws: ";
    cin>>frame>>ws;

    bool ack[100] = {false};
    int sent = 0;

    while(sent < frame){
        
        cout<<endl;

        bool s[100] = {false};   // FIXED: Removed VLA

        // Sending frames
        for(int i = sent; i < sent + ws && i < frame; i++){
            if(!ack[i]){
                cout<< "Sending frame "<< i+1 << endl;
            }
        }
        
        // Receiver side
        for(int i = sent; i < sent + ws && i < frame; i++){
            if(!ack[i]){
                bool fail = (rand() % 10 < 4);

                if(fail){
                    cout << "Receiver lost frame " << i+1 << endl;
                }
                else{
                    cout << "Receiver: received frame " << i+1 
                         << " sending ack" << endl;
                    s[i] = true;  // mark ACK generated
                }
            }
        }

        // Sender receives ACK or loses ACK
        for(int i = sent; i < sent + ws && i < frame; i++){
            if(s[i]){
                bool lost = (rand() % 10 < 4);

                if(lost){
                    cout << "Sender: Ack for frame " << i+1 
                         << " not received " << endl;
                }
                else{
                    cout << "Sender: Received ack for frame: " << i+1 << endl;
                    ack[i] = true;
                }
            }
        }

        // Slide window 
        while(sent < frame && ack[sent]){
            sent++;
        }
    }
}
