//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParserException.h"
#include "../Common/IDefines.h"

namespace CLDEParser {
    namespace Exceptions {

        ParserException::ParserException(int code, const std::string &description)
                : Exception{code, description} {
            //
            _message.reserve(Common::BufferSize::EIGHTY);
            _message += "[" + ParserException::CopyToString((ParserExceptionCode) _code) + "]";
            _message += " " + _description;
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


