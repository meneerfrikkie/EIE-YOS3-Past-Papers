/* M Dadabhay - 2023 */
#include <iostream>

using namespace std;

void swap(int& x, int* y){
    auto temp = *y;
    *y = x;
    x = temp;
}
int main()
{
    auto x = 2;
    int y = 3;
    
    swap(x,&y);
    cout << "new x value: " << x << endl;
    cout << "new y value: " << y << endl;

    int* z = &y;
    cout << &y << endl; // address of y
    cout << z << endl; // z points to y
    cout << *z << endl; // dereference z (expected to equal y)

    return 0;
}