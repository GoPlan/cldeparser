//
// Created by LE, Duc Anh on 7/31/15.
//

#ifndef CLDEPARSER_STATE_H
#define CLDEPARSER_STATE_H

#include <memory>
#include <vector>
#include "Common/IComparable.h"

namespace CldeParser {

    class State : public Common::IComparable {

        int _position{0};
        char _value{0};

    public:
        State() = default;
        State(char value, int position);
        State(const State &) = default;
        State(State &&) = default;
        State &operator=(const State &) = default;
        State &operator=(State &&) = default;
        virtual ~State() = default;

        // IComparable
        virtual bool Lesser(const Common::IComparable &target) override;
        virtual bool Greater(const Common::IComparable &target) override;
        virtual bool Equal(const Common::IComparable &target) override;
    };

    using SPtrState = std::shared_ptr<State>;
    using SPtrStateVector = std::vector<SPtrState>;
}


#endif //CLDEPARSER_STATE_H
