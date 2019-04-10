#include <stdio.h>
#include <conio.h>

double hp = 10;
int step = 100, decrease_percentage = 75;

int main() {
    for (int i = 0; i < step; i++) {
        hp += (hp * decrease_percentage / 100) * 15 / 100;
        printf("%lf\n", hp);
    }
    _getch();
    return 0;
}