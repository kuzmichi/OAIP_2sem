#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum DaysOfWeek {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Time {
    unsigned hours : 5; // 0-23
    unsigned minutes : 6; // 0-59
};

struct Train {
    int trainNumber;
    string destination;
    DaysOfWeek daysOfWeek;
    Time arrivalTime;
    Time departureTime;
};

void displayTrain(const Train& train) {
    cout << "Train Number: " << train.trainNumber << endl;
    cout << "Destination: " << train.destination << endl;
    cout << "Days of Week: ";
    switch (train.daysOfWeek) {
    case MONDAY: cout << "Monday"; break;
    case TUESDAY: cout << "Tuesday"; break;
    case WEDNESDAY: cout << "Wednesday"; break;
    case THURSDAY: cout << "Thursday"; break;
    case FRIDAY: cout << "Friday"; break;
    case SATURDAY: cout << "Saturday"; break;
    case SUNDAY: cout << "Sunday"; break;
    }
    cout << endl;
    cout << "Arrival Time: " << setw(2) << setfill('0') << train.arrivalTime.hours << ":"
        << setw(2) << setfill('0') << train.arrivalTime.minutes << endl;
    cout << "Departure Time: " << setw(2) << setfill('0') << train.departureTime.hours << ":"
        << setw(2) << setfill('0') << train.departureTime.minutes << endl;
    cout << "---------------------------------------" << endl;
}

void searchTrainByDestination(const Train trains[], int numTrains, const string& destination) {
    bool found = false;
    for (int i = 0; i < numTrains; ++i) {
        if (trains[i].destination == destination) {
            displayTrain(trains[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No trains found for destination: " << destination << endl;
    }
}

int main() {
    const int MAX_TRAINS = 100;
    Train trains[MAX_TRAINS];
    int numTrains = 0;

    // Sample data
    trains[numTrains++] = { 1001, "New York", MONDAY, {9, 30}, {10, 0} };
    trains[numTrains++] = { 1002, "Chicago", TUESDAY, {10, 0}, {10, 30} };
    trains[numTrains++] = { 1003, "Los Angeles", WEDNESDAY, {11, 0}, {11, 30} };
    trains[numTrains++] = { 1004, "Nigeria", FRIDAY, {23, 0}, {5, 30} };
    trains[numTrains++] = { 1004, "Monaco", TUESDAY, {5, 30}, {10, 30} };

    int choice;
    do {
        cout << "1. Display all trains" << endl;
        cout << "2. Search train by destination" << endl;
        cout << "3. Delete train by number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < numTrains; ++i) {
                displayTrain(trains[i]);
            }
            break;
        case 2: {
            cin.ignore();
            string destination;
            cout << "Enter destination: ";
            getline(cin, destination);
            searchTrainByDestination(trains, numTrains, destination);
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 4);

    return 0;
}
