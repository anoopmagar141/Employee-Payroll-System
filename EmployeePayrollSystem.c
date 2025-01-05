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

void addEmployee(struct Employee employees[], int *count) {
    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // To consume newline character
    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; // Remove newline character
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);
    printf("Enter HRA (House Rent Allowance): ");
    scanf("%f", &emp.hra);
    printf("Enter DA (Dearness Allowance): ");
    scanf("%f", &emp.da);
    printf("Enter Tax Percentage: ");
    scanf("%f", &emp.tax);

    emp.net_salary = calculateNetSalary(emp.basic_salary, emp.hra, emp.da, emp.tax);
    employees[*count] = emp;
    (*count)++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees(struct Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees to display.\n");
        return;
    }
    printf("\nEmployee Details:\n");
    printf("---------------------------------------------------\n");
    printf("ID\tName\t\tNet Salary\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", employees[i].id, employees[i].name, employees[i].net_salary);
    }
    printf("---------------------------------------------------\n");
}