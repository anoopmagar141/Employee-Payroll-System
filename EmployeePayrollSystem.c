#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra; // House Rent Allowance
    float da;  // Dearness Allowance
    float tax; // Tax percentage
    float net_salary;
};

float calculateNetSalary(float basic, float hra, float da, float tax) {
    float gross_salary = basic + hra + da;
    float tax_amount = (tax / 100) * gross_salary;
    return gross_salary - tax_amount;
}