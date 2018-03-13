#include "mnist.h"

int main(void)
{
	load_mnist();

	print_mnist_pixel(test_image, NUM_TEST);

	print_mnist_label(test_label, NUM_TEST);

	save_mnist_pgm(train_image, 0);

	return 0;
}
