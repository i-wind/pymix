#include <iostream>
#include "pyembed.h"

using namespace pyembed; // for brevity

int main(int argc, char** argv)
{
    try // always check for Python_exceptions
    {
        // Create an instance of the interpreter.
        Python py(argc, argv);

        // Load the test module into the interpreter
        py.load("test");           

        // value returned by python is stored here    
        long ret = 0; 

        // our argument list that maps string values 
        // to their python types    
        Arg_map args; 

        // fill up argument strings and their types.
        args["10"] = Py_long;
        args["20"] = Py_long;

        // make the call
        py.call("multiply", args, ret);

        // will print 200
        std::cout << ret << '\n'; 

        return 0;
    }
    catch (Python_exception ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
