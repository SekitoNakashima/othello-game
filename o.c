#include <stdio.h>
#define BLK 1
#define WHT -1
#define EMP 0
#define TRUE 2
#define FALSE -2

void brd_output();//�i�j�R���H�ƂȂ�Ȃ��悤�ɐ�ɐ錾
void input();
int finish();
int cell[8][8];

int main(void)
{
	int i,j;
	int x,y;
	int player = BLK;
	
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			cell[i][j] = WHT;
		}
	}
	cell[3][3] = cell[4][4] = EMP;
	cell[3][4] = cell[4][3] = BLK;
	brd_output();//�����ɋL���Ă���֐��ɂƂԁB�J�b�R���̐�����n���Bbrd_output�̃J�b�R����void�̎��A�����ɋL���J�b�R�̒��g�͂Ȃ��Ă悢��()
	
	putchar('\n');
	
	while (1){
		if(finish(cell) == FALSE){
			break;
		}
		input(player);
		brd_output();
		player *= -1;
	}
	which();
	return 0;
}


void brd_output(void)//�Ԃ��l���Ȃ����void���g���B
{//���Ԃ��l�@�@//�������Ă���l
	int i,j;
	
	putchar('\n');
	printf(" �O�P�Q�R�S�T�U�V\n");
	for(i = 0; i < 8; i++){
		printf("%d",i);
		for(j = 0; j < 8; j++){
			switch(cell[i][j]){
			case BLK:  printf("�Z");   break;
			case WHT:  printf("��");   break;
			case EMP:  printf("�E");   break;
			}	
		}
		putchar('\n');
	}
}

void input(int player)
{
	int x,y;
	
	while(1) {
		if(player == BLK){
			printf("���̃^�[���ł��B\n");
		}
		else{
			printf("���̃^�[���ł��B\n");
		}
				printf("X > ");
				scanf("%d",&x);
				printf("Y > ");
				scanf("%d",&y);
				if( x < 0 || x >= 8 || y < 0 || y >= 8 ){
					printf("<�u���܂��[��B\n\n");
				}
				else{
					cell[y][x] = player;
					break;
				}
	}
}

int finish(int cell[][8])
{
	int i,j;
	
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if(cell[i][j] == EMP){
				return TRUE;
			}
		}
	}
	return FALSE;
}

int which()
{
	int i,j;
	int cntW = 0, cntB = 0;
	
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
				if(cell[i][j] == WHT){
					cntW += 1;
				}
			else if(cell[i][j] == BLK){
					cntB += 1;
			}
		}
	}
	if(cntW > cntB){
		printf("<���̏����ł��B\n%d ��",cntW);
	}
	else if(cntB > cntW){
		printf("<���̏����ł��B\n%d ��",cntB);
	}
	else{
		printf("���������ł��B");
	}
}