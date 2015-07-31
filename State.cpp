//
// Created by LE, Duc Anh on 7/31/15.
//

#include "State.h"

namespace CldeParser {

    State::State(char value, int position)
            : _value{value}, _position{position} {
        //
    }

    bool State::Lesser(const CldeParser::Common::IComparable &target) {

        auto &dstState = dynamic_cast<CldeParser::State &>(target);

        if (_value != dstState._value) return _value < dstState._value;
        if (_position != dstState._position) return _position < dstState._position;

        return false;
    }

    bool State::Greater(const CldeParser::Common::IComparable &target) {

        auto &dstState = dynamic_cast<CldeParser::State &>(target);

        if (_value != dstState._value) return _value > dstState._value;
        if (_position != dstState._position) return _position > dstState._position;

        return false;
    }

    bool State::Equal(const CldeParser::Common::IComparable &target) {
        auto &dstState = dynamic_cast<CldeParser::State &>(target);
        return !(*this).Lesser(dstState) && !(*this).Greater(dstState);
    }
}

