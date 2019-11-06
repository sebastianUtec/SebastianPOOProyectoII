#include <iostream>
#include <fstream>
#include "funciones.h"
#include <vector>
#include "CaminosPredeterminados.h"

using namespace std;

const string fichero = "../laber1.txt";

typedef long   int variable ;

int main() {
    ifstream fi;
    fi.open(fichero);
    if(fi.is_open()){

        variable filas, columnas , cantidad_de_obstaculos; //Se define variables del tipo "variable" que seran gurdadas como columnas , filas , y la cantidad de obstaculos

        fi>>filas>>columnas>>cantidad_de_obstaculos; //Se almaceno el numero de filas , columnas y el numero de obstaculos

        variable *x=nullptr , *y=nullptr ; //inicializamos dos punteros , uno que almacenara todas las posiciones en x  y la otra en y inicializados de manera correcta
        x=new variable[cantidad_de_obstaculos]; //creamos un puntero que guarde la posicion en x , este puntero ocupara un espacio dependiendo de cuantos obstaculos tendra la arena.
        y=new variable[cantidad_de_obstaculos]; //creamos un puntero que guarde la posicion en y , este puntero ocupara un espacio dependiendo de cuantos obstaculos tendra la arena.

        for(int i=0 ; i<cantidad_de_obstaculos ; i++){

            fi>>x[i];//guardamos en un puntero todas las posiciones en x.

            fi>>y[i];//guardamos en otro puntero todas las posiciones en y.

        }


        variable **arena= creararena(filas , columnas); //creamos la arena de manera dinamica.

        llenar_la_arena_con_numeros_0(arena , filas , columnas);//llenamos la arena con numeros 0.(Recordemos que sera enviado indirectamente por referencia , porque es un puntero).

        llenar_la_arena_completa(x , y , arena , cantidad_de_obstaculos); //llenamos la arena con obstaculos

        pedir_imprimir(arena , filas , columnas); //imprimimos la arena con los obstaculos.


        variable total_de_espacios_vacios=(filas*columnas)-cantidad_de_obstaculos; //declaramos cuantos espacios en blanco o libres hay en la matriz (numero total - los espacios ya ocpuados)

        vector<vector<variable>>coordenadas_vacias ; //coordenadas vecias es un vector de vectores que tendra como unico parametro , las coordenadas de las posiciones vacias.
        //vector , coordenadas_vacias={ {x1,y2},{x2,y2},{x3,y3}}
        guardar(coordenadas_vacias , arena , filas , columnas);
        //guarda_posiciones_x_y(coordenadas_vacias , total_de_espacios_vacios , vacios);//guardaremos las posiciones x e y en coordenadas vacias.

        muestra_posiciones_libre(total_de_espacios_vacios , coordenadas_vacias);//Elijes si quieres que te muestren la sposiciones libres , si o no.


        variable posicioninicialx , posicioninicialy , posicionfinalx , posicionfinaly ; //creamos posiciones iniciales en x , y , finaes en x y en y .

        verifica_posiciones_iniciales_y_finales_correctas(posicioninicialx, posicioninicialy , posicionfinalx , posicionfinaly ,x , y, cantidad_de_obstaculos );//verifica si las posiciones iniciales y finales son correctas

        vector<vector<vector<variable >>> coordenadas_de_resultados_correctos; //Un vector triple que almacenara los resultados correctos.
        vector<vector<variable >> caminos;//Un vector recolector que almacenara los pasos que da .
        variable conteo_de_pasos_intentados_por_camino = 0; //contador de pasos , sera pasado con referencia
        vector<variable> grupos_de_conteos_exitosos; // Un vector que tendra como mision almacenar los pasosque dio hasta el final.

        vector<vector<variable>> El_camino_mas_Corto;

        //intentamos con los movimientos por default dependiendo de las posiciones.
        Caminos_Predeterminados( posicioninicialx , posicioninicialy , posicionfinalx , posicionfinaly , coordenadas_vacias ,coordenadas_de_resultados_correctos,caminos, conteo_de_pasos_intentados_por_camino ,grupos_de_conteos_exitosos , posicioninicialx , posicioninicialy);


        verifica_e_imprimir(grupos_de_conteos_exitosos , coordenadas_de_resultados_correctos , arena ,filas , columnas ,El_camino_mas_Corto);
        //verifica si el camino corto funciono , si funciono todo correcto ,sino lo informara.


        bool verificar=verifica_y_manda(grupos_de_conteos_exitosos);
        //verifica si el camino mas cort funciono , si  no funciono , sera informado a verifcar , como true o false


        lo_intentamos_o_no( verificar , posicioninicialx , posicioninicialy , posicionfinalx , posicionfinaly ,coordenadas_vacias , coordenadas_de_resultados_correctos,caminos , conteo_de_pasos_intentados_por_camino ,grupos_de_conteos_exitosos , arena ,filas ,columnas ,El_camino_mas_Corto );
        //si verificar le envia true , intentara otro algoritmo , si no funciona con el algoritmo no hay nada que hacer .
        //antes de intentar el algoritmo se le reguntara.

        delete x; //eliminamos el puntero x : que guardo las coordenadas "x" de los obstaculos.
        delete y;//eliminamos el puntero y : que guardo las coordenadas "y: de los obstaculos.

        //luego elimiminamos el espacio que ocupo la arena , debido a que es dinamico.
        for (variable i=0 ; i<filas ;i++){
            //eliminamos cada fila de la arena
            delete[]arena[i];
        }

        delete[]arena;

        arena = nullptr;

        fi.close();
    }

    else cerr<<"Error de lectura\n";

    return 0;
}