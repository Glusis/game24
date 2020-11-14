/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>


/* Function that swaps values of variable x and y.*/
void swap(float *px,float *py){
	float h=*px;
	*px=*py;
	*py=h;
}


float useOp(int op, float sum, float no){
	switch(op){
		case 0:
			return sum + no;
		case 1:
			return sum - no;
		case 2:
			return sum * no;
		case 3:
			if(no != 0){
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



int loops(int array[]){
	float sum1,sum2,sum3,sum4,sum5=0;
	int count = 0;
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
											
											//printf("a=%d, b=%d, c=%d, d=%d\n",array[a],array[b],array[c],array[d]);
											i = array[d];	
											
											
											/* Check sequential (a&b&c&d).*/					
											sum4 = useOp(z,sum3,i);
											//printf("%d ",sum4);
											if(sum4 == 24){
												count++;
												printf("SEQ: ((%d%c%d)%c%d)%c%d\n",f,showOp(x),g,showOp(y),h,showOp(z),i);
											}
											
										
									
											/* Check pairs (a&b and c&d).*/	
											
											/* Check c&d.*/
											sum5=useOp(z,h,i);												
											
											sum4 = useOp(y,sum2,sum5);
											//printf("%d ",sum4);
											if(sum4 == 24){
												count++;
												printf("PAIRS:(%d%c%d)%c(%d%c%d)\n",f,showOp(x),g,showOp(y),h,showOp(z),i);			
											}
											
											
											/* Check pairs d&((a&b)&c).*/
											sum4 = useOp(z,i,sum3);
											//printf("%d ",sum4);
											if(sum4 == 24){
												count++;
												printf("OTHER:%d%c((%d%c%d)%c%d)\n",i,showOp(z),f,showOp(x),g,showOp(y),h);
											}
											
											
											/* Check pairs (c&(a&b))&d.*/
											sum5=useOp(y,h,sum2);
											sum4 = useOp(z,sum5,i);
											//printf("%d ",sum4);
											if(sum4 == 24){
												count++;
												printf("OTHER:(%d%c(%d%c%d))%c%d\n",h,showOp(y),f,showOp(x),g,showOp(z),i);
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
	
	return count;
}




int main (int argc,char*argv[]){
	
	int a,b,c,d;
	int combos=0;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	int numbers[4]={a,b,c,d};
	
	combos+=loops(numbers);
	
	if(combos){
		printf("Amount of combinations possible: %d\n",combos);
	}else{
		printf("No possible combinations!\n");
	}
	

return 0;
}






