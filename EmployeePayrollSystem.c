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
