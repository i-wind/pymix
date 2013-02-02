/* numbers.cpp */

#include <Python.h>

class Numbers
{
public:
    Numbers(int first, double second): m_first(first), m_second(second){;}
    ~Numbers(void){;}
    double NumMemberMult(void){return (double)m_first*m_second;}
private:
    int m_first;
    double m_second;
};

static void DelNumbers(void *ptr)
{
    Numbers * oldnum = static_cast<Numbers *>(ptr);
    delete oldnum;
    return;
}

// wrapper that creates a new instance of Numbers
PyObject *wrap_new_Numbers(PyObject *, PyObject* args)
{
    //First, extract the arguments from a Python tuple
    int arg1;
    double arg2;

    int ok = PyArg_ParseTuple(args, "id", &arg1, &arg2);
    if(!ok) return 0;

    //Second, dynamically allocate a new object
    Numbers *newnum = new Numbers(arg1, arg2);

    //Third, build a Python object to return
    PyObject * py_newnum = PyCObject_FromVoidPtr(static_cast<void *>(newnum),
                                                 &DelNumbers);
    return py_newnum;
}

PyObject *wrap_Numbers_MemberMult(PyObject *, PyObject* args)
{
    // First, extract the PyCObject that has the
    // Python version of the address
    // from the args tuple
    PyObject *pynum = 0;
    int ok = PyArg_ParseTuple(args, "O", &pynum);
    //"O" is for Object
    if(!ok) return NULL;

    //Convert the PyCObject to a void *
    void * temp = PyCObject_AsVoidPtr(pynum);

    //cast void pointer to Numbers pointer
    Numbers * thisnum = static_cast<Numbers *>(temp);

    //Can combine the two lines into one:
    Numbers *thisNum = static_cast<Numbers *>( PyCObject_AsVoidPtr(pynum) );
    //Second, make the function call
    double result = thisnum->NumMemberMult();

    //Third, build a Python object with the return value
    return Py_BuildValue("d",result);
}

static PyMethodDef numbersMethods[] = {
    {"PyNumbers", wrap_new_Numbers, METH_VARARGS, "Create new Numbers object"},
    {"PyNumbers_MembMult", wrap_Numbers_MemberMult, METH_VARARGS,
            "Multiply Numbers object’s members"},
    {NULL, NULL, 0, NULL}
};

/*
extern "C"
#ifdef WIN32 || _WIN32
__declspec(dllexport)
#endif
*/
PyMODINIT_FUNC
init_numbers()
{
    (void) Py_InitModule3("_numbers", numbersMethods, "Numbers module");
}
