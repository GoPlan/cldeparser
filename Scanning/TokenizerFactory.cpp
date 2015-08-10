//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenizerFactory.h"
#include "Tokenizers/BraceOpen.h"
#include "BraceClosing.h"
#include "Tokenizers/BracketOpen.h"
#include "BracketClosing.h"
#include "Tokenizers/ParenthesesOpen.h"
#include "ParenthesesClosing.h"
#include "Tokenizers/Colon.h"
#include "Tokenizers/SemiColon.h"
#include "Tokenizers/Id.h"
#include "Tokenizers/String.h"
#include "Tokenizers/Number.h"
#include "Tokenizers/Space.h"
#include "Tokenizers/Tab.h"
#include "Tokenizers/Comma.h"

namespace CldeParser {
    namespace Scanning {

        SPtrTokenizer TokenizerFactory::CreateBraceOpen() {
            return std::make_shared<Tokenizers::BraceOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateBraceClose() {
            return std::make_shared<Tokenizers::BraceClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateBracketOpen() {
            return std::make_shared<Tokenizers::BracketOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateBracketClose() {
            return std::make_shared<Tokenizers::BracketClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateParenthesesOpen() {
            return std::make_shared<Tokenizers::ParenthesesOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateParenthesesClose() {
            return std::make_shared<Tokenizers::ParenthesesClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateSemiColon() {
            return std::make_shared<Tokenizers::SemiColon>();
        }
        SPtrTokenizer TokenizerFactory::CreateColon() {
            return std::make_shared<Tokenizers::Colon>();
        }
        SPtrTokenizer TokenizerFactory::CreateId() {
            return std::make_shared<Tokenizers::Id>();
        }
        SPtrTokenizer TokenizerFactory::CreateNumber() {
            return std::make_shared<Tokenizers::Number>();
        }
        SPtrTokenizer TokenizerFactory::CreateString() {
            return std::make_shared<Tokenizers::String>();
        }
        SPtrTokenizer TokenizerFactory::CreateSpace() {
            return std::make_shared<Tokenizers::Space>();
        }
        SPtrTokenizer TokenizerFactory::CreateTab() {
            return std::make_shared<Tokenizers::Tab>();
        }
        SPtrTokenizer TokenizerFactory::CreateComma() {
            return std::make_shared<Tokenizers::Comma>();
        }
    }
}


