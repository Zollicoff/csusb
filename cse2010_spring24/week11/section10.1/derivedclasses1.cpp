#include <iostream>
#include <string>
using namespace std;

class GenericItem {
public:
    GenericItem(string name = "", int quantity = 0) : name(name), quantity(quantity) {}

    void SetName(string name) {
        this->name = name;
    }

    void SetQuantity(int quantity) {
        this->quantity = quantity;
    }

    virtual void PrintItem() {
        cout << "Item: " << name << ", Quantity: " << quantity << endl;
    }

protected:
    string name;
    int quantity;
};

class ProduceItem : public GenericItem {
public:
    ProduceItem(string name = "", int quantity = 0, string expiration = "") 
        : GenericItem(name, quantity), expiration(expiration) {}

    void SetExpiration(string expiration) {
        this->expiration = expiration;
    }

    string GetExpiration() {
        return expiration;
    }

    void PrintItem() override {
        GenericItem::PrintItem();
        cout << "  (Expires: " << expiration << ")" << endl;
    }

private:
    string expiration;
};

int main() {
    GenericItem miscItem;
    ProduceItem perishItem;

    miscItem.SetName("Crunchy Cereal");
    miscItem.SetQuantity(9);
    miscItem.PrintItem();

    perishItem.SetName("Apples");
    perishItem.SetQuantity(40);
    perishItem.SetExpiration("Dec 5, 2019");
    perishItem.PrintItem();

    return 0;
}
