//
// Created by SEBASTIAN on 5/11/2019.
//

#ifndef PRACTICAR_ALGORITMO_SP_H
#define PRACTICAR_ALGORITMO_SP_H
#include <iostream>
#include <vector>
typedef long int variable;
using namespace std;
variable verifica(vector<vector<variable>>&vectorprobar, variable x , variable y){
    variable medida=vectorprobar.size();
    variable a=0;
    variable posicion;
    for (int i=0 ; i<medida; i++){
        if(x==vectorprobar[i][0] && y==vectorprobar[i][1]){
            a=1;
        }
    }
    return a;
}
void borrar(vector<vector<variable>>&vv , variable x , variable  y ){
    variable medida=vv.size();
    variable a=0;
    variable posicion;
    for (int i=0 ; i<medida; i++){
        if(x==vv[i][0] && y==vv[i][1]){
            a=1;
            posicion=i;
        }
    }
    if(a==1){
        vv.erase(begin(vv)+posicion);
    }
}
void Algoritmo_Sp(variable pix , variable piy , variable pfx , variable pfy, vector<vector<variable >>posiciones_libres , vector<vector<vector<variable>>>&camino_exitoso , vector<vector<variable>>caminos_intentados , variable conteo ,vector<variable>&conteomax ){
    //Algoritmo &SFPM&
    variable medida_del_vector = posiciones_libres.size(); //asemejamos una variable para el tamaño del vector de posiciones libres .
    if(pix==pfx && piy==pfy){ //si la posicion inicial es igual a la final
        camino_exitoso.push_back(caminos_intentados); //camino exitoso guardara los caminos ya establecidos , sera guardado por referencia.
        conteomax.push_back(conteo);// se agregara al conteomax los pasos que este dio.
    }
    else{
        variable x=pix , y=piy , ab , ar , iz , de ;
        ab=verifica(posiciones_libres, x+1 , y);//mov abajo
        if(ab==1){

            variable  conteo_2 = conteo;
            conteo_2++;
            vector<variable>temp={x+1 , y};
            vector<vector<variable >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<variable>>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x+1 , y, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        ar=verifica(posiciones_libres , x-1 , y);//mov arriba
        if(ar==1){
            variable  conteo_2 = conteo;
            conteo_2++;
            vector<variable>temp={x-1 , y};
            vector<vector<variable >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<variable>>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x-1 , y, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        iz=verifica(posiciones_libres , x , y-1 );//mov izquierda
        if(iz==1){
            variable  conteo_2 = conteo;
            conteo_2++;
            vector<variable>temp={x , y-1};
            vector<vector<variable >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<variable>>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x , y-1, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        de=verifica(posiciones_libres , x , y+1);//mov derecha
        if(de==1) {
            variable  conteo_2 = conteo;
            conteo_2++;
            vector<variable>temp={x , y+1};
            vector<vector<variable >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<variable>>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x , y+1, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
    }
}

#endif //PRACTICAR_ALGORITMO_SP_H
