class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return

        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def paste(self, m):
        # FIXME: По условию требуется вставлять M ПЕРЕД каждым вторым элементом,
        # FIXME: а текущая реализация вставляет элементы после текущего узла.

        # FIXME: Метод не возвращает P2 (ссылку на последний элемент списка),
        # FIXME: хотя это явно требуется в условии задачи.

        if not self.head or not self.head.next:
            # FIXME: Нет обработки требования:
            # FIXME: при нечётном числе элементов вставку в конец делать нельзя.
            return

        current = self.head
        count = 1

        while current.next:
            # FIXME: Использование счётчика усложняет логику
            # FIXME: и не гарантирует корректную вставку
            # FIXME: именно перед вторыми элементами.
            if count % 2 != 0:
                new_node = Node(m)
                new_node.next = current.next
                current.next = new_node
                current = new_node.next
                count += 2
            else:
                current = current.next
                count += 1

    def get_last_element(self):
        # FIXME: Получение P2 вынесено в отдельный метод,
        # FIXME: хотя по условию P2 должен быть результатом вставки.
        current = self.head
        if not current:
            return None
        while current.next:
            current = current.next
        return current

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()


linked_list = LinkedList()

num_elements = int(input("Введите количество элементов для добавления в список: "))
for i in range(num_elements):
    data = input(f"Введите элемент {i + 1}: ")
    linked_list.append(data)

m = input("Введите значение M: ")
linked_list.paste(m)

print("Измененный список:")
linked_list.print_list()

last_node = linked_list.get_last_element()
# FIXME: P2 должен возвращаться методом paste(),
# FIXME: а не вычисляться отдельным обходом списка.

if last_node:
    print(f"Последний элемент списка: {last_node.data}, ссылка: {last_node}")
else:
    print("Список пуст")
