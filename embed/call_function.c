// call_function.c - A sample of calling 
// python functions from C code
// 
#include <python2.7/Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3) {
        printf("Usage: call_function python_source function_name\n");
        return 1;
    }

    // Initialize the Python Interpreter
    Py_Initialize();

    PyRun_SimpleString("import sys\n"
                       "sys.path.append('.')");

    // Build the name object
    pName = PyString_FromString(argv[1]);

    // Load the module object
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // pFunc is a borrowed reference 
        pFunc = PyObject_GetAttrString(pModule, argv[2]);

        if (PyCallable_Check(pFunc)) {
            PyObject_CallObject(pFunc, NULL);
        }
        else {
            PyErr_Print();
        }

        // Clean up
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
    }

    // Finish the Python Interpreter
    Py_Finalize();

    return 0;
}
