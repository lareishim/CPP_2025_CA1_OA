#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

void print_record(const Record& record)
{
    cout << "Employee ID: " << record.employee_id << ", Name: " << record.name
        << ", Age: " << record.age << ", Salary: " << record.salary
        << ", Department: " << record.department << ", City: " << record.city << endl;
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
    Record records[100]; // Array to store records
    int count = 0;

    // Skip the header line
    getline(file, line);

    // Read the file line by line
    while (getline(file, line) && count < 100)
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

        // Store the values in the record
        records[count].employee_id = stoi(idStr);
        records[count].name = name;
        records[count].age = stoi(ageStr);
        records[count].salary = stod(salaryStr);
        records[count].department = department;
        records[count].city = city;
        count++;
    }
    file.close();

    // Display records
    for (int i = 0; i < count; i++)
    {
        print_record(records[i]);
    }

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
            // If user enters an invalid option, display an error message
            cout << "Invalid choice. Please enter numbers between 1-8." << endl;
        }
    }
}
