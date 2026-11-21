#include <iostream>
#include<array>
#include<memory>


using namespace std;

struct Robot{
    array<float,2>coordenandas;
    int bateria;
};

int main()
{
    Robot rob = {{2,2},100};
    shared_ptr<Robot>Rob1 = make_shared<Robot>(rob);

    shared_ptr<int>VidaRob1 = make_shared<int>(100);

    //Mostrar el entero :
    cout<<"Vida del robot : "<<*VidaRob1<<endl;
    //Direccion de memoria a la que apunta:
    cout<<"Donde apunta la informacion : "<<VidaRob1<<endl;

    //Mostrar el Robot:
    cout<<"Coordenadas : "<<endl;
    cout<<"En X : "<<Rob1->coordenandas[0]<<endl;
    cout<<"En Y : "<<Rob1->coordenandas[1]<<endl;
    cout<<"Vida del robot : "<<Rob1->bateria<<endl;
    //Donde señala la informacion de Rob1 :
    cout<<"Donde apunta la informacion : "<<Rob1<<endl;


    cout<<"Hello World";
    return 0;
}
