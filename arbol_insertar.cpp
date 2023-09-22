#include <iostream>

using namespace std;

struct Nodo{
	
	int num;
	Nodo *der;
	Nodo *izq;
	
};

typedef struct Nodo *arbol;

void insertNodoRaiz (arbol& raiz, int valor){
	
	arbol x = new struct Nodo;
	x -> num = valor;
	x -> der = NULL;
	x -> izq = NULL;
	
	raiz = x;
	
}

void insertNodo(arbol& raiz, int valor) {
	
    if (raiz == NULL) {
    	
        insertNodoRaiz(raiz, valor);
        
    } else {
    	
        if (valor < raiz->num) {
        	
            insertNodo(raiz->izq, valor);
            
        } else if (valor > raiz->num) {
        	
            insertNodo(raiz->der, valor);
            
        } else {
        	
            cout << "El valor ya ha sido ingresado en el arbol previamente." << endl;
            
        }
    }
}

bool buscarInorden(arbol raiz, int valor) {
	
    if (raiz == NULL) { 
        
        return false;
        
    }

    if (buscarInorden(raiz->izq, valor)) {
    	
        return true;
    }

    if (raiz->num == valor) {
    	
        cout << "Se ha encontrado el numero " << valor << " en el arbol" << endl;
        return true;
        
    }

    if (buscarInorden(raiz->der, valor)) {
    	
        return true;
    }

    return false;
}
       

void mostrarArbolInorden (arbol& raiz){
	
	
	if (raiz == NULL){
           
            return;
            
        }
        
    mostrarArbolInorden (raiz -> izq);
    
    
    cout << " -- "<< raiz -> num << " -- " ;
    
    mostrarArbolInorden (raiz -> der);
}        


void eliminarNodo (arbol& raiz, int valor){
	
	if (raiz == NULL){
		
		return;
	}
	
	if (valor < raiz -> num){
		
		eliminarNodo (raiz -> izq , valor);
	}
	
	else if (valor > raiz -> num){
		
		eliminarNodo(raiz -> der , valor);
	}
	
	else{
		
		if(raiz -> izq == NULL){
			
			arbol aux = raiz;
			raiz = raiz -> der;
			delete aux;
		}
		
		else if (raiz -> der == NULL){
			
			arbol aux = raiz;
			raiz = raiz -> izq;
			delete aux;
		}
		
		else {
		
			arbol aux = raiz -> der;
			while (aux -> izq == NULL){
			
				aux = aux -> izq;
			}
		
			raiz -> num = aux -> num;
		
			eliminarNodo(raiz -> der, aux -> num);
		}
	}
	
}

void memoria (arbol& raiz){
	
	if(raiz != NULL){
		
		memoria(raiz -> izq);
		memoria(raiz -> der);
		delete raiz;
		raiz = NULL;
	}
}


int main (){
	
	arbol raiz = NULL;
	int valor;
	int opc;
	int form =0;
	
	
	do{
		
		cout << endl << "------ Menu de opciones -------" << endl << endl;
		cout << "1. Insertar nodo" << endl;
		cout << "2. Buscar nodo" <<endl;
		cout << "3. Mostrar nodos" <<endl;
		cout << "4. Eliminar nodo" <<endl;
		cout << "0. Salir del programa" <<endl <<endl;
		cout << endl << "Ingrese la opcion: ";
		cin >> opc;
		
		switch (opc){
			
			case 1:
				
				cout << endl << "Ingrese el numero a insertar (digite 0 para salir): ";
				cin >> valor;
				cout <<endl;
				
				if (valor != 0) {
                    	
                        insertNodo(raiz, valor);
                    }

                    cout << endl << endl;
                    
                    
                    
				break;
				
			case 2:
                 
                 cout << endl << "Con que metodo desea encontrar el nodo (digite 0 para salir)" <<endl<<endl ;
                 cout << "2. Inorden" <<endl;
                 cin >> form;
                 cout << endl << "Ingrese el numero a buscar: ";
                 cin >> valor;
                 
                switch (form){



			 		case 2:
                        
						if (valor != 0) {
						
                         	bool encontrado = buscarInorden(raiz, valor);
                            
                          	if (!encontrado) {
                            	
                          	    cout << endl << "El numero " << valor << " no se encuentra en el arbol." << endl;
                                
                          	}
                      	}
                        
                       	cout << endl << endl;
						              
					break;  
                    
						
						
					}
					break;
				
			case 3:
				
				cout << endl << "Con que metodo desea mostrar el nodo (digite 0 para salir)" <<endl<< endl ;
                cout << "2. Inorden" <<endl;
                cout << "0. Salir " << endl;
                cin >> form;
                cout << endl;
				              
                switch (form){
            		
                	case 2:
						
						if (raiz != NULL){
							
							cout << "Mostrando los datos en Inorden:" << endl << endl;
							mostrarArbolInorden (raiz);
							cout << endl;
							
						} 
						else {
							
							cout << "El arbol esta vacio" << endl;
						
						}
						
						break;
						
					case 0:
						
						cout << endl << "Fin del programa" <<endl;
						
						break;
						
					default:
						
						cout << "Opcion invalida, intente nuevamente" <<endl;
						
						break;				
				}
				break;
			
			case 4:
				
				cout << endl << "Ingrese el numero a eliminar: ";
				cin >> valor;
				eliminarNodo (raiz, valor);
				
				cout  << "Se ha eliminado el numero " << valor << " del arbol." <<endl;
				
				break;
			

			case 0:
				
				cout << endl << "Fin del programa" <<endl;
				break;
			
			default:
			
				cout << "Opcion invalida, intente nuevamente" <<endl;
				break;		
		}
		
		
		
	}while (opc !=0);
	
	memoria(raiz);
	
	return 0;
}




