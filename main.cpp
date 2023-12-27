#include "BSmodel.h"
#include <iostream>
#include <vector>

int main() {
    // Exemple de paramètres pour l'initialisation
    double time = 0.0;
    double stockPrice = 100.0;
    double volatility = 0.2;
    double drift = 0.05;
    double riskFreeRate = 0.03;

    // Créer une instance de BlackScholes
    BlackScholes bs(time, stockPrice, volatility, drift, riskFreeRate);

    // Générer un chemin de prix
    double targetDate = 1.0; // Par exemple, 1 an plus tard
    int steps = 10; // Nombre de pas dans le chemin de prix
    std::vector<double> pricePath = bs.pricePath(targetDate, steps);

    // Afficher le chemin de prix
    std::cout << "Price Path:" << std::endl;
    for (double price : pricePath) {
        std::cout << price << std::endl;
    }

    return 0;
}
