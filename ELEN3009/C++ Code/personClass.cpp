/* Poor Sanity Check */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

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

    string name() {return name_;}
private:
    string name_;
};

Person newPerson()
{
    return Person{"Bobby"};
}

int main()
{
    // auto persons =  vector<Person>{}; 
    // persons.push_back(Person("Muaawiyah"));
    // cout << persons.size() << endl;
    // cout << persons.capacity() << endl;

    // persons.push_back(Person("Frikkie"));
    // for (auto &person_ : persons)
    // {
    //     cout << person_.name() << endl;
    // }

    auto persons =  vector<shared_ptr<Person>>{}; 
    persons.push_back(make_shared<Person>("Muaawiyah"));
    cout << persons.size() << endl;
    cout << persons.capacity() << endl;

    persons.push_back(make_shared<Person>("Frikkie"));
    for (auto &person_ : persons)
    {
        cout << person_->name() << endl;
    }
    

    return 0;
}
