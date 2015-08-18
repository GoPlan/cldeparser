//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenizerFactory.h"
#include "Tokenizers/CurlyBraceOpen.h"
#include "Tokenizers/CurlyBraceClosing.h"
#include "Tokenizers/BracketOpen.h"
#include "Tokenizers/BracketClosing.h"
#include "Tokenizers/ParenthesesOpen.h"
#include "Tokenizers/ParenthesesClosing.h"
#include "Tokenizers/Colon.h"
#include "Tokenizers/SemiColon.h"
#include "Tokenizers/Id.h"
#include "Tokenizers/String.h"
#include "Tokenizers/Number.h"
#include "Tokenizers/Space.h"
#include "Tokenizers/Tab.h"
#include "Tokenizers/Comma.h"
#include "Tokenizers/SquareBracketOpen.h"
#include "Tokenizers/SquareBracketClosing.h"
#include "Tokenizers/AngleBracketOpen.h"
#include "Tokenizers/AngleBracketClosing.h"
#include "Tokenizers/ForwardSlash.h"
#include "Tokenizers/BackwardSlash.h"
#include "Tokenizers/Adding.h"
#include "Tokenizers/Subtracting.h"
#include "Tokenizers/Multiplication.h"
#include "Tokenizers/Division.h"
#include "Tokenizers/BoolFalse.h"
#include "Tokenizers/BoolTrue.h"
#include "Tokenizers/Null.h"
#include "Tokenizers/NumberInteger.h"

namespace CldeParser {
    namespace Scanning {

        SPtrTokenizer TokenizerFactory::CreateCurlyBraceOpen() {
            return std::make_shared<Tokenizers::CurlyBraceOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateCurlyBraceClosing() {
            return std::make_shared<Tokenizers::CurlyBraceClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateBracketOpen() {
            return std::make_shared<Tokenizers::BracketOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateBracketClosing() {
            return std::make_shared<Tokenizers::BracketClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateParenthesesOpen() {
            return std::make_shared<Tokenizers::ParenthesesOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateParenthesesClosing() {
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
        SPtrTokenizer TokenizerFactory::CreateNumberInteger() {
            return std::make_shared<Tokenizers::NumberInteger>();
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
        SPtrTokenizer TokenizerFactory::CreateSquareBracketOpen() {
            return std::make_shared<Tokenizers::SquareBracketOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateSquareBracketClosing() {
            return std::make_shared<Tokenizers::SquareBracketClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateAngleBracketOpen() {
            return std::make_shared<Tokenizers::AngleBracketOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateAngleBracketClosing() {
            return std::make_shared<Tokenizers::AngleBracketClosing>();
        }
        SPtrTokenizer TokenizerFactory::CreateForwardSlash() {
            return std::make_shared<Tokenizers::ForwardSlash>();
        }
        SPtrTokenizer TokenizerFactory::CreateBackwardSlash() {
            return std::make_shared<Tokenizers::BackwardSlash>();
        }
        SPtrTokenizer TokenizerFactory::CreateAdding() {
            return std::make_shared<Tokenizers::Adding>();
        }
        SPtrTokenizer TokenizerFactory::CreateSubtracting() {
            return std::make_shared<Tokenizers::Subtracting>();
        }
        SPtrTokenizer TokenizerFactory::CreateMultiplication() {
            return std::make_shared<Tokenizers::Multiplication>();
        }
        SPtrTokenizer TokenizerFactory::CreateDivision() {
            return std::make_shared<Tokenizers::Division>();
        }
        SPtrTokenizer TokenizerFactory::CreateBoolFalse() {
            return std::make_shared<Tokenizers::BoolFalse>();
        }
        SPtrTokenizer TokenizerFactory::CreateBoolTrue() {
            return std::make_shared<Tokenizers::BoolTrue>();
        }
        SPtrTokenizer TokenizerFactory::CreateNull() {
            return std::make_shared<Tokenizers::Null>();
        }
    }
}


