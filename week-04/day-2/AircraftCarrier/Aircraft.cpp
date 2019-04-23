//
// Created by Varga Júlia on 2019-04-23.
//

#include "Aircraft.h"

Aircraft::Aircraft() {
    _maxAmmo = 0;
    _baseDamage = 0;
    _currentAmmo = 0;
    _type = "undefined";
    _isPriority = false;
}

Aircraft::Aircraft(int maxAmmo, int baseDamage, int currentAmmo) {
    _maxAmmo = maxAmmo;
    _baseDamage = baseDamage;
    _currentAmmo = currentAmmo;
    _type = "undefined";
    _isPriority = false;
}

int Aircraft::getMaxAmmo() const {
    return _maxAmmo;
}

void Aircraft::setMaxAmmo(int maxAmmo) {
    _maxAmmo = maxAmmo;
}

int Aircraft::getBaseDamage() const {
    return _baseDamage;
}

void Aircraft::setBaseDamage(int baseDamage) {
    _baseDamage = baseDamage;
}

std::string Aircraft::getType() const {
    return _type;
}

void Aircraft::setType(std::string type) {
    _type = type;
}

void Aircraft::getStatus() {
    std::cout << "Type " <<  getType() << ", Ammo: " << getCurrentAmmo() << ", Base Damage: " <<  getBaseDamage() << ", All Damage: " << getCurrentAmmo() * getBaseDamage() << std::endl;
}

int Aircraft::getCurrentAmmo() const {
    return _currentAmmo;
}

int Aircraft::refill(int num) {
    while (getCurrentAmmo() < getMaxAmmo() && num > 0) {
        _currentAmmo++;
        num--;
    }
    return num;
}

int Aircraft::fight() {
    int damageDealt = _currentAmmo * _baseDamage;
    _currentAmmo = 0;
    return damageDealt;
}

bool Aircraft::isIsPriority() const {
    return _isPriority;
}

void Aircraft::setIsPriority(bool isPriority) {
    _isPriority = isPriority;
}

void Aircraft::setCurrentAmmo(int currentAmmo) {
    _currentAmmo = currentAmmo;
}
