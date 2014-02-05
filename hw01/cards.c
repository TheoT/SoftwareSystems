/*

Theo Thompson
A program to keep track of card count. Excercise for hw1

*/
#include <stdio.h>
#include <stdlib.h>

/*
Converts card_name string to int value

card_name: char array storing name of a playing card
*/
int get_card_val(char card_name[])
{
	switch(card_name[0]){
		case 'K':
		case 'Q':
		case 'J':
			return 10;
			break;
		case 'A':
			return 11;
			break;
		default:
			return atoi(card_name);
	}
}
/*
Updates the count base on the current card value

count: points to the current count
val: the value of the latest card
*/
void adjust_count(int *count,int val)
{
	if (val>2 && val<7){
		*count = *count + 1;
	} else if (val==10){
		*count = *count - 1;
	}
}

int main(int argc, char const *argv[])
{
	char card_name[3];
	int count = 0;
	int run_flag = 1;
	int val;
	while(run_flag){
		puts("enter the card_name");
		scanf("%2s",card_name);
		if(card_name[0]=='X'){
			run_flag = 0;
			puts("quitting");
			continue;
		}
		val = get_card_val(card_name);
		if (val<1 || val>10){
			puts("invalid input");
			continue;
		}
		adjust_count(&count,val);
		printf("current count: %i\n",count);
	}
	return 0;
}
