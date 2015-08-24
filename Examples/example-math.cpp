//
// Created by LE, Duc Anh on 8/11/15.
//

#include <iostream>
#include "CLDEParser.h"

using namespace CLDEParser;

int main() {

    std::string example{"(15 + 7) * 21 / 15 ; abc"};

    Scanner scanner;
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSubtracting());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateAdding());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateMultiplication());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateDivision());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateParenthesesOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateParenthesesClosing());

    SPtrTokenVector tokens = scanner.Scan(example);

    for (auto &token : tokens) {

        if (token->id() == (int) Scanning::TokenType::Space)
            continue;

        std::cout << token->CopyToString() << std::endl;
    }

    return EXIT_SUCCESS;
}