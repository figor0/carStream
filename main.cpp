#include <vector>
#include <random>
#include <Cars.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

void spawnCarFromTop() {
	sCar* car;
	int carType = rand();
	if (carType % 3 == 0) {
		car = new sGasEngine();
	}
	else if (carType % 3 == 1) {
		car = new sElectroCar();
	}
	else if (carType % 3 == 2) {
		car = new sHybrid();
	}
	car->rect = sRect(SCREEN_WIDTH / 2, 0, 100, 100);
	car->speed = 1;
	car->dir = eDirection::DOWN;
}

void spawnCarFromBot() {
	sCar* car;
	int carType = rand();
	if (carType % 3 == 0) {
		car = new sGasEngine();
	}
	else if (carType % 3 == 1) {
		car = new sElectroCar();
	}
	else if (carType % 3 == 2) {
		car = new sHybrid();
	}
	car->rect = sRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT, 100, 100);
	car->speed = 1;
}

void SpawnCarFromLeft() {
	sCar* car;
	int carType = rand();
	if (carType % 3 == 0) {
		car = new sGasEngine();
	}
	else if (carType % 3 == 1) {
		car = new sElectroCar();
	}
	else if (carType % 3 == 2) {
		car = new sHybrid();
	}
	car->rect = sRect(0, SCREEN_HEIGHT / 2, 100, 100);
	car->speed = 1;
}

void spawnCarFromRight() {
	sCar* car;
	int carType = rand();
	if (carType % 3 == 0) {
		car = new sGasEngine();
	}
	else if (carType % 3 == 1) {
		car = new sElectroCar();
	}
	else if (carType % 3 == 2) {
		car = new sHybrid();
	}
	car->rect = sRect(0, SCREEN_HEIGHT / 2, 100, 100);
	car->speed = 1;
}

std::vector<sCar*> asdasd;
const int initialCarsCount = 10;

void spawnCar()
{
	if (rand() % 4 == 1)
		spawnCarFromRight();
	else if (rand() % 4 == 2)
		spawnCarFromTop();
	else if (rand() % 4 == 3)
		spawnCarFromBot();
	else if (rand() % 4 == 4)
		SpawnCarFromLeft();
}


bool main_loop() {
	for (auto car : asdasd) {
	for (auto car22 : asdasd) {
		if (car->getFuturePos().intersects(car22->getFuturePos())) {
			if (car->needPassOtherCar(car22))
			car->move();
			}
			else {
			car22->move();
			}
		}
		if (car->rect.pos.x <= 0 || car->rect.pos.x >= SCREEN_WIDTH || car->rect.pos.y <= 0 ||
		car->rect.pos.y >= SCREEN_HEIGHT)
			spawnCar();
	}
	return main_loop();
}

int main(int argc, char** argv) {
	for (auto i = 0; i < initialCarsCount; ++i) {
		spawnCar();
	}
	main_loop();
	return 0;
}
