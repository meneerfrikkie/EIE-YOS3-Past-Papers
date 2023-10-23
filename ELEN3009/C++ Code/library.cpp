/* M Dadabhay - 2023 */
/* 2019 - Using Composition */

class ItemInfo {
public:
    ItemInfo(int total_copies = 1, int copies_on_loan = 0) : total_copies_{total_copies}, copies_on_loan_{copies_on_loan} {}
    void returnItem() { copies_on_loan_--; }
    void borrowItem() { copies_on_loan_++; }
    int availableCopies() { return total_copies_ - copies_on_loan_; }
private:
    int total_copies_;
    int copies_on_loan_;
};

class Book {
public:
    Book(const string& title, const string& author, int copies = 1) : item_{copies}, title_{title}, author_{author} {}
    string title() { return title_; }
    string author() { return author_; }
    void returnItem() { item_.returnItem(); }
    void borrowItem() { item_.borrowItem(); }
    int availableCopies() { return item_.availableCopies(); }
private:
    ItemInfo item_;
    string title_;
    string author_;
};

class DVD {
public:
    DVD(const string& title, int runtime, int copies = 1) : item_{copies}, title_{title}, runtime_{runtime} {}
    string title() { return title_; }
    int runtime() { return runtime_; } // runtime in minutes
    void returnItem() { item_.returnItem(); }
    void borrowItem() { item_.borrowItem(); }
    int availableCopies() { return item_.availableCopies(); }
private:
    ItemInfo item_;
    string title_;
    int runtime_;
};
