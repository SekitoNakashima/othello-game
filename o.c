#include <stdio.h>
#define BLK 1
#define WHT -1
#define EMP 0

void brd_output();//�i�j�R���H�ƂȂ�Ȃ��悤�ɐ�ɐ錾
void input();
int cell[8][8];

int main(void)
{
	int i,j;
	int x,y;
	int player = BLK;
	
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			cell[i][j] = EMP;
		}
	}
	cell[3][3] = cell[4][4] = WHT;
	cell[3][4] = cell[4][3] = BLK;
	brd_output();//�����ɋL���Ă���֐��ɂƂԁB�J�b�R���̐�����n���Bbrd_output�̃J�b�R����void�̎��A�����ɋL���J�b�R�̒��g�͂Ȃ��Ă悢��()
	while (1){
			input(player);
			brd_output();
			player *= -1;
	}
		
	return 0;
}


void brd_output(void)//�Ԃ��l���Ȃ����void���g���B
{//���Ԃ��l�@�@//�������Ă���l
	int i,j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			switch(cell[i][j]){
			case BLK:  printf("�Z");   break;
			case WHT:  printf("��");   break;
			case EMP:  printf("�E");   break;
			}	
		}
		puts("");
	}
}

void input(int player)
{
	int x,y;
	
	while(1) {
	printf("X > ");
	scanf("%d",&x);
	printf("Y > ");
	scanf("%d",&y);
	if( x < 0 || x >= 8 || y < 0 || y >= 8 ){
		printf("m9(^�D^)�߷ެ� < �u���ˁ[��\n\n");
	}
	else{
		cell[x][y] = player;
		break;
	}
	}
}

void fin(int cell[][])
{
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if(cell[i][j] == BLK || cell[i][j] == WHT){