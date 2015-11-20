//
// Created by LE, Duc Anh on 8/13/15.
//

#include "JsonException.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {


            JsonException::JsonException(int code, std::string const &description)
                    : _code{code}, _description{description} {
                //
                _message.clear();
                _message.reserve(Common::BufferSize::EIGHTY);
                _message += "[Json]";
                _message += "[";
                _message += JsonException::CopyToString((JsonExceptionCode) _code);
                _message += "]";
            }

            JsonException::JsonException(int code, SPtrJsonSyntaxNodeIterator const &iterator)
                    : _code{code}, _iterator{iterator} {
                //
                _message.clear();
                _message.reserve(Common::BufferSize::EIGHTY);
                _message += "[Json]";
                _message += "[";
                _message += JsonException::CopyToString((JsonExceptionCode) _code);
                _message += ": " + (*iterator)->CopyToString();
                _message += "]";
                _message += " in \"" + _description + "\"";
            }

            std::string JsonException::CopyToString(JsonException::JsonExceptionCode code) {

                switch (code) {
                    case JsonExceptionCode::UnknownSyntaxNode:
                        return "UknownSyntaxNode";
                    case JsonExceptionCode::UnknownValueType:
                        return "UknownSyntaxNode";
                    case JsonExceptionCode::InvalidTypeCasting:
                        return "InvalidTypeCasting";
                    case JsonExceptionCode::UnSupportedValueType:
                        return "UnSupportedValueType";
                    case JsonExceptionCode::ValueIsNull:
                        return "ValueIsNull";
                }
            }
        }
    }
}


