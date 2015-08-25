//
// Created by LE, Duc Anh on 8/18/15.
//

#include "ParserSingle.h"
#include "Exceptions/ParserException.h"
#include "Common/IDefines.h"

namespace CLDEParser {

    SPtrSyntaxModel ParserSingle::Parse(SPtrTokenVector const &sptrTokens) const {

        auto iterator = sptrTokens.cbegin();

        try {

            // Empty string returns a nullptr entity
            if(iterator == sptrTokens.cend()){
                return _sptrDerivative->SyntaxModel();
            }

            // Process
            if (!_sptrDerivative->Derive(iterator)) {
                int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                throw Exceptions::ParserException{code, iterator};
            }

        } catch (Exceptions::ParserException &ex) {

            std::string _description;

            _description.reserve(Common::BufferSize::EIGHTY);

            auto exIter = sptrTokens.cbegin();

            for (; exIter != ex.Iterator(); ++exIter) {
                _description += (*exIter)->CopyToString();
            }

            _description += (*(ex.Iterator()))->CopyToString();

            throw Exceptions::ParserException{(int) ex.Code(), iterator, _description};
        }

        return _sptrDerivative->SyntaxModel();
    }
}


