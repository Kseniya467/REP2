#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Holod.h"

void printProducts(Product *products, int count) {
	printf("Содержимое холодильника:\n");
	for(int i=0; i < count; i++) {
	printf("Название: %s, Количество: %d, Цена: %.2f\n", products[i].name, products[i].quantity, products[i].price);
}
}

void searchProducts(Product *products, int count) {
	char name[50];
	float price;
	int parameter;
	printf("Поиск по:\n 1.Названию\n 2.Цене\n Выберите параметр поиска:");
	scanf("%d", &parameter);
if(parameter == 1) {
	printf("Введите название продукта:");
	scanf("%s", name);
	for(int i=0; i < count; i++) {
	if(strcmp(products[i].name, name) == 0) {
	printf("Нашлось: %s, Цена: %.2f, Количество: %d\n", products[i].name, products[i].price, products[i].quantity);
return;
}
}
printf("Продукт не найден\n");
}
else if(parameter == 2) {
printf("Введите цену продукта:");
scanf("%f", &price);
int j = 0;
for(int i=0; i < count; i++) {
        if(products[i].price == price) {
        printf("Нашлось: %s, Цена: %.2f, Количество: %d\n", products[i].name, products[i].price, products[i].quantity);
j = 1;
}
}
if(!j) {
printf("Продукт не найден\n");
}
}
else {
printf("Некорректный параметр для поиска\n");
}
}


void addProduct(Product **products, int *count) {
	*products = realloc(*products, (*count + 1) * sizeof(Product));
	printf("Введите название продукта:");
	scanf("%s", (*products)[*count].name);

	printf("Введите цену:");
	scanf("%f", &(*products)[*count].price);

	printf("Введите количество:");
	scanf("%d", &(*products)[*count].quantity);

	(*count)++;
}

void deleteProduct(Product *products, int *count) {
	int index;
	printProducts(products, *count);
	printf("Введите номер продукта для удаления:");
	scanf("%d", &index);
	if(index < 1 || index > *count) {
		printf("Несуществующий номер\n");
	return;
}
	for(int i=index - 1; i < *count - 1; i++) {
	products[i] = products[i+1];
}
(*count)--;
products = realloc(products, (*count) * sizeof(Product));
}

void editProduct(Product *products, int count) {
	int index;
	printProducts(products, count);
	printf("Введите номер продукта для редактирования:");
	scanf("%d", &index);
	if(index < 1 || index > count) { 
		printf("Несуществующий номер\n");
	return; 
}
	printf("Введите новое название:"); 
	scanf("%s", products[index - 1].name);
	printf("Введите новую цену:");
	scanf("%f", &products[index - 1].price);
	printf("Введите новое количество:");
	scanf("%d", &products[index - 1].quantity);
}

void loadProducts(Product **products, int *count, const char *filename) {
FILE *file = fopen(filename, "rb");
if (!file) return;
fseek(file, 0, SEEK_END);
*count = ftell(file) / sizeof(Product);
fseek(file, 0, SEEK_SET);
*products = malloc(*count * sizeof (Product));
fread(*products, sizeof(Product), *count, file);

fclose(file);
}

void saveProducts(Product *products, int count, const char *filename) {
FILE *file = fopen(filename, "wb");
if (!file) return;
fwrite(products, sizeof(Product), count, file);
fclose(file);
}
