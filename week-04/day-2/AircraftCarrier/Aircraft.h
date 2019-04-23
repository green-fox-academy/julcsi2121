//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <iostream>
#include <string>


class Aircraft {
public:
    Aircraft();
    Aircraft(int maxAmmo, int baseDamage, int currentAmmo);

    int getMaxAmmo() const;
    void setMaxAmmo(int maxAmmo);
    int getBaseDamage() const;
    void setBaseDamage(int baseDamage);
    std::string getType() const;
    void setType(std::string type);
    int getCurrentAmmo() const;
    bool isIsPriority() const;
    void setCurrentAmmo(int currentAmmo);

    void setIsPriority(bool isPriority);

    void getStatus();
    int refill(int num);
    int fight();

private:
    int _maxAmmo;
    int _currentAmmo;
    int _baseDamage;
    std::string _type;
    bool _isPriority;

};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
