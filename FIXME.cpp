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
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertBeforeEverySecond(int M) {
        Node* current = head;
        int count = 1;  

        // FIXME: Счётчик count используется для логики вставки,
        // FIXME: но после первой вставки структура списка меняется,
        // FIXME: и позиции элементов больше не соответствуют
        // FIXME: исходному списку, как требуется по условию.

        while (current != nullptr && current->next != nullptr) {
            if (count % 2 == 1) {
                // FIXME: Вставка выполняется ПОСЛЕ текущего элемента,
                // FIXME: а по условию требуется вставлять M ПЕРЕД
                // FIXME: каждым вторым элементом исходного списка.

                Node* newNode = new Node(M);
                newNode->next = current->next;
                current->next = newNode;

                // FIXME: Переход current учитывает уже вставленный элемент,
                // FIXME: что нарушает корректный обход исходных узлов.
                current = newNode->next;
            }
            else {
                current = current->next;
            }
            count++;
        }

        // FIXME: Метод не возвращает P2 — указатель на последний элемент
        // FIXME: полученного списка, как требуется в условии задачи.
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
        // FIXME: Получение P2 вынесено в отдельный метод,
        // FIXME: хотя по условию P2 должен быть результатом
        // FIXME: операции вставки.
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

    // FIXME: Дружественный интерфейс формально присутствует,
    // FIXME: но дружественная функция лишь вызывает метод класса
    // FIXME: и не предоставляет самостоятельного интерфейса.
    friend void insertBeforeEverySecond(LinkedList& list, int M);
};

void insertBeforeEverySecond(LinkedList& list, int M) {
    // FIXME: Дружественная функция не возвращает P2,
    // FIXME: хотя по условию задачи требуется вывести
    // FIXME: ссылку на последний элемент полученного списка.
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

    // FIXME: Указатель P2 вычисляется отдельным обходом списка,
    // FIXME: а не возвращается как результат операции вставки.

    if (lastNode != nullptr) {
        cout << "Указатель на последний элемент списка: " << lastNode << endl;
        cout << "Значение последнего элемента: " << lastNode->data << endl;
    }
    else {
        cout << "Список пуст." << endl;
    }

    list.clearList();

    cout << "Проверка списка после очистки: ";
    list.print();

    return 0;
}
