#include<stdio.h>
#include<stdlib.h>

struct data{
	int node;
	int cost;
}heap[100];

int ctr = 0;

void insert(int node, int cost){
	ctr++;
	int idx = ctr;

	heap[ctr].cost = cost;
	heap[ctr].node = node;

	while(idx != 1 && heap[idx].cost < heap[idx/2].cost){
		data temp;
		temp = heap[idx];
		heap[idx] = heap[idx/2];
		heap[idx/2] = temp;
		
		idx = idx/2;
	}
}

data findMin(){
	if(ctr == 0){
		data d;
		d.cost = 1<<30;
		d.node = -1;
		return d;
	}
	else{
		return heap[1];
	}
}

void downheap(int idx){
	int currIdx = idx;
	data currData = heap[idx];

	if(idx*2 < ctr && heap[idx*2].cost < currData.cost){
		currIdx = idx*2;
		currData = heap[currIdx];
	}
	if(idx*2+1 < ctr && heap[idx*2+1].cost < currData.cost){
		currIdx = idx*2+1;
		currData = heap[currIdx];
	}

	if(idx == currIdx) return;

	data d;
	d = heap[currIdx];
	heap[currIdx] = heap[idx];
	heap[idx] = d;

	downheap(currIdx);
}

data extractMin(){
	if(ctr == 0){
		data d;
		d.cost = 1<<30;
		d.node = -1;
		return d;
	}

	if(ctr == 1){
		ctr--;
		return heap[1];
	}

	data temp;
	temp = heap[1];

	heap[1] = heap[ctr];
	ctr--;

	downheap(1);

	return temp;
}

int main(){
	insert(5, 7);
	insert(5, 8);
	insert(5, 9);

	data d = extractMin();
	printf("%d - %d\n", d.node, d.cost);
	d = extractMin();
	printf("%d - %d\n", d.node, d.cost);
	d = findMin();
	printf("%d - %d\n", d.node, d.cost);

	getchar();
	return 0;
}