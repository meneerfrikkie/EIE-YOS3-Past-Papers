/* M Dadabhay - 2023 */
#include <iostream>
#include <string>

using namespace std;

class Item
{
    public:
        Item(string name, double price) : _item_name{name}, _price{price} {}
        ~Item() {};
        string name() const { return _item_name; };
        double price() const { return _price; };

    private:
        string _item_name;
        double _price;
};

class ShoppingCart
{
    public:
        ShoppingCart() : _total_cart_price{0} {}
        ~ShoppingCart() {};
        void addItem(Item item)
        {
            _total_cart_price += item.price();
        }
        void adjustTotal(double amount_) { _total_cart_price += amount_; }
        double total() const { return _total_cart_price; }

    private:
        double _total_cart_price;
};

class Promotion
{
    public:
        Promotion() {};
        virtual ~Promotion() {};
        virtual void applyPromotion(Item& item_, ShoppingCart& cart_) {};
};

class ThreeForTwo : Promotion
{
    public:
        void applyPromotion(Item& item_, ShoppingCart& cart_) override
        {
            cart_.adjustTotal(-item_.price());
        };
};

// Creates promotion, accepts item on promotion and cart to apply promotion to
void createThreeForTwoPromotion(Item& item, ShoppingCart& cart);

int main(){

    Item milk("Clover 2L", 21.00);
    cout << "You have added item: " << milk.name() << " into your cart with a cost of: R" << milk.price() << endl;
    ShoppingCart cart;
    cart.addItem(milk);
    cart.addItem(milk);
    cout << "Your cart total is: R" << cart.total() << endl;
    cart.addItem(milk);
    ThreeForTwo promotion;
    cout << "Your cart total before promotion is: R" << cart.total() << endl;
    promotion.applyPromotion(milk, cart);
    cout << "Your cart total is: R" << cart.total() << endl;
}