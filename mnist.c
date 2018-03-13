#include "mnist.h"

int main(void)
{
	// mnist data will be stored in following array:
	// train image -> train_image[60000][784] (type: double, normalized, flattened)
	// train label -> train_label[60000]      (type: int)
	// test image  -> test_image[10000][784]  (type: double, normalized, flattened)
	// test label  -> test_label[10000]       (type: int)
	load_mnist();

	// print the pixel values of mnist images to stdout
	print_mnist_pixel(test_image, NUM_TEST);
	// print the label of mnist data to stdout
	print_mnist_label(test_label, NUM_TEST);

	// save mnist image as pgm file
	// argument1: image array
	// argument2: index of image to save
	save_mnist_pgm(train_image, 0);

	return 0;
}
