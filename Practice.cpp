#include<iostream>
#include<ctime>
using namespace std;

int main() {
    srand(time(0));

    int n, ws;
    cout << "Enter the number of frames & ws: ";
    cin >> n >> ws;

    int base = 1;      // first unacknowledged frame
    int next = 1;      // next frame to send

    while (base <= n) {

        // Send all frames in window
        for (int i = next; i < base + ws && i <= n; i++) {
            cout << "Sending frame " << i << endl;
        }

        next = base + ws;  
        
        for (int i = base; i < next && i <= n; i++) {

            bool lost = (rand() % 10 < 3); 
            if (lost) {
                cout << "Frame " << i << " has been lost." << endl;
                next = i;     
                break;
            }

            cout << "Frame " << i << " received successfully." << endl;

            bool acklost = (rand() % 10 < 3);
            if (acklost) {
                cout << "ACK for frame " << i << " lost. Retransmitting..." << endl;
                next = i;     
                break;
            }

            cout << "ACK for frame " << i << " received." << endl;
            base++;           
        }
    }
}
