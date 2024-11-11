#include "analisis_clinico.h"

// Implementación de AnalisisClinico
AnalisisClinico::AnalisisClinico(string f, string p) : fecha(f), paciente(p) {}
AnalisisClinico::~AnalisisClinico() {}

// Implementación de QuimicaSanguinea
QuimicaSanguinea::QuimicaSanguinea(string f, string p, vector<float> g, vector<float> c, vector<float> au,
                                   vector<float> u, vector<float> t, vector<float> cr)
    : AnalisisClinico(f, p), glucosa(g), colesterol(c), acidoUrico(au),
      urea(u), trigliceridos(t), creatinina(cr) {}

// Implementación de Ego
Ego::Ego(string f, string p, vector<string> c, vector<float> d, vector<string> a, vector<float> ph,
         vector<float> pr, vector<float> g, vector<float> h, vector<float> cc, vector<float> cel,
         vector<float> cr, vector<float> gr, vector<float> gb)
    : AnalisisClinico(f, p), color(c), densidad(d), aspecto(a), pH(ph),
      proteinas(pr), glucosa(g), hemoglobina(h), cCetonicos(cc), celulas(cel),
      cristales(cr), globulosRojos(gr), globulosBlancos(gb) {}

// Implementación de Node
template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}

// Implementación de LinkedList
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
void LinkedList<T>::insert(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* temp = head;
    while (temp) {
        cout << "Paciente: " << temp->data.paciente
             << ", Fecha: " << temp->data.fecha << endl;

        if constexpr (std::is_same<T, QuimicaSanguinea>::value) {
            for (size_t i = 0; i < temp->data.glucosa.size(); ++i) {
                cout << "Glucosa: " << temp->data.glucosa[i]
                     << ", Colesterol: " << temp->data.colesterol[i]
                     << ", Acido Urico: " << temp->data.acidoUrico[i] << endl;
            }
        }

        if constexpr (std::is_same<T, Ego>::value) {
            for (size_t i = 0; i < temp->data.color.size(); ++i) {
                cout << "Color: " << temp->data.color[i]
                     << ", Densidad: " << temp->data.densidad[i]
                     << ", pH: " << temp->data.pH[i] << endl;
            }
        }
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}
