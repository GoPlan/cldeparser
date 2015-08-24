//
// Created by LE, Duc Anh on 8/3/15.
//

#include "ScannerException.h"
#include "../Common/IDefines.h"

namespace CLDEParser {
    namespace Exceptions {

        ScannerException::ScannerException(int code, std::string const &description)
                : _code{code}, _description{description} {
            //
            _message.reserve(Common::BufferSize::EIGHTY);
            _message += "[Scanner]";
            _message += "[" + ScannerException::CopyToString((ScannerExceptionCode) _code) + "]";
            _message += " at \"" + _description + "\"";
        }

        ScannerException::ScannerException(int code, std::string const &description, char token)
                : _code{code}, _description{description}, _token{token} {
            //
            _message.reserve(Common::BufferSize::EIGHTY);
            _message += "[Scanner]";
            _message += "[" + ScannerException::CopyToString((ScannerExceptionCode) _code) + " " + _token + "]";
            _message += " at \"" + _description + "\"";
        }

        std::string ScannerException::CopyToString(ScannerException::ScannerExceptionCode code) {

            switch (code) {
                case ScannerExceptionCode::TokenUnmatchable:
                    return "TokenUnmatchable";
                case ScannerExceptionCode::TokenizerUnsupportedFunction:
                    return "TokenizerUnsupportedFunction";
            }
        }
    }
}


