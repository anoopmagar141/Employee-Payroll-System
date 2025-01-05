#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra; 
    float da; 
    float tax; 
    float net_salary;
};


float calculateNetSalary(float basic, float hra, float da, float tax) {
    float gross_salary = basic + hra + da;
    float tax_amount = (tax / 100) * gross_salary;
    return gross_salary - tax_amount;
}


float parseFloat(char *str) {
    char temp[50];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ',') {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    return atof(temp);
}


int readInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter a valid integer: ");
        while (getchar() != '\n'); 
    }
    return value;
}

void addEmployee(struct Employee **employees, int *count) {
    struct Employee emp;
    char input[50];

    printf("\nEnter Employee ID: ");
    emp.id = readInt();  

    getchar();

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    size_t len = strlen(emp.name);
    if (len > 0 && emp.name[len - 1] == '\n') {
        emp.name[len - 1] = '\0'; 
    }

    printf("Enter Basic Salary: ");
    fgets(input, sizeof(input), stdin);
    emp.basic_salary = parseFloat(input);

    printf("Enter HRA (House Rent Allowance): ");
    fgets(input, sizeof(input), stdin);
    emp.hra = parseFloat(input);

    printf("Enter DA (Dearness Allowance): ");
    fgets(input, sizeof(input), stdin);
    emp.da = parseFloat(input);

    printf("Enter Tax Percentage: ");
    fgets(input, sizeof(input), stdin);
    emp.tax = parseFloat(input);

    emp.net_salary = calculateNetSalary(emp.basic_salary, emp.hra, emp.da, emp.tax);

    
    *employees = realloc(*employees, (*count + 1) * sizeof(struct Employee));
    (*employees)[*count] = emp;
    (*count)++;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees(struct Employee *employees, int count) {
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
int main() {
    struct Employee *employees = NULL;
    int count = 3, choice;
    struct Employee preload[3] = {
        {101, "Anup Magar", 50000.0, 10000.0, 5000.0, 15.0, 55250.00},
        {102, "Priya Sharma", 60000.0, 12000.0, 6000.0, 12.0, 63720.00},
        {103, "Ravi Kumar", 45000.0, 9000.0, 4500.0, 10.0, 51450.00}
    };
    employees = malloc(count * sizeof(struct Employee));
    for (int i = 0; i < count; i++) {
        employees[i] = preload[i];
    }

    while (1) {
        printf("\nEmployee Payroll System");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEmployee(&employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                printf("\nExiting... Goodbye!\n");
                free(employees); 
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
