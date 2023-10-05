#include <string>
#ifndef node_hpp
#define node_hpp
using namespace std;
class node //düğüm sınıfı oluşturuldu.
{
public:
    node* after;
    node* before;
    string veri;
    node(string veri);
};
#endif