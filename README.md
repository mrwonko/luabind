luabind
=======
- STATE: 
- MSVC 2013 RC: Builds OK, Tests OK (but the two ones I keep ignoring)
- GCC 4.8.1 MinGW64: Build OK, Tests OK (but this is only windows)
- (here is where you come in!)

Create Lua bindings for your C++ code easily - my improvements
- Variadic templates.
- Got rid of the arrays created in invoke.
- All boost removed (except if the nothrow policy shall be used).
- No backward compatibility to any old or faulty (MS) compilers.
- This is 24mb of Intellisense db versus close to 90mb with original luabind, also Intellisense is not crippled by boost preprocessor usage.

Important: This is not drop in replacable.
- The template parameters to class class_ work a bit differently to the original (Wrapper and Holder have a specific index, if you don't want one of them, use null_type)
- The policies are not implemented as functions with a wrapped integer argument, they're aliases to policy lists containing exactly the one respective policy
