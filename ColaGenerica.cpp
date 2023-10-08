#include<iostream>

template<class T>
class node{

    private:
        T data;
        node<T>* sig;
    public:
        node();
        node(const T&);

        void setData(const T&);
        void setSiguiente(node<T>*);

        T getData();
        node<T>* getSiguiente();

};

template<class T >
node<T>::node(){sig == nullptr;}


template<class T>
node<T>::node(const T& dat){
    data  = dat;
    sig  = nullptr;
}


template<class T>
void node<T>::setData(const T& dat){
    data = dat;
}

template<class T>
void node<T>::setSiguiente(node<T>* pos){
    sig = pos;
}

template<class T>
T node<T>::getData(){
    return data;
}

template<class T>
node<T>* node<T>::getSiguiente(){
    return sig;
}



template<class T>
class ColaGenerica{
    private:
        node<T>* frente;
        node<T>* final;

    public:
        ColaGenerica(){
            frente =nullptr;
            final =nullptr;
        }
        void insertar(T );
        T quitar();
        void borrarCola();
        T frenteCola();
        bool colaVacia();
        ~ColaGenerica(){borrarCola();};

};


template<class T>
void ColaGenerica<T>::insertar(T dat){
    node<T>* nuevo(new node<T>(dat));
    if(colaVacia()){
        frente = nuevo;
    }else{
        final->setSiguiente(nuevo);
    }
    final = nuevo;
}



template<class T>
T ColaGenerica<T>::quitar(){
    if(colaVacia()){
        std::cout<<"Cola vacia, no se ppuede extraer";
    }else{
        T aux = frente->getData();
        node<T>* a = frente;
        frente = frente->getSiguiente();
        delete a;
        return aux;
    }
}


template<class T>
T ColaGenerica<T>::frenteCola(){
    if(colaVacia()){
        std::cout<<"Cola vacia... nada en el frente"<<std::endl;
    }else{
        return frente->getData();
    }
}

template<class T>
void ColaGenerica<T>::borrarCola(){
    while(frente != nullptr){
        node<T>* a = frente;
        frente = frente ->getSiguiente();
        delete a;
    }
    final = nullptr;
}


template<class T>
bool ColaGenerica<T>::colaVacia(){
    return frente == nullptr;
}
