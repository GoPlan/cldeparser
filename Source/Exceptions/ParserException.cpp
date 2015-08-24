//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParserException.h"
#include "../Common/IDefines.h"

namespace CLDEParser {
    namespace Exceptions {

        ParserException::ParserException(int code,
                                         SPtrTokenVectorIterator const &iterator,
                                         std::string const &description)
                : _code{code}, _iterator{iterator}, _description{description} {
            //
            _message.clear();
            _message.reserve(Common::BufferSize::EIGHTY);
            _message += "[Parser]";
            _message += "[";
            _message += ParserException::CopyToString((ParserExceptionCode) _code);
            _message += ": " + (*iterator)->CopyToString();
            _message += "]";
            _message += " in \"" + _description + "\"";
        }

        ParserException::ParserException(int code, SPtrTokenVectorIterator const &iterator)
                : _code{code}, _iterator{iterator} {
            //
            _message.clear();
            _message.reserve(Common::BufferSize::EIGHTY);
            _message += "[Parser]";
            _message += "[";
            _message += ParserException::CopyToString((ParserExceptionCode) _code);
            _message += ": " + (*iterator)->CopyToString();
            _message += "]";
        }

        std::string ParserException::CopyToString(ParserException::ParserExceptionCode code) {

            switch (code) {
                case ParserExceptionCode::UnmatchedToken:
                    return "UnmatchedToken";
                case ParserExceptionCode::UnknownEntityType:
                    return "UnknownEntityType";
                case ParserExceptionCode::UnknownValueType:
                    return "UnknownValueType";
            }
        }
    }
}


