//
// Created by SEBASTIAN on 24/10/2019.
//

#ifndef PROYECTOPOOII_CREARARENA_H
#define PROYECTOPOOII_CREARARENA_H
#include <iostream>
#include <vector>
#include "Algoritmo_&SP.h"
using namespace std;
typedef long int variable;
const char figura=219;
void llenar_la_arena_con_numeros_0(variable **puntero, variable n , variable m ){ //llena la matriz con numeros 0.
    for(int i=0 ;i<n ;i++){for(int p=0 ;p<m ;p++){puntero[i][p]=0;}}
}

void llenar_la_arena_completa(variable *puntero1 , variable *puntero2 , variable **puntero3 , int j){ //llenamos la arena con 1:hace referencia a las ubicaciones bloqueadas.
    for (int i=0 ;i<j ;i++){
        int posicionx , posiciony;
        posicionx=puntero1[i];
        posiciony=puntero2[i];
        puntero3[posicionx][posiciony]=1;
    }
}

void imprimirarena(variable **puntero , variable n , variable m){ //imprimimos la arena.
    for(int i=0 ;i<n ;i++){
        for (int z=0 ;z<m;z++){
            if(puntero[i][z]==0){ cout<<"[ ]\t";}
            else{cout<<"[X]\t";}
        }
        cout<<endl<<endl;
    }
}

void pedir_imprimir(variable **puntero , variable n , variable m){
    cout<<"Hola deseas que imprimamos la arena , para que puedas ver el laberinto ? ";
    cout<<endl;
    variable opcion;
    do{
        cout<<"1. Si"<<endl<<"2. No"<<endl; //opciones si o no
        cin>>opcion;
        if(opcion<1 || opcion>2){
            cout<<"Porfavor que este dentro del rango.(1 y 2)"<<endl; //si equivoca , te dira que pongas posiciones correctas.
        }
    }while(opcion<1 || opcion>2);
    if(opcion ==1 ){
        cout<<endl;
        imprimirarena( puntero , n , m);
    }
}
variable **creararena(variable filas , variable columnas){
    variable **puntero=nullptr;
    puntero=new variable*[filas];
    for(int i=0 ;i<filas ;i++){
        puntero[i]=new variable[columnas];
    }
    return puntero;
}

void guardar(vector<vector<variable>>&vector_posiciones_libres_coordenadas , variable **arena , variable filas1 , variable columnas1){
    for(variable i=0 ; i<filas1 ;i++){
        for(variable j=0 ; j<columnas1 ;j++){
            if(arena[i][j]==0){
                vector<variable > temporalmente={i,j};
                vector_posiciones_libres_coordenadas.push_back(temporalmente);
                temporalmente.clear();
            }
        }
    }
}
void muestra_posiciones_libre(variable total_de_espacios_vacios , vector<vector<variable>> coordenadas){
    cout<<"Deseas que te muestre las posiciones que estan libres :"<<endl;
    variable si;
    do{
        cout<<"1. Si."<<endl<<"2. No.";
        cin>>si;
        if(si==1 || si==2){
            break;
        }
    }while(true);
    if(si==1){
        cout<<"Puede utilizar estas coordenadas para su posicion y su objetivo."<<endl;
        cout<<"<  x   ,   y  >"<<endl;
        for(int i=0 ; i<total_de_espacios_vacios ; i++){ //imprime las coordenadas x e y que estan libres.
            cout<<"< "<<coordenadas[i][0]<<" , "<<coordenadas[i][1]<<" >";
            if(i!=total_de_espacios_vacios-1){
                cout<<" ; ";
            }
            else{
                cout<<" .";
            }
        }
        cout<<endl;
    }
}
void verifica_posiciones_iniciales_y_finales_correctas(variable &posicioninicialx , variable &posicioninicialy , variable  &posicionfinalx , variable  &posicionfinaly , variable *x , variable *y , variable cantidad_de_obstaculos){
    variable contador=0;
    do{ //se verifica si las posiciones que son mandadas estan libres.
        contador=0;
        cout<<"1. La posicion inicial en x : ";cin>>posicioninicialx;
        cout<<"2. La posicion inicial en y : ";cin>>posicioninicialy;
        cout<<"3. La posicion final en x   : ";cin>>posicionfinalx;
        cout<<"4. La posicion final en y   : ";cin>>posicionfinaly;
        for (int i=0 ; i<cantidad_de_obstaculos ;i++){
            variable verificarx , verificary ;
            verificarx=x[i];
            verificary=y[i];
            if (((posicioninicialx==verificarx && posicioninicialy==verificary)||(posicionfinaly==verificary && posicionfinalx==verificarx))||(posicionfinalx==posicioninicialx && posicionfinaly==posicioninicialy)){
                contador++;
            }
        }
        if(contador!=0){cout<<"Porfavor iniciar las posiciones que no esten en una restriccion(mandar coordenadas libres).";}
    }while(contador !=0);
    cout<<endl;
}

variable halleelmenor(vector<variable> verificar){
    variable menor=100000000;
    variable posicion;
    variable a;
    for(variable i=0;i<verificar.size();i++){
        if(verificar[i]<menor){
            menor=verificar[i];
            posicion=i;
            a=posicion;
        }
    }
    return a;

}
void separarvariables(vector<variable>&x , vector<variable>&y , vector<vector<vector<variable >>>vectortotal ,variable o){
    variable e=vectortotal[o].size();
    for(int i=0 ; i<e; i++){
        variable ox=vectortotal[o][i][0];
        variable oy=vectortotal[o][i][1];
        x.push_back(ox);
        y.push_back(oy);
    }
}
void llenar_arena_final(variable **arena, vector<variable>x , vector<variable>y , variable medida){
    for (int i=0 ;i<medida ;i++){
        variable posicionx , posiciony;
        posicionx=x[i];
        posiciony=y[i];
        arena[posicionx][posiciony]=88;
    }
}
void mostrar_coordenadas_del_camino_mas_corto(vector<vector<variable>> coordenadas){
    cout<<"Deseas que te muestre las coordenadas del camino mas corto , del camino que hizo?"<<endl;
    variable a;
    do{
        cout<<"1.Si "<<endl;
        cout<<"2.No "<<endl;
        cin>>a;
    }while(a<1 || a>2);
    if(a==1){
        for(int i=0;i<coordenadas.size();i++){
            cout<<"< "<<coordenadas[i][0]<<" , "<<coordenadas[i][1]<<" >";
            if(i!=coordenadas.size()-1){
                cout<<" ; ";
            }
            else{
                cout<<" .";
            }
        }
        cout<<endl<<"Los pasos que dio fueron : "<<coordenadas.size()<<" pasos."<<endl;
    }
    else{
        cout<<"Muhas gracias por jugar."<<endl;
    }
}
void imprimirarena2(variable **puntero , variable n , variable m){
    for(int i=0 ;i<n ;i++){
        for (int z=0 ;z<m;z++){
            if(puntero[i][z]==0){cout<<"[ ]"<<"\t";}

            if(puntero[i][z]==1){
                cout<<"[X]"<<"\t";
            }
            if(puntero[i][z]==88){
                cout<<figura<<figura<<"\t";
            }
        }
        cout<<endl<<endl;
    }

}
void verifica_e_imprimir(vector<variable > grupos_de_conteos_exitosos , vector<vector<vector<variable >>> &coordenadas_de_resultados_correctos , variable **arena ,variable filas , variable columnas , vector<vector<variable>>&Elcamino){
    if(grupos_de_conteos_exitosos.size()>0){ //evalua si pudo llegar a la meta , recordemos que el vector conteo maximo almacenara cuando este llegue a la meta ,si no es asi No llego

        variable posicion = halleelmenor(grupos_de_conteos_exitosos);// se buscara los pasos mas cortos cuando llego este a la meta. y se guardara su posicion.
        Elcamino=coordenadas_de_resultados_correctos[posicion];
        vector<variable>posiciones_correctas_X ;//se crea un vector que almacenara todas las posiciones en x que hizo hasta llegar a la meta
        vector<variable>posiciones_correcta_y;// se creara un vector que almacenara todas las posiciones en y que hizo hasta llegar a la meta
        separarvariables(posiciones_correctas_X ,posiciones_correcta_y , coordenadas_de_resultados_correctos , posicion);
        //ahora vamos a partir el vector triple y iremos a su coordenada o posicion donde fue su menor paso.
        //luego separaremos las posiciones x e y y lo guardaremos en posicionescorrectasx y posicionescorrectasy respectivamente.
        llenar_arena_final(arena , posiciones_correctas_X , posiciones_correcta_y , coordenadas_de_resultados_correctos[posicion].size());
        //llenaremos la arena y lo pintaremos con 8 los movimientos que este tuvo.
        imprimirarena2(arena, filas , columnas);
        mostrar_coordenadas_del_camino_mas_corto(Elcamino);
    }

}
bool verifica_y_manda(vector<variable >grupos_de_conteos_exitosos){
    bool retornar;
    variable medida=grupos_de_conteos_exitosos.size();
    if(medida>0){
        cout<<"Muchas gracias por jugar."<<endl;
        retornar= false;
        return retornar;
    }
    else{
        retornar=true;
        return retornar;
    }
}
bool verificar_si_el_usuario_desea_intentarlo_1_vez_mas(){
    variable diga;
    bool mandar;
    cout<<"No se pudo encontrar caminos con los camino default o caminos prederteminados.\nQuizas con otro algoritmo.\n";
    cout<<"Usted desea intentarlo una vez mas con un algoritmo distinto? \tAlgoritmo_&SP\n"<<endl;
    cout<<"El algoritmo durara un poco de tiempo."<<endl;
    do{
        cout<<"1. Si "<<endl;
        cout<<"2. No "<<endl;
        cin>>diga;
        if(diga<1 || diga>2){
            cout<<"Ponga numero correctos , solo 1 y 2 ."<<endl;
        }
    }while (diga<1 || diga>2);
    if(diga==1){
        mandar= true;
    }
    else{
        mandar= false;
    }
    return mandar;
}
void ultimo_intento(bool &eleccion , variable &posicioninicialx , variable &posicioninicialy , variable &posicionfinalx , variable &posicionfinaly , vector<vector<variable >>coordenadas_vacias , vector<vector<vector<variable >>>&coordenadas_de_resultados_correctos, vector<vector<variable >>caminos , variable  conteo_de_pasos_intentados_por_camino , vector<variable >grupos_de_conteos_exitosos , variable **arena , variable filas , variable columnas , vector<vector<variable>>&elcamino){
    if(eleccion){
        cout<<"Tomara un tiempo , espere porfavor  "<<endl;
        cout<<"Cargandooo........."<<endl;
        Algoritmo_Sp(posicioninicialx , posicioninicialy , posicionfinalx , posicionfinaly , coordenadas_vacias , coordenadas_de_resultados_correctos ,caminos,  conteo_de_pasos_intentados_por_camino , grupos_de_conteos_exitosos );

        verifica_e_imprimir(grupos_de_conteos_exitosos ,coordenadas_de_resultados_correctos ,arena ,filas , columnas , elcamino);
        if(grupos_de_conteos_exitosos.size()<0){
            cout<<"Ups no pudimos encontrar el camino, debe estar obstruido. "<<endl;
            cout<<"Lo siento , no se pudo encontrar ningun camino correcto."<<endl;
        }
    }
    else{

    }
}
void lo_intentamos_o_no(bool verificar ,variable &posicioninicialx , variable &posicioninicialy , variable &posicionfinalx , variable &posicionfinaly , vector<vector<variable >>coordenadas_vacias , vector<vector<vector<variable >>>&coordenadas_de_resultados_correctos, vector<vector<variable >>caminos , variable  conteo_de_pasos_intentados_por_camino , vector<variable >grupos_de_conteos_exitosos , variable **arena , variable filas , variable columnas , vector<vector<variable>>&elcamino){
    if(verificar==true){
        bool eleccion=verificar_si_el_usuario_desea_intentarlo_1_vez_mas();
        ultimo_intento(eleccion , posicioninicialx , posicioninicialy , posicionfinalx , posicionfinaly , coordenadas_vacias , coordenadas_de_resultados_correctos, caminos , conteo_de_pasos_intentados_por_camino , grupos_de_conteos_exitosos , arena , filas , columnas , elcamino );
    }
}




//codigo de crear los movimientos predeterminados.
/*
int pmx , pmy;//pmx:posicion momentania en x ; pmy :posicion momentanea en y
if(pmx=pix && pmy == piy+1){ //indica un movimiento hacia la derehca de la posicion inicial.
}
if(pmx == pix && pmy == piy - 1){//indica un movimiento hacia la izquierda
}
if(pmx==pix+1 && pmy == piy ){ //inidica un movimiento hacia abajo.
}
if(pmx = pix - 1 && pmy == piy){ // inidica un movimiento hacia arriba.
}
 */
#endif //PROYECTOPOOII_CREARARENA_H