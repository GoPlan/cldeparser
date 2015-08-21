//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParserException.h"

namespace CldeParser {
    namespace Exceptions {


        ParserException::ParserException(int id, const std::string &message)
                : Exception{message}, _id{id} {
            //
        }
    }
}


