# Лабораторная работа №4: структура хранения очереди

Создан класс TQueue - реализация очереди. В нём реализованы следующие методы:

- Запись элемента в очередь;
- Чтение элемента из очереди с удалением;
- Чтение элемента из очереди без удаления;
- Чтение последнего элемента в очереди без удаления;
- Проверка на пустоту очереди;
- Проверка на заполненность очереди;
- Очистка очереди.

Для проверки правильности работы класса реализован следующий алгоритм:

  На вход поступают 2 числа - общее количество задач n и вероятность поступления задачи
  в очередь p. C помощью генератора случайных чисел создаётся массив вещественных чисел q
  размера n, где каждое число находится в диапазоне от 0 до 1. Если число из q меньше p, то 
  с помощью генератора случайных чисел создаётся число tmp (будем считать его "задачей") от 1 до 100, 
  которое заносится в очередь. Далее смотрим на число, которое стоит первым в очереди - если оно 
  меньше числа, которое замыкает очередь, то "задача" считается выполненной и она выходит из очереди.
  Во время выполнения программы на экране появлются все "задачи", которые поступают и выходят из очереди.
