#include <python3.8/Python.h>

void kill_process(int process_id);

static PyObject *PyKillError;

static PyObject *
kill(PyObject *self, PyObject *args) {
    int process_id;

    if (!PyArg_ParseTuple(args, "i", &process_id)) {
        PyErr_SetString(PyKillError, "expected 1 arguments, got 0");
        return NULL;
    }

    kill_process(process_id);

    return Py_BuildValue("i", process_id);
}

static PyMethodDef PyKillMethods[] = {
    {"kill",  kill, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef killmodule = {
    PyModuleDef_HEAD_INIT,
    "kill_process",
    NULL,
    -1,
    PyKillMethods
};

PyMODINIT_FUNC
PyInit_kill_process(void){
    PyObject *m;
    m = PyModule_Create(&killmodule);
    if (m == NULL)
        return NULL;

    PyKillError = PyErr_NewException("kill_process.Error", NULL, NULL);
    Py_XINCREF(PyKillError);

    if (PyModule_AddObject(m, "Error", PyKillError) < 0) {
        Py_XDECREF(PyKillError);
        Py_CLEAR(PyKillError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}