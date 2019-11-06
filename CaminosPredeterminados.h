//
// Created by SEBASTIAN on 6/11/2019.
//

#ifndef PROYECTOPOOII_CAMINOSPREDETERMINADOS_H
#define PROYECTOPOOII_CAMINOSPREDETERMINADOS_H

#include <iostream>
#include <vector>
using namespace std;
typedef long int variable;
void Caminos_Predeterminados(variable pix , variable piy , variable pfx , variable pfy, vector<vector<variable >>posiciones_libres , vector<vector<vector<variable>>>&camino_exitoso , vector<vector<variable>>caminos_intentados , variable conteo ,vector<variable>&conteomax , variable xx , variable yy){
    variable c;
    vector<vector<variable >> copia_posiciones_libres=posiciones_libres ;
    for(int i=0 ; i<copia_posiciones_libres.size() ; i++){ //si las posiciones iniciales se encuentran en el vector seran eliminadas.
        if (copia_posiciones_libres[i][0]==pix && copia_posiciones_libres[i][1]==piy){
            c=i;
        }
    }
    copia_posiciones_libres.erase(begin(copia_posiciones_libres)+c); //se elimina la posicion en la que te encuentras
    variable medida_del_vector = copia_posiciones_libres.size(); //asemejamos una variable para el tamaño del vector de posiciones libres .
    vector<vector<variable >> copia_caminos_intentados = caminos_intentados; //creamos un vector que va a guardar las posiciones dadas.

    if(pix==pfx && piy==pfy){ //si la posicion inicial es igual a la final
    camino_exitoso.push_back(caminos_intentados); //camino exitoso guardara los caminos ya establecidos , sera guardado por referencia.
    conteomax.push_back(conteo);// se agregara al conteomax los pasos que este dio.
    }
    else{
        for(int i=0 ; i<medida_del_vector ; i++){
            variable pmx=copia_posiciones_libres[i][0];//el parametro de x se guarda en una posicion temporal
            variable pmy=copia_posiciones_libres[i][1];//el parametro de y se guarda en una posicion temporal
            variable x=pix , y=piy;
            if(xx<pfx && yy<pfy){
                if(pmx==x+1 && pmy==y){
                    vector<variable>posiciones_actuales={x+1,y};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x+1 , y , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
                if(pmx==x && pmy==y+1 ){
                    vector<variable>posiciones_actuales={x,y+1};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x , y+1 , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
            }
            if(xx>pfx && yy>pfy){
                if(pmx==x-1 && pmy==y){
                    vector<variable>posiciones_actuales={x-1,y};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x-1 , y , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
                if(pmx==x && pmy==y-1 ){
                    vector<variable>posiciones_actuales={x,y-1};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x , y-1 , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
            }
            if(xx<pfx && yy>pfy){
                if(pmx==x+1 && pmy==y){
                    vector<variable>posiciones_actuales={x+1,y};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x+1 , y , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
                if(pmx==x && pmy==y-1 ){
                    vector<variable>posiciones_actuales={x,y-1};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x , y-1 , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
            }
            if(xx>pfx && yy<pfy){
                if(pmx==x-1 && pmy==y){
                    vector<variable>posiciones_actuales={x-1,y};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x-1 , y , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
                if(pmx==x && pmy==y+1 ){
                    vector<variable>posiciones_actuales={x,y+1};
                    vector<vector<variable>> posiciones_intentadas=caminos_intentados;
                    posiciones_intentadas.push_back(posiciones_actuales);
                    variable conteo_2=conteo;
                    conteo_2++;
                    Caminos_Predeterminados(x , y+1 , pfx ,pfy , copia_posiciones_libres , camino_exitoso , posiciones_intentadas , conteo_2 , conteomax , xx , yy);
                }
            }
        }
    }

}
#endif //PROYECTOPOOII_CAMINOSPREDETERMINADOS_H
