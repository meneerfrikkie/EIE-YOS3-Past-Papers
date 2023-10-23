/* M Dadabhay - 2023 */
/* 2022 Exam */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using TelephoneNumbers = std::vector<std::string>;

class Employee {
public:
    Employee(const std::string& name, const std::string& address): _name(name), _address(address) {}
    void addTelephoneNumber(const std::string& number) { _telephone_numbers.push_back(number); }
    std::string getDetails() const {
        std::string details = _name + "\n" + _address + "\n";
        for (const auto& number : _telephone_numbers) {
            details += number + " ";
        }
        details.erase(details.length()-1, 1); // remove last space
        return details;
    }
private:
    std::string _name;
    std::string _address;
    TelephoneNumbers _telephone_numbers;
};

class Payroll {
public:
    void createEmployeeLabel(const Employee& employee) {
        _label = employee.getDetails();
    }
    std::string getLabel() const { return _label; }
private:
    std::string _label;
};

class TelephoneGuide {
public:
    void setCurrentEmployee(Employee* employee) { _employee = employee; }
    std::string formatTelephoneNumbers() const {
        std::string tel_list = _employee->getDetails();
        std::replace(tel_list.begin(), tel_list.end(), ' ', '-'); // replace spaces with dashes
        return tel_list;
    }
private:
    Employee* _employee;
};

int main() {
    // Create an Employee
    Employee john("Muaawiyah Dadabhay", "123 Frikkie St");
    john.addTelephoneNumber("0837998442");
    john.addTelephoneNumber("0817263232");
    
    // Create a Payroll
    Payroll payroll;
    payroll.createEmployeeLabel(john);
    
    // Print the Payroll label
    std::cout << "Payroll Label:\n" << payroll.getLabel() << "\n\n";
    
    // Create a TelephoneGuide
    TelephoneGuide guide;
    guide.setCurrentEmployee(&john);
    
    // Print the formatted telephone numbers
    std::cout << "Telephone Guide:\n" << guide.formatTelephoneNumbers() << "\n";
    
    return 0;
}
