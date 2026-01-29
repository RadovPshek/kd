# FIXTO удалены лишние/очевидные комментарии
# FIXTO дополненно название класса
class NodeClass:
    def __init__(self, data):
        self.data = data
        self.next = None

# FIXTO дополненно название класса
class LinkedListClass:
    def __init__(self):
        self.head = None

    def append(self, data):
        # FIXTO добавлены комментарии для функций в формате docstring
        """
        Добавляет узел с данными в конец списка.
        arguments:
        data - добавляемое значение
        """
        new_node = NodeClass(data)
        if not self.head:
            self.head = new_node
            return

        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    # FIXTO переменная m переименована в понятную переменную insert_element
    # FIXTO функция оптимизирована
    def paste(self, insert_element):
        # FIXTO добавлены комментарии для функций в формате docstring
        """
        Вставляет новый узел с значением insert_element перед каждым вторым узлом.
        arguments:
        Insert_elements - вставляемое значение
        """
        if not self.head or not self.head.next:
            return

        current = self.head
        count = 1

        """Проверяет, что существует следующий узел."""
        while current.next:
            if count % 2 != 0:  
                new_node = NodeClass(insert_element)
                new_node.next = current.next
                current.next = new_node
                current = new_node.next
                count += 1 # FIXTO, исправлено
            else:
                current = current.next
                count += 1    

    def get_last_element(self):
        # FIXTO добавлены комментарии для функций в формате docstring
        """Возвращает ссылку на последний узел списка, если список не пуст."""
        current = self.head
        if not current:
            return None        
        while current.next:
            current = current.next            
        return current

    def print_list(self):
        # FIXTO добавлены комментарии для функций в формате docstring
        """Выводит в консоль список."""
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next            
        print()

# FIXTO удалены лишние/очевидные комментарии
# FIXTO выполнение программы происходит в функции main
def main():
    # FIXTO переменная m переименована в insert_element, чтобы отразить логику
    linked_list = LinkedListClass()

    # FIXTO добавлена проверка на корректный ввод   
    num_elements = input("Введите количество элементов для добавления в список: ")
    if(not str.isdigit(num_elements) or int(num_elements)<0):
        return(print("Ошибка ввода"))
    num_elements = int(num_elements)

    # FIXTO добавлена проверка на корректный ввод 
    for i in range(num_elements):
        data = input(f"Введите элемент {i+1}: ")
        if(not str.isdigit(data)):
            return(print("Ошибка ввода"))
        linked_list.append(data)

    # FIXTO добавлена проверка на корректный ввод
    insert_element = input("Введите значение для вставки: ")
    if(not str.isdigit(insert_element)):
        return(print("Ошибка ввода"))
    linked_list.paste(insert_element)

    print("Измененный список:")
    linked_list.print_list()

    last_node = linked_list.get_last_element()

    # FIXTO убрано лишнее действие по выводу значения элемента
    if last_node:
        print(f"Ссылка на последний элемент списка : {last_node}")
    else:
        print("Список пуст")

# FIXTO добавлена конструкция вызова функции main
if __name__ == "__main__":
    main()