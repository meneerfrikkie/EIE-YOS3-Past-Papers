/* M Dadabhay - 2023 */
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Toy {
    // Toy class definition goes here
};

class LuckyPacket {
public:
    LuckyPacket() {
        if (rand() % 2) toy_ptr_ = make_unique<Toy>();
    }

    LuckyPacket(const LuckyPacket& other) {
        if (other.toy_ptr_) toy_ptr_ = make_unique<Toy>(*other.toy_ptr_);
    }

    LuckyPacket& operator=(const LuckyPacket& other) {
        if (&other == this) return *this;
        if (other.toy_ptr_) toy_ptr_ = make_unique<Toy>(*other.toy_ptr_);
        else toy_ptr_.reset();
        return *this;
    }

    void open() {
        if (toy_ptr_) {
            cout << "Congrats, you won a toy!" << endl;
            // other functions which make use of the toy
            // ...
        }
        else cout << "Sorry, this lucky packet is empty." << endl;
    }

private:
    unique_ptr<Toy> toy_ptr_;
};

/*
std::unique_ptr<Toy> toy_ptr_;: This is a private member variable of the class. It’s a unique pointer to a Toy object. A unique pointer is a smart pointer that owns and manages another object and disposes of that object when the unique_ptr is itself destroyed.

LuckyPacket(): This is the default constructor. It initializes toy_ptr_ to nullptr. If rand() % 2 is true, it creates a new Toy object and assigns its ownership to toy_ptr_.

LuckyPacket(const LuckyPacket& other): This is the copy constructor. It takes a reference to another LuckyPacket object. If the other object has a Toy, it creates a new Toy that’s a copy of the other one and assigns its ownership to toy_ptr_.

LuckyPacket& operator=(const LuckyPacket& other): This is the copy assignment operator. It takes a reference to another LuckyPacket object. If the other object is the same as this one, it does nothing and returns a reference to this object. Otherwise, if the other object has a Toy, it creates a new Toy that’s a copy of the other one and assigns its ownership to toy_ptr_. If the other object doesn’t have a Toy, it resets toy_ptr_.

void open(): This function checks if this packet has a toy (i.e., if toy_ptr_ points to a toy). If it does, it prints “Congrats, you won a toy!” and performs other operations related to the toy. If it doesn’t, it prints “Sorry, this lucky packet is empty.”
*/

int main() {
    srand(static_cast<unsigned int>(time(0)));

    auto packet_1 = make_unique<LuckyPacket>();
    auto packet_2 = make_unique<LuckyPacket>(*packet_1);
    LuckyPacket packet_3 = *packet_2;

    packet_1->open();
    packet_1.reset();

    packet_2->open();
    packet_2.reset();

    packet_3.open();

    return 0;
}
