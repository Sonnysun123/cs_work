#pragma once
#include <functional>
#include <vector>
using namespace std;
//Full template
    template<typename Signature>
    class Functions;
//Partial specification
template<typename ReturnType, typename... Args>
class Functions<ReturnType(Args...)> {
    vector<function<ReturnType(Args...)>> _actions;

public:
    void AddAction(function<ReturnType(Args...)> a) {
        _actions.push_back(a);
    }

    void DoAllActions(Args... args) const {
        for (auto action : _actions) {
            action(args...);
        }
    }
};
