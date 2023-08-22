#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float height;
	float width;
	
	void (*setHeight)(void*, float);
	void (*setWidth)(void*, float);
	
	float (*getArea)(void*);
	float (*getPerimeter)(void*);
	void (*toString)(void*);
} Rectangle;

void setHeight(void* self, float h) {
	Rectangle* this = self;
	this->height = h;
}

void setWidth(void* self, float w) {
	Rectangle* this = self;
	this->width = w;
}

float getArea(void* self) {
	Rectangle* this = self;
	return this->height * this->width;
}

float getPerimeter(void* self) {
	Rectangle* this = self;
	return 2 * (this->height + this->width);
}

void toString(void* self) {
	Rectangle* this = self;
	printf("Altura: %.2f\n", this->height);
	printf("Largura: %.2f\n", this->width);
	printf("------------------\n");
}

Rectangle* newRectangle(float height, float width) {
	Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle));

	rect->height = height;
	rect->width = width;
	
	rect->setHeight = setHeight;
	rect->setWidth = setWidth;

	rect->getArea = getArea;
	rect->getPerimeter = getPerimeter;
	rect->toString = toString;

	return rect;
}

int main() {
	Rectangle* rect = newRectangle(1, 2);

	rect->toString(rect);
	printf("Área: %.2f\n", rect->getArea(rect));
	printf("Perímetro: %.2f\n", rect->getPerimeter(rect));

	rect->setHeight(rect, 2);
	rect->setWidth(rect, 10);
	printf("\n");

	rect->toString(rect);
	printf("Área: %.2f\n", rect->getArea(rect));
	printf("Perímetro: %.2f\n", rect->getPerimeter(rect));

	free(rect);
	return 0;
}