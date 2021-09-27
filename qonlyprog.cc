//qrackbf
//License CC0
#include <stdio.h>
#include <string.h>
#include <random>
#define RAM_SIZE 2317
std::random_device qdexl;
std::uniform_int_distribution<char> color(0,1);
std::uniform_real_distribution<long double> distro(0.0,1.0);
const char program[] = "0>1<";
int main(void) {
	double *ram = (double *)calloc(RAM_SIZE, sizeof(double));
	for(unsigned long i = 0; i < RAM_SIZE; i++)
		ram[i] = 0.5;
	unsigned long ip = 0;
	unsigned long dp = 0;
	loopc:
	ip = 0;
	while(1) {
		switch(program[ip]) {
			case '>': //move left
				dp = dp + 1;
				if(dp >= RAM_SIZE)
					dp = 0;
				break;
			case '<': //move right
				dp = dp - 1;
				if(dp < 0)
					dp = RAM_SIZE - 1;
				break;
			case '!': //flip
				ram[dp] = 1.0 - ram[dp];
				break;
			case '?': //ifz skip
				if(!(distro(qdexl) <= ram[dp]))
					ip = ip + 1;
				break;
			case '0': //mean false
				ram[dp] = (ram[dp] + 0.0)/2.0;
				break;
			case '1': //mean true
				ram[dp] = (ram[dp] + 1.0)/2.0;
				break;
			case '2': //mean both
				ram[dp] = (ram[dp] + 0.5)/2.0;
				break;
			case 'L': //loop program ip
				goto loopc;
				break;
			default:
				break;
		}
		ip = ip + 1;
		//printhere
		printf("\x1b[1;1H");
		for(int i = 0; i < RAM_SIZE; i++) {
			if(distro(qdexl) <= ram[i])
				putchar('#');
			else
				putchar(' ');
		}
		fflush(stdout);
		//loopr
		if(ip >= strlen(program))
			goto loopc;
	}
	free(ram);
}
