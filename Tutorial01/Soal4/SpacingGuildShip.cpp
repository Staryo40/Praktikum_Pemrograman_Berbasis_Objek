#include "SpacingGuildShip.hpp"
#include <iostream>
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip():maxPassengerCap(50), serialNum(++producedShips), guildNavigatorCount(3){
    passengerCount = 0;
    operatingGuildNavigator = 3;
    spiceStock = 50;
}
/* Ctor default: jumlah penumpang adalah 0, jumlah Guild Navigator adalah 3,
    * Kapasitas pesawat adalah 50 orang, dan stok spice 50*/

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock):
    maxPassengerCap(maxPassengerCap), serialNum(++producedShips), guildNavigatorCount(guildNavigatorCount), spiceStock(spiceStock){
    passengerCount = 0;
    operatingGuildNavigator = guildNavigatorCount;
}
/* Ctor jika diketahui jumlah Guild Navigator, kapasitas maksimal pesawat, 
    * dan stok spice. Jumlah penumpang 0 */

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s):serialNum(++producedShips), guildNavigatorCount(s.guildNavigatorCount), maxPassengerCap(s.maxPassengerCap){
    this->passengerCount = s.passengerCount;
    this->operatingGuildNavigator = s.operatingGuildNavigator;
    this->spiceStock = s.spiceStock;
}
/* Cctor SpacingGuildShip */

SpacingGuildShip::~SpacingGuildShip(){}
/* Dtor SpacingGuildShip */

int SpacingGuildShip::getShipSerialNum() const{
    return serialNum;
};
/* Mengembalikan serial number dari pesawat */

int SpacingGuildShip::getPassengerCount() const {
    return passengerCount;
}
/* Mengembalikan jumlah penumpang pesawat */

void SpacingGuildShip::travel(float distance){
    if (operatingGuildNavigator != 0){
        totalGuildTravel += distance / (E*E*operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}
/* Pesawat bergerak sebesar distance, sehingga 
    * totalGuildTravel bertambah sebesar:
    *
    * distance / (E^2 * operatingGuildNavigator).
    * 
    * Catatan: 
    * 1. Apabila tidak ada Guild Navigator yang operasional, 
    *    maka totalGuildTravel tidak bertambah;
    * 2. Apabila ada Guild Navigator yang operasional, 
    *    maka jumlah Guild Navigator operasional berkurang 1 */

void SpacingGuildShip::boarding(int addedPassengers){
    if (passengerCount + addedPassengers >= maxPassengerCap) {
        passengerCount = maxPassengerCap;
    } else {
        passengerCount += addedPassengers;
    }
}

/* Penumpang naik ke pesawat sebesar addedPassenger. 
    * Jika pesawat tidak muat, penumpang pesawat menjadi penuh */

void SpacingGuildShip::dropOff(int droppedPassengers){
    if (droppedPassengers >= passengerCount){
        passengerCount = 0;
    } else {
        passengerCount -= droppedPassengers;
    }
}
/* Penumpang turun dari pesawat sebesar droppedPassenger. 
    * Jika jumlah penumpang kurang, kosongkan pesawat */

void SpacingGuildShip::refreshNavigator(int n){
    int maxRefresh = GUILD_NAVIGATOR_SPICE_DOSE * n;
    if (maxRefresh > spiceStock){
        int refreshable = (int) spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
        operatingGuildNavigator += refreshable;
        spiceStock -= refreshable * GUILD_NAVIGATOR_SPICE_DOSE;
    } else {
        operatingGuildNavigator += n;
        spiceStock -= maxRefresh;
    }

}
/* Menambah n Guild Navigator operasional yang menghabiskan
    * n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
    * 
    * Catatan:
    * 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat 
    * 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
    *    dari stok spice yang ada */

void SpacingGuildShip::transitToArrakis(int addedSpice){
    spiceStock += addedSpice;
}
/* Menambah stok spice sebesar addedSpice */

