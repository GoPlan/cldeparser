#include <string>
#include <iostream>
#include "CldeParser.h"
#include "Common/TokenizerFactory.h"
#include "Common/TokenType.h"

using namespace CldeParser;

int main() {

    std::string example{"{ _a_15 : 'Example', 'a16' : 10.78Ee10 }"};

    Scanner scanner;

    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateId());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateString());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateColon());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateComma());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateTab());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateBraceOpen());
    scanner.Tokenizers().push_back(Common::TokenizerFactory::CreateBraceClose());

    SPtrTokenVector tokens = scanner.Scan(example);

    for (auto &token : tokens) {

        if (token->id() == (int) Common::TokenType::Space)
            continue;

        std::cout << token->CopyToString() << std::endl;
    }

    return 0;
}