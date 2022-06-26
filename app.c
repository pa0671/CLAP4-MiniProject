#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define R 7
# define C 2
void aeroplane(char ar[R][C]){
    FILE* ptr;
    ptr = fopen("reservations.txt", "w");
    printf("\n");
    int a = 65;
    int i;
    printf("\n");
    printf("0 1 2\n");
    fprintf(ptr, "0 1 2\n");
    for(i=0;i<R; i++){
        printf("%c %c %c\n", a, ar[i][0], ar[i][1]);
        fprintf(ptr, "%c %c %c\n", a, ar[i][0], ar[i][1]);
        a++;
    }
    fclose(ptr);
}
int main()
{
	FILE* ptr;
	char ch;
	ptr = fopen("reservations.txt", "r");
    char arr[R][C];
    int i, j;
    i=0;
    j=0;
	if (NULL == ptr) {
		printf("File can't be opened \n");
	}
	do {
		ch = fgetc(ptr);
        
        if (ch == '\n') {
            i++;
            j=0;
        }
        if (ch == 'O' || ch == 'X') {
            //printf("%d %d %c\n", i-1, j, ch);
            arr[i-1][j] = ch;
            j++;
        }
	} while (ch != EOF);
    printf("Welcome to Piyush Airlines!\nPlease choose a seat.\nSeat with X is already booked.");
    aeroplane(arr);
    int k;
    char seat_number[3];
    printf("Enter seat number: ");
    gets(seat_number);
    int row = seat_number[0] - 65;
    int column = seat_number[1] - '0' - 1;
    if (arr[row][column] == 'X') {
        printf("%s already booked! Please choose another seat!", seat_number);
    } else {
        arr[row][column] = 'X';
    }
    aeroplane(arr);
    printf("%s booked. Thank you for choosing Piyush Airlines!", seat_number);
	fclose(ptr);

	return 0;
}