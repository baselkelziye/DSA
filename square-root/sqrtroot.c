#include <stdio.h>
#include <math.h>
#define hata 0.000000000001
int main(){
	
	int t = 0;
	int flag = 1,control = 1;
	double kok,right, left,possible_value;
	left = 0;
	printf("\n Kok un degerini bulan programa hos geldiniz\n");
	
	printf("\n Lutfen sayi giriniz\n");
	scanf("%lf", &kok); // sayi alma
	
	while(flag == 1){
		if(kok < 0){// negatif olunca mat kuralina aykiri oldugu icin programdan cikarilir
		printf("\n Math Error");
		flag = 0;
		control = 0;
	}
	else{
		right = kok; // kokun degerini saga atmal
		do{
			t++;
			possible_value = (left + right)/2; // kok adayimiz
			printf("\n %d. giriste possible_value degeri : %lf", t, possible_value);
			if(possible_value * possible_value > kok){
				right = possible_value;
				printf("\n right is : %lf", right);
			}
			else if(possible_value * possible_value < kok){
				left = possible_value;
				printf("\n left is : %lf", left);
			}
			else{
				break;
			}
			
			
			
		}
		while(fabs(possible_value * possible_value - kok) > hata );
		flag = 0;
		
	}
	
	}
	if(control == 1){
		printf("\n kokun yaklasik degeri : %lf", possible_value);
	}
	
	printf("\n");
	return 0;
}
