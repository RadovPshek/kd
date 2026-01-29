/*
Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов — добавления / удаления / вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

Дан односвязный линейный список и указатель на голову списка P1.
Необходимо вставить значение M перед каждым вторым элементом списка
и вывести ссылку на последний элемент полученного списка P2.
При нечётном числе элементов исходного списка в конец списка вставлять не надо.
*/

#include <iostream>
#include <windows.h>
// FIXTO: Использование using namespace std удалено.
// FIXTO: Используется явное указание std::

// FIXTO: Добавлен комментарий по назначению класса.
// Класс, представляющий узел односвязного списка.
class Node {
 public:
  // FIXTO: Поля данных скрыты (private) для соблюдения инкапсуляции.
  // FIXTO: Имена полей имеют суффикс подчёркивания согласно Google Style Guide.
  explicit Node(int value) : data_(value), next_(nullptr) {}

  int Data() const { return data_; }
  Node* Next() const { return next_; }
  void SetNext(Node* next) { next_ = next; }

 private:
  int data_;
  Node* next_;
};

// FIXTO: Добавлен комментарий по назначению класса.
// Класс для работы с односвязным линейным списком.
class LinkedList {
 public:
  LinkedList() : head_(nullptr) {}

  // FIXTO: Запрещено копирование и присваивание,
  // так как класс управляет динамической памятью.
  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  // FIXTO: Метод переименован согласно правилам именования Google Style Guide.
  void Add(int value) {
    Node* new_node = new Node(value);
    if (head_ == nullptr) {
      head_ = new_node;
      return;
    }

    Node* current = head_;
    while (current->Next() != nullptr) {
      current = current->Next();
    }
    current->SetNext(new_node);
  }

  // FIXTO: Метод переименован.
  // FIXTO: Параметр M переименован в insert_element для ясности.
  // Вставляет значение insert_element перед каждым вторым элементом списка.
  void InsertBeforeEverySecond(int insert_element) {
    Node* current = head_;

    // Счётчик позиции: первый элемент имеет индекс 1.
    int count = 1;

    while (current != nullptr && current->Next() != nullptr) {
      if (count % 2 == 1) {
        Node* new_node = new Node(insert_element);
        new_node->SetNext(current->Next());
        current->SetNext(new_node);
        current = new_node->Next();
      } else {
        current = current->Next();
      }
      count++;
    }
  }

  // FIXTO: Метод переименован.
  // Выводит элементы списка на экран.
  void Print() const {
    Node* current = head_;
    while (current != nullptr) {
      std::cout << current->Data() << " ";
      current = current->Next();
    }
    std::cout << std::endl;
  }

  // FIXTO: Комментарий перенесён перед объявлением метода.
  // Возвращает указатель на последний элемент списка.
  Node* Last() const {
    Node* current = head_;
    while (current != nullptr && current->Next() != nullptr) {
      current = current->Next();
    }
    return current;
  }

  // FIXTO: Метод управления памятью не выполняет ввод/вывод.
  void Clear() {
    while (head_ != nullptr) {
      Node* temp = head_;
      head_ = head_->Next();
      delete temp;
    }
  }

 private:
  // FIXTO: Имя поля оканчивается подчёркиванием.
  Node* head_;
};

int main() {
  // FIXTO: Выбрана верная кодировка.
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  LinkedList list;  
  // FIXTO: Переменные переименованы для ясности.
  int element_count = 0;
  int value = 0;
  int insert_value = 0;

  // FIXTO: Добавлена проверка корректности ввода.
  std::cout << "Введите количество элементов списка: ";
  if (!(std::cin >> element_count) || element_count < 0) {
    std::cout << "Некорректный ввод." << std::endl;
    return 1;
  }

  // FIXTO: Добавлена проверка корректности ввода.
  for (int i = 0; i < element_count; ++i) {
    std::cout << "Введите элементы списка номер "<< i+1 <<": ";
    if (!(std::cin >> value)){
      std::cout << "Некорректный ввод." << std::endl;
      return 1;
    }
    list.Add(value);
  }

  // FIXTO: Добавлена проверка корректности ввода.
  std::cout << "Введите значение для вставки: ";
  if (!(std::cin >> insert_value)) {
    std::cout << "Некорректный ввод." << std::endl;
    return 1;
  }

  list.InsertBeforeEverySecond(insert_value);

  std::cout << "Список после вставки: ";
  list.Print();

  Node* last_node = list.Last();

  // FIXTO: Убрано отображение значения последнего элемента.
  if (last_node != nullptr) {
    std::cout << "Указатель на последний элемент списка: "
              << last_node << std::endl;
  } else {
    std::cout << "Список пуст." << std::endl;
  }

  // FIXTO: Убрано оповещение об очиске списка.
  list.Clear();
  return 0;
}
