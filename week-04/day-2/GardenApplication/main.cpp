#include <iostream>
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Garden.h"

int main() {
    /*
    garden - virágok és fák listája; locsoláskor lecsekkolja, hogy az elemeknek kell-e víz, és ha igen, akkor meglocsolja. kap paraméternek x vizet, és elosztja a locsolást igénylők között
    növény - mindenkinek van vízigénye, és arra vonatkozó adata, hogy kell-e neki víz, absorb % - mennyit nyel el
    növény -> fa: csak pontos értékek egyediek
    növény -> virág: csak pontos értékek egyediek
     */
    Plant unspec("purple");
    Plant withWater("pink", 4);

    Flower blue("Blue");

    Flower yellow("Red", 3);

    Tree bukk("grey");
    Tree tolgy("brown", 7);

    Garden mygarden;
    mygarden.addPlant(&blue);
    mygarden.addPlant(&yellow);
    mygarden.addPlant(&bukk);
    mygarden.addPlant(&tolgy);
    mygarden.printPlantInfo();

    //std::cout << mygarden.countThirsty();
    mygarden.watering(12);
    mygarden.watering(12);
    mygarden.watering(12);

}