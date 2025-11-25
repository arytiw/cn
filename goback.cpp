#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    int frame, wind;

    srand(time(0));
    cout << "Enter the number of frames " << endl;
    cin >> frame;
    cout << "Enter the window size" << endl;
    cin >> wind;

    
    

    int ackReceived = 1;
    int sendFrame = 1;

    while (ackReceived <= frame)
    {
        cout << "Sending frames: " << endl;
        for (int i = sendFrame; i < ackReceived + wind && i <= frame; i++)
        {
            cout << "Sending frame " << i << endl;
            
        }

        cout << "\n";

        sendFrame = ackReceived + wind;

        for (int i = ackReceived; i < sendFrame && i <= frame; i++)
        {
            bool fail = (rand() % 10 < 5);

            if (fail)
            {
                cout << "Frame " << i << " has been lost" << endl;
                cout << "Resending the frame from " << i << endl;
                sendFrame = i;
                break;
            }
            else
            {
                cout << "Frame " << i << " has been sent successfully" << endl;

                bool acklost = (rand() % 10 < 5);
                if (acklost)
                {
                    cout << "Acknowledgement has been lost" << endl;
                    cout << "Resending Frame from " << i << endl;
                    sendFrame = i;
                    break;
                }
                else
                {
                    cout << "Acknowledgement has been received\n\n"
                         << endl;
                    ackReceived = i + 1;
                }
            }
        }
    }
    cout << "All messages have been received" << endl;
}