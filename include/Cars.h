#include <Geometry.h>
#include <random>

struct sCar {
	sRect rect;
	eDirection dir;
	int speed;
	void move();
	sRect getFuturePos();

	bool needPassOtherCar(sCar* otherCar);

	virtual int getFuel() = 0;
	virtual void refill(int count) = 0;
};

struct sGasEngine : virtual sCar {
	int getFuel() override;
	void refill(int count) override;
	void move();
	int fuel;
};

struct sElectroCar : virtual sCar {
	int getFuel() override;
	void refill(int count) override;
	void move();
	int charge;
};

struct sHybrid : sGasEngine, sElectroCar {
	void refill(int count) override;
	int getFuel() override;
	void move();
};
