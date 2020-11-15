/*file : gameOf24.c */
/*author : Julia & Phil */
/*date : 14/11-2020*/
/*version: 1.99*/


#include <stdio.h>
#include <stdlib.h>

/*Function that uses a chosen operation on two given numbers and returns the 
 * value we get after the operation.*/
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

/*Function that returns the chosen operator as a character.*/
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

/*Function that finds possible solutions and prints them.*/
int find24(int array[4]){
	
	float sum2,sum3,sum4,sum5;	
	int count=0,end=0,m=0,n=0;
	int x,t,y,z,a,b,c,d;
	int dupeb[4]={0,0,0,0};
	int dupec[4]={0,0,0,0};
	
	/* Choose the first number in the combination.*/
	for(a=0; a<4; a++){ 
			
		/* Skips duplicate numbers by checking if we have used the chosen number before, 
		 * if we have then the loop chooses a new unused number and if there is none we break out.*/	
		for(x=a-1;x>=0&&a<4;x--){
			if(array[x]==array[a]){
				a++;
				x=a;
			}
			if(a==4){
				end=1;
				break;
			}
		}		
		if(end){
			end=0;
			break;			
		}
		
		/* Choose the first operator.*/
		for(t=0; t<4; t++){
			
			/* Choose the second number.*/
			for(b=0; b<4; b++){
				
				if(b != a){
					
					/* Skips duplicate numbers.*/
					dupeb[m]=array[b];
					m++;
											
					for(x=m-2;x>=0&&m<4;x--){
						if(dupeb[m-1]==dupeb[x]){
							end=1;
							break;
						}
					}		
					if(end){
						end=0;
						break;
					}					
					
					sum2 = useOp(t,array[a],array[b]);	
					
					/* Choose the second operator.*/
					for(y=0; y<4; y++){
						
						/* Choose the third number.*/
						for(c=0; c<4; c++){
							
							if(c != a && c != b){
								
								/* Skips duplicates.*/	
								dupec[n]=array[c];
								n++;
					
								for(x=n-2;x>=0&&n<4;x--){
									if(dupec[x]==dupec[n-1]){
										end=1;
										break;
									}
								}		
								if(end){
									end=0;
									break;
								}	
							
								sum3 = useOp(y,sum2,array[c]);								
								
								/* Choose the third operator.*/
								for(z=0; z<4; z++){
									
									/* Choose the fourth number.*/
									for(d=0; d<4; d++){
										
										if(d != a && d != b && d != c){											
											
											/* Here we check if we have a solution, and if so we print it.*/					
											sum4 = useOp(z,sum3,array[d]);											
											if(sum4 == 24){
												count++;
												printf("((%d%c%d)%c%d)%c%d\n",array[a],showOp(t),array[b],showOp(y),array[c],showOp(z),array[d]);
											}											
										
											sum5=useOp(z,array[c],array[d]);									
											sum4 = useOp(y,sum2,sum5);
											if(sum4 == 24){
												count++;
												printf("(%d%c%d)%c(%d%c%d)\n",array[a],showOp(t),array[b],showOp(y),array[c],showOp(z),array[d]);			
											}
											
											sum4 = useOp(z,array[d],sum3);
											if(sum4 == 24){
												count++;
												printf("%d%c((%d%c%d)%c%d)\n",array[d],showOp(z),array[a],showOp(t),array[b],showOp(y),array[c]);
											}
											
											sum5=useOp(y,array[c],sum2);
											sum4 = useOp(z,sum5,array[d]);
											if(sum4 == 24){
												count++;
												printf("(%d%c(%d%c%d))%c%d\n",array[c],showOp(y),array[a],showOp(t),array[b],showOp(z),array[d]);
											}											
										}
									}
								}
							}
						}
						n=0;
					}
				}			
			}
			m=0;
		}
	}	
	return count;
}

int main (int argc,char*argv[]){
	
	int a,b,c,d;
	int combos=0;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	int numbers[4]={a,b,c,d};
	
	combos+=find24(numbers);
	
	if(combos){
		printf("Amount of combinations possible: %d\n",combos);
	}else{
		printf("No possible combinations!\n");
	}	

return 0;
}


