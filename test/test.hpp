// Copyright (c) 2004 Daniel Wallin

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef TEST_040212_HPP
#define TEST_040212_HPP

#include <luabind/lua_include.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/preprocessor/cat.hpp>

struct lua_state
{
    lua_state();
    ~lua_state();

    operator lua_State*() const;

private:
    lua_State* m_state;
    int m_top;
};

void dostring(lua_State* L, char const* str);

template<class T>
struct counted_type
{
    static int count;
    
    counted_type()
    {
        ++count;
    }

    counted_type(counted_type const&)
    {
        ++count;
    }

    ~counted_type()
    {
        BOOST_CHECK(--count >= 0);
    }
};

template<class T>
int counted_type<T>::count = 0;
/*
#define COUNTER_GUARD(type) \
    struct BOOST_PP_CAT(type, _counter_guard) \
    { \
        ~BOOST_PP_CAT(type, _counter_guard()) \
        { \
            BOOST_CHECK(counted_type<type>::count == 0); \
        } \
    }; \
    type##_counter_guard BOOST_PP_CAT(type, _guard)
*/

#define COUNTER_GUARD(x)

#define DOSTRING_EXPECTED(state, str, expected) \
{                                               \
    try                                         \
    {                                           \
        dostring(state, str);                   \
    }                                           \
    catch (std::string const& s)                \
    {                                           \
        if (s != expected)                      \
            BOOST_ERROR(s.c_str());             \
    }                                           \
}

#define DOSTRING(state, str)                    \
{                                               \
    try                                         \
    {                                           \
        dostring(state, str);                   \
    }                                           \
    catch (std::string const& s)                \
    {                                           \
        BOOST_ERROR(s.c_str());                 \
    }                                           \
}

#endif // TEST_040212_HPP

