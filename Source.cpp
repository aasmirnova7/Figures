#include <stdio.h>
#include <conio.h>

void f(char *x1_old, char *x2_old, char *x3_old)
{
	char x1 = *x1_old;
	char x2 = *x2_old;
	char x3 = *x3_old;
	__asm {
		mov al, x1; // al = x1
		sub al, 48;
		mov bl, x2; //bl = x2
		sub bl, 48;
		mov cl, x3; // cl = x3
		sub cl, 48;
		cmp al, cl; // al ?? cl
		jne INACHE; // if != -> INACHE
		cmp al, bl; //al ?? bl
		jge INACHE; // if == -> INACHE
		mov dl, 9; // dl = 9
		sub dl, al; // dl = 9 - al
		mov al, dl; // al = 9 - al
		mov dl, 9; // dl = 9
		sub dl, cl; // dl = 9 - cl
		mov cl, dl; // cl = 9 -cl
		jmp EXIT;
	INACHE: mov dl, 9; // dl = 9
		sub dl, bl; // dl = 9 - bl
		mov bl, dl; // bl = 9 - bl
	EXIT: add al, 48;
		add bl, 48;
		add cl, 48;
		mov x1, al;
		mov x2, bl;
		mov x3, cl;
	}
	*x1_old = x1;
	*x2_old = x2;
	*x3_old = x3;
}
int main()
{
	char x1, x2, x3, x4;
	printf("\n\n    Input numbers\n    ");
	scanf_s("%c", &x1);
	scanf_s("%c", &x2);
	scanf_s("%c", &x3);
	scanf_s("%c", &x4);
	
	if ((x1 < '0' || x1 > '9') || (x2 < '0' || x2 > '9') || (x3 < '0' || x3 > '9'))
	{
		printf("    Bad input\n");
		_getch();
		return -1;
	}
	if (x4 != '\n')
	{
		printf("    Bad number of arguments\n");
		_getch();
		return -1;
	}
	f(&x1, &x2, &x3);
	printf("    x1 = %c\n    x2 = %c\n    x3 = %c\n", x1, x2, x3);
	_getch();
}