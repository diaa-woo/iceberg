#include <stdio.h>

#include <stdlib.h> // rand()�Լ� ���� ���̺귯��

#include <time.h> // time()�Լ� ���� ���̺귯��



int main()

{

	srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����

	int random = 0; // ������ ���� ����

	for (int i = 0; i < 10; i++) { // 10�� �ݺ�

		random = rand()%9; // ���� ����

	}
	
	printf("%d\n", random); // ���

}
