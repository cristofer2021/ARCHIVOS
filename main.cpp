#include <iostream>
#include <fstream>
using namespace std;

void ingresar();
void mostrar();

  string nombre;
  string apellido, carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  string nombrearchivo;
  

int main() 
{
  int op;
 
  do
  {
  cout <<"opciones\n"<<endl;
  cout<<"1.-ingresar datos"<<endl;
  cout<<"2.-mostrar datos"<<endl;
  cout <<"ingresar el numero de su opcion:";

   //getline(cin,op);
   cin>>op;
    
  switch(op)
  {
    case 1:
    {
    cout<<"caso 1"<<endl;
    ingresar();
    }
    break;
    case 2:
    {
      mostrar();
    }
    break;
  }
  }while(r=='n');
  
}




void ingresar()
{
    cout<<"Ingrese el nombre del archivo: ";
    while(getchar()!='\n');
    getline(cin,nombrearchivo);
    archivoprueba.open(nombrearchivo.c_str(), ios::out);

  
  do{
    cout<<"\t Ingrese el nombre: ";
    getline(cin,nombre);
    cout<<"\t Ingrese el apellido: ";
    getline(cin,apellido);
    cout<<"\t Ingrese carrera: ";
    getline(cin,carrera);
    cout<<"\t Ingrese la edad: ";
    cin>>edad;
    archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea ingresar otro contacto: (s/n) \n ";
    cin>>r;
    cin.ignore();


  }while(r =='s');
  archivoprueba.close();
 
}





void mostrar()
{
  
  
  ifstream archivolecura(nombrearchivo.c_str());
  string texto;
  if(archivolecura.fail()){
   cout<<"El archivo no se pudo leer";
 }
 else{
   while(!archivolecura.eof()){
    archivolecura>>nombre>>apellido>>carrera>>edad;
  if(!archivolecura.eof())
     {
     cout<<"***************************\n";
     cout<<"Nombre: "<<nombre<<endl;
     cout<<"Apellido: "<<apellido<<endl;
     cout<<"Carrera: "<<carrera<<endl;
     cout<<"Edad: "<<edad<<endl;
     }
   }
 }
 archivolecura.close();
}