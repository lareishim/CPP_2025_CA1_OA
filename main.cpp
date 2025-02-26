#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void menu();

// Define a struct
struct Record
{
    int employee_id{};
    string name;
    int age{};
    double salary{};
    string department;
    string city;
};

// Function to print a single record
void print_record(const Record& record)
{
    cout << "Employee ID: " << record.employee_id << ", Name: " << record.name
        << ", Age: " << record.age << ", Salary: " << record.salary
        << ", Department: " << record.department << ", City: " << record.city << endl;
}

// Function to display all records
void display_records(const vector<Record>& records)
{
    for (const auto& record : records)
    {
        print_record(record);
    }
}

int main()
{
    ifstream file("employee_records.csv"); // Open the CSV file
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    vector<Record> records; // Vector to store records

    // Skip the header line
    getline(file, line);

    // Read the file line by line
    while (getline(file, line))
    {
        stringstream ss(line);
        string idStr, name, ageStr, salaryStr, department, city;

        // Read each column in the CSV file
        getline(ss, idStr, ','); // Read Employee ID
        getline(ss, name, ','); // Read Name
        getline(ss, department, ','); // Read Department
        getline(ss, ageStr, ','); // Read Age
        getline(ss, salaryStr, ','); // Read Salary
        getline(ss, city, ','); // Read City

        // Add record to the vector
        records.push_back({stoi(idStr), name, stoi(ageStr), stod(salaryStr), department, city});
    }
    file.close();

    // Display records
    display_records(records);

    return 0;
}

// Created a console-based menu system
void menu()
{
    int choices;
    bool exit = false;
    while (!exit)
    {
        cout << "Menu:" << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "7. " << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choices;

        // Perform actions based on the user's choice
        switch (choices)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            exit = true;
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter numbers between 1-8." << endl;
        }
    }
}
