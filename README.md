# MNIST for C

This repository contains a header file for loading MNIST dataset in C language.


## preparation

1. download the following data files

	- train image : `train-images.idx3-ubyte`
	- train label : `train-labels.idx1-ubyte`
	- test image : `t10k-images.idx3-ubyte`
	- test label : `t10k-labels.idx1-ubyte`  

	you can find these files inside `/data` directory in this repository  
	they are also available at http://yann.lecun.com/exdb/mnist/

2. download `mnist.h`

3. in `mnist.h`, set the appropriate data path to the following macros

	- ```#define TRAIN_IMAGE (ex: "./data/train-images.idx3-ubyte")```
	- ```#define TRAIN_LABEL (ex: "./data/train-labels.idx1-ubyte")```
	- ```#define TEST_IMAGE  (ex: "./data/t10k-images.idx3-ubyte")```
	- ```#define TEST_LABEL  (ex: "./data/t10k-labels.idx1-ubyte")```

4. add `#include "mnist.h"` in your C code


## usage

after calling the following *void* function,  
`load_mnist();`  
you will be able to access the corresponding data through the following array:

- train image : train_image[60000][784] (type: double, normalized, flattened)
- train label : train_label[60000]      (type: int)
- test image  : test_image[10000][784]  (type: double, normalized, flattened)
- test label  : test_label[10000]       (type: int)


## functions

- void **load_mnist (** void **)**  
	load mnist data to respective array (as mentioned above)  

- void **print_mnist_pixel (** double data_image[][], int num_data **)**  
	print pixel values of all mnist images to stdout  
	data_image[][]: `train_image` or `test_image`  
	num_data: `NUM_TRAIN` or `NUM_TEST`  

- void **print_mnist_label (** double data_label[][], int num_data **)**  
	print label of all mnist data to stdout  
	data_label[][]: `train_image` or `test_image`  
	num_data: `NUM_TRAIN` or `NUM_TEST`  

- void **save_mnist_pgm (** double data_image[][SIZE], int index **)**  
	save mnist image as pgm file  
	data_image[][]: `train_image` or `test_image`  
	index: index of data to save (`0~59999` for train image, `0~9999` for test image)  


## example
```c
#include "mnist.h"

int main(void)
{
	load_mnist();

	int i;
	for (i=0; i<784; i++) {
		printf("%1.1f ", test_image[0][i]);
		if ((i+1) % 28 == 0) putchar('\n');
	}
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.3 0.7 0.6 0.6 0.2 0.1 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.9 1.0 1.0 1.0 1.0 0.9 0.8 0.8 0.8 0.8 0.8 0.8 0.8 0.8 0.7 0.2 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.3 0.4 0.3 0.4 0.6 0.9 1.0 0.9 1.0 1.0 1.0 1.0 0.9 1.0 1.0 0.5 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.1 0.3 0.1 0.3 0.3 0.3 0.2 0.1 0.9 1.0 0.4 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.3 1.0 0.8 0.1 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.1 0.9 1.0 0.3 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 0.9 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.2 1.0 1.0 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 0.7 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.8 1.0 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 0.7 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.3 1.0 0.9 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.1 0.9 1.0 0.7 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.8 1.0 0.9 0.1 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.1 1.0 1.0 0.3 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.1 0.9 1.0 0.5 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 1.0 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.2 0.9 1.0 1.0 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 1.0 0.9 0.2 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.5 1.0 0.8 0.1 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 
	// 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0

	printf("label: %d\n", test_label[0]);
	// label: 7

	return 0;
}
```
to see an actual runnig code, compile and run `example.c`