#include <iostream>
#include <string.h>

using namespace std ;

typedef struct contacto{
 char * nombre;
 int edad;
 float altura;
 unsigned long telefono;

 struct contacto * sigContacto;
 struct contacto * antContacto;

}Contacto;

typedef struct lista_contactos{
  Contacto * inicio;
  Contacto * final;
  int cardinalidad;
}Agenda;

void crearLista(Agenda ** agenda){
  *agenda =(Agenda*)malloc(sizeof(Agenda));
  (*agenda)->inicio = NULL;
  (*agenda)->final  = NULL;
  (*agenda)->cardinalidad = 0;
}

void agregarContacto(Agenda * agenda,char * nombre,int edad,float altura, int tel){

  Contacto * aux = (Contacto *)malloc (sizeof(Contacto));
  aux->nombre = nombre;
  aux->edad = edad;
  aux->altura = altura;
  aux->telefono = tel;

  if(agenda->inicio == NULL){
    agenda->cardinalidad=1;
    agenda->inicio = aux;
    agenda->final = aux;

    aux->antContacto = aux;

  }else{
    agenda->final->sigContacto = aux;
    aux->antContacto = agenda->final;
    agenda->final = aux;

    agenda->cardinalidad++;
  }

}

void verContactos(Agenda * agenda ){
  Contacto * aux = agenda->inicio;
  int count = 0;

  cout << "\n********************************" << endl;


  cout << "PRINTING CONTACTS\n" << endl;
  

  while(count < agenda->cardinalidad){
    cout <<"\t"<< aux->nombre << ": "<<aux->telefono<<" "<<aux->edad<<" "<<aux->altura <<endl;
    aux=aux->sigContacto;
    count++;
  }

  cout << "\nNumero de Contactos: " << agenda->cardinalidad << "\n"<<endl;
  cout << "********************************\n" << endl;

}

void eliminarContacto(Agenda * agenda , char * nombreEliminar){
  Contacto * aux_buscador = agenda->inicio;
  Contacto * aux_buscador2 = NULL;
  int sensor = 0;

  cout << "\n";

  for(int i = 0 ; i < agenda->cardinalidad ; i++){

      if(strcmp((aux_buscador->nombre),(nombreEliminar))==0){

        sensor = 1;

        if(i==0){
      
            agenda->inicio = aux_buscador->sigContacto;
            agenda->cardinalidad--;
            agenda->inicio->antContacto = NULL;
            cout <<"*Status: Contacto Eliminado*" << endl;

        }else if(aux_buscador == agenda->final){
          agenda->final = aux_buscador->antContacto;     
          agenda->cardinalidad--;          
          agenda->final->sigContacto=NULL;
          cout <<"*Status: Contacto Eliminado*" << endl;
          
          
      }else{
        aux_buscador->antContacto->sigContacto = aux_buscador->sigContacto;
        aux_buscador->sigContacto->antContacto = aux_buscador->antContacto;
        agenda->cardinalidad--;
        aux_buscador = NULL;
        cout <<"*Status: Contacto Eliminado*" << endl;
      }
    }
    aux_buscador = aux_buscador->sigContacto;
  }

  if(sensor==0){
    cout <<"*Status: No se encuentra registrado*" << endl;
  }
}

int main()

{
  Agenda * nuevaAgenda1;

  crearLista(&nuevaAgenda1);

  agregarContacto(nuevaAgenda1,"Andres", 27,1,3112341124);
  agregarContacto(nuevaAgenda1,"Ethan",  3,1,3123453255);
  agregarContacto(nuevaAgenda1,"Mabel",  20,1,3214957647);
  agregarContacto(nuevaAgenda1,"Camila", 25,1,3103973625);
  
  eliminarContacto(nuevaAgenda1,"Andres");
  eliminarContacto(nuevaAgenda1,"Andres");
  eliminarContacto(nuevaAgenda1,"Camila");

  verContactos(nuevaAgenda1);
  return 0;
}
