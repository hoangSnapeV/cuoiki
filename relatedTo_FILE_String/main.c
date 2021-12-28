#include <stdio.h>

int read_numbers(char path[]) // doc tep tin tu
{
    FILE* file = fopen(path, "r");

    if (file == NULL) return -1;

    int sum = 0;
    
    //scanf("%d", &n);
    while (1)
    {
        int n;
        int status = fscanf(file, "%d", &n);
        if(status == -1) break;

        printf("%d ", n);
        sum += n;
    }
    

    fclose(file);
    return sum;
}

int write_array(int a[], const char path[], int n) /// in ra tep tin output tu mang trong main
{
    FILE* f =  fopen(path, "w");

    if(f == NULL) return 0;

    
    for (int i = 0; i < n; i++)
    {   
        if (i == n - 1)
        {
            fprintf(f, "%d.", a[i]);
        } else fprintf(f, "%d, ", a[i]);
        
    }
    

    fclose(f);
    return 1;
}
int main()
{
    int sum = read_numbers("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/data.txt");

    printf("\nsum = %d\n", sum);

    int a[] = {2, 10, -5, 100, 58, 25};
    
    int n = sizeof(a) / sizeof(int);

    int status = write_array(a, "C:/Users/Admin/OneDrive/Desktop/cuoiki/test/output.txt", n); // test/output.txt - thư mục cùng cấp độ 
    // ../để back ra cùng cấp độ

    if (status == 1)
        printf("success");
    else 
        printf("fail");

    return 0;
}