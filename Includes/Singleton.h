#pragma once
#include "Prerequisites.h"

class Singleton {
private:
	Singleton() : value(0) {};
public:
	getInstancia() {
		if (instance != nullptr) {
			return instance;
		}
		else {
			instance = new Singleton;
			return instance;
		}
	}
	void setValue(int _value) {
		value = _value;
	}

	int getValue() {
		return value;
	}

private:
	static Singleton* instance;
	int value;
};