#include <stdio.h>
#include <stdlib.h>

void bts_world(){
	printf("BTS WORLD\n");
}

void kfc_read(){
	printf("KFC Read\n");
}

void mc(int x){
	printf("X = [%d]\n", x);
}

struct fops {
	void (*bts)();
	void (*kfc)();
	void (*mc)();
};

int main(){
	struct fops *p = (struct fops*)malloc(sizeof(struct fops));

	p->bts = &bts_world;
	p->kfc = &kfc_read;
	p->mc = &mc;

	p->bts();
	p->kfc();
	p->mc(123);

	return 0;
}
