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

// Function to search for an employee by ID
int search_by_id(const vector<Record>& records, const int search_id)
{
    for (size_t i = 0; i < records.size(); i++)
    {
        if (records[i].employee_id == search_id)
        {
            return i;
        }
    }
    return -1; // Return -1 if not found
}

// Function to load and display records
void displayRecords(vector<Record>& records)
{
    ifstream file("employee_records.csv"); // Open the CSV file
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    records.clear(); // Clear existing records before loading

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
}

// Function to search by ID and display results
void searchByID(const vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records loaded. Please load records first." << endl;
        return;
    }

    int search_id;
    cout << "Enter Employee ID to search: ";
    cin >> search_id;

    int index = search_by_id(records, search_id);
    if (index != -1)
    {
        cout << "Employee found:\n";
        print_record(records[index]);
    }
    else
    {
        cout << "Employee with ID " << search_id << " not found.\n";
    }
}

int main()
{
    vector<Record> records;
    menu();
}

// Created a console-based menu system
void menu()
{
    vector<Record> records;
    int choices;
    bool exit = false;

    while (!exit)
    {
        cout << "Menu:" << endl;
        cout << "1. Display All Employees" << endl;
        cout << "2. Search Employee by ID" << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "7. " << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choices;

        // Perform actions based on the user's choice
        switch (choices)
        {
        case 1:
            displayRecords(records);
            break;
        case 2:
            searchByID(records);
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
            cout << "Invalid choice. Please enter a number between 1-4." << endl;
        }
    }
}
