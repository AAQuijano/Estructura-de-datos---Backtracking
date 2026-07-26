#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include <stdio.h>
#include <cstring>
#include <vector>
#define Max 100
#define MAX 500

using namespace std;

struct vertice{
 string name;//nombre del vertice o nodo
 struct vertice *sig;
 struct arista *arco;//puntero hacia la primera arista del nodo
 };
struct arista{
 float km;
 float time;
 float costo;
 struct vertice *destino;//puntero al nodo de llegada
 struct arista *sig;
 };
typedef struct vertice *Tnodo;// Tipo Nodo
typedef struct arista *Tarista; //Tipo Arista
Tnodo p,pre_p;//puntero cabeza


float MatrizAdyacente[Max][Max],MatrizKm[Max][Max];
string Provincia[8] = {"Panama","Herrera","Colon","Cocle","LosSantos","Chiriqui","Veraguas","BocasDelToro"};

void gotoxy(int x,int y);
void Pre_cargar();
void menu();
void insertar_nodo(string a);
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista(string ini,string fin,float dis,float tiemp,float dinero);
void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();
void matriz();


void CrearMatriz(); //funci�n para crear nuestra matriz adyacente.
void CrearMatrizKm();
void mostrarmatriz();//funci�n para mostrar nuestra matriz.
int CantidadVertices();//funci�n para contar nuestros vertices o nodos.
float ExisteArcoKm(string i,string f);
float ExisteArco(string i,string f);//funci�n para  verificar si nuestro grafo tiene arcos
float BuscarAdy(Tnodo aux,string word);
float BuscarAdyKm(Tnodo aux,string word);
Tarista SeeAdy(Tnodo aux,string word);
Tnodo Buscarv(string valor); //funci�n para buscar.
void mostrarmatrizKm();
void mostrarmatriz();
void menu2();

vector<int> ady[ MAX ];  //lista de adyacencia
bool visitado[ MAX ];    //para nodos visitados
int V;
int path[ MAX ];
bool first;


void dfs( int u ){

    ( first )? cout<<u : cout<<"->"<<u;
    first = false;
    visitado[ u ] = true;
    for( int v = 0 ; v < ady[ u ].size(); ++v ){
        if( !visitado[ ady[ u ][ v ] ] ){
            dfs( ady[ u ][ v ] );
        }
    }
}



///Ver todos las rutas posibles partiendo de nodo inicial y llegando a uno final, usamos backtracking
void De_ori_a_dest( int u , int fin , int len,float compa ){
    visitado[ u ] = true;
    path[ len ] = u;                    //almaceno en el path el vertice actual

    if( u == fin ){                     //si se llego al final imprimimos ese path
        first = true;
        float a =0;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta:"<<tempo->name : cout<<"->"<<tempo->name;
        if(tempo->arco != NULL){
            a+=tempo->arco->km;
        }
        first = false;
        }
        if(a < compa){
cout<<"\n"<<"Distancia: "<<a<<" menor que: "<<compa<<endl;}
else if(a > compa){
  cout<<"\n"<<"Distancia: "<<a<<" mayor que: "<<compa<<endl;
}
else if(a == compa){
    cout<<"\n"<<"Distancia: "<<a<<" igual a: "<<compa<<endl;
}
        printf("\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        if( !visitado[ v ] ){
            De_ori_a_dest( v , fin , len + 1,compa );
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}

void De_ori_a_dest_minu( int u , int fin , int len,float compa ){
    visitado[ u ] = true;
    path[ len ] = u;                    //almaceno en el path el vertice actual

    if( u == fin ){                     //si se llego al final imprimimos ese path
        first = true;
        float a =0;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta:"<<tempo->name : cout<<"->"<<tempo->name;
        if(tempo->arco != NULL){
            a+=tempo->arco->time;
        }
        first = false;
        }
        if(a < compa){
cout<<"\n"<<"Minutos: "<<a<<" menor que: "<<compa<<endl;}
else if(a > compa){
  cout<<"\n"<<"Minutos: "<<a<<" mayor que: "<<compa<<endl;
}
else if(a == compa){
    cout<<"\n"<<"Minutos: "<<a<<" igual a: "<<compa<<endl;
}
        printf("\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        if( !visitado[ v ] ){
            De_ori_a_dest_minu( v , fin , len + 1,compa );
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}

void De_ori_dest3( int u , int fin , int len,float compa ){
    visitado[ u ] = true;
    path[ len ] = u;                    //almaceno en el path el vertice actual

    if( u == fin ){                     //si se llego al final imprimimos ese path
        first = true;
        float a =0;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta:"<<tempo->name : cout<<"->"<<tempo->name;
        if(tempo->arco != NULL){
            a+=tempo->arco->costo;
        }
        first = false;
        }
        if(a < compa){
cout<<"\n"<<"Costo: "<<a<<" menor que: "<<compa<<endl;}
else if(a > compa){
  cout<<"\n"<<"Costo: "<<a<<" mayor que: "<<compa<<endl;
}
else if(a == compa){
    cout<<"\n"<<"Costo: "<<a<<" igual a: "<<compa<<endl;
}
        printf("\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        if( !visitado[ v ] ){
            De_ori_a_dest( v , fin , len + 1,compa );
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}


void Desde_origen_km( int u ,float enlaces, int len,float compa,int indice,Tnodo y ){
    visitado[ u ] = true;
    path[ len ] = u; //almaceno en el path el vertice actual
    Tnodo tempN = Buscarv(Provincia[u]);
    Tarista tempA,L;
    int n,cont=0;
if(y->arco != NULL){
L = y->arco;
while(L != NULL){
if(L->km > compa){
    n = cont;
    break;
 }
 cont++;
 L = L->sig;
}
}
    if( enlaces > compa ){                     //si se llego al final imprimimos ese path
        first = true;
        Tnodo tempo,a;
        Tarista b;
        if(n == indice){
        for( int i = 0 ; i <= len-1 ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        b = SeeAdy(Buscarv(Provincia[path[len-1]]),Provincia[path[len]]);
        cout<<"\n"<<"Distancia de ruta (Km): "<<enlaces-b->km<<endl;
        cout<<"Destino menor a "<<compa;}
        printf("\n\n");

        first = true;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        cout<<"\n"<<"Distancia de ruta (Km): "<<enlaces<<endl;
        cout<<"Destino mayor a "<<compa<<endl;
        cout<<"---------------------------------------------------------------------";
        printf("\n\n");

        return;
    }
    if(tempN->arco == NULL){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        if(compa > enlaces){
        cout<<"\n"<<"Distancia de ruta (Km): "<<enlaces<<endl;
        cout<<"Destino menor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";}
        else if(compa < enlaces){
        cout<<"\n"<<"Distancia de ruta (Km): "<<enlaces<<endl;
        cout<<"Destino menor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        }

        printf("\n\n");
        return;
    }
    if(enlaces == compa){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
       cout<<"\n"<<"Distancia de ruta (Km): "<<enlaces<<endl;
       cout<<"Destino igual a "<<compa<<endl;
       cout<<"-----------------------------------------------------------------------";
        printf("\n\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        tempA = SeeAdy(tempN,Provincia[v]);
        if( !visitado[ v ] ){
            Desde_origen_km( v , enlaces+tempA->km , len + 1,compa,i,tempN );
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}

void Desde_origen_time( int u ,float enlaces, int len,float compa,int indice,Tnodo y ){
    visitado[ u ] = true;
    path[ len ] = u; //almaceno en el path el vertice actual
    Tnodo tempN = Buscarv(Provincia[u]);
    Tarista tempA,L;
    int n,cont=0;

if(y->arco != NULL){
L = y->arco;
while(L != NULL){
if(L->time > compa){
    n = cont;
    break;
 }
 cont++;
 L = L->sig;
}
}


    if( enlaces > compa ){                     //si se llego al final imprimimos ese path
        first = true;
        Tnodo tempo,a;
        Tarista b;
        if(n == indice){
        for( int i = 0 ; i <= len-1 ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        b = SeeAdy(Buscarv(Provincia[path[len-1]]),Provincia[path[len]]);
        cout<<"\n"<<"Minutos de ruta: "<<enlaces-b->time<<endl;
        cout<<"Minutos menor a "<<compa<<endl;}

        printf("\n");
        first = true;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        cout<<"\n"<<"Minutos de ruta: "<<enlaces<<endl;
        cout<<"Minutos mayor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        printf("\n\n");

        return;
    }
    if(tempN->arco == NULL){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        if(compa > enlaces){
        cout<<"\n"<<"Minutos de ruta: "<<enlaces<<endl;
        cout<<"Minutos menor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";}
        else if(compa < enlaces){
        cout<<"\n"<<"Minutos de ruta: "<<enlaces<<endl;
        cout<<"Minutos mayor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        }
        printf("\n\n");
        return;
    }
    if(enlaces == compa){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        cout<<"\n"<<"Minutos de ruta: "<<enlaces<<endl;
        cout<<"Minutos igual a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        printf("\n\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        tempA = SeeAdy(tempN,Provincia[v]);
        if( !visitado[ v ] ){
            Desde_origen_time( v , enlaces+tempA->time , len + 1,compa,i,tempN);
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}


void Desde_origen_costo( int u ,float enlaces, int len,float compa,int indice,Tnodo y ){
    visitado[ u ] = true;
    path[ len ] = u; //almaceno en el path el vertice actual
    Tnodo tempN = Buscarv(Provincia[u]);
    Tarista tempA,L;
    int n,cont=0;

if(y->arco != NULL){
L = y->arco;
while(L != NULL){
if(L->costo > compa){
    n = cont;
    break;
 }
 cont++;
 L = L->sig;
}
}


    if( enlaces > compa ){                     //si se llego al final imprimimos ese path
        first = true;
        Tnodo tempo,a;
        Tarista b;
        if(n == indice){
        for( int i = 0 ; i <= len-1 ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        b = SeeAdy(Buscarv(Provincia[path[len-1]]),Provincia[path[len]]);
        cout<<"\n"<<"Costo de ruta: "<<enlaces-b->costo<<endl;
        cout<<"Costo menor a "<<compa<<endl;}

        printf("\n");
        first = true;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        cout<<"\n"<<"Costo de ruta: "<<enlaces<<endl;
        cout<<"Costo mayor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        printf("\n\n");

        return;
    }
    if(tempN->arco == NULL){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len ; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        if(compa > enlaces){
        cout<<"\n"<<"Costo de ruta: "<<enlaces<<endl;
        cout<<"Costo menor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";}
        else if(compa < enlaces){
        cout<<"\n"<<"Costo de ruta: "<<enlaces<<endl;
        cout<<"Costo mayor a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        }
        printf("\n\n");
        return;
    }
    if(enlaces == compa){
    first = true;
        Tnodo tempo;
        for( int i = 0 ; i <= len; ++i ){
        tempo = Buscarv(Provincia[path[i]]);
        ( first ) ? cout<<"Ruta: "<<tempo->name : cout<<"->"<<tempo->name;
        first = false;
        }
        cout<<"\n"<<"Costo de ruta: "<<enlaces<<endl;
        cout<<"Costo igual a "<<compa<<endl;
        cout<<"-----------------------------------------------------------------------";
        printf("\n\n");
        return;
    }
int i;
    for( i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        tempA = SeeAdy(tempN,Provincia[v]);
        if( !visitado[ v ] ){
            Desde_origen_costo( v , enlaces+tempA->costo , len + 1,compa,i,tempN );
            //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
            visitado[ v ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
        }
    }
}



/* Programa Principal
*/
int main(void){
p=NULL;
pre_p = NULL;
Tnodo y,j;
Tarista w;
int op,x=0,inicial,finend,opcion;// opcion del menu
float kmd,waste,check,prueba;


 while(x<8){
insertar_nodo(Provincia[x]);
 x++;
 }

  ady[3].push_back(6);
        ady[6].push_back(4);
        ady[6].push_back(5);
        ady[6].push_back(1);
        ady[4].push_back(5);
        ady[0].push_back(2);
        ady[0].push_back(6);
        ady[0].push_back(3);
        ady[2].push_back(7);
        ady[2].push_back(3);
        ady[2].push_back(5);
Pre_cargar();
system("cls");
system("color 0b");
menu2();
system("cls");
 do{
 menu();
 cin>>op;
 switch(op)
 {

 case 1:
mostrar_grafo();

 break;
 case 2: mostrar_aristas();
 break;

 case 3:
     CrearMatriz();
     CrearMatrizKm();
     system("cls");
     gotoxy(145,2);
     cout<<"MATRIZ DE RELACION";
      gotoxy(145,7);
     cout<<"SEGUN COSTO";
     gotoxy(145,21);
     cout<<"SEGUN DISTANCIA (Km)";
     mostrarmatriz();
     mostrarmatrizKm();


    break;

 case 4:
     opcion = 0;
 while(opcion != 4){
cout<<"1. Consulta en distancia (Km)"<<endl;
cout<<"2. Consulta en minutos"<<endl;
cout<<"3. Consulta con costo"<<endl;
cout<<"4. Salir"<<endl;
cout<<"\n";
cout<<"Digite opcion en numero: ";
cin>>(opcion);
system("cls");
     switch(opcion){
  case 1:
      prueba = 0;
      inicial = 0;
      finend = 0;
     system("cls");

        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado
    cout<<"Nodo destino: ";
    cin>>finend;

    cout<<"Distancia en Km: ";
    cin>>(prueba);
    cout<<"\n";
    De_ori_a_dest( inicial-1 , finend-1 , 0,prueba ); //posibles rutas de nodo inicial a final
    system("pause");
    break;
  case 2:
      system("cls");
      prueba = 0;
      inicial = 0;
      finend = 0;
        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado
    cout<<"Nodo destino: ";
    cin>>finend;

    cout<<"Digite minutos: ";
    cin>>(prueba);
    cout<<"\n";
    De_ori_a_dest_minu( inicial-1 , finend-1 , 0,prueba ); //posibles rutas de nodo inicial a final
    system("pause");
    break;
  case 3:
      system("cls");
      prueba = 0;
      inicial = 0;
      finend = 0;
        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado
    cout<<"Nodo destino: ";
    cin>>finend;

    cout<<"Digite costo: ";
    cin>>(prueba);
    cout<<"\n";
    De_ori_dest3( inicial-1 , finend-1 ,0,prueba ); //posibles rutas de nodo inicial a final
    system("pause");
    break;
  case 4:
      system("pause");
    break;
  default:cout<<"\n"<<"Error"<<endl;
  system("pause");
    break;

 }
 system("cls");
 }
    break;

 case 5:
     system("cls");
        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado

    cout<<"Digite distancia en Km: ";
    cin>>(kmd);
    cout<<"\n";
    j = Buscarv(Provincia[inicial-1]);
    Desde_origen_km( inicial-1 ,0 , 0,kmd,0,j ); //posibles rutas de nodo inicial a final

    break;
 case 6:
     system("cls");
        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado

    cout<<"Digite minutos: ";
    cin>>(waste);
    cout<<"\n";
    j = Buscarv(Provincia[inicial-1]);
    Desde_origen_time( inicial-1 ,0 , 0,waste,0,j ); //posibles rutas de nodo inicial a final

    break;
 case 7:
     system("cls");
        //ady[ y ].push_back( x );    //Commentar si se desea aplicar en grafo dirigido

    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado

   mostrar_grafo();
   cout<<"\n";
    cout<<"1. Panama"<<endl;
    cout<<"2. Herrera"<<endl;
    cout<<"3. Colon"<<endl;
    cout<<"4. Cocle"<<endl;
    cout<<"5. Los Santos"<<endl;
    cout<<"6. Chiriqui"<<endl;
    cout<<"7. Veraguas"<<endl;
    cout<<"8. Bocas del Toro"<<endl;
    cout<<"\n";
    cout<<"Digite numero de opcion:"<<endl;
    cout<<"Nodo origen: ";
     cin>>inicial;//Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado

    cout<<"Digite costo: ";
    cin>>(check);
    cout<<"\n";
    j = Buscarv(Provincia[inicial-1]);
    Desde_origen_costo( inicial-1 ,0, 0,check, 0,j); //posibles rutas de nodo inicial a final
    break;
 case 8:
     return 0;
    break;
 default: cout<<"OPCION NO VALIDA...!!!";
 break;
 }
 cout<<endl<<endl;
 system("pause"); system("cls");
 }while(op!=8);
 getch();
 return 0;
}


/* Menu De Opciones
*/
void menu()
{
system("cls");
 cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
 cout<<" 1. MOSTRAR GRAFO "<<endl;
 cout<<" 2. MOSTRAR ARISTAS DE UN NODO "<<endl;
 cout<<" 3. MATRIZ DE COSTO DE LA AEREOLINEA"<<endl;
 cout<<" 4. CONSULTA DE ORIGEN A DESTINO"<<endl;
 cout<<" 5. DISTANCIA DEL VIAJE EN (Km)"<<endl;
 cout<<" 6. DISTANCIA DEL VIAJE EN MINUTOS"<<endl;
 cout<<" 7. DISTANCIA DEL VIAJE EN COSTO"<<endl;
 cout<<" 8. SALIR "<<endl;
 cout<<"\n INGRESE OPCION: ";
}
/* INSERSION DE NODO AL GRAFO
*/

void menu2(){
cout<<"\t\t\t              Universidad Tecnologica de Panama\n";
cout<<"\t\t\t       Facultad de Ingenieria de Sistemas Computacionales\n";
cout<<"\t\t\t     Departamento de Computacion y Sistemas Computacionales\n";
cout<<"\t\t\t           0684- Estructura y Representacion de Datos\n";
cout<<"\t\t\t                          Proyecto III\n\n\n";
cout<<"\t\t\t                   Prof.Nicholas Beliz Osorio\n";
	cout<<"\t\t\t\t\t\tIntegrantes\n";
	cout<<"\t\t\t\t\t\t\t\tAntonio Quijano  8-908-1148\n";
	cout<<"\t\t\t\t\t\t\t\tLuis Ku          8-923-509\n";
	cout<<"\t\t\t\t\t\t\t\tLouis Espino     8-945-1231\n";
	cout<<"\t\t\t\t\t\t\t\tIan Beckford     8-967-1300\n\n";


cout<<"\t\t\t                      I Semestre 2019\n\n\n";
system("pause");







}
void matriz()
{
 int matriz [4][4], i, j, num;

for (i= 0;i<=3;i++)
{
for (int j=0;j<=3;j++)
{
cout<<"\n\n\tIngrese 1 o 0";
cin>>(num);
 matriz [i][j]=num;
}
}
for (i= 0;i<=3;i++)
{for (j=0;j<=3;j++)
{ cout<<" "+matriz[i][j];}
 cout<<"\n"; }
}
/* INSERSION DE NODO AL GRAFO
*/

void Pre_cargar(){
float tiemp,dinero;

tiemp = 0;
 dinero = 0;
 tiemp = 60*(2414.0/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[3],Provincia[6],2414.0,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(3218.6/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[6],Provincia[4],3218.6,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(2414.0/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[6],Provincia[5],2414.0,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(2414.0/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[6],Provincia[1],2414.0,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(3218.6/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[4],Provincia[5],3218.6,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(2414.0/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[0],Provincia[2],2414.0,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(3862.4/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[0],Provincia[6],3862.4,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(2092.2/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[0],Provincia[3],2092.2,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(3218.6/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[2],Provincia[7],3218.6,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(1609.4/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[2],Provincia[3],1609.4,tiemp,dinero);
 tiemp = 0;
 dinero = 0;
 tiemp = 60*(3701.5/945);
 dinero = 1.56*tiemp;
 insertar_arista(Provincia[2],Provincia[5],3701.5,tiemp,dinero);

}
void insertar_nodo(string a){

 Tnodo t,nuevo = new struct vertice;
 nuevo->name = a;
 nuevo->sig = NULL;
 nuevo->arco=NULL;

 if(p==NULL){
 p = nuevo;
 cout<<"PRIMER NODO...!!!";

 }else{
 t = p;
 while(t->sig!=NULL){
 t = t->sig;

 }
 t->sig = nuevo;
 cout<<"NODO INGRESADO...!!!";

 }
}
/* AGREGAR ARISTA
 Primero se debe agregar para insertar arista */
void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo){

 Tarista a;
 if(aux->arco==NULL){
 aux->arco=nuevo;
 nuevo->destino=aux2;
 cout<<"PRIMERA ARISTA....!";
 }
 else{

 a = aux->arco;
 while(a->sig!=NULL){
 a = a->sig;
 }
 nuevo->destino = aux2;
 a->sig = nuevo;
 cout<<"ARISTA AGREGADA...!!!!";
 }
}
/* INSERSION DE ARISTA
 */
void insertar_arista(string ini,string fin,float dis,float tiemp,float dinero){

int pes;
 Tarista nuevoA = new struct arista;
 Tnodo aux=NULL,aux2=NULL;
 if(p==NULL){
 cout<<"GRAFO VACIO...!!!!";
 return;
 }
 nuevoA->sig=NULL;
 nuevoA->km = dis;
 nuevoA->time = tiemp;
 nuevoA->costo = dinero;



 aux = p;
 aux2 = p;

 while(aux2!=NULL){

 if(aux2->name == fin){
 break;
 }
 aux2 = aux2->sig;
 }

 while(aux!=NULL){
 if(aux->name == ini)
 {
 agrega_arista(aux,aux2,nuevoA);
 return;
 }
 aux = aux->sig;
 }

}
/* PARA BORRAR TODAS LAS ARISTAS DE UN NODO
 */
void vaciar_aristas(Tnodo &aux)
{
 Tarista q,r;
 q=aux->arco;
 while(q->sig!=NULL)
 {
 r=q;
 q=q->sig;
 delete(r);
 }
}
/* ELIMINAR NODO
 */
void eliminar_nodo(){
string var;
 Tnodo aux,ant;
 aux=p;
 cout<<"ELIMINAR UN NODO\n";
 if(p==NULL)
 {
 cout<<"GRAFO VACIO...!!!!";
 return;
 }
 cout<<"INGRESE NOMBRE DE VARIABLE:";
 cin>>var;
 while(aux!=NULL)
 {
 if(aux->name==var)
 {
 if(aux->arco!=NULL)
 vaciar_aristas(aux);
 if(aux==p)
 {
 p=p->sig;
 delete(aux);
 cout<<"NODO ELIMINADO...!!!!";
return;
 }
 else{
 ant->sig = aux->sig;
 delete(aux);
 cout<<"NODO ELIMINADO...!!!!";
return;
 }
 }
 else{
 ant=aux;
 aux=aux->sig;
 }
 }
}
/* ELIMINAR ARISTA
 */
void eliminar_arista()
{
string ini, fin;
 Tnodo aux, aux2;
 Tarista q,r;
 cout<<"\n ELIMINAR ARISTA\n";
 cout<<"INGRESE NODO DE INICIO:";
 cin>>ini;
 cout<<"INGRESE NODO FINAL:";
 cin>>fin;
 aux=p;
 aux2=p;
 while(aux2!=NULL)
 {
 if(aux2->name==fin)
 {
 break;
 }
 else
 aux2=aux2->sig;
 }
 while(aux!=NULL)
 {
 if(aux->name==ini)
 {
 q=aux->arco;
 while(q!=NULL)
 {
 if(q->destino==aux2)
 {
 if(q==aux->arco)
 aux->arco=aux->arco->sig;
 else
 r->sig=q->sig;
 delete(q);
cout<<"ARISTA "<<aux->name<<"----->"<<aux2->name<<"ELIMINADA......!!!!";
 return;
 }
 }
 r=q;
 q=q->sig;
 }
 aux = aux->sig;
 }
}
/* MOSTRAR GRAFO (impresion)
 */
void mostrar_grafo(){
Tnodo ptr;
 Tarista ar;
 ptr=p;
 cout<<"NODO|LISTA DE ADYACENCIA\n";
 while(ptr!=NULL){
cout<<" "<<ptr->name<<"| ";
 if(ptr->arco!=NULL){
 ar=ptr->arco;
 while(ar!=NULL){
 cout<<" "<<ar->destino->name;
 ar=ar->sig;
 }
 }
 ptr=ptr->sig;
 cout<<endl;
 }
}
/* MOSTRAR ARISTAS(imprimir)
 */
void mostrar_aristas()
{
 Tnodo aux;
 Tarista ar;
 string var;
 cout<<"MOSTRAR ARISTAS DE NODO\n";
 cout<<"INGRESE NODO:";
getline(cin,var);
getline(cin,var);
 aux=p;
 while(aux!=NULL)
 {
 if(aux->name==var)
 {
 if(aux->arco==NULL)
 { cout<<"EL NODO NO TIENE ARISTAS...!!!!";
 return;
 }
 else
 {
 cout<<"NODO|LISTA DE ADYACENCIA\n";
 cout<<" "<<aux->name<<"|";
ar=aux->arco;
 while(ar!=NULL)
 {
 cout<<ar->destino->name<<" ";
 ar=ar->sig;
 }
 cout<<endl;
return;
 }
 }
 else
 aux=aux->sig;
 }
}
Tarista SeeAdy(Tnodo aux,string word){ //funci�n booleana para poder realizar la matriz adyacente
     Tarista temp=aux->arco; //creamos un nuevo puntero.
     Tarista a = NULL;  //creamos un varible de tipo boolena.
     while(temp != NULL){ //ciclo while o mientras.
        if(word == temp->destino->name){ //sentencia if.
           return temp;} //retornamos a verdadero.
        temp=temp->sig;//igualamos nuestro puntero para que verifique todos los valores.
     }
	 return a;// sino retornamos a falso
}

int CantidadVertices(){ //funci�n para contar nuestro vertices o nodos
    Tnodo nodo=p; //creamos un nuevo nodo y lo igualamos a otro.
    int i=0;//creamo una nueva variable entera y la igualamos a 0
    while(nodo!=NULL){//ciclo mientras, si nuestro nodo es distinto de NULL
       i++;//le sumamos 1 a nuestra variable.
       nodo=nodo->sig;  //igualamos nuestro nodos, para poder sumar la cantidad de los mismos
    }
    return i; //retornamos i.
}

Tnodo Buscarv(string valor){ //funci�n para buscar valores dentro de nuestro grafo

	Tnodo indice,n=NULL; //creamos un nuevo nodo e igualamos a la varible n a NULL
	indice=p; //igualamos nuestro
	while(indice!=NULL){ // se recorre la lista  hasta encontrar el valor buscado
	if(indice->name == valor){
			return indice; // al encontar el valor  lo retorna
			}
		indice=indice->sig; //igualamos nuestros nodos para que verifiquen nuestros datos
	}
    cout<<"\n\n\tEL VALOR BUSCADO NO ESTA EN EL GRAFO";
 return n; // si el valor buscado no esta en la lista retorna nulo
}
float BuscarAdyKm(Tnodo aux,string word){ //funci�n booleana para poder realizar la matriz adyacente
     Tarista temp=aux->arco; //creamos un nuevo puntero.
     float a;  //creamos un varible de tipo boolena.
     while(temp != NULL){ //ciclo while o mientras.
        if(word == temp->destino->name){ //sentencia if.
           return a=temp->km;} //retornamos a verdadero.
        temp=temp->sig;//igualamos nuestro puntero para que verifique todos los valores.
     }
	 return a=0;// sino retornamos a falso
}

float BuscarAdy(Tnodo aux,string word){ //funci�n booleana para poder realizar la matriz adyacente
     Tarista temp=aux->arco; //creamos un nuevo puntero.
     float a;  //creamos un varible de tipo boolena.
     while(temp != NULL){ //ciclo while o mientras.
        if(word == temp->destino->name){ //sentencia if.
           return a=temp->costo;} //retornamos a verdadero.
        temp=temp->sig;//igualamos nuestro puntero para que verifique todos los valores.
     }
	 return a=0;// sino retornamos a falso
}

float ExisteArcoKm(string i,string f){//funci�n para poder realizar la matriz adyacente
  Tnodo nodo; //creamos un nuevo nodo.
  float a;//creamos una variable entera, y la inicializamos en 1
    nodo=Buscarv(i);//igualamos nuestro nodo a la funci�n buscar.
    if(nodo != NULL){ //sentencia if, utilizando el nodo creado.
         if(BuscarAdyKm(nodo,f) != 0){ //sentencia if, llamamos a nuestra funci�n booleana.
		 return a = BuscarAdyKm(nodo,f); //retornamos a
		 }else{
		 return a=0; //retornamos a
		 }
    }
}

float ExisteArco(string i,string f){//funci�n para poder realizar la matriz adyacente
  Tnodo nodo; //creamos un nuevo nodo.
  float a;//creamos una variable entera, y la inicializamos en 1
    nodo=Buscarv(i);//igualamos nuestro nodo a la funci�n buscar.
    if(nodo != NULL){ //sentencia if, utilizando el nodo creado.
         if(BuscarAdy(nodo,f) != 0){ //sentencia if, llamamos a nuestra funci�n booleana.
		 return a = BuscarAdy(nodo,f); //retornamos a
		 }else{
		 return a=0; //retornamos a
		 }
    }
}

void CrearMatriz(){ //funci�n para crear nuestra matriz adyacente.
     Tnodo nodo=p,nodotemp; //creamos un nuevo puntero y lo igualamos.
     int i,j,inicio,fin; //creamos nuestras variables enteras.
     int cant=CantidadVertices(); //creamos un varibale entera y la igualamos a nuestra funci�n cantidad de vertices.
     for(i=0;i<cant;i++){ //ciclo for
         nodotemp=p;//igualamos nuestros punteros.
       for(j=0;j<cant;j++){//ciclos for
       //guardamos en la matriz creada anteriormente los datos de nuestra funci�n existe arco.
         MatrizAdyacente[i][j]=ExisteArco(nodo->name,nodotemp->name);
         nodotemp=nodotemp->sig; //igualamos nuestros punteros para que verifiquen todos los datos.
       }
        nodo=nodo->sig;//igualamos nuestros punteros para que verifiquen todos los datos.
     }
     delete nodo; //eliminamos nodo  al terminar los ciclos for
     delete nodotemp;  //eliminamos nodotemp al terminar los ciclos for.
}

void CrearMatrizKm(){ //funci�n para crear nuestra matriz adyacente.
     Tnodo nodo=p,nodotemp; //creamos un nuevo puntero y lo igualamos.
     int i,j,inicio,fin; //creamos nuestras variables enteras.
     int cant=CantidadVertices(); //creamos un varibale entera y la igualamos a nuestra funci�n cantidad de vertices.
     for(i=0;i<cant;i++){ //ciclo for
         nodotemp=p;//igualamos nuestros punteros.
       for(j=0;j<cant;j++){//ciclos for
       //guardamos en la matriz creada anteriormente los datos de nuestra funci�n existe arco.
         MatrizKm[i][j]=ExisteArcoKm(nodo->name,nodotemp->name);
         nodotemp=nodotemp->sig; //igualamos nuestros punteros para que verifiquen todos los datos.
       }
        nodo=nodo->sig;//igualamos nuestros punteros para que verifiquen todos los datos.
     }
     delete nodo; //eliminamos nodo  al terminar los ciclos for
     delete nodotemp;  //eliminamos nodotemp al terminar los ciclos for.
}


void mostrarmatriz(){ //funci�n para mostrar nuestra matriz adyacente.
    int i,j,cant,a,b; //creamos varibales enteras
    Tnodo nodo=p; //creamos un nuevo puntero.
    cant=CantidadVertices(); //igulamos  la varibale creada anteriormente a la cantidad de vertices.
	 //espacios
a = 0;
    for(i=0;i<cant;i++){//ciclo for.
    gotoxy(15+a,0);
	cout<<nodo->name; //mostramos los nodos o vertices del grafo.
	nodo=nodo->sig; //igualamos los punteros para que muestre todos los vertices
	a = a+15;
	}
    nodo=p; //igualamos los punteros
	 //saltos de linea.

    for( i=0;i<cant;i++){ //ciclo for.
        gotoxy(0,3+i);
		 cout<<nodo->name; //mostramos los vertices de nuestro grafo.
		 a = 0;
         for(j=0;j<cant;j++){ //ciclo for
             gotoxy(15+a,3+i);
			cout<<MatrizAdyacente[i][j]; //mostramos los datos guardados en la matriz.
         a = a+15;
         }
         nodo=nodo->sig; //igualamos los punteros para que muestre todos los datos.
         cout<<"\n"; //salto de linea.
    }
}

void mostrarmatrizKm(){ //funci�n para mostrar nuestra matriz adyacente.
    int i,j,cant,a,b; //creamos varibales enteras
    Tnodo nodo=p; //creamos un nuevo puntero.
    cant=CantidadVertices(); //igulamos  la varibale creada anteriormente a la cantidad de vertices.
	 //espacios
a = 0;
    for(i=0;i<cant;i++){//ciclo for.
    gotoxy(15+a,15);
	cout<<nodo->name; //mostramos los nodos o vertices del grafo.
	nodo=nodo->sig; //igualamos los punteros para que muestre todos los vertices
	a = a+15;
	}
    nodo=p; //igualamos los punteros
	 //saltos de linea.

    for( i=0;i<cant;i++){ //ciclo for.
        gotoxy(0,17+i);
		 cout<<nodo->name; //mostramos los vertices de nuestro grafo.
		 a = 0;
         for(j=0;j<cant;j++){ //ciclo for
             gotoxy(15+a,17+i);
			cout<<MatrizKm[i][j]; //mostramos los datos guardados en la matriz.
         a = a+15;
         }
         nodo=nodo->sig; //igualamos los punteros para que muestre todos los datos.
         cout<<"\n"; //salto de linea.
    }
}


void gotoxy(int x, int y){

HANDLE view = GetStdHandle(STD_OUTPUT_HANDLE);

COORD Pos;
Pos.X = x;
Pos.Y = y;

SetConsoleCursorPosition(view,Pos);

}


