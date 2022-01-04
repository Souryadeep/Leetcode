/*
	program: printinorder.c
	leetcode: https://leetcode.com/problems/print-in-order/
	link with -lpthreads option
	Runtime: 61 ms, faster than 89.56% of C online submissions for Print in Orde
	Memory Usage: 6.5 MB, less than 96.52% of C online submissions for Print in Order
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t second;
    pthread_mutex_t third;
    
} Foo;


Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->second, NULL);
    pthread_mutex_lock(&obj->second);
    pthread_mutex_init(&obj->third, NULL);
    pthread_mutex_lock(&obj->third);
    
    return obj;
}

void printFirst(){

	printf("first\n");

}

void printSecond(){

	printf("second\n");

}

void printThird(){

	printf("third\n");

}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_unlock(&obj->second);
}

void second(Foo* obj) {
    
    pthread_mutex_lock(&obj->second);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pthread_mutex_unlock(&obj->third);
}

void third(Foo* obj) {
    
    pthread_mutex_lock(&obj->third);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&obj->third);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
    
}



int main(int argc, char *argv[]){

	Foo *obj = fooCreate();

	pthread_t threadA,threadB,threadC;

	//spawn the 3 threads
	pthread_create(&threadA,NULL,(void *)first,obj);	
	pthread_create(&threadB,NULL,(void *)second,obj);	
	pthread_create(&threadC,NULL,(void *)third,obj);	


	//wait for three threads to complete
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);

	fooFree(obj);

	return 0;

}
