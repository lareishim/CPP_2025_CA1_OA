#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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