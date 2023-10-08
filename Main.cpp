#include"ColaGenerica.cpp"
#include<iostream>
#include<fstream>
#include<time.h>


const int N = 99;
#define randomize (srand(time(NULL)))
#define random(num) (rand()%(num))



void Opcion1(ColaGenerica<int>&);
void Opcion2(ColaGenerica<int>&);
void GuardarInformacion(ColaGenerica<int>&);


template <class T>
void mostrarCola(ColaGenerica<T>& q);




int main(){
    int opc;
    ColaGenerica<int> myCola;
    do
    {
        std::cout<<"\t === MENU === \n\n";
        std::cout<<"[1] - Generar y mostar numeros de la suerte "<<std::endl;
        std::cout<<"[2] - Cargar archivo2, generar y mostrar nuemros de la suerte "<<std::endl;
        std::cout<<"[3] - Salir"<<std::endl;
        std::cout<<"Seleccione una opcion: "<<std::endl;
        std::cin>>opc;
        
        switch (opc){
        case 1:
            Opcion1(myCola);
            break;
        case 2: 
            Opcion2(myCola);
            break;
        case 3: 
            std::cout<<"Saliendo del programa ..."<<std::endl;
            break;
            
        default:
            break;
        }



    } while (opc != 3);
    

    

}


void Opcion1(ColaGenerica<int>& q){
    int n, n1, n2, i;
    

    randomize;
    n = 11 + random(N);
    for(int i = 1; i <= n; i++)
    {
        q.insertar(random(N * 3));
    }

    n1 = 1 + random(11);
    while(n1 <= n)
    {
        int nt;
        n2 = 0;
        for(i = 1; i <= n; i++)
        {
            nt = q.quitar();
            if(i % n1 == 1)
            {
                std::cout<<"\n Se quita "<< nt <<std::endl;
            }else{
                q.insertar(nt);
                n2++;
            }
        }
        n = n2;
        n1 = 1 + random(11);
    }
    std::cout<<"\n\t los numeros de la suerte: "<<std::endl;
    ColaGenerica<int> cola = q;
    mostrarCola(q);
    GuardarInformacion(cola);

}


void Opcion2(ColaGenerica<int>&q){ 
    std::ifstream archivo2NumEntrada;
    archivo2NumEntrada.open("numeros_suerte2.txt", std::ios::in);
  

    int numeroLeido;
    while (archivo2NumEntrada >> numeroLeido) {
        q.insertar(numeroLeido);
    }
    archivo2NumEntrada.close();

    int n = 11 + std::rand() % N;

    int n1 = 1 + std::rand() % 11;
    while (n1 <= n) {
        int n2 = 0;
        for (int i = 1; i <= n; i++) {
            int nt = q.quitar();
            if (i % n1 == 1) {
                std::cout << "\n Se quita " << nt << std::endl;
            } else {
                q.insertar(nt);
                n2++;
            }
        }
        n = n2;
        n1 = 1 + std::rand() % 11;
    }

    
    std::cout << "Los numeros de la suerte: " << std::endl;
    mostrarCola(q);


}



template <class T>
void mostrarCola(ColaGenerica<T>& q)
{
    while(! q.colaVacia())
    {
        int v;
        v = q.quitar();
        std::cout<< v << " "<<std::endl;
    }
    std::cout << std::endl;
}

void GuardarInformacion(ColaGenerica<int>&q){
    std::ofstream archivo1NumSalida;
    archivo1NumSalida.open("numeros_suerte1.txt", std::ios::out);

    while (!q.colaVacia()){
        int v;
        v = q.quitar();
        archivo1NumSalida<< v <<" "<<std::endl;
    }
    archivo1NumSalida<<std::endl;
    

}
