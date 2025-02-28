#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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
};

// Helper function to convert a string to lowercase
// Did research to get this and i now understand it
string toLowerCase(string str)
{
    ranges::transform(str, str.begin(), ::tolower);
    return str;
}

// Function to print a single record
void print_record(const Record& record)
{
    cout << "Employee ID: " << record.employee_id << ", Name: " << record.name
        << ", Age: " << record.age << ", Salary: " << record.salary
        << ", Department: " << record.department << endl;
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

// Counts occurrences of unique values in the specified column and returns a map.
map<string, int> countByColumn(const vector<Record>& records, const string& column)
{
    map<string, int> countMap;

    for (const auto& record : records)
    {
        string key;
        if (column == "department")
            key = record.department;
        else
        {
            cout << "Invalid column name!" << endl;
            return {};
        }
        countMap[key]++;
    }
    return countMap;
}

// Function to display employees based on department
void displayByDepartment(const vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records loaded. Please load records first." << endl;
        return;
    }
    string department;
    cout << "Enter department to filter by: ";
    cin >> department;

    // Convert input to lowercase
    string lowerDept = toLowerCase(department);

    bool found = false;
    for (const auto& record : records)
    {
        if (toLowerCase(record.department) == lowerDept)
        {
            print_record(record);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found in the " << department << " department." << endl;
    }
}

// Function to display counts by column
void displayCountByColumn(const vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records loaded. Please load records first." << endl;
        return;
    }

    string column;
    cout << "Enter column to count by (department): ";
    cin >> column;

    map<string, int> countMap = countByColumn(records, column);

    for (const auto& pair : countMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
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
        string idStr, name, ageStr, salaryStr, department;

        // Read each column in the CSV file
        getline(ss, idStr, ','); // Read Employee ID
        getline(ss, name, ','); // Read Name
        getline(ss, department, ','); // Read Department
        getline(ss, ageStr, ','); // Read Age
        getline(ss, salaryStr, ','); // Read Salary

        // Add record to the vector
        records.push_back({stoi(idStr), name, stoi(ageStr), stod(salaryStr), department});
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

void findMinMaxAvgAge(const vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records available to analyze." << endl;
        return;
    }
    Record highest = records[0];
    Record lowest = records[0];
    int totalAge = 0;

    for (const auto& record : records)
    {
        if (record.age > highest.age) highest = record;
        if (record.age < lowest.age) lowest = record;
        totalAge += record.age;
    }
    int avgAge = totalAge / records.size();

    cout << "Average Age: " << avgAge << endl;
    cout << "Oldest Employee:\n";
    print_record(highest);
    cout << "Youngest Employee:\n";
    print_record(lowest);
}

void searchByName(const vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records loaded. Please load records first." << endl;
        return;
    }

    string searchText;
    cout << "Enter text to search for in names: ";
    cin.ignore(); // Ignore leftover newline from previous input
    getline(cin, searchText); // Allow multi-word input

    searchText = toLowerCase(searchText);
    bool found = false;

    cout << "Matching records:\n";
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if (toLowerCase(it->name).find(searchText) != string::npos)
        {
            print_record(*it);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No employees found matching " << searchText << ".\n";
    }
}

void displaySortedBySalary(vector<Record>& records)
{
    if (records.empty())
    {
        cout << "No records loaded. Please load records first." << endl;
        return;
    }

    sort(records.begin(), records.end(), [](const Record& a, const Record& b)
    {
        return a.salary > b.salary;
    });

    cout << "Employees sorted by salary (descending order):\n";
    display_records(records);
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
        cout << "1. Display All Employees " << endl;
        cout << "2. Search Employee by ID " << endl;
        cout << "3. Count by Column " << endl;
        cout << "4. Display employees based on user input" << endl;
        cout << "5. Display the Oldest, youngest employees and average employee age" << endl;
        cout << "6. Search Employee by Name" << endl;
        cout << "7. Display Employee List sorted by Salary" << endl;
        cout << "8. Exit " << endl;
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
            displayCountByColumn(records);
            break;
        case 4:
            displayByDepartment(records);
            break;
        case 5:
            findMinMaxAvgAge(records);
            break;
        case 6:
            searchByName(records);
            break;
        case 7:
            displaySortedBySalary(records);
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
