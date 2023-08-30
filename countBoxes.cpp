#include <iostream>

class Box
{
public:
    Box(double length, double breadth, double height)
        : length_{length}, breadth_{breadth}, height_{height}
    {
        count_++; // Increment the count whenever a new box is created
    }

    Box(){count_++;}

    double volume() const { return length_ * breadth_ * height_; }

    // Static member function to retrieve the total number of boxes created
    static int getTotalBoxCount() { return count_; }

private:
    double length_ = 1.0;
    double breadth_ = 1.0;
    double height_ = 1.0;

    // Static member variable to keep track of the count
    static int count_;
};

// Initialize the static member variable
int Box::count_ = 0;

int main()
{
    auto box_1 = Box{3.3, 1.2, 1.5};
    std::cout << "Volume of box_1: " << box_1.volume() << std::endl;

    auto box_2 = Box{};
    std::cout << "Volume of box_2: " << box_2.volume() << std::endl;

    // Call the static member function to get the total box count
    std::cout << "Total number of boxes created: " << Box::getTotalBoxCount() << std::endl;

    return 0;
}
