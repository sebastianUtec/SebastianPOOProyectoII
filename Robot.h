//
// Created by SEBASTIAN on 31/10/2019.
//

#ifndef PROYECTOPOOII_ROBOT_H
#define PROYECTOPOOII_ROBOT_H

#include <iostream>
using namespace std;
typedef string palabra;


class Robot: public objeto {
private:
    palabra Nombre_R;
    int numero_vidas;
    int intensidad_de_Poder;
    palabra material;
public:
    Robot(){};
    void set_Nombre_R(palabra Nombre_R){this->Nombre_R=Nombre_R;
    void danio();
    void ataque();

};


#endif //PROYECTOPOOII_ROBOT_H
