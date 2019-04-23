#include <iostream>
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"

int main() {
    /*
    garden - virágok és fák listája; locsoláskor lecsekkolja, hogy az elemeknek kell-e víz, és ha igen, akkor meglocsolja. kap paraméternek x vizet, és elosztja a locsolást igénylők között
    növény - mindenkinek van vízigénye, és arra vonatkozó adata, hogy kell-e neki víz, absorb % - mennyit nyel el
    növény -> fa: csak pontos értékek egyediek
    növény -> virág: csak pontos értékek egyediek
     */
    Plant unspec("purple");
    unspec.info();
    Plant withWater("pink", 5);
    withWater.info();

    Flower blue("Blue");
    blue.info();

    Flower yellow("Red", 10);
    yellow.info();

    Tree bukk("grey");
    Tree tolgy("brown", 14);
    bukk.info();
    tolgy.info();

}