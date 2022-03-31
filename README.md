# Частотный криптоанализ
## Постановка задачи
Используя алгоритм, необходимо расшифровать текст, описанный в файле формата .txt. Также, как дополнительные функции, необходимо реализовать историю замен, автоанализ и вывод слов.

## Теоретические исследования
Главной функцией программы является расшифровка текста методом частотного криптоанализа. Для этого необходимо узнать характерное частотное распределение символов русского алфавита и произвести дешифровку. В приведённой ниже таблице отображён частотный спектр русского языка, относительно которого и строилось решение поставленной задачи
## Алгоритм решения
- Cоздаётся массив, в котором упорядоченно написаны все буквы русского языка, начиная от самой часто-используемой (A[0] = ‘о’), и заканчивая самой редко-используемой (A[32] = ‘Ъ’)\
- Просматривается данный текст и происходит его буквенный частотный криптоанализ
- Далее, используя созданные функции, выполняется, на выбор пользователя, либо автоматический анализ и замена букв, либо пользователь сам заменяет необходимые ему буквы
## Описание реализованных функций
- scann() — вспомогательная функция для ввода числа
- print() — функция вывода текста в его текущем варианте
- error() — вспомогательная функция, выводит ошибку при неверных входных данных.
- decrypt() — основная функция программы. Она выполняет автоматическую расшифровку текста, основываясь на его частотном анализе.  Создаются 2 вспомогательных массива cur_alph[] и cur_freq[]. В первом хранятся буквы, найденные программой в тексте, а во втором, под соответствующими индексами, хранится их частота встречи. Далее берётся максимальное значение из 2-ого массива, и, как самый часто-встречающийся символ, он заменяется на соответственно самый часто-встречающийся символ русского алфавита (букву ‘о’). Далее таким образом прогоняются все буквы исходного текста. Однако данный алгоритм не может полностью идеально расшифровать код, ввиду некой погрешности в частоте встречи букв.
- freq() — практически это часть вышеописанной функции, однако вместо замены букв, она производит частотный анализ текста и выводит буквы, их частоту и предполагаемую замену
- words_len() — функция для последовательного(от самого большого, до самого малого) вывода слов исходного текста. Реализована с использованием особого типа данных — структуры. sturct Words words_text[] содержит в себе сами слова и их длину. Далее программа последовательно выводит их
- words_non_crypt() — схожая с вышеописанной функцией функция, которая последовательно выводит слова, с самым большим количеством нерасшифрованных букв
- replace() — функция замены букв собственноручно пользователем. Юзер вводит 2 буквы — заменяемую и заменяющую. Далее программа, с помощью цикла, осуществляет полный перебор текста и заменяет соответствующие буквы. Также это действие остаётся в истории изменений
- history_print() — функция вывода истории изменений
- clear() — отмена последнего действия. Фактически — replace() наоборот с удалением пункта из истории.
