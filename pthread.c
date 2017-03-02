#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct sum_args{
	long limit;
	double sum;
};

const int MAX_THREAD = 5;

//	Thread subroutine
void * sumall(void * arg){
	struct sum_args * tmp = (struct sum_args *) arg;

	for(long i = 0; i < tmp->limit; ++i){
		tmp->sum += i;
	}
	pthread_exit(NULL);
}


//	MAIN PROGRAM
int main(int argc, char ** argv){

	if(argc <= 1 || argc > MAX_THREAD){
		printf("invalid usage!\n");
		return 1;
	}

	pthread_t t[argc - 1];
	struct sum_args sumBuffer[argc - 1];

	for(long i = 0; i < argc - 1; ++i){
		pthread_attr_t attr;
		pthread_attr_init(&attr);

		sumBuffer[i].limit = atol(argv[i + 1]);
		sumBuffer[i].sum = 0;

		pthread_create(&t[i],&attr,sumall,&sumBuffer[i]);
	}

	for(long i = 0; i < argc - 1; ++i){
		pthread_join(t[i],NULL);
		printf("sum is %lf\n", sumBuffer[i].sum);
	}

	return 1;
}
