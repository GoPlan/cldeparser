#include <string>
#include <iostream>
#include "CldeParser.h"

using namespace CldeParser;

int main() {

    std::string example{"{ _a_15 : 'Example', 'a16' : 10.78Ee10 }"};

    Scanner scanner;

    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBraceOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBraceClose());

    SPtrTokenVector tokens = scanner.Scan(example);

    for (auto &token : tokens) {

        if (token->id() == (int) Scanning::TokenType::Space)
            continue;

        std::cout << token->CopyToString() << std::endl;
    }

    return 0;
}