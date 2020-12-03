#include <cstdlib>
#include <iostream>

using namespace std;

struct Paquetes;
template <typename Data>
struct NodoC;
template <typename Data>
struct Cola;
struct NodoLista;
struct ListaCircular;
struct Galleta;
struct Repartidor;
struct Mixer;


template <typename Data>
struct NodoC{
    Data data;
    NodoC * next;

    NodoC(){          
	}
	
    NodoC(Data d){
        data = d;
        next = NULL;
                
	}

    NodoC(Data _data, NodoC<Data> * _next){
        data = _data;
        next = _next;
    }

	void print(){
        cout << "Dato: " << data << endl;
	}


};

template <typename Data>
struct Cola{
    NodoC<Data> * first;
    
    Cola(){
        first = NULL;
    }
    
    void push (Data dato){
        if (isEmpty()){
            first = new NodoC<Data>(dato);
        }
        else{
            NodoC<Data>* tmp = first;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }

            NodoC<Data>* _new = new NodoC<Data>(dato);
            tmp->next = _new;
        }
    }

    NodoC<Data> * pull(){
        if (isEmpty()){
             return NULL;
        }
        else{

            NodoC<Data>* _del = first;
            first = first->next;
            _del->next = NULL;
            return _del;
        }
    }

    bool isEmpty(){
        if (first == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void print(){

        cout << "First" << endl;
        NodoC<Data>* tmp = first;

        while (tmp != NULL){
            tmp->print();
            tmp = tmp->next;
        }

        cout << "Final" << endl;
    }

    NodoC<Data>* vFirst(){
          return first;
    }
};

struct Paquetes{
	string nombre;
	int cantGalle;

	Paquetes(string nombre, int cantGalle){
		this->nombre = nombre;
		this->cantGalle = cantGalle;
	}
	
	void impPaquete(){
		cout << "Tipo: " << nombre << " cantidad ->" << cantGalle;
	}
};

struct NodoLista{
	Paquetes * paquete;
	NodoLista * siguiente;
	NodoLista * anterior;
	
	NodoLista(Paquetes * tp)
	{
		paquete = tp;
		siguiente = anterior = NULL;
	}
	
	NodoLista()
	{
		paquete = NULL;
		siguiente = anterior = NULL;
	}
	
	void imprimir ()
	{
		paquete->impPaquete();
		cout << "\n";
	}
	
};

struct ListaCircular{
	NodoLista * primerNodo;
	ListaCircular(){ 
		primerNodo = NULL;
	}	
	// INSERTAR AL INICIO
	void insertarAUX(Paquetes * tipo)
	{
		if (primerNodo == NULL){
			primerNodo = new NodoLista(tipo);
			primerNodo->siguiente= primerNodo;
			primerNodo->anterior = primerNodo;
		}
		else{
			NodoLista * nuevo = new NodoLista (tipo);
			nuevo->siguiente = primerNodo;
			nuevo->anterior = primerNodo->anterior;
			primerNodo->anterior->siguiente = nuevo;
			primerNodo->anterior = nuevo;
		}
	}
	
	void insertar(string nombre, int cantidad){
		if(nombre == "Paquetico"){
			for(int i = 0;i<cantidad;i++){
                insertarAUX( new Paquetes(nombre,4) );
			}
		}
		if(nombre == "Tubo"){
			for(int i = 0;i<cantidad;i++){
				insertarAUX(new Paquetes(nombre,16));
			}
		}
		if(nombre == "Paquete"){
			for(int i = 0;i<cantidad;i++){
				insertarAUX(new Paquetes(nombre,40));
			}
		}		
	}
	
	int totalGalletas(){
		int total = 0 ;
		if (primerNodo != NULL){
			NodoLista * tmp = primerNodo;
			do{
				total += tmp->paquete->cantGalle;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			cout << endl;
			}
		return total;
	}
	// IMPRIMIR LISTA
	void imprimir()
	{
		if (primerNodo != NULL){
			NodoLista * tmp = primerNodo;
			do{
				tmp->imprimir();
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			cout << endl;
		}
	}
	
	// IMPRIMIR LISTA
    NodoLista * buscar(string nombre)
	{
		if (primerNodo != NULL){
			
			NodoLista * tmp = primerNodo;
			do{
                if (tmp->paquete->nombre == nombre)
					return tmp;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			
		}
		return NULL;
	}

    NodoLista * eliminar(string nombre){
        NodoLista * eliminado = buscar(nombre);
		
		if (eliminado != NULL){ // s� lo encontr�
			if (primerNodo->siguiente == primerNodo) // solo un elemento
				primerNodo = eliminado->siguiente = eliminado->anterior = NULL;
			else{
				if (eliminado == primerNodo)
					primerNodo = primerNodo->siguiente;
				
				NodoLista * tmp = eliminado->anterior;
				tmp->siguiente = tmp->siguiente->siguiente;
				tmp->siguiente->anterior = tmp;
				eliminado->siguiente = eliminado->anterior = NULL;
			} 
		}
		return eliminado;
	}
};

struct Receta{
	int masa;
	int choco;
	Receta(int masa, int choco){
		this->masa = masa;
		this->choco = choco;
	}
};

struct planificador{
	ListaCircular * lc;

    planificador(int tito, int te, int tubo){
		lc = new ListaCircular();
        lc->insertar("Paquetico",tito);
        lc->insertar("Paquete",te);
        lc->insertar("Tubo",tubo);
	}

	void insertarMas(){
		//Aqui debe de tener algo en pantalla que me pida el tipo y la canitidad a sumar;
		lc->insertar("Paquete",4);
	}

    int totalGalle(){
        return lc->totalGalletas();
    }
};

//El carrito debe de ser configurable en sus cantidades y este debe de ser un hilo
struct Mixer{
    Receta  * receta;
    Repartidor * carro;
	int min;
	int max;
    int gProcesar;
    Mixer(int gProcesar, int min, int max,Receta * receta, Repartidor * carro){
		this->min = min;
		this->max = max;
        this->gProcesar = gProcesar;

        this->receta = receta;
        this->carro = carro;
	}

    void procesar(){

    }
};

struct Repartidor{
    int gramos;
    Repartidor(int gramos){
        this->gramos = gramos;
    }
    int entrega(int cantidad){
        if (gramos <= cantidad){
            cantidad -= cantidad-gramos;
        }
        return cantidad;

    }
};
struct Ensambladora{
	
};
