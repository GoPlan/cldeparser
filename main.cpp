#include <string>
#include <iostream>
#include "CldeParser.h"
#include "Parsing/ParserFactory.h"

using namespace CldeParser;

int main() {

    std::string example{"{ _a_15 : 'Example', 'a16' : 10.78E10 , isExample: true, isNotExample : false, abc : null }"};

    // Scanning
    Scanner scanner;
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNull());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolTrue());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolFalse());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBraceOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBraceClosing());

    SPtrTokenVector tokens = scanner.Scan(example);
    SPtrTokenVector filteredTokens;

    for (auto &item : tokens) {

        if (item->id() == (int) Scanning::TokenType::Space)
            continue;

        std::cout << item->CopyToString() << std::endl;
        filteredTokens.push_back(item);
    }

    // Parsing
    Parser parser;
    parser.Derivatives().push_back(Parsing::ParserFactory::CreateJsonDerivative());

    SPtrSyntaxTreeVector syntaxTrees = parser.Parse(filteredTokens);


    return EXIT_SUCCESS;
}