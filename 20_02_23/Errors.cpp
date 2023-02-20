
#include <iostream>
#include <exception>

int input_n()
{
    int n;
    std::cout << "введи size : ";
    std::cin >> n;
    if (n > 0)
    {
        return n;
    }
    else
    {
        throw "Число должно быть больше 0";
    }
}

// // Выбрсывает исключение
// int print_n()
// {

//     int n = input_n();

//     if (n >= 10 && n <= 15)
//     {
//         std::cout << n << "\n";
//     }
//     else
//     {
//         throw "Число должно быть от 10 до 15!";
//     }

//     return n;
// }

// void print_all_del(int n)
// {

//     for (int i = 1; i < n; ++i)
//     {

//         if (n % i == 0)
//         {
//             std::cout << i << " ";
//         }
//     }
//     std::cout << "\n";
// }

// void print_div(int n)
// {
//     int m = input_n();

//     if (m == 0)
//         throw "На ноль делить нельзя!!!";

//     std::cout << "Остаток от деления " << n % m << "\n";
// }

void full_arr(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "число массива = ";
        std::cin >> array[i];
    }
}

void print_arr(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void exite()
{
    exit(0);
}

void search_index(int *array, int n)
{
    int val;
    std::cout<<"val = ";
    std::cin>>val;

    int f = -1;
    for (int i = 0; i < n; ++i)
    {
        if (val == array[i])
        {
            f = i;
            break;
        }
    }

    if (f < 0) {
            throw "Такого число нет";
    }

    std::cout << f << "\n";
}
void chose_com(int *array, int n)
{

    int v;

    std::cout << "Выберите команду \n";
    std::cout << "1. Вывод массива \n";
    std::cout << "2. Поиск элемена \n";
    std::cout << "5. Удаление элемента элемена по значению \n";
    std::cout << "6. Удаление элемента элемена по индексу \n";
    std::cout << "-1. Выход \n";
    std::cout << " : ";

    std::cin >> v;

    switch (v)
    {
    case 1:
        print_arr(array, n);
        break;
    case -1:
        exite();
        break;
    case 2:
        search_index(array, n);
        break;
    default:
        break;
    }
}

int main()
{
    int *array;

    try
    {

        int n = input_n();
        array = new int[n];

        full_arr(array, n); // заполнение массива // ошибка при неверном размере

        while (true)
        {
            try
            {
                // full_arr(array, n); // заполнение массива // ошибка при неверном размере

                chose_com(array, n);
            }
            catch (const char *error)
            {
                std::cout << "Ошибка!!!\n";

                std::cout << error << "\n";
            }
        }
        std::cout << "End!!\n";
        delete[] array;
    }
    catch (const char *error)
    {
        std::cout << "Ошибка!!!\n";

        std::cout << error << "\n";
    }
}