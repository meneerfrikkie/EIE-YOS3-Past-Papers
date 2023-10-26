/* M Dadabhay - 2023 */
/* 2017 Exam */
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Photo {
    public:
        Photo(const string& photo_file_name) : _photo_file_name{photo_file_name} {}; // reads an existing photo from disk
        Photo(const Photo& rhs) { _photo_file_name = rhs._photo_file_name; };
        Photo& operator=(const Photo& rhs) {
            if (this != &rhs) {
                _photo_file_name = rhs._photo_file_name;
            }
            return *this;
        }
        void setPhoto(const string& photo_file_name) {_photo_file_name = photo_file_name;};
        string getPhoto() { return _photo_file_name;};

    private:
        string _photo_file_name;
};

class Project {
    public:
        Project(const string& title_, const string& description_, const string& supervisor_, vector<pair<string, string>>& members_) 
            : _title{title_} , _description{description_} , _supervisor{supervisor_} , _members{members_} {}; 
        Project(const Project& rhs) 
        { 
            _title = rhs._title; 
            _description = rhs._description; 
            _supervisor = rhs._supervisor; 
            _members = rhs._members;
            if(rhs._photo != nullptr)
                _photo = make_unique<Photo>(*rhs._photo);
        };
        Project& operator=(const Project& rhs) {
            if (this != &rhs) {
                _title = rhs._title; 
                _description = rhs._description; 
                _supervisor = rhs._supervisor; 
                _members = rhs._members;
                if(rhs._photo != nullptr)
                    _photo = make_unique<Photo>(*rhs._photo);
            }
            return *this;
        }
        void setPhoto(const string& photo_file_name) {
            if(_photo == nullptr)
                _photo = make_unique<Photo>(photo_file_name);
            else
                _photo->setPhoto(photo_file_name);
        }
        void setTitle(const string& title_) {
            _title = title_;
        }
        void setDescription(const string& description_) {
            _description = description_;
        }
        void printProject() {
            cout << "Title: " << _title << endl;
            cout << "Description: " << _description << endl;
            cout << "Supervisor: " << _supervisor << endl;
            
            cout << "Members: " << endl;
            for(auto &member : _members) {
                cout << "\tName: " << member.first << ", Student Number: " << member.second << endl;
            }
            
            if(_photo != nullptr)
                cout << "Photo File Name: " << _photo->getPhoto() << endl;
        }

    private:
        string _title, _description, _supervisor;
        vector<pair<string, string>> _members; // pair of name and student number
        unique_ptr<Photo> _photo = nullptr;
};

int main() {
    vector<pair<string, string>> members1 {{"Frikkie", "2426234"}, {"Tahiri", "2434204"}};
    Project project1("Project 1", "This is a description of project 1.", "Prof. SP Levitt", members1);
    project1.setPhoto("project1.jpg");

    // Copy construct project2 from project1
    Project project2(project1);
    project1.printProject();
    project2.setTitle("Project 2");
    project2.setDescription("This is a description of project 2.");
    cout << endl;
    project2.printProject();

    return 0;
}
