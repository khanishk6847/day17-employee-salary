#include <stdio.h>

int main() {
    char name[50], reg[20], sec[5];
    int n, i, j, ch;
    float s[10], total = 0, avg, temp;
    float high, low;
    int above = 0, below = 0;

    printf("Enter Student Name: ");
    scanf("%s", name);
    printf("Enter Registration Number: ");
    scanf("%s", reg);
    printf("Enter Section: ");
    scanf("%s", sec);

    printf("Enter number of employees (max 10): ");
    scanf("%d", &n);

    printf("Enter salaries:\n");
    for(i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%f", &s[i]);
        total += s[i];
    }

    avg = total / n;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Above/Below Average\n");
        printf("5. Display Sorted Salaries\n");
        printf("6. Exit\n");
        printf("================\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("All Salaries:\n");
            for(i = 0; i < n; i++) {
                printf("%.2f\n", s[i]);
            }
        } 
        else if(ch == 2) {
            printf("Total Salary = %.2f\n", total);
            printf("Average Salary = %.2f\n", avg);
        } 
        else if(ch == 3) {
            high = s[0];
            low = s[0];
            for(i = 1; i < n; i++) {
                if(s[i] > high) high = s[i];
                if(s[i] < low) low = s[i];
            }
            printf("Highest Salary = %.2f\n", high);
            printf("Lowest Salary = %.2f\n", low);
        } 
        else if(ch == 4) {
            above = 0;
            below = 0;
            for(i = 0; i < n; i++) {
                if(s[i] > avg) above++;
                else if(s[i] < avg) below++;
            }
            printf("Employees Above Average: %d\n", above);
            printf("Employees Below Average: %d\n", below);
        } 
        else if(ch == 5) {
            for(i = 0; i < n - 1; i++) {
                for(j = 0; j < n - i - 1; j++) {
                    if(s[j] > s[j + 1]) {
                        temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }
            printf("Sorted Salaries (Ascending):\n");
            for(i = 0; i < n; i++) {
                printf("%.2f\n", s[i]);
            }
        } 
        else if(ch == 6) {
            printf("Exiting...\n");
        } 
        else {
            printf("Invalid choice!\n");
        }

        printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, reg, sec);
        printf("Challenge Day 17 – Code2Grow Program\n");

    } while(ch != 6);

    return 0;
}
