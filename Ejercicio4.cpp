#include <iostream>
#include<array>
#include<memory>
#include<set>
#include<string>
#include<limits>
using namespace std;
struct Gato{
    string nombre;
    bool es_bueno;
};
struct Contenedor{
    set<shared_ptr<string>>Puntero_string;
    set<shared_ptr<int>>Puntero_int;
    //set<shared_ptr<Gato>>Puntero_gato;
};


bool Repetir();
void Puntero_String( set<shared_ptr<string>> & p);
void Puntero_Int( set<shared_ptr<int>> & p);

void MostrarInfo_String(const set<shared_ptr<string>>&p);
void MostrarInfo_Int(const set<shared_ptr<int>>&p);

int main()
{   Contenedor info;
    do{
        int tipo;
        cout<<"\n\t1.Puntero de strings";
        cout<<"\n\t2.Puntero de ints";
        cout<<"\n\tQue tipo de dato quieres acceder a : ";

        cin>>tipo;

        if(cin.fail() or tipo>3 or tipo<0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n\tNumero no valido introduzca otro valido : ";
            cin>>tipo;
        }

        switch(tipo){
        case 1:
            Puntero_String(info.Puntero_string);
            break;
        case 2:
            Puntero_Int(info.Puntero_int);
            break;
        default:
            cout<<"\n\tRespuest ano aceptada";
            break;
        }
        cout<<"\n\tVolver a capturar datos de diferentes tipos"<<endl;
    }while(Repetir());

    cout<<"\n\tINFORMACION SOBRE LOS VECTORES :"<<endl;
    MostrarInfo_String(info.Puntero_string);
    MostrarInfo_Int(info.Puntero_int);



    return 0;
}
bool Repetir(){
    //Ir almacendando info de forma ciclica :
    bool rpetir;
    int cont = 0;
    do{
        if(cont == 0){
            cout<<"\n\tQuieres meter mas datos? (0-no/1-si)";
            cin>>rpetir;
            cont++;
        }
        else{
            cout<<"\n\tEntrada no valida, introducala de nuevo : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin>>rpetir;
        }
    }while(cin.fail());
    return rpetir;
}
void Puntero_String( set<shared_ptr<string>> & p){
    string frase;
    bool repetir;
    do{
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Por si acaso en el anteriori cin se quede un espacio en el buffer.
        cout<<"\n\tIntroduzca una frase : ";
        getline(cin,frase);

        p.insert(make_shared<string>(frase));
        repetir = Repetir();
    }while(repetir);
}

void Puntero_Int( set<shared_ptr<int>> & p){
    int numero ;
    bool repetir;
    do{
        int contador = 0;
        do{
            if(contador== 0){
                cout<<"\n\tIntroduce un NUMERO :";
                cin>>numero;
                contador++;
            }
            else{
                cout<<"\n\tNumero no se ha podido leer correctamente, introduce otro: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin>>numero;
            }
        }while(cin.fail());

        p.insert(make_shared<int>(numero));
        repetir = Repetir();

    }while(repetir);  //¿Podria hacer Repetir() directamente?
}



void MostrarInfo_String(const set<shared_ptr<string>>&p){
    for(const shared_ptr<string>&n : p){
        cout<<"\n\t "<<*n;
    }
    cout<<endl;
}

void MostrarInfo_Int(const set<shared_ptr<int>>& p){
    for(const shared_ptr<int>&n :p){
        cout<<"\n\t "<<*n;
    }
    cout<<endl;
}

//No se puede utilizar un se<Struct> ya que no esta definido como se ha de ordenar un struct debido a su gran cantidad de posibles elementos.
//Por lo tanto todo invocación de tal manera resultara en un error y la maquina parando.


