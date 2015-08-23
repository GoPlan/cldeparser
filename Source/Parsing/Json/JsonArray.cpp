//
// Created by LE, Duc Anh on 8/10/15.
//

#include "JsonArray.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            std::string JsonArray::CopyToString() const {

                std::string body{};
                body.reserve(20);

                for (auto &sptrJsonValue : _container) {

                    if (!body.empty())
                        body += ", ";

                    body += sptrJsonValue->CopyToString();
                }

                std::string msg{};
                msg.reserve(40);
                msg += "[";
                msg += body;
                msg += "]";

                return msg;
            }
        }
    }
}

