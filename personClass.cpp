#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(const string& name) : name_{name}
    { cout << "Constructing a person" << endl; }

    Person(const Person& rhs) : name_{rhs.name_}
    { cout << "Copying a person" << endl; }

    ~Person()
    { cout << "Destructing a person" << endl; }

private:
    string name_;
};

Person newPerson()
{
    return Person{"Bobby"};
}

int main()
{
    Person muaawiyah = newPerson();

    return 0;
}
