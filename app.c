#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define R 7
# define C 2
void aeroplane(char lol[R][C]){
    printf("\n");
    int a = 65;
    int i;
    printf("0 1 2\n");
    for(i=0;i<R; i++){
        printf("%c %c %c\n", a, lol[i][0], lol[i][1]);
        a++;
    }
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
	fclose(ptr);
    aeroplane(arr);
    
    char seat_number[2];
    printf("Enter seat number: ");
    gets(seat_number);
    //printf("%s", seat_number);
    int row = seat_number[0] - 65;
    int column = seat_number[1] - '0' - 1;
    printf("%d %d", row, column);
    arr[3][0] = 'X';
    aeroplane(arr);
	return 0;
}