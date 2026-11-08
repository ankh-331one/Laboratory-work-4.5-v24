#ifndef P_FUNCTION.H
#define P_FUNCTION.H
#include <stdio.h>

int input(char a, int min_d, int max_d);

void mass_input(FILE* in_file, int n, double* *X);
void mass_print(FILE* out_file, char a, int n, double* X);

int id_max(int n, double* X);
void cr_geomet_poloz(FILE* out_file, int n, double* X);


#endif // P_FUNCTION.H
