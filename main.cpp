#include <string>
#include <iostream>
#include "CldeParser.h"
#include "Parsing/Json/Json.h"
#include "ParserSingle.h"

using namespace CldeParser;

int main() {

    std::string example{
            "{ 'a\\t01' : { \"first\\u1ab4Name\": \"\", age : 34, lastName : '' }, a02 : [1.3E-2, 312.05 ,3.0 , 4.0, 5.0] }"};

    // Scanning
    Scanner scanner;
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNull());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolTrue());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolFalse());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumberInteger());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceClosing());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketClosing());

    SPtrTokenVector tokens = scanner.Scan(example);
    SPtrTokenVector filtered(tokens.size());

    // Remove Space tokens
    std::copy_if(tokens.cbegin(), tokens.cend(), filtered.begin(),
                 [](SPtrToken const &token) -> bool {
                     return token->id() != (int) Scanning::TokenType::Space;
                 });

    filtered.shrink_to_fit();

    // Parsing
    ParserSingle parser{Parsing::ParserFactory::CreateJsonDerivative()};
    auto sptrSyntaxModel = std::dynamic_pointer_cast<Parsing::Json::JsonSyntaxModel>(parser.Parse(filtered));
    auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();

    std::cout << "Input: " << example << std::endl;
    std::cout << "Output: " << sptrJsonEntity->CopyToString() << std::endl;

    return EXIT_SUCCESS;
}