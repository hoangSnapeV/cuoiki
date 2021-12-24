#include <stdio.h>

double read_and_sum(const char path[])
{

    FILE* f = fopen(path, "r");

    double sum = 0;
    while (!feof(f))
    {
        double x;
        int success = fscanf(f, "%lf", &x);

        printf("%lf\n", x);
        if(success == 1) 
        {
            sum += x;
        }
        
    }
    
    fclose(f);
    return sum;
}

void write_number(const char path[], double value)
{

    FILE* f = fopen(path, "w");
    fprintf(f, "%.2lf", value);

    fclose(f);

}
int main()
{
    double sum = read_and_sum("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/vd4.txt");
    write_number("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/out_vd4.txt", sum);

    return 0;
}