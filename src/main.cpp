#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "linkedlist.hpp"
#include "node.hpp"
using namespace std;
int main()
{
    ifstream orderFile("Veri.txt"); //dosya işlemi
    string orderLine;
    linkedlist *list = new linkedlist();
    while
     (getline(orderFile, orderLine)) 
    {
        switch ((char)tolower(orderLine[0])) 
        {
        case 's':
            if(orderLine[2]==')' || orderLine[2]=='-' || orderLine[2]=='0')  // indexin sıfır veya eksi olma durumunu kontrol
            {
                list->remove();
            }
            else
            {
                int index=stoi(orderLine.substr(2,orderLine.length()-3));
                list->remove(index);
            }
            break;
        case 'e':
            string order = orderLine.substr(2, orderLine.length() - 3); //ekleme işlemini kontrol
            if (orderLine.find('#') != string::npos) 
            {
                if(orderLine[2]=='#'|| orderLine[2]=='-' || orderLine[2]=='0')
                {
                    string yorder=orderLine.substr(orderLine.find('#')+1,orderLine.length()-orderLine.find('#')-2);
                    list->add(yorder);
                }
                else
                {
                    int i = 1;
                    while ((char)orderLine[i] != '#') //diyezi bulma
                    {
                        i++;
                    }
                    int index = stoi(order.substr(0,i));
                    order = order.substr(i -1 ); 
                    list->add(index, order);
                }
            }
            else
            {
                list->add(order);
            }
            break;
            }
    }
    list->print(); //yazdır
    return 0;
}