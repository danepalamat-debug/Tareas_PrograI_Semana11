#include <iostream>
#include<array>
#include<memory>
#include<vector>

using namespace std;

int main()
{
    shared_ptr<vector<int>>Puntero1 = make_shared<vector<int>>();


    vector<shared_ptr<float>>Contenedor1;

    cout<<"Meter informacion al puntero de vector de enteros "<<endl;
    for(int i{0};i<10;i++){
        Puntero1->push_back(i);
    }

    cout<<"Info del puntero de vectores de enteros :"<<endl;
    for(int i{0};i<Puntero1->size();i++){
        cout<<Puntero1->at(i);
    }
    cout<<endl;


    cout<<"Meter informacion al vector de punteros"<<endl;
        for(int i{0};i<10;i++){
        Contenedor1.push_back(make_shared<float>(i));
    }


    cout<<"Info del vector de punteros de floats : "<<endl;
    for(int i{0};i<Contenedor1.size();i++){
        cout<<*Contenedor1.at(i);
    }
    cout<<endl;

    return 0;
}
