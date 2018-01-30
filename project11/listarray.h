#include <iostream>

using namespace std;

//template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray&);
    ~ListArray();

    bool insertBefore(const int&);
    bool insertAfter(const int&);
    bool get(int&) const;
    bool remove(int&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray& operator = (const ListArray&);

    //template <typename S>
    friend ostream& operator << (ostream&, const ListArray&);

private:
    int *data;
    int cursor;
    int actual;
    int size;
};







