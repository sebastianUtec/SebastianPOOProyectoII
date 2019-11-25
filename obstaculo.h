#ifndef UNTITLED11_OBSTACULO_H
#define UNTITLED11_OBSTACULO_H


class obstaculo:public objeto {
private:
  int danio;
  palabra tipo_de_danio;
public:
  obstaculo(){};
  void restarvidas();
};


#endif //UNTITLED11_OBSTACULO_H
