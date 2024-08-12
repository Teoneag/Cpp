#include <iostream>
using namespace std;

int nrpeople;

struct people
{
    string surname, name;
    int age, weight, height, IQ;
} person[100];

int main()
{
    cout<<"Baga un nr de oameni la care sa bagi date: ";
    cin>>nrpeople;
    for (int i=0; i<nrpeople; i++)
    {
        cout<<"Baga un nume: ";
        cin>>person[i].surname;
        cout<<"Baga inca un nume (D-ala mic): ";
        cin>>person[i].name;
        cout<<"Za si o varsta: ";
        cin>>person[i].age;
        cout<<"Da cata suncile are? ";
        cin>>person[i].weight;
        cout<<"Pe usa incape? ";
        cin>>person[i].height;
    }
    cout<<"\n";
    for (int i=0; i<nrpeople; i++)
    {
        cout<<person[i].surname
        <<"\n, known as "<<person[i].name
        <<"\nis "<<person[i].age
        <<"\nyears old, has "<<person[i].weight
        <<"\nsunci and "<<person[i].height
        <<"\nheadhits on the door frame!.\n";
    }
    return 0;
}