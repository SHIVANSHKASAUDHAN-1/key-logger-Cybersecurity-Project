
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//ok

void startLogger() {

    string input;
    ofstream file("keylog.txt", ios::app);

    if (!file.is_open()) {
        cout << "Error opening log file!" << endl;
        return;
    }

    cout << "\n--- Recording Started ---" << endl;
    cout << "Type your text (type STOP to finish):\n";

    while (true) {

        cout << "> ";
        getline(cin, input);

        if (input == "STOP") {
            break;
        }

        file << input << endl;
    }

    file.close();

    cout << "\nRecording stopped successfully!" << endl;
}

void showLogs() {

    string line;
    ifstream file("keylog.txt");

    if (!file.is_open()) {
        cout << "No log file found!" << endl;
        return;
    }

    cout << "\n--- Recorded Text ---\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {

    int choice;

    do {

        cout << "\n===== C++ KEYLOGGER SIMULATOR =====";
        cout << "\n1. Start Recording";
        cout << "\n2. View Recorded Text";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            return 1;
        }

        cin.ignore(10000, '\n');

        switch (choice) {

            case 1:
                startLogger();
                break;

            case 2:
                showLogs();
                break;

            case 3:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}


