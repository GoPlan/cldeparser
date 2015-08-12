#include <string>
#include <iostream>
#include "CldeParser.h"
#include "Parsing/ParserFactory.h"

using namespace CldeParser;

int main() {

    std::string example{"{ _a_15 : 'Example', 'a16' : 10.78Ee10 }"};


    // Scanning
    Scanner scanner;
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


    // Parsing
    Parser parser;
    parser.Derivatives().push_back(Parsing::ParserFactory::CreateJsonDerivative());

    SPtrSyntaxTree syntaxTree = parser.Parse(tokens);


    return EXIT_SUCCESS;
}