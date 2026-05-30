#include <iostream> 

using namespace std; 

// Estructura que define un nodo para la lista simple
struct Nodo {
    int dato;        // Valor entero del nodo
    Nodo *siguiente; // Puntero al siguiente nodo
};

// Clase que gestiona la lista enlazada simple
class ListaSimple {
private:
    Nodo *cabeza; // Puntero al primer elemento de la lista
public:
    ListaSimple() : cabeza(nullptr) {} // Constructor: inicializa la lista vacía

    // Inserta un nodo al inicio de la lista
    void insertarInicio(int valor) {
        Nodo *nuevo = new Nodo;  // Reserva memoria para el nuevo nodo
        nuevo->dato = valor;     // Asigna el valor dado
        nuevo->siguiente = cabeza; // Apunta el nuevo nodo a la antigua cabeza
        cabeza = nuevo;          // Actualiza la cabeza de la lista
    }

    // Imprime todos los elementos de la lista en consola
    void imprimir() {
        Nodo *actual = cabeza; // Puntero auxiliar para recorrer la lista
        while (actual != nullptr) { // Mientras no llegue al final
            cout << actual->dato << " -> "; // Muestra el valor actual
            actual = actual->siguiente;    // Avanza al siguiente nodo
        }
        cout << "NULL" << endl; // Fin de la lista
    }

    // Elimina el primer nodo que coincida con el valor dado
    void eliminar(int valor) {
        Nodo *actual = cabeza;     // Puntero para buscar el nodo
        Nodo *anterior = nullptr;  // Puntero para mantener el rastro del nodo previo

        // Busca el nodo con el valor o el final de la lista
        while (actual != nullptr && actual->dato != valor) {
            anterior = actual;          // El actual se convierte en el anterior
            actual = actual->siguiente; // Avanza al siguiente nodo
        }

        if (actual == nullptr) { // Caso 1: No se encontró el valor
            cout << "Valor no encontrado." << endl;
            return;
        }

        if (anterior == nullptr) { // Caso 2: El nodo a eliminar es la cabeza
            cabeza = actual->siguiente; // Mueve la cabeza al segundo nodo
        } else { // Caso 3: El nodo está en medio o al final
            anterior->siguiente = actual->siguiente; // Desvía el puntero saltándose el actual
        }

        delete actual; // Libera la memoria del nodo eliminado
        cout << "Valor eliminado: " << valor << endl;
    }

    // Destructor para liberar toda la memoria dinámica al terminar
    ~ListaSimple() {
        Nodo *actual = cabeza;
        while (actual != nullptr) {
            Nodo *siguiente = actual->siguiente; // Guarda el siguiente antes de borrar
            delete actual;                      // Borra el nodo actual
            actual = siguiente;                 // Avanza
        }
    }
};

int main() {
    ListaSimple lista; // Instancia de la lista simple

    // Inserciones de prueba
    lista.insertarInicio(5);
    lista.insertarInicio(10);
    lista.insertarInicio(15);

    cout << "Lista despues de inserciones:" << endl;
    lista.imprimir(); // Muestra la lista inicial

    lista.eliminar(10); // Elimina el valor 10
    cout << "Lista despues de eliminar 10:" << endl;
    lista.imprimir(); // Muestra la lista final

    return 0; // Fin del programa
}
