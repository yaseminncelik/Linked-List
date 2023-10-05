#include "node.hpp"
#include "linkedlist.hpp"
#include <iostream>
#include <string>
using namespace std;
          
linkedlist::linkedlist()  //bağlı liste
{
    sayac=0;
    first=0;
}
linkedlist::~linkedlist() //yıkıcı bağlı liste
{
    node* gec = first;
    while(gec!=0)
    {
        node* remove = gec;
        gec= gec->after;
        delete remove;
    }           
}
void linkedlist::add(string veri) //kopyalayarak ekleme fonksiyonu
    {
        node* yeni= new node(veri);
        sayac++;
        if(first==0)   
        {
            first=yeni;
            return;
             
        }
        node* gec=first;
        while (gec->after!=0) 
        {
            gec=gec->after; 
        }
        gec->after=yeni;
        yeni->before = gec;
    }
    void linkedlist::add(int index, string sayi) //kopyalayarak indexli ekleme fonksiyonu
    {  
        add("");
        node* gec=first;
        
        while(gec->after!=0) 
        {
            gec=gec->after;
            
        }
        for(int i=sayac; i>index; i--)
        {  
            gec=gec->before;
            gec->after->veri=gec->veri;
        }
            gec->veri = sayi;
    }
    void linkedlist::remove() //içi boş silme
    {
        if(first==0) return;
        if(first->after==0)
        {
            delete first;
            first=0;
            sayac--;
        }
        else
        {
            node* gec=first;
            while(gec->after!=0)  // son düğüme gitme
            {
                gec=gec->after;
            }
            gec->before->after=0;
            delete gec;
            sayac--;
         }
    }
    void linkedlist::remove(int index) //indexli silme
    {   
        if(first==0) return;
        if(first->after==0)
        {
            delete first;
            first=0;
            sayac--;
        }
        else
        {
            if(sayac<index) 
            {
                index=sayac;
                return remove(index);
            }
            else
            {node* gec=first;

                for(int i=0; i<index-1; i++) 
                {
                    gec=gec->after;
                }
                for(int i=index; i<sayac;i++) 
                {
                    gec->veri=gec->after->veri;
                    gec=gec->after;
                }
                gec->before->after=0;
                delete gec;
                sayac--;
            }
        }
        
        
        
    }
    void linkedlist::print() //yazdırma fonksiyonu
    { 
        node *yaz = this->first;
        cout << yaz->veri;
        yaz = yaz->after;
        if(sayac==0)
        {
            cout << " ";
        }
        else
        {
            for (int i = 0; i < sayac - 1; i++) 
            {
                cout << " <--> " << yaz->veri;
                yaz = yaz->after;
            }
            cout << endl;
        }
        
    }
