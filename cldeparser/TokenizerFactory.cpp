//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenizerFactory.h"
#include "Scanning/Tokenizers/CurlyBraceOpen.h"
#include "Scanning/Tokenizers/CurlyBraceClosing.h"
#include "Scanning/Tokenizers/BracketOpen.h"
#include "Scanning/Tokenizers/BracketClosing.h"
#include "Scanning/Tokenizers/ParenthesesOpen.h"
#include "Scanning/Tokenizers/ParenthesesClosing.h"
#include "Scanning/Tokenizers/Colon.h"
#include "Scanning/Tokenizers/SemiColon.h"
#include "Scanning/Tokenizers/Id.h"
#include "Scanning/Tokenizers/String.h"
#include "Scanning/Tokenizers/Number.h"
#include "Scanning/Tokenizers/Space.h"
#include "Scanning/Tokenizers/Tab.h"
#include "Scanning/Tokenizers/Comma.h"
#include "Scanning/Tokenizers/AngleBracketOpen.h"
#include "Scanning/Tokenizers/AngleBracketClosing.h"
#include "Scanning/Tokenizers/ForwardSlash.h"
#include "Scanning/Tokenizers/BackwardSlash.h"
#include "Scanning/Tokenizers/Adding.h"
#include "Scanning/Tokenizers/Subtracting.h"
#include "Scanning/Tokenizers/Multiplication.h"
#include "Scanning/Tokenizers/Division.h"
#include "Scanning/Tokenizers/BoolFalse.h"
#include "Scanning/Tokenizers/BoolTrue.h"
#include "Scanning/Tokenizers/Null.h"
#include "Scanning/Tokenizers/NumberInteger.h"
#include "Scanning/Tokenizers/CarriageReturn.h"
#include "Scanning/Tokenizers/LineFeed.h"

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


