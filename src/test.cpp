#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;

void displayMenu(int &choice);
void displaySpecialisation(struct specialisation spec[]);
void addPatient(std::string name, int spec_id, int status, std::vector <std::string> &patient_queue1, std::vector <std::string> &patient_queue2, std::vector <std::string> &patient_queue3); 

struct specialisation {
    std::string branch;
    int id;
};


int main(int argc, char** argv) {
    int choice;
    std::string name;
    int spec_id;
    int status;
    bool exit = false;

    struct specialisation spec[3] = {{"Cardiology", 1}, {"Radiology", 2}, {"General", 3}};
    std::vector <std::string> patient_queue1;
    std::vector <std::string> patient_queue2;
    std::vector <std::string> patient_queue3;
    std::vector <std::vector <std::string>> hosp_queue = {patient_queue1, patient_queue2, patient_queue3};

    do
    {
        displayMenu(choice); 

        switch (choice)
        {
        case 1:
            addPatient(name, spec_id, status,patient_queue1, patient_queue2, patient_queue3);
            break;

        case 2:
            displaySpecialisation(spec);
        
        case 3:
            cout << "Mak kau hijau\n";
            break;
        
        case 4:
            cout << "Thank you\n";
            exit = true;
            break;

        default:
            cout << "Invalid choice.\n";
        }
        
    } while (!exit);
    

    return 0;
}

//////////////////////////////*      Functions          *//////////////////////////////
void displayMenu(int &choice) {
    cout << "1. Add new patient.\n";
    cout << "2. Print all patients.\n";
    cout << "3. Get next patient.\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "\n";
}

void displaySpecialisation(struct specialisation spec[]){
    for (int i=0; i<3;i++){
        cout << spec[i].id << " " << spec[i].branch << "\n";
    }
}

void addPatient(std::string name, int spec_id, int status, std::vector <std::string> &patient_queue1, std::vector <std::string> &patient_queue2, std::vector <std::string> &patient_queue3) {

    cout << "Enter patient name: ";
    std::getline(std::cin >> std::ws,name);
    cout << "Enter specialisation ID: ";
    cin >> spec_id;
    cout << "Enter patient status: ";
    cin >> status;

    if (spec_id == 1) {
        patient_queue1.push_back(name);
    }
    else if (spec_id == 2) {
        patient_queue2.push_back(name);
    }
    else if (spec_id == 3) {
        patient_queue3.push_back(name);
    }
    else {
        cout << "Invalid specialisation ID.\n";
    }
    cout << patient_queue1.at(0) << '\n';
};