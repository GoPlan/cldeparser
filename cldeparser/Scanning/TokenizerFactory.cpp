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
#include "Tokenizers/CarriageReturn.h"
#include "Tokenizers/LineFeed.h"

namespace CLDEParser {
    namespace Scanning {

        UPtrTokenizer TokenizerFactory::CreateCurlyBraceOpen() {
            return std::unique_ptr<Tokenizers::CurlyBraceOpen>(new Tokenizers::CurlyBraceOpen());
        }
        UPtrTokenizer TokenizerFactory::CreateCurlyBraceClosing() {
            return std::unique_ptr<Tokenizers::CurlyBraceClosing>(new Tokenizers::CurlyBraceClosing());
        }
        UPtrTokenizer TokenizerFactory::CreateBracketOpen() {
            return std::unique_ptr<Tokenizers::BracketOpen>(new Tokenizers::BracketOpen());
        }
        UPtrTokenizer TokenizerFactory::CreateBracketClosing() {
            return std::unique_ptr<Tokenizers::BracketClosing>(new Tokenizers::BracketClosing());
        }
        UPtrTokenizer TokenizerFactory::CreateParenthesesOpen() {
            return std::unique_ptr<Tokenizers::ParenthesesOpen>(new Tokenizers::ParenthesesOpen());
        }
        UPtrTokenizer TokenizerFactory::CreateParenthesesClosing() {
            return std::unique_ptr<Tokenizers::ParenthesesClosing>(new Tokenizers::ParenthesesClosing());
        }
        UPtrTokenizer TokenizerFactory::CreateSemiColon() {
            return std::unique_ptr<Tokenizers::SemiColon>(new Tokenizers::SemiColon());
        }
        UPtrTokenizer TokenizerFactory::CreateColon() {
            return std::unique_ptr<Tokenizers::Colon>(new Tokenizers::Colon());
        }
        UPtrTokenizer TokenizerFactory::CreateId() {
            return std::unique_ptr<Tokenizers::Id>(new Tokenizers::Id());
        }
        UPtrTokenizer TokenizerFactory::CreateNumber() {
            return std::unique_ptr<Tokenizers::Number>(new Tokenizers::Number());
        }
        UPtrTokenizer TokenizerFactory::CreateNumberInteger() {
            return std::unique_ptr<Tokenizers::NumberInteger>(new Tokenizers::NumberInteger());
        }
        UPtrTokenizer TokenizerFactory::CreateString() {
            return std::unique_ptr<Tokenizers::String>(new Tokenizers::String());
        }
        UPtrTokenizer TokenizerFactory::CreateSpace() {
            return std::unique_ptr<Tokenizers::Space>(new Tokenizers::Space());
        }
        UPtrTokenizer TokenizerFactory::CreateTab() {
            return std::unique_ptr<Tokenizers::Tab>(new Tokenizers::Tab());
        }
        UPtrTokenizer TokenizerFactory::CreateComma() {
            return std::unique_ptr<Tokenizers::Comma>(new Tokenizers::Comma());
        }
        UPtrTokenizer TokenizerFactory::CreateAngleBracketOpen() {
            return std::unique_ptr<Tokenizers::BracketOpen>(new Tokenizers::BracketOpen());
        }
        UPtrTokenizer TokenizerFactory::CreateAngleBracketClosing() {
            return std::unique_ptr<Tokenizers::BracketClosing>(new Tokenizers::BracketClosing());
        }
        UPtrTokenizer TokenizerFactory::CreateForwardSlash() {
            return std::unique_ptr<Tokenizers::ForwardSlash>(new Tokenizers::ForwardSlash());
        }
        UPtrTokenizer TokenizerFactory::CreateBackwardSlash() {
            return std::unique_ptr<Tokenizers::BackwardSlash>(new Tokenizers::BackwardSlash());
        }
        UPtrTokenizer TokenizerFactory::CreateAdding() {
            return std::unique_ptr<Tokenizers::Adding>(new Tokenizers::Adding());
        }
        UPtrTokenizer TokenizerFactory::CreateSubtracting() {
            return std::unique_ptr<Tokenizers::Subtracting>(new Tokenizers::Subtracting());
        }
        UPtrTokenizer TokenizerFactory::CreateMultiplication() {
            return std::unique_ptr<Tokenizers::Multiplication>(new Tokenizers::Multiplication());
        }
        UPtrTokenizer TokenizerFactory::CreateDivision() {
            return std::unique_ptr<Tokenizers::Division>(new Tokenizers::Division());
        }
        UPtrTokenizer TokenizerFactory::CreateBoolFalse() {
            return std::unique_ptr<Tokenizers::BoolFalse>(new Tokenizers::BoolFalse());
        }
        UPtrTokenizer TokenizerFactory::CreateBoolTrue() {
            return std::unique_ptr<Tokenizers::BoolTrue>(new Tokenizers::BoolTrue());
        }
        UPtrTokenizer TokenizerFactory::CreateNull() {
            return std::unique_ptr<Tokenizers::Null>(new Tokenizers::Null());
        }
        UPtrTokenizer TokenizerFactory::CreateCarriageReturn() {
            return std::unique_ptr<Tokenizers::CarriageReturn>(new Tokenizers::CarriageReturn());
        }
        UPtrTokenizer TokenizerFactory::CreateLineFeed() {
            return std::unique_ptr<Tokenizers::LineFeed>(new Tokenizers::LineFeed());
        }
    }
}


