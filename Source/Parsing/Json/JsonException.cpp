//
// Created by LE, Duc Anh on 8/13/15.
//

#include "JsonException.h"
#include "../../Common/IDefines.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            JsonException::JsonException(int code, SPtrJsonSyntaxNodeIterator const &iterator)
                    : _code{code}, _iterator{iterator} {
                //
                _message.clear();
                _message.reserve(Common::BufferSize::EIGHTY);
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
                }
            }
        }
    }
}


