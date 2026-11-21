#include <iostream>
#include<array>
#include<memory>
#include<vector>
#include<string>
#include<limits>
using namespace std;
struct Gato{
    string nombre;
    bool es_bueno;
};
struct Contenedor{
    vector<shared_ptr<string>>Puntero_string;
    vector<shared_ptr<int>>Puntero_int;
    vector<shared_ptr<Gato>>Puntero_gato;
};


bool Repetir();
void Puntero_String( vector<shared_ptr<string>> & p);
void Puntero_Int( vector<shared_ptr<int>> & p);
void Puntero_Struct(vector<shared_ptr<Gato>>&p);

void MostrarInfo_String(const vector<shared_ptr<string>>&p);
void MostrarInfo_Int(const vector<shared_ptr<int>>&p);
void MostrarInfo_Struct(const vector<shared_ptr<Gato>>&p);

int main()
{   Contenedor info;
    do{
        int tipo;
        cout<<"\n\t1.Puntero de strings";
        cout<<"\n\t2.Puntero de ints";
        cout<<"\n\t3.Puntero de gatos";
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

        case 3:
            Puntero_Struct(info.Puntero_gato);
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
    MostrarInfo_Struct(info.Puntero_gato);


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
void Puntero_String( vector<shared_ptr<string>> & p){
    string frase;
    bool repetir;
    do{
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Por si acaso en el anteriori cin se quede un espacio en el buffer.
            cout<<"\n\tIntroduzca una frase : ";
            getline(cin,frase);

            p.push_back(make_shared<string>(frase));
            repetir = Repetir();
    }while(repetir);
}

void Puntero_Int( vector<shared_ptr<int>> & p){
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

        p.push_back(make_shared<int>(numero));
        repetir = Repetir();

    }while(repetir);  //¿Podria hacer Repetir() directamente?
}

void Puntero_Struct(vector<shared_ptr<Gato>>&p){
    Gato minino;
    do{
        int contador = 0;
        do{
            if(contador == 0){
                cout<<"\n\tIntroduce el nombre del gato : ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Lo mismo que en el anterior getline()
                getline(cin,minino.nombre);

                cout<<"\n\tSe comporta bien el gato? : ";
                cin>>minino.es_bueno;
                contador++;
            }
            else{
                cout<<"\n\tLos datos no se han podido almacenar correctamente, introduzclaos de nuevo  "<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"\n\tNombre del gato : ";
                getline(cin,minino.nombre);
                cout<<"\n\tComportamiento del gato :";
                cin>>minino.es_bueno;
            }
        } while(cin.fail());
        p.push_back(make_shared<Gato>(minino));
    }while(Repetir());
}

void MostrarInfo_String(const vector<shared_ptr<string>>&p){
    for(int i{0};i<p.size();i++){
        cout<<"\n\t "<<*p.at(i)<<endl;
    }
    cout<<endl;
}

void MostrarInfo_Int(const vector<shared_ptr<int>>& p){
    for(int i{0};i<p.size();i++){
        cout<<"\n\t "<<*p.at(i);
    }
    cout<<endl;
}

void MostrarInfo_Struct(const vector<shared_ptr<Gato>>&p){
    cout<<"\n\t==================="<<endl;
    for(int i{0};i<p.size();i++){
        cout<<"\n\tNombre del gato : "<<p.at(i)->nombre;
        cout<<"\n\tEs bueno : ";
        if(p.at(i)->es_bueno == false){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"SI"<<endl;
        }
    }
    cout<<"\n\t==================="<<endl;
}

