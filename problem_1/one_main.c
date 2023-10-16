#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int MONTHS = 12;
char *ALL_MONTHS[] = {"January", "February", "March", "April", "May", 
                    "June", "July", "August", "September", "October", 
                    "November", "December"};

void sales_report(float *sales_amt){
    printf("Monthly sales report for 2022:\n");
    printf("%-20s %-20s\n", "Month", "Sales");
    for(int i = 0; i < MONTHS; ++i) {
        printf("%-20s $%-20f\n", ALL_MONTHS[i], sales_amt[i]);
    }
}

void sales_sum(float *sales_amt) {
    int min = 0;
    int max = 0;
    float min_sales = sales_amt[0];
    float max_sales = sales_amt[0];
    float sum = 0;
    float avg = 0;
    for(int i = 0; i < MONTHS; ++i) {
        min_sales = MIN(min_sales, sales_amt[i]);
        min = ((sales_amt[i] == min_sales)? i : min);
        max_sales = MAX(max_sales, sales_amt[i]);
        max = ((sales_amt[i] == max_sales)? i : max);
        sum += sales_amt[i];
    }
    avg = sum / MONTHS;
    printf("Sales summary:\n");
    printf("Minimum sales: $%f (%s)\n", min_sales, ALL_MONTHS[min]);
    printf("Maximum sales: $%f (%s)\n", max_sales, ALL_MONTHS[max]);
    printf("Average sales: %f\n", avg);
}

void six_month(float* sales_amt){
    printf("Six-Month Moving Average Report: \n");
    for(int i = 0; i <= 6; ++i) {
        float sum = 0;
        float avg = 0;
        for(int j=i; j < i + 6; ++j){
            sum += sales_amt[j];
        }
        avg = sum / 6;
        printf("%-20s - %-20s: $%-20f\n", ALL_MONTHS[i], ALL_MONTHS[i+5], avg);
    }
}

void sales_descending(float* sales_amt){
    int temp;
    int index[MONTHS];
    for(int i = 0; i < MONTHS; ++i) {
        index[i] = i;
    }

    for(int i = 0; i < MONTHS; ++i) {
        for(int j = i + 1; j < MONTHS; ++j) {
            if(sales_amt[index[i]] < sales_amt[index[j]]){
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    for(int i = 0; i < MONTHS; ++i) {
        printf("%-20s : $%-20f\n", ALL_MONTHS[index[i]], sales_amt[index[i]]);
    }
}

int main(){
    const int months = 12;
    float* sales_data = (float*)malloc(sizeof(float) * months);
    FILE *contents = fopen("sales_input.txt", "r+");
    for(int i = 0; i < months; i++){
        fscanf(contents, "%f\n", &sales_data[i]);
    }
    sales_report(sales_data);
    printf("\n");
    sales_sum(sales_data);
    printf("\n");
    six_month(sales_data);
    printf("\n");
    sales_descending(sales_data);
    printf("\n");
    return 0;
}