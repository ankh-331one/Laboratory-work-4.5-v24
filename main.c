//Лабораторная работа №4.5v24
/**
4.5 Усложненная задача обработки трех массивов

    Во всех задачах дано 3 одномерных массива A, B и C разного размера. Для
 каждого из них найти требуемое значение, и затем использовать его для
 решения второй задачи. Если найденные значения совпадают, вывести
 соответствующее сообщение (с указанием имён массивов с совпадающими
 значениями). Для обработки массивов, ввода и вывода использовать
 подпрограммы. Имейте в виду, что искомых элементов в массиве(ах) может
 не быть. Этот случай должен быть предусмотрен. Будьте внимательны при
 определении типа данных элементов массивов.

    24.В том из массивов, у которого индекс максимума наибольший, найти
 среднее геометрическое положительных элементов.
*/

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "p_function.h"

#define L_DIAPAZON_MASSIV 1
#define R_DIAPAZON_MASSIV 99

int main()
{
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");

    FILE* out_file = fopen("output.txt", "a");
    fprintf(out_file, "Программа 4.5v24. Сборка: %s %s", __DATE__, __TIME__);
    fprintf(out_file, "\n---------------------------------------------------------------\n");

    FILE* in_file = fopen("input.txt", "r");

    int n_a = input('A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* A;
    mass_input(in_file, n_a, &A);

    int n_b = input('B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* B;
    mass_input(in_file, n_b, &B);

    int n_c = input('C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* C;
    mass_input(in_file, n_c, &C);

    fclose(in_file);

    mass_print(out_file,'a', n_a, A);
    mass_print(out_file,'b', n_b, B);
    mass_print(out_file,'c', n_c, C);

    fprintf(out_file, "\n\n---------------------------------------------------------------\n");

    int a = id_max(n_a, A);
    int b = id_max(n_b, B);
    int c = id_max(n_c, C);

    fprintf(out_file, "\nИндексы максимумов: A - %d, B - %d, C - %d\n", a, b, c);


    fprintf(out_file, "\n===============================================================\n\n\t\t");

    fprintf(out_file, "Результат: \n\n");
    if (a > b && a > c){
        fprintf(out_file, "Наибольший индекс максимума в масссиве A");
        cr_geomet_poloz(out_file, n_a, A);
    }else if (a == b && a > c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах A и B");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_b, B);
    }else if (a > b && a == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах A и C");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_c, C);
    }else if (a == b && a == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума во всех трёх массивах A, B, C");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_b, B);
        cr_geomet_poloz(out_file, n_c, C);
    }else if (b > c){
        fprintf(out_file, "Наибольший индекс максимума в масссиве B");
        cr_geomet_poloz(out_file, n_b, B);
    }else if (b == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах B и C");
        cr_geomet_poloz(out_file, n_b, B);
        cr_geomet_poloz(out_file, n_c, C);
    }else{
        fprintf(out_file, "Наибольший индекс максимума в масссиве C");
        cr_geomet_poloz(out_file, n_c, C);
    }

    fprintf(out_file, "\n\n===============================================================\n\n\n\n\n");

    fclose(out_file);
    free(A);
    free(B);
    free(C);

    return 0;
}
