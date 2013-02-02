#include <Python.h>

static int numargs=0;

/* Return the number of arguments of the application command line */
static PyObject*
emb_numargs(PyObject *self, PyObject *args)
{
    if(!PyArg_ParseTuple(args, ":numargs"))
        return NULL;
    return Py_BuildValue("i", numargs);
}

static PyMethodDef EmbMethods[] = {
    {"numargs", emb_numargs, METH_VARARGS,
     "Return the number of arguments received by the process."},
    {NULL, NULL, 0, NULL}
};

int
main(int argc, char *argv[])
{
    Py_SetProgramName(argv[0]);  /* optional but recommended */
    Py_Initialize();

    numargs = argc;
    Py_InitModule("emb", EmbMethods);

    PyRun_SimpleString("from time import time, ctime\n"
                       "print 'Today is', ctime(time())\n");

    PyRun_SimpleString("import emb\n"
                       "print 'Number of arguments', emb.numargs()\n");

    Py_Finalize();
    return 0;
}
