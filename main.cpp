#include <string>
#include "CldeParser.h"

using namespace CldeParser;

int main() {

    auto characters = {'{', '}', ':', ',', '"'};
    auto completeStateIds = {1, 2, 3, 4, 5, 6, 7};
    auto acceptedStateIds = {2, 4, 6};

    std::string example{"{ name: 15 }"};

    SimpleScanner scanner{};
    scanner.Scan(example);

    return 0;
}