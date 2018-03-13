#include "mnist.h"

int main(void)
{
	load_mnist();

	printf("%d", test_label[0]);

	save_mnist_pgm(test_image, 0);

	print_mnist_pixel(test_image, NUM_TEST);
	print_mnist_label(test_label, NUM_TEST);

	return 0;
}
