/* call_function.c - A sample of calling
 * python functions from C code
 */
#include <python2.7/Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pArgs, *pFunc, *pValue;
    int i;

    if (argc < 3) {
        printf("Usage: call_function python_source function_name\n");
        return 1;
    }

    /* Initialize the Python Interpreter */
    Py_Initialize();

    PyRun_SimpleString("import sys\n"
                       "sys.path.append('.')");

    /* Build the name object */
    pName = PyString_FromString(argv[1]);

    /* Load the module object */
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        /* pFunc is a borrowed reference */
        pFunc = PyObject_GetAttrString(pModule, argv[2]);

        if (pFunc && PyCallable_Check(pFunc)) {
            /* Prepare the argument list for the call */
            if( argc > 3 ) {
                pArgs = PyTuple_New(argc - 3);
                for (i = 0; i < argc - 3; ++i) {
                    pValue = PyInt_FromLong(atoi(argv[i + 3]));
                    if (!pValue) {
                        Py_DECREF(pArgs);
                        Py_DECREF(pModule);
                        fprintf(stderr, "Cannot convert argument\n");
                        return 1;
                    }
                    /* pValue reference stolen here: */
                    PyTuple_SetItem(pArgs, i, pValue);
                }
                pValue = PyObject_CallObject(pFunc, pArgs);
                Py_DECREF(pArgs);
                if (pValue != NULL) {
                    printf("Result of call: %ld\n", PyInt_AsLong(pValue));
                    Py_DECREF(pValue);
                }
                else {
                    Py_DECREF(pFunc);
                    Py_DECREF(pModule);
                    PyErr_Print();
                    fprintf(stderr,"Call failed\n");
                    return 1;
                }
            }
            else {
                pValue = PyObject_CallObject(pFunc, NULL);
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        /* Clean up */
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    /* Finish the Python Interpreter */
    Py_Finalize();

    return 0;
}
