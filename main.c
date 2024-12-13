#include <stdio.h>
#include <stdlib.h>
#include "Holod.h"

int main() {
	Product *products = NULL;
	int count = 0;
	const char *filename = "producti.bin";
	loadProducts(&products, &count, filename);
	int option;

	do {
		printf("\nМеню:\n");
		printf("1. Вывести продукты на экран\n");
		printf("2. Найти продукт\n"); 
		printf("3. Добавить продукт\n"); 
		printf("4. Удалить продукт\n");
		printf("5. Редактировать продукт\n");
		printf("6. Выйти\n");
		printf("Введите номер:");
scanf("%d", &option);
 
	switch(option) {
	case 1:
		printProducts(products, count);
	break;
	case 2:
		searchProducts(products, count);
	break;
	case 3:
		addProduct(&products, &count);
	break;
	case 4:
		deleteProduct(products, &count);
	break;
	case 5:
		editProduct(products, count);
	break;
	case 6:
		saveProducts(products, count, filename);
printf("Изменения сохранены\n");
	break;
	default:
printf("Некорректный выбор\n");
}
}
while(option != 6);
free(products);
return 0;
}
