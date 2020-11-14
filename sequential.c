<<<<<<< Updated upstream
/* 
 * 	file: sequential.c
 *	author: Philip Blesinger (p.a.blesinger@student.rug.nl)
 * 	date: 11/11/2020
 * 	version: 1.0
 */
=======
/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */
>>>>>>> Stashed changes


#include <stdio.h>
#include <stdlib.h>




int useOp(int op, int sum, int no){
	switch(op){
		case 0:
			return sum + no;
		case 1:
			return sum - no;
		case 2:
			return sum * no;
		case 3:
			if(no != 0 && sum%no == 0){
				return sum / no;
			}else{
				return 0;
			}
		default:
			printf("incorrect input for useOp function\n");
			exit(0);
			return 0;
	}
}
char showOp(int op){
	switch(op){
		case 0:
			return '+';
		case 1:
			return '-';
		case 2:
			return '*';
		case 3:
			return '/';
		default:
			printf("incorrect input for showOp function\n");
			exit(0);
			return 0;
	}
}
void loops(int array[]){
	int sum1,sum2,sum3,sum4 = 0;
	int f,g,h,i = 0;
	
	for(int a=0; a<4; a++){
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		sum4 = 0;
		//choose first no
		f = array[a];
		sum1 = array[a];
		for(int x=0; x<4; x++){
			//choose op
			for(int b=0; b<4; b++){
				//choose second no
				if(b != a){
					g = array[b];
						
					sum2 = useOp(x,sum1,array[b]);
					for(int y=0; y<4; y++){
						//choose op
						for(int c=0; c<4; c++){
							//choose third no
							if(c != a && c != b){
								h = array[c];
									
								sum3 = useOp(y,sum2,h);
								for(int z=0; z<4; z++){
									//choose op
									
									for(int d=0; d<4; d++){
										//choose fourth no
										if(d != a && d != b && d != c){
											i = array[d];						
											sum4 = useOp(z,sum3,i);
											//printf("%d ",sum4);
											if(sum4 == 24){
												printf("%d((%d%c%d)%c%d)%c%d\n",sum4,f,showOp(x),g,showOp(y),h,showOp(z),i);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]){
	int array[4];
	for(int i=0;i<4;i++){
		scanf("%d",&array[i]);
	}
	loops(array);
	return 0;
}
