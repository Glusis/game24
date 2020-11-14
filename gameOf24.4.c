/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>


/* Function that swaps values of variable x and y.*/
void swap(int *px,int *py){
	int h=*px;
	*px=*py;
	*py=h;
}


/* Function that checks the number in pairs.*/

int searchPairs(int x,int y, int z, int t, char array[8],int start){
	
	int sum=x;
	int count=0;
	
	/* If start is 8, this means we now have our 2 pairs, so we see
	 * if we can get 24.*/
	if(start==8){
		
		/* Check for pair1 + pair 2*/
		sum+=y;
		
		if(sum==24){
			count++;			
			array[3]='+';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum-=y;	
			
		/* Check for pair1 * pair 2*/
		sum=sum*y;
		
		if(sum==24){
			count++;			
			array[3]='*';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum=(sum/y)+(sum%y);
	
		/* Check for pair1 - pair 2*/
		
		sum-=y;
		
		if(sum==24){
			count++;			
			array[3]='-';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
				
		sum+=y;
		
		/* Check for pair1 / pair 2*/
		if(sum%y==0){
			sum=sum/y;
			
			if(sum==24){
				count++;			
				array[3]='/';
				printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
			}
			
			sum=sum*y;
		}
		
	}else{	
	
		/*Check for x+y*/	
		sum+=y;
		
		array[start]=x;
		array[start+1]='+';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
		
		start-=4;
		sum-=y;	
		
		/*Check for x*y*/
		sum=sum*y;
		
		array[start]=x;
		array[start+1]='*';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
		
		start-=4;	
		sum=sum/y;
		
		/*Check for x-y*/
		sum-=y;
		
		array[start]=x;
		array[start+1]='-';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
			
		start-=4;
		sum+=y;
		
		/*Check for x/y */
		if(sum%y==0){
				
			sum=sum/y;
			
			array[start]=x;
			array[start+1]='/';
			array[start+2]=y;
			start+=4;
			
			if(start==8){
				t=sum;
			}
			
			count+=searchPairs(z,t,sum,0,array,start);
				
			start-=4;	
			sum=sum*y;
		}
	}
	
	return count;
	
}




/* Function that checks the number in order.*/

int searchSeq(int x,int y, int z, int t, char array[8],int start){
	
	
	int sum=x;
	int count=0;
	
	if(start==0){
		array[start]=x;		
	}
	
	/* If start is 8, this means we now have our 2 pairs, so we see
	 * if we can get 24.*/
	if(start==6){
		
		if(x==24){
			count++;
			printf("Solution: ((%d %c %d) %c %d) %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		
	}else{	
		
		/*Check for x+y.*/	
		sum+=y;
		
		array[start+1]='+';
		array[start+2]=y;
		start+=2;
		
		count+=searchSeq(sum,z,t,0,array,start);
		
		start-=2;	
		sum-=y;		
		
		/*Check for x*y.*/
		sum=sum*y;
		
		array[start+1]='*';
		array[start+2]=y;
		start+=2;
		
		count+=searchSeq(sum,z,t,0,array,start);
		
		start-=2;	
		sum=sum/y;
		
		/*Check for x-y*/
		sum-=y;
		
		array[start+1]='-';
		array[start+2]=y;
		start+=2;
		
		count+=searchSeq(sum,z,t,0,array,start);
		
		start-=2;
		sum+=y;
		
		/*Check for x/y */
		if(sum%y==0){
				
			sum=sum/y;
			
			array[start+1]='+';
			array[start+2]=y;
			start+=2;
		
			count+=searchSeq(sum,z,t,0,array,start);
		
			start-=2;	
			sum=sum*y;
		}
	}
	
	return count;
	
}

int searchMid(int a,int b, int c, int d, char array[8],int start){

//	printf("a=%d, b=%d, c=%d, d=%d, start=%d\n",a,b,c,d,start);
	
	int sum=0;
	int count=0;
	int y=0;
	
	if (start==0){
		sum=b;
		y=c;
		array[start]=b;
	}
	
	if(start==2){
		start++;
		sum=a;
		y=b;
		array[start]=a;
	}
	
	if (start==5){
		start--;
		sum=b;
		y=d;
	}
	
	
	if(start==6){
		
	//		printf(" start=6, b=%d\n",b);
		
		if(b==24){
			count++;
			printf("Solution MID: (%d %c (%d %c %d)) %c %d\n",array[3],array[4],array[0],array[1],array[2],array[5],array[6]);
		}
		
		return count;
		
		
	}
		
		/*Check for x+y.*/	
		sum+=y;
		
		array[start+1]='+';
		if(start!=3){
			array[start+2]=y;
		}
		start+=2;
				
		count=count+searchMid(a,sum,c,d,array,start);
		
		
		start-=2;	
		sum-=y;		
		

		/*Check for x*y.*/
		sum=sum*y;
		
		array[start+1]='*';
		if(start!=3){
			array[start+2]=y;
		}
		start+=2;
		
		
		count=count+searchMid(a,sum,c,d,array,start);
		
		
		start-=2;	
		sum=sum/y;
		
		/*Check for x-y*/
		sum-=y;
		
		array[start+1]='-';
		if(start!=3){
			array[start+2]=y;
		}
		start+=2;
		
				
		count=count+searchMid(a,sum,c,d,array,start);
		
		
		start-=2;	
		sum+=y;
		
		/*Check for x/y */
		if(sum%y==0){
				
			sum=sum/y;
		
			array[start+1]='/';
			if(start!=3){
				array[start+2]=y;
			}
			start+=2;
			
			
			count=count+searchMid(a,sum,c,d,array,start);
			
			
			start-=2;	
			sum=sum*y;
		
	}
	

	
	return count;
	
}


int main (int argc,char*argv[]){
	
	int a,b,c,d,x,y;
	int combos=0;
	char answers[8];
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	
	/* This loop tries all different combinations of the 4 numbers.*/
	for(x=1;x<5;x++){	
		for(y=1;y<4;y++){
			
			combos+=searchPairs(a,b,c,d,answers,0);
			combos+=searchSeq(a,b,c,d,answers,0);
			combos+=searchMid(a,b,c,d,answers,0);
			
	
				
			swap(&c,&d);
			
			combos+=searchSeq(a,b,c,d,answers,0);
			combos+=searchPairs(a,b,c,d,answers,0);
			combos+=searchMid(a,b,c,d,answers,0);
			
			swap(&b,&c);
		
		}
		swap(&c,&d);
		swap(&b,&c);
		swap(&a,&b);
		
	}
	
	printf("Amount of combinations possible: %d\n",combos);
	
	
	
	
	
	
return 0;
}






