
#include "list.h"
#include "time.h"

using namespace std;

// Constructor por defecto
template<typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        m_head ->previous = new_node;
        new_node->next = m_head;

        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;

        }
        temp->next = new_node;
        new_node->previous = temp;
    }
    m_num_nodes++;
}

template<typename T>
void List<T>::add_in(T _data, int position) {
    Node<T> *_node = new Node<T> (_data);
    Node<T> *temp = m_head;
    if (!m_head) {
            m_head = _node;
//        this->_node = new Node<T>(_data, NULL, NULL);
    }
    else if (position < 1 || position > m_num_nodes) {
        cout << "Fuera de rango" << endl;
        system("Pause");
    }
    else {
        Node<T>* aux = new Node<T>();
        Node<T>* aux_1 = new Node<T>();

        aux = _node;

        int _index_position = 0;
        while (aux != NULL && _index_position != position)
        {
            aux_1 = aux;
            aux = aux->next;
            _index_position++;
        }
        Node<T>* _back_node = aux_1->previous;
        Node<T>* aux_2 = new Node<T>(_data);

//        _back_node->next(aux_2);
 //       aux_1->previous(aux_2);
    }
}

// Insertar de manera ordenada
template<typename T>
void List<T>::add_sort(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        if (m_head->data > data_) {
            new_node->next = m_head;
            m_head = new_node;
        } else {
            while ((temp->next != NULL) && (temp->next->data < data_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    m_num_nodes++;
}

// Concatenar a otra List
template<typename T>
void List<T>::concat(List list)
{
    Node<T> *temp2 = list.m_head;

    while (temp2) {
        add_end(temp2->data);
        temp2 = temp2->next;
    }
}

// Eliminar todos los nodos
template<typename T>
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

// Eliminar por data del nodo
template<typename T>
void List<T>::del_by_data(T data_)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = m_head->next;

    int cont = 0;

    if (m_head->data == data_) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->data == data_) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

// Eliminar por posición del nodo
template<typename T>
void List<T>::del_by_position(int pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

// Llenar la Lista por teclado
template<typename T>
void List<T>::fill_by_user(int dim)
{
    T ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}

// Llenar la Lista aleatoriamente para enteros
template<typename T>
void List<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}

// Usado por el método intersección
template<typename T>
void insert_sort(T a[], int size)
{
    T temp;
    for (int i = 0; i < size; i++) {
        for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--) {
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
}

// Números que coinciden en 2 Lists
template<typename T>
void List<T>::intersection(List list_2)
{
    Node<T> *temp = m_head;
    Node<T> *temp2 = list_2.m_head;

    List intersection_list;

    int num_nodes_2 = list_2.m_num_nodes;
    int num_inter = 0;

    T *v1 = new T[m_num_nodes];
    T *v2 = new T[num_nodes_2];

    int i = 0;

    while (temp) {
        v1[i] = temp->data;
        temp = temp->next;
        i++;
    }

    int j = 0;

    while (temp2) {
        v2[j] = temp2->data;
        temp2 = temp2->next;
        j++;
    }

    insert_sort(v1, m_num_nodes);
    insert_sort(v2, num_nodes_2);

    int v1_i = 0;
    int v2_i = 0;

  while (v1_i < m_num_nodes && v2_i < num_nodes_2) {
      if (v1[v1_i] == v2[v2_i]) {
          intersection_list.add_end(v1[v1_i]);
          v1_i++;
          v2_i++;
          num_inter++;
      } else if (v1[v1_i] < v2[v2_i]) {
          v1_i++;
      } else {
          v2_i++;
      }
  }
  if (num_inter > 0) {
      cout << "Existen " << num_inter << " intersecciones " << endl;
      intersection_list.print();
  } else {
      cout << "No hay interseccion en ambas listas" << endl;
  }
}

// Invertir la List
template<typename T>
void List<T>::invert()
{
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    Node<T> *temp = m_head;

    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}

// Cargar una lista desde un archivo
template<typename T>
void List<T>::load_file(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());

    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        while (in >> line) {
            add_end(line);
        }
    }
    in.close();
}

// Imprimir la Lista
template<typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacia " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}

// Buscar el dato de un nodo
template<typename T>
void List<T>::search(T data_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posicion: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}

// Ordenar de manera ascendente
template<typename T>
void List<T>::sort()
{
    T temp_data;
    Node<T> *aux_node = m_head;
    Node<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }

        aux_node = aux_node->next;
    }
}

// Guardar una lista en un archivo
template<typename T>
void List<T>::save_file(string file)
{
    Node<T> *temp = m_head;
    ofstream out;
    out.open(file.c_str());

    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->data;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}

template<typename T>
List<T>::~List() {}
