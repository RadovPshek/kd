#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // ИСПРАВЛЕННАЯ логика вставки
    void insertBeforeEverySecond(int M) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* prev = head;
        Node* current = head->next;  // 2-й элемент исходного списка
        int index = 2;

        while (current != nullptr) {
            if (index % 2 == 0) {
                Node* newNode = new Node(M);
                prev->next = newNode;
                newNode->next = current;

                prev = current;
                current = current->next;
                index++;
            } else {
                prev = current;
                current = current->next;
                index++;
            }
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* getLastNode() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    void clearList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Список очищен." << endl;
    }

    friend void insertBeforeEverySecond(LinkedList& list, int M);
};

void insertBeforeEverySecond(LinkedList& list, int M) {
    list.insertBeforeEverySecond(M);
}

int main() {
    LinkedList list;
    int n, value, M;

    cout << "Введите количество элементов в списке: ";
    cin >> n;

    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.add(value);
    }

    cout << "Введите значение M для вставки: ";
    cin >> M;

    insertBeforeEverySecond(list, M);

    cout << "Список после вставки: ";
    list.print();

    Node* lastNode = list.getLastNode();

    if (lastNode != nullptr) {
        cout << "Указатель на последний элемент списка: " << lastNode << endl;
        cout << "Значение последнего элемента: " << lastNode->data << endl;
    } else {
        cout << "Список пуст." << endl;
    }

    list.clearList();

    cout << "Проверка списка после очистки: ";
    list.print();

    return 0;
}
