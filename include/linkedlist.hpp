#ifndef linkedlist_hpp
#define linkedlist_hpp
#include "node.hpp"
#include <string>
using namespace std;
class linkedlist
{
public:
    linkedlist(); //fonksiyonların her biri ayrı ayrı tanımlandı 
    ~linkedlist();
    void add(string veri);
    void add(int index,string veri);
    void remove(int index);
    void remove();
    void print();
    node* first; //ilk düğüm
    int sayac;
};
#endif