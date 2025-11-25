#include<iostream>
#include<string>
#include<ctime>

using namespace std;

int main() {
    int n;
    cout << "Enter number of frames: ";
    cin >> n;

    srand(time(0));

    int frame = 1;
    string msg;

    while (frame <= n) {
        cout << "\nEnter the message for frame " << frame << ": ";
        cin >> msg;

        bool delivered = false;

        while (!delivered) {
            cout << "\nSending Frame " << frame << "..." << endl;

           
            bool frameLost = (rand() % 10 < 5);

            if (frameLost) {
                cout << "Frame " << frame << " LOST!" << endl;
                cout << "Retransmitting Frame " << frame << "...\n";
                continue; 
            }

            cout << "Frame " << frame << " delivered successfully.\n";
            cout << "Waiting for ACK...\n";

            // Simulate ACK loss
            bool ackLost = (rand() % 10 < 5);

            if (ackLost) {
                cout << "ACK for Frame " << frame << " LOST!" << endl;
                cout << "Retransmitting Frame " << frame << "...\n";
                continue; 
            }

            cout << "ACK received for Frame " << frame << ".\n";
            delivered = true; // both frame and ack successful
        }

        frame++;
    }

    cout << "\nAll frames have been sent successfully.\n";
    return 0;
}
