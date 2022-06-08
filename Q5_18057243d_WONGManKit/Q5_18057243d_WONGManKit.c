#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void in(char msg[],int arr[]){
	
	//split message into 4 blocks
	char s_a[5], s_b[5], s_c[5], s_d[5];
	memcpy( s_a, &msg[0], 4 );
	s_a[4] = '\0';
	memcpy( s_b, &msg[4], 4 );
	s_b[4] = '\0';
	memcpy( s_c, &msg[8], 4 );
	s_c[4] = '\0';
	memcpy( s_d, &msg[12], 4 );
	s_d[4] = '\0';
	
	
	//convert char to int
	memcpy(&arr[0], s_a, sizeof arr[0]);
	memcpy(&arr[1], s_b, sizeof arr[1]);
	memcpy(&arr[2], s_c, sizeof arr[2]);
	memcpy(&arr[3], s_d, sizeof arr[3]);

	
}

void quat(int arr[]){
	int a,b,c,d;
	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
	
	a += b;
	d ^= a;
	d = d << 16;

	c += d;
	b ^= c;
	b = b << 12;
	
	a += b;
	d ^= a;
	d = d << 8;
	
	c += d;
	b ^= c;
	b = b << 7;
	
	arr[0] = a;
	arr[1] = b; 
	arr[2] = c; 
	arr[3] = d; 

}

void full(char input[]){
	int arr[4] = {0};
	
	printf("Input: %s \n", input); 
	//in is the function to assign variable to integer array
	in(input, arr);
	//printf("%x", arr[0]);
	//quater function
	quat(arr);
	
	//print 4 integers in the form of bytes
	printf("Output:");
	for(int i = 0; i<4;i++)
		printf("%x ", arr[i]);
	printf("\n");

}

int main(void){
	char input[16];
	
	printf("Normal inputs\n");
	strcpy(input, "expand 32-btye k");
	//full accept 4*32bits words and print 4 32 bit integer
	full(input);
	
	printf("Input with only characters\n");
	strcpy(input, "abcdefghijklmnop");
	full(input);
	
	printf("Input with only numbers\n");
	strcpy(input, "0123456789101112");
	full(input);
	
	printf("The input is 16 duplicate characters\n");
	strcpy(input, "aaaaaaaaaaaaaaaa");
	full(input);
		
	strcpy(input, "baaaaaaaaaaaaaaa");
	full(input);
	
	return 0;
}

