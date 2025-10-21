//
//
// Lab_1.cpp : 
// 
// Start with the following program employee record simple database:
// 
// Assignment:
// Part 1: Implementation
// Add a main menu to manage the employees data, which will include a choice of: 
// 1) Access employee record based on employee ID only (can be the index of the array, you may not to perform asearch, this is called Hashing 
// 2) Add an employee to the database
// 3) Delete an employee (delete the index), if an ID is available use it for the new employee

// Part 2: Report
// Provide program run snapshots and data validation in a report
// Upload your full lab to CANVAS   
//

// The above items are only suggestions, you can come up with your own design, 
// At minimum you should be able to perform the above programming steps.
// Lab grade will be based on programming creativity also.
//




#include <iostream>
#include <string>
using namespace std;

// Employee Class Declaration

class Employee
{
private:
    string name;        // Employee's name
    int idNumber;       // ID number
    string department;  // Department name
    string position;    // Employee's position

public:
    // Constructors
    Employee(string, int, string, string);
    Employee();

    // update methods
    void setName(string n)
    {
        name = n;
    }

    void setIdNumber(int i)
    {
        idNumber = i;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    void setPosition(string p)
    {
        position = p;
    }

    // Accessors
    string getName()
    {
        return name;
    }

    int getIdNumber()
    {
        return idNumber;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }
};

// Constructor #1
Employee::Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

// Constructor #3, default constructor
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}


// Function prototype
void displayEmployee(Employee);

// Driver program to demonstrate the class
int main()
{
    // Create an Employee object based on the current constructor.
    //Employee Albert("Albert Smith", 1, "Executive", "President");

    Employee employees[10];

    // Display each employee's data.
    //displayEmployee(Albert);
    //displayEmployee(employees[2]);

    // Main Menu
    bool quit = false;
    while(quit == false){
        cout << "\n1) Access employee record based on employee ID\n2) Add an employee to the database\n3) Delete an employee \n4) Quit program" << endl;
        int choice;
        int id;
        Employee *ptr = nullptr;
        cin >> choice;
        switch(choice){
            case 1: // choice 1
                cout << "Enter employee ID" << endl;
                cin >> id;
                id = --id;
                if (id < 0 || id > 9)
                {
                    cout << "\nInvalid ID, Please enter a Valid ID next time (1-10)" << endl;
                    break;
                }else
                {
                    ptr = &employees[id];
                    if(ptr->getName() == ""){
                        cout << "\nThere is currently no Employee with that ID" << endl;
                        break;
                    }else
                    {
                        displayEmployee(employees[id]);
                        break;
                    }
                }
            case 2: // choice 2
                cout << "\nEnter employee ID you would like to add (Between 1-10)" << endl;
                cin >> id;
                id = --id;
                if (id < 0 || id > 9)
                {
                    cout << "\nInvalid ID, Please enter a Valid ID next time (1-10)" << endl;
                    break;
                }else
                {
                    ptr = &employees[id];
                    if(ptr->getName() != ""){
                        cout << "\nThe current ID is already taken if you would like to replace the current ID, please delete first then add new employee!" << endl;
                        break;
                    }else{
                        ptr->setIdNumber(id+1);
                        string input;
                        cout << "\nEnter the following information \n1) Name\n2) Department\n3) Position" << endl;
                        cin >> input;
                        ptr->setName(input);
                        cin >> input;
                        ptr->setDepartment(input);
                        cin >> input;
                        ptr->setPosition(input);
                        cout << "\nNew Employee Successfully Added!" << endl;
                        break;
                    }
                    
                }
                
                
            case 3: // choice 3
                cout << "\nEnter employee ID you would like to delete" << endl;
                cin >> id;
                id = --id;
                if (id < 0 || id > 9)
                {
                    cout << "\nInvalid ID, Please enter a Valid ID next time (1-10)" << endl;
                    break;
                }else
                {

                    ptr = &employees[id];
                    ptr->setName("");
                    ptr->setDepartment("");
                    ptr->setPosition("");
                    cout << "\nEmployee Deleted!" << endl;
                }
                break;
            case 4: // choice to quit
                quit = true;
                break;
            default:
                cout << "\nPlease Select a valid choice!" << endl;
                break;
        }
    }

    return 0;
}

//**************************************************
// The displayEmployee function displays the data  *
// in the Employee object passed as an argument.   *
//**************************************************

void displayEmployee(Employee e)
{
    cout << "Name: " << e.getName() << endl;
    cout << "ID Number: " << e.getIdNumber() << endl;
    cout << "Department: " << e.getDepartment() << endl;
    cout << "Position: " << e.getPosition() << endl << endl;
}