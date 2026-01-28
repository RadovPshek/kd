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
        # FIXTO: Вставка выполняется ПЕРЕД каждым вторым элементом
        # FIXTO: исходного списка, а не с учётом уже вставленных узлов

        if not self.head or not self.head.next:
            # FIXTO: При 0 или 1 элементе вставка не требуется
            return self.get_last_element()

        prev = self.head
        current = self.head.next
        index = 2  # FIXTO: индекс считается по ИСХОДНОМУ списку

        while current:
            if index % 2 == 0:
                # FIXTO: Вставляем M перед текущим вторым элементом
                new_node = Node(m)
                prev.next = new_node
                new_node.next = current
                prev = current
                current = current.next
                index += 1
            else:
                prev = current
                current = current.next
                index += 1

        # FIXTO: Возвращаем P2 — последний элемент итогового списка
        return self.get_last_element()

    def get_last_element(self):
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

n = int(input("Введите количество элементов: "))
for i in range(n):
    linked_list.append(input(f"Элемент {i + 1}: "))

m = input("Введите значение M: ")

last_node = linked_list.paste(m)

print("Изменённый список:")
linked_list.print_list()

if last_node:
    print(f"P2 указывает на элемент: {last_node.data}, ссылка: {last_node}")
else:
    print("Список пуст")
