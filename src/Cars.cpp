#include <Cars.h>

void sCar::move() {
	switch (dir) {
	case eDirection::UP:
		rect.pos.y += speed;
	break;
	case eDirection::DOWN:
		rect.pos.y -= speed;
	break;
	case eDirection::RIGHT:
		rect.pos.x += speed;
	break;
	case eDirection::LEFT:
		rect.pos.x -= speed;
	break;
	}
}

sRect sCar::getFuturePos() {
	switch (dir) {
	case eDirection::UP:
		return sRect(rect.pos.x, rect.pos.y + speed, rect.size.width, rect.size.height);
	case eDirection::DOWN:
		return sRect(rect.pos.x, rect.pos.y - speed, rect.size.width, rect.size.height);
	case eDirection::RIGHT:
		return sRect(rect.pos.x + speed, rect.pos.y, rect.size.width, rect.size.width);
	case eDirection::LEFT:
		return sRect(rect.pos.x + speed, rect.pos.y, rect.size.width, rect.size.height);
	}
}

bool sCar::needPassOtherCar(sCar *otherCar) {
	bool result;
	auto otherdir = otherCar->dir;
	switch (dir) {
	case eDirection::UP:{
		if (otherdir == eDirection::LEFT)
			result = true;
		break;
	}
	case eDirection::DOWN:{
		if (otherdir == eDirection::RIGHT)
			result = true;
		break;
	}
	case eDirection::RIGHT:{
		if (otherdir == eDirection::UP)
			result = true;
		break;
	}
	case eDirection::LEFT:{
		if (otherdir == eDirection::LEFT)
			result = false;
		else
			result = false;
		break;
	}
	}
	return result;
}

int sGasEngine::getFuel() { return fuel; }

void sGasEngine::refill(int count) { fuel += count; }

void sGasEngine::move() { fuel--; sCar::move(); }

int sElectroCar::getFuel() { return charge; }

void sElectroCar::refill(int count) { charge += count; }

void sElectroCar::move() { charge--; sCar::move(); }

void sHybrid::refill(int count) { charge += count / 2; fuel += count / 2; }

int sHybrid::getFuel() { return charge + fuel; }

void sHybrid::move() {
	if (rand() % 2 == 0)
		charge--;
	else
		fuel--;
	sCar::move();
}
