#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser();
bool loginUser();

int main() {
    int choice;
    cout << "1. Register\n2. Login\n3. Exit\n";
    cin >> choice;
    
    switch(choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Login failed. Try again!" << endl;
            }
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ofstream file;
    file.open("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    
    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}
