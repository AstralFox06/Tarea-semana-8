#include <iostream> 

using namespace std;

// Estructura que define un nodo de la lista doblemente enlazada
struct NodoDoble {
    int dato;             // Valor entero almacenado en el nodo
    NodoDoble *siguiente; // Puntero al siguiente elemento de la lista
    NodoDoble *anterior;  // Puntero al elemento anterior de la lista
};

// Clase que gestiona la estructura y operaciones de la lista doble
class ListaDoble {
private:
    NodoDoble *cabeza; // Puntero al primer nodo de la lista
public:
    ListaDoble() : cabeza(nullptr) {} // Constructor: inicializa la lista vacía

    // Inserta un nuevo nodo al principio de la lista
    void insertarInicio(int valor) {
        NodoDoble *nuevo = new NodoDoble; // Reserva memoria para el nuevo nodo
        nuevo->dato = valor;             // Asigna el valor al nuevo nodo
        nuevo->siguiente = cabeza;       // El siguiente del nuevo nodo será la antigua cabeza
        nuevo->anterior = nullptr;       // Como va al inicio, no tiene nodo anterior

        if (cabeza != nullptr) {         // Si la lista no estaba vacía
            cabeza->anterior = nuevo;    // Enlaza la antigua cabeza con el nuevo nodo
        }
        cabeza = nuevo;                  // Actualiza la cabeza para que apunte al nuevo nodo
    }

    // Imprime la lista desde el primer nodo hasta el final
    void imprimirAdelante() {
        NodoDoble *actual = cabeza; // Puntero auxiliar para recorrer la lista desde el inicio
        cout << "Lista (adelante): ";
        while (actual != nullptr) { // Recorre la lista mientras no llegue al final
            cout << actual->dato << " <-> "; // Imprime el valor actual
            actual = actual->siguiente;      // Avanza al siguiente nodo
        }
        cout << "NULL" << endl; // Indica el fin de la lista
    }

    // Imprime la lista en orden inverso (de fin a principio)
    void imprimirAtras() {
        NodoDoble *actual = cabeza; // Puntero auxiliar para posicionarse
        if (actual == nullptr) return; // Si la lista está vacía, termina la función
        
        // Llega al último nodo de la lista
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente; // Avanza hasta el último elemento disponible
        }
        
        cout << "Lista (atras): ";
        while (actual != nullptr) { // Recorre la lista hacia atrás
            cout << actual->dato << " <-> "; // Imprime el valor actual
            actual = actual->anterior;       // Retrocede al nodo anterior
        }
        cout << "NULL" << endl; // Indica el inicio de la lista (nulo al regresar)
    }

    // Elimina el primer nodo que contenga el valor especificado
    void eliminar(int valor) {
        NodoDoble *actual = cabeza; // Puntero auxiliar para buscar el elemento
        
        // Busca el nodo con el valor deseado o el fin de la lista
        while (actual != nullptr && actual->dato != valor) {
            actual = actual->siguiente; // Avanza al siguiente elemento
        }

        if (actual == nullptr) { // Caso 1: El valor no fue encontrado
            cout << "Valor no encontrado." << endl;
            return; // Termina la función
        }

        if (actual->anterior != nullptr) { // Caso 2: El nodo a eliminar no es el primero
            actual->anterior->siguiente = actual->siguiente; // El anterior apunta al siguiente de actual
        } else { // Caso 3: El nodo a eliminar es la cabeza
            cabeza = actual->siguiente; // Mueve la cabeza al segundo nodo
        }

        if (actual->siguiente != nullptr) { // Si no es el último nodo de la lista
            actual->siguiente->anterior = actual->anterior; // El siguiente apunta hacia el anterior de actual
        }

        delete actual; // Libera la memoria del nodo eliminado
        cout << "Valor eliminado: " << valor << endl;
    }

    // Destructor para liberar toda la memoria dinámica de la lista al terminar
    ~ListaDoble() {
        NodoDoble *actual = cabeza; // Puntero auxiliar desde el inicio
        while (actual != nullptr) { // Mientras queden nodos en la lista
            NodoDoble *siguiente = actual->siguiente; // Resguarda la dirección del siguiente nodo
            delete actual; // Borra el nodo actual de la memoria
            actual = siguiente; // Pasa al siguiente nodo resguardado
        }
    }
};

int main() {
    ListaDoble lista; // Declara una instancia de la lista doblemente enlazada

    // Inserción de valores de prueba
    lista.insertarInicio(20); // Inserta 20 (Lista: 20 -> NULL)
    lista.insertarInicio(30); // Inserta 30 (Lista: 30 -> 20 -> NULL)
    lista.insertarInicio(40); // Inserta 40 (Lista: 40 -> 30 -> 20 -> NULL)

    cout << "Lista doblemente encadenada:" << endl;
    lista.imprimirAdelante(); // Muestra el recorrido de inicio a fin
    lista.imprimirAtras();    // Muestra el recorrido de fin a inicio

    lista.eliminar(30); // Elimina el nodo con el valor 30
    cout << "Despues de eliminar 30:" << endl;
    lista.imprimirAdelante(); // Muestra la lista modificada hacia adelante
    lista.imprimirAtras();    // Muestra la lista modificada hacia atrás

    return 0; // Fin del programa con éxito
}
