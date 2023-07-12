#ifndef HEADER
#define HEADER

class Set{
private:
    int size, max_size;
    int* set;
public:
    Set();
    Set(int max_size);
    ~Set();
    int* getSet();
    int getSize();
    int getMaxSize();
    void printSet();
    void sortingSet();
    void addElement(int x);
    void removeElement(int x);
    void intersectionSet(Set s);
    void unionSet(Set s);
    void addAllElements(Set s);
    void removeAllElements(Set s);
};

#endif