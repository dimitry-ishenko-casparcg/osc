////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef OSC_ELEMENT_HPP
#define OSC_ELEMENT_HPP

////////////////////////////////////////////////////////////////////////////////
#include "bundle.hpp"
#include "message.hpp"
#include "types.hpp"

////////////////////////////////////////////////////////////////////////////////
namespace osc
{

class packet;

////////////////////////////////////////////////////////////////////////////////
class element
{
public:
    element(message m) : element_(std::move(m)) { }
    element(bundle  b) : element_(std::move(b)) { }

    bool is_message() const { return std::holds_alternative<message>(element_); }
    bool is_bundle () const { return std::holds_alternative<bundle >(element_); }

    auto const& to_message() const { return std::get<message>(element_); }
    auto const& to_bundle () const { return std::get<bundle >(element_); }

    int32 space() const;

private:
    std::variant<message, bundle> element_;

    void append_to(packet&) const;
    friend class bundle;
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif