#include<stdio.h>
#include<string.h>

struct Book{
    char title[50];
    char author[50];
    float price;
};

int main(){
    struct Book b1;
    strcpy(b1.title, "The great Gasby");
    b1.author , "F. Scott Fitzgerald";
    b1.price = 10.99;

    printf("Book Title: %s\n", b1.title);
    printf("Book Author: %s\n", b1.author);
    printf("Book Price: %.2f\n",b1.price);
    return 0;
}
