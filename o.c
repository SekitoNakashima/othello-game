#include <stdio.h>
#define BLK 1
#define WHT -1
#define EMP 0

void brd_output();//ナニコレ？とならないように先に宣言
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
	brd_output();//ここに記している関数にとぶ。カッコ内の数字を渡す。brd_outputのカッコ内がvoidの時、ここに記すカッコの中身はなくてよい→()
	while (1){
			input(player);
			brd_output();
			player *= -1;
	}
		
	return 0;
}


void brd_output(void)//返す値がなければvoidを使う。
{//↑返す値　　//↑持ってくる値
	int i,j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			switch(cell[i][j]){
			case BLK:  printf("〇");   break;
			case WHT:  printf("●");   break;
			case EMP:  printf("・");   break;
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
		printf("m9(^Д^)ﾌﾟｷﾞｬｰ < 置けねーよ\n\n");
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