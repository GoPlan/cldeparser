#include <string>
#include "CldeParser.h"

using namespace CldeParser;

int main() {

    auto characters = {'{', '}', ':', ',', '"'};
    auto completeStates = {1, 2, 3, 4, 5, 6, 7};
    auto acceptedStates = {2, 4, 6};

    Scanner scanner{completeStates, acceptedStates, characters};


    return 0;
}