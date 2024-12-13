#ifndef HOLOD_H
#define HOLOD_H 

typedef struct {
	char name[50];
	int quantity;
	float price;
} Product;

void printProducts(Product *products, int count);
void searchProducts(Product *products, int count);
void addProduct(Product **products, int *count);
void deleteProduct(Product *products, int *count);
void editProduct(Product *products, int count);
void loadProducts(Product **products, int *count, const char *producti);
void saveProducts(Product *products, int count, const char *producti);

#endif
